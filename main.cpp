#include <iostream>
#include "Time.h"
#include "movie.h"
//#include "addon.h"
#include "minutes.h"

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
TimeSlot afternoon = {movie2, {11, 11}};

std::string s = getTimeSlot(morning);
std::cout << s << "\n";
TimeSlot after = scheduleAfter(morning,movie2);
std::string ss = getTimeSlot(after);
std::cout << ss << "\n";

bool test4 = timeOverlap(morning, afternoon); 
if(test4) {
    std::cout << "true\n";
} else {
    std::cout << "false\n";
}
return 0;
}