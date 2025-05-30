<<<<<<< HEAD
#include "SensorManager.h"

int main() {
    // Get the singleton instance of SensorManager
    SensorManager* manager = getSensorManagerInstance();

    // Set up database connection
    setupDatabaseConnection(manager);

    // Collect some sample sensor data
    collectSensorData(manager, 1, 23.5, "Temperature");
    collectSensorData(manager, 2, 45.2, "Humidity");
    collectSensorData(manager, 3, 1015.0, "Pressure");

    // Print collected sensor data
    printSensorData(manager);

    // Push data to the database
    if (pushDataToDatabase(manager)) {
        printf("Data successfully stored in the database.\n");
    }

    // Destroy the SensorManager instance
    destroySensorManagerInstance();

    return 0;
}

