#ifndef SENSOR_H
#define SENSOR_H

typedef struct {
    void (*readData)(void); 
} Sensor;


Sensor* createSensor(const char* sensorType);

#endif 