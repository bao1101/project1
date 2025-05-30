
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sensor.h"

int main() {
    // Initialize random seed for sensor data variation
    srand(time(NULL));

    // Create sensors dynamically using the factory method
    Sensor* tempSensor = createSensor("Temperature");
    Sensor* humiditySensor = createSensor("Humidity");
    Sensor* pressureSensor = createSensor("Pressure");
    Sensor* lightSensor = createSensor("Light");

    // Check and use each sensor if successfully created
    if (tempSensor) tempSensor->readData();
    if (humiditySensor) humiditySensor->readData();
    if (pressureSensor) pressureSensor->readData();
    if (lightSensor) lightSensor->readData();

    // Free allocated memory for each sensor
    free(tempSensor);
    free(humiditySensor);
    free(pressureSensor);
    free(lightSensor);

    return 0;
}

