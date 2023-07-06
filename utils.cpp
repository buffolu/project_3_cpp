#include "utils.h"
#include <iostream>
#include <sstream>
#include <chrono>

std::vector<std::string>
utils::split(const std::string& str, char delim)
{
	std::stringstream ss(str);
	std::vector<std::string> res;
	std::string token;
	while (std::getline(ss, token, delim)) {
		res.push_back(token);
	}
	return res;
}

/**
int
utils::calculateMinutesBetweenDates(const std::string& date1, const std::string& date2) {
	std::istringstream stream1(date1);
	std::istringstream stream2(date2);

	int day1, month1, hour1, minute1;
	char delimiter1, delimiter2;
	stream1 >> day1 >> delimiter1 >> month1 >> hour1 >> delimiter2 >> minute1;

	int day2, month2, hour2, minute2;
	stream2 >> day2 >> delimiter1 >> month2 >> hour2 >> delimiter2 >> minute2;

	// Create time_point objects for each date
	std::tm time1 = {0, minute1, hour1, day1, month1 - 1, 2023 - 1900, 0, 0, 0};
	std::tm time2 = {0, minute2, hour2, day2, month2 - 1, 2023 - 1900, 0, 0, 0};

	// Convert time_point objects to durations
	std::chrono::system_clock::time_point tp1 = std::chrono::system_clock::from_time_t(std::mktime(&time1));
	std::chrono::system_clock::time_point tp2 = std::chrono::system_clock::from_time_t(std::mktime(&time2));
	// Calculate duration between the two time points
	std::chrono::minutes duration = std::chrono::duration_cast<std::chrono::minutes>(tp2 - tp1);

	// Return the total number of minutes
	return duration.count();
}
*/
