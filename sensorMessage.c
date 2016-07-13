//
// Created by sebastian on 5/31/16.
//
#include "sensorMessage.h"
#include <jansson.h>
#include <string.h>

SensorMessage getSensorMessageFromJson(char* jsonMessage) {
    json_t *root;
    json_error_t error;

    root = json_loads(jsonMessage, 0, &error);

    char* sensorName = (char*)json_string_value(json_object_get(root, "name"));

    json_t *sensorValuesData = json_object_get(root, "sensorValues");
    int sensorValuesCount = (int)json_array_size(sensorValuesData);

    SensorMessage sensorMessage;
    sensorMessage.name = malloc(strnlen(sensorName, 255) * sizeof(char) + 1);
    strncpy(sensorMessage.name, sensorName, 255);

    sensorMessage.sensorValues = malloc(sensorValuesCount * sizeof(SensorValue));

    int i;
    for(i = 0; i < sensorValuesCount; i++) {
        json_t *sensorValueJson = json_array_get(sensorValuesData, i);

        char *sensorType = (char *) json_string_value(json_object_get(sensorValueJson, "sensorType"));

        if(strcmp(sensorType, "temp")) {
            sensorMessage.sensorValues[i].sensorType = TEMP;
        } else if (strcmp(sensorType, "humidity")) {
            sensorMessage.sensorValues[i].sensorType = HUMIDITY;
        } else {
            sensorMessage.sensorValues[i].sensorType = UNKNOWN;
        }

        sensorMessage.sensorValues[i].value = json_real_value(json_object_get(sensorValueJson, "value"));
    }
    
    json_decref(root);

    printf("%d\n", sensorValuesCount);
    printf("With struct: %d\n", sensorMessage.sensorValues);   
    
    
    return sensorMessage;    
}
