#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#include <MYSQL\mysql.h>

void giveAlert(GtkBuilder *builder){
    GtkComboBoxText *listLine = NULL;
    GtkComboBoxText *listStation = NULL;
    GtkEntry *commentary;
    listLine = GTK_COMBO_BOX_TEXT(gtk_builder_get_object (builder, "listLine"));
    listStation = GTK_COMBO_BOX_TEXT(gtk_builder_get_object (builder, "listStation"));
    commentary = GTK_ENTRY(gtk_builder_get_object (builder, "commentary"));
    int line = gtk_combo_box_get_active(listLine) + 1;
    char *station = gtk_combo_box_text_get_active_text(listStation);
    char *com = gtk_entry_get_text(commentary);

    insertAlert(line, station, com);
}

void printAlertByLine(GtkBuilder *builder){
    int num_fields;
    int i = 0;
    MYSQL_RES *alerts;
    MYSQL_ROW alertsRow;
    GtkComboBoxText *lineToFraud = NULL;
    lineToFraud = GTK_COMBO_BOX_TEXT(gtk_builder_get_object (builder, "lineToFraud"));
    int lineSelected = gtk_combo_box_get_active(lineToFraud) + 1;

    if(!getAlertByLine(lineSelected, &alerts) ){
        int num_fields = mysql_num_fields(alerts);
        while(alertsRow = mysql_fetch_row(alerts)){
            for(i=0; i<num_fields; i++){
                printf("%s ", alertsRow[i]);
            }
            printf("\n");
        }
    }else{
        printf("Fetching failed");
    }

    mysql_free_result(alerts);
}

void printAlertByStation(GtkBuilder *builder){
    int num_fields;
    int i = 0;
    char station[50];
    MYSQL_RES *alerts;
    MYSQL_ROW alertsRow;
    GtkComboBoxText *stationToFraud2 = NULL;
    stationToFraud2 = GTK_COMBO_BOX_TEXT(gtk_builder_get_object (builder, "stationToFraud2"));
    strcpy(station, gtk_combo_box_text_get_active_text(stationToFraud2));

    if(!getAlertByStation(station, &alerts) ){
        printf("\n%s ", station);
        int num_fields = mysql_num_fields(alerts);

        while((alertsRow = mysql_fetch_row(alerts))){
            for(i = 0; i<num_fields; i++){
                printf("%s ", alertsRow[i]);
            }
             printf("\n");
        }
    }else{
        printf("Fetching failed");
    }

    mysql_free_result(alerts);
}

void insertStationsInList(GtkBuilder *builder){
    MYSQL_RES *stations;
    MYSQL_ROW stationRow;
    GtkComboBoxText *listLine;
    listLine = GTK_COMBO_BOX_TEXT(gtk_builder_get_object (builder, "listLine"));
    GtkComboBoxText *listStation;
    listStation = GTK_COMBO_BOX_TEXT(gtk_builder_get_object (builder, "listStation"));

    int lineSelected = gtk_combo_box_get_active(listLine) + 1;
    gtk_combo_box_text_remove_all(listStation);


    if(!getStationsByLine(lineSelected, &stations)){
        while(stationRow = mysql_fetch_row(stations)){
            printf("\nRow : %s", stationRow[0]);
            gtk_combo_box_text_append_text(listStation, stationRow[0]);
        }
    }else{
        printf("Fetching stations failed");
    }
}

void insertStationsInList2(GtkBuilder *builder){
    MYSQL_RES *stations;
    MYSQL_ROW stationRow;
    GtkComboBoxText *lineToFraud2;
    lineToFraud2 = GTK_COMBO_BOX_TEXT(gtk_builder_get_object (builder, "lineToFraud2"));
    GtkComboBoxText *stationToFraud2;
    stationToFraud2 = GTK_COMBO_BOX_TEXT(gtk_builder_get_object (builder, "stationToFraud2"));

    int lineSelected = gtk_combo_box_get_active(lineToFraud2) + 1;
    gtk_combo_box_text_remove_all(stationToFraud2);

    if(!getStationsByLine(lineSelected, &stations)){
        while(stationRow = mysql_fetch_row(stations)){
            printf("\nRow : %s", stationRow[0]);
            gtk_combo_box_text_append_text(stationToFraud2, stationRow[0]);
        }
    }else{
        printf("Fetching stations failed");
    }
}



