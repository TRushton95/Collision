#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include "Timer.cpp"

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;
constexpr double PHYSICS_FRAME_RATE_MS = 1.0 / 60.0;

bool gRunning = true;
SDL_Window* gWindow;
SDL_Renderer* gRenderer;

void UpdatePhysics(double deltaMs) {
	
	// Has close button been pressed
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			gRunning = false;
		}
	}
}

void Render() {

}

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to initialise SDL: %s\n", SDL_GetError());
		return 0;
	}

	gWindow = SDL_CreateWindow("Collision", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		printf("Failed to create window: %s\n", SDL_GetError());
		return 0;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		return 0;
	}

	Timer timer{};
	timer.Start();
	Uint64 prevTimeMs{ 0 };
	double accumulator{ 0.0 };

	while (gRunning)
	{
		Uint64 deltaMs = timer.GetElapsedTime() - prevTimeMs;
		prevTimeMs = timer.GetElapsedTime();
		accumulator += static_cast<double>(deltaMs);

		// Arbitrary cap on physics time build-up, don't try to catch up if too many physics frames have been missed
		if (accumulator > 250) {
			accumulator = 250;
		}

		while (accumulator >= PHYSICS_FRAME_RATE_MS) {
			accumulator -= PHYSICS_FRAME_RATE_MS;
			UpdatePhysics(PHYSICS_FRAME_RATE_MS);
		}

		Render();
	}

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();

	printf("SDL app gracefully shut down\n");

	return 0;
}