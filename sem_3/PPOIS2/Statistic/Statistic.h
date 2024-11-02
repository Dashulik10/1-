#ifndef STATISTIC_H
#define STATISTIC_H
#include <iostream>
#include <string>
using namespace std;

class Statistic
{
private:
	int number_of_clients;
	int number_of_tours;
	double gain;
public:
	Statistic();
	Statistic(int number_of_clients, int number_of_tours, double gain);

	string getStatistics() const;

	string averageStatisticalIndicators(int, int, double) const;
	string analysAgencyGain() const;
	string getPformanceFeedback() const;
};
#endif