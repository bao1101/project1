#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sensor.h"


void readTemperature() {
    float temperature = (rand() % 300) / 10.0; 
    printf("Temperature Sensor: %.1f°C\n", temperature);
}


void readHumidity() {
    float humidity = (rand() % 101); 
    printf("Humidity Sensor: %.0f%%\n", humidity);
}


void readPressure() {
    float pressure = 900 + (rand() % 200); 
    printf("Pressure Sensor: %.1f hPa\n", pressure);
}


void readLight() {
    int light = rand() % 10000; 
    printf("Light Sensor: %d lux\n", light);
}

Sensor* createSensor(const char* sensorType) {
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));

    if (strcmp(sensorType, "Temperature") == 0) {
        sensor->readData = readTemperature;
    } else if (strcmp(sensorType, "Humidity") == 0) {
        sensor->readData = readHumidity;
    } else if (strcmp(sensorType, "Pressure") == 0) {
        sensor->readData = readPressure;
    } else if (strcmp(sensorType, "Light") == 0) {
        sensor->readData = readLight;
    } else {
        free(sensor);
        return NULL;
    }

    return sensor;
}