#include "gps.h"

GPS::GPS(){
	gpsResult = "";
	lastGPSData = "no_lat no_lng no_alt no_v_spd no_spd";
	gpsSerial = new SoftwareSerial(RXPin, TXPin);
}

void GPS::getGPSData(){
  if (gpsSerial->available() > 0){
    // Get information every time a new sentence is correctly encoded.
    Serial.println("gps received");
    while (gpsSerial->available() > 0){
      if (gps.encode(gpsSerial->read())){
        parseGPSInfo();
      }
    }
  }
}


void GPS::parseGPSInfo(){
  lastGPSData = "";
  // parse location data
//  if (gps.location.isValid()){
      lastGPSData.concat(String(gps.location.lat(), 6));
      lastGPSData.concat(' ');
      lastGPSData.concat(String(gps.location.lng(), 6));
//  } else {
//    gpsResult.concat(noPosMsg);
//  }
  // parse altitude and calculate the vertical speed
  lastGPSData += ' ';
//  if (gps.altitude.isValid()){
      float alt = gps.altitude.meters();
      lastGPSData += String(alt,6);
      lastGPSData += ' ';
      lastGPSData += String(calcGPSVertSpd(alt),6);
//  } else {
//    gpsResult += noAltMsg;
//  }

   //get the speed
    lastGPSData.concat(' ');
//    if (gps.speed.isValid()){
      lastGPSData.concat(String(gps.speed.kmph(),6));
//    } else {
//      gpsResult.concat(noSpdMsg);
//    }
//  lastGPSData = gpsResult;
}


double last_gps_alt = 0;
unsigned long lastVSpdTake;

double GPS::calcGPSVertSpd(double alt){
  unsigned long currTime = micros();
  double result = 1000000*(alt - last_gps_alt)/(currTime - lastVSpdTake);
  lastVSpdTake = currTime;
  last_gps_alt = alt;
  return result;
}

void GPS::init(){
	gpsSerial->begin(GPSBaud);
}
