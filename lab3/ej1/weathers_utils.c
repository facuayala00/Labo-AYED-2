#include <stdio.h>
#include <stdlib.h>
#include "weathers_utils.h"
#include "array_helpers.h"
#include "weather.h"


int min_historica(WeatherTable array){
    int temp_min = 99999;
    for(unsigned int year = 0u ; year < YEARS; ++year){
        for(month_t month = january; month <= december; ++month){
            for(unsigned int day = 0u ; day < DAYS; ++day){
                if(array[year][month][day]._min_temp < temp_min){
                    temp_min = array[year][month][day]._min_temp;
                }
            }
        }
    }
    return temp_min;
}


void max_anual(WeatherTable array){
    int temperature[YEARS], t_maxima = -99999;
    for(unsigned int year=0u; year<YEARS; ++year){
        t_maxima = -99999;
        for(month_t month=january; month <= december; ++month){
            for(unsigned int day = 0u; day < DAYS; ++day){
                if (array[year][month][day]._max_temp > t_maxima){
                    temperature[year] = array[year][month][day]._max_temp;
                    t_maxima = array[year][month][day]._max_temp;
                }
            }
        }
    }
    for(unsigned int year = 0u; year < YEARS; ++year) {
        printf("La mayor tempertura maxima de %d fue de %d grados\n", year+1980 ,temperature[year]);
    }
}


void max_month_rain(WeatherTable array, month_t output[YEARS]){
    for(unsigned int year = 0u; year < YEARS; ++year) {
        unsigned int max_rainfall;
        output[year] = january;
        for(month_t month=january; month <= december; ++month){
            unsigned int sum_rainfall = 0;
            for(unsigned int day=0u; day < DAYS; ++day){
                sum_rainfall += array[year][month][day]._rainfall;
            }
            if(month == january){
                max_rainfall = sum_rainfall;
            }else if(max_rainfall < sum_rainfall){
                max_rainfall = sum_rainfall;
                output[year] = month;
            }
        }
    }
    for(unsigned int year = 0u; year < YEARS; ++year) {
        printf("El mes con mayor precipitaciones de %d fue %d\n", year+1980, output[year] + 1);
    }
}
