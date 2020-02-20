#pragma warning ( disable : 4244 )

#include "Random.h"

#include <random>
#include <chrono>

int Random::GetInteger(int begin, int end)
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(begin, end);
	return distribution(generator);
}

double Random::GetDouble(double begin, double end)
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<double> distribution(begin, end);
	return distribution(generator);
}