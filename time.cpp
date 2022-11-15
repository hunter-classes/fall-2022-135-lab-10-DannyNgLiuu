#include <iostream>
#pragma once
#include "Time.h"

int minutesSinceMidnight(Time time) {
    int minutes;
    minutes = time.h * 60 + time.m;
    return minutes;
}

int minutesUntil(Time earlier, Time later) {
    int hour = later.h - earlier.h;
    int min = later.m - earlier.m;
    return hour * 60 + min;
}

Time addMinutes(Time time0, int min) {
    int newHour = time0.h;
    int newMin;
    if((time0.m + min) % 60 != 0) {
        newHour += (time0.m + min) / 60;
        newMin = time0.m + min % 60;
    } else {
        newHour += time0.m + min % 60;
    }
    Time newTime = {newHour, newMin};
    return newTime;
}

