#include "Timer.h"

using namespace std;
using namespace std::chrono;

double Timer::StandTimer()
{
	static bool stdTimerStarted = false;
	static time_point<system_clock> start;
	static time_point<system_clock> end;

	if (stdTimerStarted == false) {
		start = system_clock::now();
		stdTimerStarted = true;
		return -1;
	}
	else {
		end = system_clock::now();
		duration<double> elpasedTime = end - start;
		start = system_clock::now();
		return elpasedTime.count();
	}
}

void Timer::Begin()
{
	start = system_clock::now();
}

void Timer::End()
{
	end = system_clock::now();
	duration<double> elpasedTime = end - start;
}
