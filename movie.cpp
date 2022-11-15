#include <iostream>
#include "movie.h"
#include "Time.h"
#include <string>

std::string getTimeSlot(TimeSlot ts) {
    Time oldTime = {ts.startTime.h, ts.startTime.m};
    Time newTime = addMinutes(oldTime, ts.movie.duration);
    std::string text;
    text += ts.movie.title + " ";
    text += ts.movie.genre;
    text += " (" + std::to_string(ts.movie.duration);
    text += " min)";
    text += " [starts at " + std::to_string(ts.startTime.h);
    text += ":" + std::to_string(ts.startTime.m);
    text += ", ends by " + std::to_string(newTime.h);
    text += ":" + std::to_string(newTime.m);
    text += "] \n";
    return text;
}