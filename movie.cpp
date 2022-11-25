#include <iostream>
#include "movie.h"
#include "minutes.h"
#include "Time.h"
#include <string>

std::string getTimeSlot(TimeSlot ts) {
    Time oldTime = {ts.startTime.h, ts.startTime.m};
    Time newTime = addMinutes(oldTime, ts.movie.duration);
    std::string text;
    std::string g;
    switch (ts.movie.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    text += ts.movie.title;
    text += " ";
    text += g;
    text += " (" + std::to_string(ts.movie.duration);
    text += " min)";
    text += " [starts at " + std::to_string(ts.startTime.h);
    text += ":" + std::to_string(ts.startTime.m);
    text += ", ends by " + std::to_string(newTime.h);
    text += ":" + std::to_string(newTime.m % 60);
    text += "]\n";
    return text;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    Time oldTime = {ts.startTime.h, ts.startTime.m};
    Time newTime = addMinutes(oldTime, ts.movie.duration);
    TimeSlot after = {nextMovie, {newTime.h, newTime.m % 60}};
    return after;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    Time movie1 = {ts1.startTime.h, ts1.startTime.m};
    Time movie2 = {ts2.startTime.h, ts2.startTime.m};
    int min = minutesUntil(movie1, movie2);
    if(ts1.movie.duration <= min) {
        return false;
    } else {
        return true;
    }
    return true;
}