#include "SensorManager.h"
#include <stdlib.h>
#include <string.h>

// Static variable to store the single instance of SensorManager
static SensorManager* instance = NULL;

// Function to get the single instance of SensorManager (Singleton Pattern)
SensorManager* getSensorManagerInstance() {
    if (instance == NULL) {
        instance = (SensorManager*)malloc(sizeof(SensorManager));
        instance->dataCount = 0;
        instance->isDbConnected = false;
        printf("SensorManager instance created.\n");
    }
    return instance;
}

// Function to collect sensor data
void collectSensorData(SensorManager* manager, int sensorId, float value, const char* sensorType) {
    if (manager->dataCount < MAX_SENSOR_NODES) {
        SensorNode* node = &manager->sensorNodes[manager->dataCount];
        node->id = sensorId;
        strncpy(node->sensorType, sensorType, MAX_SENSOR_TYPE - 1);
        node->sensorType[MAX_SENSOR_TYPE - 1] = '\0';
        node->value = value;
        manager->dataCount++;
        printf("Data collected: ID=%d, Type=%s, Value=%.2f\n", sensorId, sensorType, value);
    } else {
        printf("Memory full, cannot collect more data.\n");
    }
}

// Function to push sensor data to the database
bool pushDataToDatabase(SensorManager* manager) {
    if (manager->isDbConnected) {
        printf("Pushing data to the database...\n");
        return true;
    } else {
        printf("Cannot push data, database not connected.\n");
        return false;
    }
}

// Function to set up database connection
void setupDatabaseConnection(SensorManager* manager) {
    manager->isDbConnected = true;
    printf("Database connection established.\n");
}

// Function to print collected sensor data
void printSensorData(const SensorManager* manager) {
    if (manager->dataCount == 0) {
        printf("No sensor data available.\n");
        return;
    }

    printf("Sensor data list:\n");
    for (size_t i = 0; i < manager->dataCount; i++) {
        printf("ID: %d, Type: %s, Value: %.2f\n",
               manager->sensorNodes[i].id,
               manager->sensorNodes[i].sensorType,
               manager->sensorNodes[i].value);
    }
}

// Function to free memory when no longer needed
void destroySensorManagerInstance() {
    if (instance != NULL) {
        free(instance);
        instance = NULL;
        printf("SensorManager instance destroyed.\n");
    }
}