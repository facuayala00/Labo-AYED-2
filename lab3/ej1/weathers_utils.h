#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include <stdlib.h>
#include <stdio.h>
#include "weather.h"
#include "array_helpers.h"

int min_historica(WeatherTable array);

void max_anual(WeatherTable array);

void max_month_rain(WeatherTable array,  month_t output[YEARS]);

#endif

