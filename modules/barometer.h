#ifndef BAROMETER_H
#define BAROMETER_H

// sensor library
#include "../lib/BMP180/src/SFE_BMP180.h"


SFE_BMP180 pressure;

double baseline; // baseline pressure
// for exponential pressure smoothing
float alpha = 0.3;

void initBarometer();

double getPressure();

float calcBaroVertSpd(float alt);

// implements exponential smoothing for the altitude
float smoothAltitudeExp(float a);

#endif
