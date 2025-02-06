#include <iostream>
#include <SDL.h>

constexpr int WINDOW_WIDTH = 640;
constexpr int WINDOW_HEIGHT = 480;

bool gRunning = true;
SDL_Window* gWindow;
SDL_Renderer* gRenderer;

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

	while (gRunning)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				gRunning = false;
			}
		}
	}

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();

	printf("SDL app gracefully shut down\n");

	return 0;
}