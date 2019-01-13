#include <winsock.h>
#include <MYSQL\mysql.h>

int insertAlert(int line, char **station, char **com);
int getAllAlerts();
int getAlertByLine(int lineToFraud, MYSQL_RES** result);
int getAlertByStation(char *station, MYSQL_RES** result);
int printStationsByLine(int line);
int printLinesByStation(int **station);
int getStationsByLine(int line, MYSQL_RES** result);

