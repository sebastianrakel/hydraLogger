//
// Created by sebastian on 5/31/16.
//

#ifndef HYDRALOGGER_SENSORMESSAGE_H
#define HYDRALOGGER_SENSORMESSAGE_H

enum SensorType {UNKNOWN=0, HUMIDITY=1, TEMP=2};

typedef struct SensorValue {
    enum SensorType sensorType;
    double value;
} SensorValue;

typedef struct SensorMessage {
    char* name;
    SensorValue* sensorValues;
} SensorMessage;

SensorMessage getSensorMessageFromJson(char* jsonMessage);

#endif //HYDRALOGGER_SENSORMESSAGE_H
