#ifndef MPU_H
#define MPU_H

// sensor library
#include "../lib/MPU6050/MPU6050.h"

MPU6050 mpu;


// Pitch, Roll and Yaw values
float pitch = 0;
float roll = 0;
float yaw = 0;

float yawRate = 0;

void initMPU();

float calcAccelValue(Vector acc){
  return sqrt(pow(acc.XAxis,2)+pow(acc.YAxis,2)+pow(acc.ZAxis,2));
}




#endif
