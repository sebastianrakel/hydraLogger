#include <stdio.h>
#include <libpq-fe.h>
#include "sqlLogger.h"
#include "sensorMessage.h"

PGconn* getConnection() {
    return PQconnectdb("dbname=testdb");
}

void doExit(PGconn *conn, PGresult *result) {
    PQclear(result);
    PQfinish(conn);
}

int getServerVersion() {
    PGconn *conn = getConnection();

    if(PQstatus(conn) == CONNECTION_BAD) {

    }

    int ver = PQserverVersion(conn);
    doExit(conn, NULL);
    return ver;
}

void writeSensorLog(SensorMessage sensorMessage) {
    PGconn *conn = getConnection();

    const char *paramValues[1];

    paramValues[0] = sensorMessage.name;

    char *sqlString = "SELECT id " \
                      "FROM   sensor " \
                      "WHERE  sensor_name = $1";    

    PGresult *res = PQexecParams(conn, sqlString, 1, NULL, paramValues, NULL, NULL, 0);

    if(PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("No data retrieved\n");
        PQclear(res);
        doExit(conn, res);
    }


    int sensor_id;
    sensor_id = PQgetvalue(res, 0, 0);

    if(sensor_id == 0) {
        
    }
}
