#pragma once

#include <chrono>

class Timer
{
	std::chrono::time_point<std::chrono::system_clock> start;
	std::chrono::time_point<std::chrono::system_clock> end;
public:
	static double StandTimer();

	void Begin();
	void End();
};