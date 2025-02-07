#ifndef TIMER_CPP
#define TIMER_CPP

#include <SDL.h>

class Timer {
private:
	bool m_IsActive{};
	Uint64 m_startTimeMs{};

public:
	void Start() {
		m_IsActive = true;
		m_startTimeMs = SDL_GetTicks64();
	}

	Uint64 GetElapsedTime()
	{
		if (!m_IsActive) {
			return -1;
		}

		return SDL_GetTicks64() - m_startTimeMs;
	}
};

#endif