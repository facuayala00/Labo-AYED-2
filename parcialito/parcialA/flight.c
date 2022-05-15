/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include <stdlib.h>
#include "flight.h"

static const int AMOUNT_OF_FLIGHT_VARS = 3 ;

Flight flight_from_file(FILE* file, char code)
{
    Flight flight;
    flight.code = code;

    flight_t type;
    unsigned int hour;
    unsigned int passengers_amount;

    int res = fscanf(file, " %u %u %u ", &type, &hour, &passengers_amount);
    if (res != AMOUNT_OF_FLIGHT_VARS){
      fprintf(stderr, "Invalid array.\n");
      exit(EXIT_FAILURE);
    }
    flight.type = type;
    flight.hour = hour;
    flight.passengers_amount = passengers_amount;

    return flight;
}
