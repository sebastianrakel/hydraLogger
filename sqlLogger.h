//
// Created by sebastian on 5/31/16.
//

#ifndef HYDRALOGGER_SQLLOGGER_H
#define HYDRALOGGER_SQLLOGGER_H

#include <libpq-fe.h>
#include "sensorMessage.h"

int getServerVersion();
void writeSensorLog(SensorMessage sensorMessage);

#endif //HYDRALOGGER_SQLLOGGER_H

