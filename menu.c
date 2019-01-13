#include <winsock.h>
#include <MYSQL\mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "eventFunctions.c"
#include "dbQuery.c"
#include "protoQuery.h"

int main(int argc, char **argv)
{
    int choice;
    char station[100];
    char stationToFraud[80];
    int line, lineToFraud;
    char com[500];

    printf("1_ Signaler l'emplacement des controleurs\n");
    printf("2_ Afficher les emplacements des controleurs\n");
    printf("3_ Afficher les emplacements des controleurs en fonction des lignes\n");
    printf("4 Afficher les emplacements des controleurs en fonction des stations\n");
    printf("5_ Quitter l'application\n");
    scanf("%d", &choice);

    if( choice == 1 ){
        printf("Veuillez entrer le ligne de metro : \n");
        scanf("%d", &line);

        printf("Veuillez entrer la station : \n");
        fflush(stdin);
        fgets(station, 100, stdin);

        printf("Veuillez entrer le commentaire : \n");
        fflush(stdin);
        fgets(com, 100, stdin);

        if(strlen(station)<100){
            station[strlen(station)-1] = '\0';
        }
        if(strlen(com)<500){
            com[strlen(com)-1] = '\0';
        }

        insertAlert(line, station, com);

    }
    if( choice == 2){
        getAllAlerts();
    }
    if( choice == 3){
        printf("Choisir la ligne a  frauder : \n");
        scanf("%d", &lineToFraud);
        getAlertByLine(lineToFraud);
    }
    if( choice == 4){
        printf("Choisir la station a frauder ");
        fflush(stdin);
        fgets(stationToFraud, 80, stdin);

    if(strlen(stationToFraud)<80){
    stationToFraud[strlen(stationToFraud)-1] = '\0';
    }
     getAlertByStation(stationToFraud);
    return 0;
    }
}




