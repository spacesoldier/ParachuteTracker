#include "mpu.h"

void initMPU(){
  // Initialize MPU6050
  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_8G)){
    logData("MPU6050 not found. Wiring?");
    delay(500);
  }

  // Calibrate gyroscope. The calibration must be at rest.
  mpu.calibrateGyro();
  // Set threshold sensivty. Default 3.
  mpu.setThreshold(3);
}

