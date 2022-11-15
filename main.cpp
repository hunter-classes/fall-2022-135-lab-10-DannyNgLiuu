#include <iostream>
#include "Time.h"
#include "movie.h"
int main() {

Time time1 = {13, 40};
Time time2 = {10, 30};
Time time3 = {8, 10};
int test1 = minutesSinceMidnight(time1);
std::cout << test1 << '\n';
int test2 = minutesUntil(time2, time1);
std::cout << test2 << "\n";
Time test3 = addMinutes(time3, 75);
std::cout << test3.h << " " << test3.m << "\n";

Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};

TimeSlot morning = {movie1, {9, 15}}; 

getTimeSlot(morning);
return 0;
}