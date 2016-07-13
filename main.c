#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#include "MQTTClient.h"
#include "sqlLogger.h"
#include "sensorMessage.h"

void testJson() {
    char* json = "{\"name\": \"testSensor\", \"sensorValues\": [{\"sensorType\":\"temp\", \"value\":12.4}, {\"sensorType\":\"humidity\", \"value\":70.0}]}";
    //char* json = "test";

    SensorMessage sensorMessage = getSensorMessageFromJson(json);
}

int main(int argc, char* argv[]) {
    testJson();
}
