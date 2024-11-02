#include <iostream>
#include <string>
#include "Statistic.h"
using namespace std;

// Statistic
Statistic::Statistic() : number_of_clients(0), number_of_tours(0), gain(0.0) {}
Statistic::Statistic(int clients, int tours, double g)
    : number_of_clients(clients), number_of_tours(tours), gain(g) {}

string Statistic::averageStatisticalIndicators(int avg_clients, int avg_tours, double avg_gain) const
{
    string result = "Comparison with average:\n";
    result += "Number of clients: " + to_string(number_of_clients) +
        (number_of_clients > avg_clients ? " above " : " below ") + "average (" + to_string(avg_clients) + ")\n";
    result += "Number of tours: " + to_string(number_of_tours) +
        (number_of_tours > avg_tours ? " above " : " below ") + "average (" + to_string(avg_tours) + ")\n";
    result += "Gain: $" + to_string(gain) +
        (gain > avg_gain ? " above " : " below ") + "average ($" + to_string(avg_gain) + ")\n";
    return result;
}

string Statistic::analysAgencyGain() const
{
    string analysis = "Analysis of current statistics:\n";
    analysis += "Number of clients: " + to_string(number_of_clients) + "\n";
    analysis += "Number of tours: " + to_string(number_of_tours) + "\n";
    analysis += "Gain: $" + to_string(gain) + "\n";

    if (gain < 10000) return analysis += "The budget plan is behind schedule.\n";
    else if (gain >= 10000 && gain <= 50000) return analysis += "The budget plan is within the boundaries of the average plan.\n";
    else return analysis += "Budget plan reaches new level.\n";
}

string Statistic::getPformanceFeedback() const
{
    string advice = "Advice based on current statistics:\n";
    if (number_of_clients < 10) return advice += "Opportunities to increase the efficiency of the marketing department should be considered.\n";
    if (number_of_tours < 5) return advice += "The tourist base should be diversified.\n";
}
string Statistic::getStatistics() const
{
    return "Number of Clients: " + to_string(number_of_clients) +
        ", Number of Tours: " + to_string(number_of_tours) +
        ", Total Gain: $" + to_string(gain);
}
