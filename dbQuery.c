#include <winsock.h>
#include <MYSQL\mysql.h>
#include "protoQuery.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DB_CONNECTION_ERROR 1
#define DB_QUERY_ERROR 2

 int printStationsByLine(int line){
     MYSQL *con = mysql_init(NULL);
    char query[800];
    sprintf(query, "SELECT ligne, stations FROM stationmetro WHERE ligne='%d' ", line);
    int i = 0;

        if (mysql_real_connect(con, "localhost", "root", "", "fraudItSafe", 0, NULL, 0) == NULL){
            mysql_close(con);
            return 1;
            }

    if (mysql_query(con, query)){
            mysql_close(con);
            return 1;
            }

    MYSQL_RES *result = mysql_store_result(con);


    if (result == NULL){
            mysql_close(con);
            return 1;
            }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ( (row = mysql_fetch_row(result)) ){
            for(i = 0; i < num_fields; i++){
                printf("%s ", row[i]);
            }
            printf("\n");
            }

  mysql_free_result(result);
  mysql_close(con);

  return 0;
}

int printLinesByStation(int **station){
    MYSQL *con = mysql_init(NULL);
    char query[800];
    sprintf(query, "SELECT ligne FROM stationmetro WHERE ligne='%s' ", station);
    int i = 0;

    if (mysql_real_connect(con, "localhost", "root", "", "fraudItSafe", 0, NULL, 0) == NULL){
        mysql_close(con);
        return 1;
        }

    if (mysql_query(con, query)){
            mysql_close(con);
            return 1;
            }

    MYSQL_RES *result = mysql_store_result(con);


    if (result == NULL){
            mysql_close(con);
            return 1;
            }

    int num_fields = mysql_num_fields(result);
    MYSQL_ROW row;

    while ( (row = mysql_fetch_row(result)) ){
            for(i = 0; i < num_fields; i++){
                printf("%s ", row[i]);
            }
            printf("\n");
            }

  mysql_free_result(result);
  mysql_close(con);

  return 0;
}

 int getAllAlerts(){
    MYSQL *con = mysql_init(NULL);
      if (mysql_real_connect(con, "localhost", "root", "",
          "fraudItSafe", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
            mysql_close(con);
            return 1;
  }

  if (mysql_query(con, "SELECT ligne, station, commentaire FROM alert"))
  {
            mysql_close(con);
            return 1;;
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL){
            mysql_close(con);
            return 1;
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result))){
      for(int i = 0; i < num_fields; i++){
          printf("%s ", row[i]);
      }
          printf("\n");
  }

  mysql_free_result(result);
  mysql_close(con);

  return 0;
}

int insertAlert(int line, char **station, char **com){

    MYSQL *con = mysql_init(NULL);
    char query[800];
    sprintf(query, "INSERT INTO alert(ligne, station, commentaire) values(%d, \'%s\', \'%s\')", line, station, com);

     if (mysql_real_connect(con, "localhost", "root", "", "fraudItSafe", 0, NULL, 0) == NULL){
                mysql_close(con);
                return 1;
          }

    if(mysql_query(con, query)){
            mysql_close(con);
            return 1;
    }

    mysql_close(con);
    return 0;

}

int getStationsByLine(int line, MYSQL_RES** result){

    MYSQL *con = mysql_init(NULL);
    char query[712];
    sprintf(query, "SELECT stations FROM stationsmetro WHERE ligne='%d' ", line);

    if (mysql_real_connect(con, "localhost", "root", "", "fraudItSafe", 0, NULL, 0) == NULL){
        mysql_close(con);
        return DB_CONNECTION_ERROR;
    }

    if (mysql_query(con, query)){
        mysql_close(con);
        return DB_QUERY_ERROR;
    }
    printf("Returning results");
    *result = mysql_store_result(con);
    mysql_close(con);
    return 0;
}



int getAlertByLine(int lineToFraud, MYSQL_RES** result){

    MYSQL *con = mysql_init(NULL);
    char query[500];
    sprintf(query, "SELECT ligne, station, commentaire FROM alert WHERE ligne=%d", lineToFraud);

    if (mysql_real_connect(con, "localhost", "root", "", "fraudItSafe", 0, NULL, 0) == NULL){
            mysql_close(con);
            return DB_CONNECTION_ERROR;
            }

    if (mysql_query(con, query)){
            mysql_close(con);
            return DB_QUERY_ERROR;
            }

    printf("Return results");
    *result = mysql_store_result(con);
    mysql_close(con);
    return 0;
}

int getAlertByStation(char *station, MYSQL_RES** result){
    MYSQL *con = mysql_init(NULL);
    char query[712];
    sprintf(query, "SELECT ligne, station, commentaire FROM alert WHERE ligne='%s'", station);

    if (mysql_real_connect(con, "localhost", "root", "", "fraudItSafe", 0, NULL, 0) == NULL){
            mysql_close(con);
            return DB_CONNECTION_ERROR;
            }

    if (mysql_query(con, query)){
            mysql_close(con);
            return DB_QUERY_ERROR;
            }

  printf("\nReturn results");
  *result = mysql_store_result(con);
  mysql_close(con);

  return (0);
 }
