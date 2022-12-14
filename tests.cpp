#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "minutes.h"
#include "doctest.h"
#include "movie.h"

TEST_CASE("Task A"){
    CHECK(minutesSinceMidnight( {10, 0} ) == 600);
    CHECK(minutesUntil( {10, 30}, {13, 40} ) == 190);
}

TEST_CASE("Task B"){
    Time before = addMinutes({8, 10}, 75);
    Time after = {9, 25};
    
    CHECK((before.h == after.h && before.m == after.m));
}

TEST_CASE("Task C"){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}};
    
    CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]");
    CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]");
    CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]");
}

TEST_CASE("Task D"){
    Movie movie = {"Back to the Future", COMEDY, 116};
    
    TimeSlot first = {movie, {9, 15}};  
    TimeSlot after = scheduleAfter(first, movie);

    Time end = addMinutes(first.startTime, first.movie.duration);

    CHECK((after.startTime.h == end.h && after.startTime.m == end.m));

}

TEST_CASE("Task E"){
    Movie movie1 = {"Back to the Future", COMEDY, 120};
    Movie movie2 = {"Black Panther", ACTION, 134};

    TimeSlot timeslot1 = {movie1, {9, 15}};  
    TimeSlot timeslot2 = {movie2, {11, 15}}; 
    TimeSlot timeslot3 = {movie2, {12, 15}};
    TimeSlot timeslot4 = {movie2, {14, 55}};
    
    CHECK(timeOverlap(timeslot1, timeslot2) == false);
    CHECK(timeOverlap(timeslot2, timeslot3) == true);
    CHECK(timeOverlap(timeslot3, timeslot4) == false);
}
