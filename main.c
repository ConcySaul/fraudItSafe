#include <winsock.h>
#include <MYSQL\mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "eventFunctions.c"
#include "dbQuery.c"
#include "header.h"
#include "menuNavigation.h"
#include "protoQuery.h"

 int main(int argc, char *argv []){


      GtkWidget *mainWindow = NULL;
      GtkButton *exitMenu = NULL;
      GtkButton *sendAlert = NULL;
      GtkButton *printAlert = NULL;
      GtkButton *printAllAlert = NULL;
      GtkButton *printAlertsByLine = NULL;
      GtkButton *printAlertsByStation = NULL;
      GtkButton *backToMenu = NULL;
      GtkButton *backToMenu2 = NULL;
      GtkButton *printAllAlertsBtn = NULL;
      GtkButton *sendAlertButton = NULL;
      GtkButton *lineToFraudBtn = NULL;
      GtkButton *stationToFraudBtn = NULL;
      GtkButton *validateStn = NULL;
      GtkBuilder *builder = NULL;
      GtkComboBoxText *listLine = NULL;
      GError *error = NULL;
      gchar *filename = NULL;

      gtk_init(&argc, &argv);

      builder = gtk_builder_new();
      filename =  g_build_filename ("fraudisafeInterface.glade", NULL);

      /* Chargement du fichier */
      gtk_builder_add_from_file (builder, filename, &error);
      g_free (filename);

        /* on recupere les composants de l'interface */
      mainWindow = GTK_WIDGET(gtk_builder_get_object (builder, "mainWindow"));
      exitMenu = GTK_BUTTON(gtk_builder_get_object (builder, "exitMenu"));
      sendAlert = GTK_BUTTON(gtk_builder_get_object (builder, "sendAlert"));
      printAlert = GTK_BUTTON(gtk_builder_get_object (builder, "printAlert"));
      printAllAlert = GTK_BUTTON(gtk_builder_get_object (builder, "printAllAlert"));
      printAlertsByLine = GTK_BUTTON(gtk_builder_get_object (builder, "printAlertsByLine"));
      printAlertsByStation = GTK_BUTTON(gtk_builder_get_object (builder, "printAlertsByStation"));
      backToMenu = GTK_BUTTON(gtk_builder_get_object (builder, "backToMenu"));
      backToMenu2 = GTK_BUTTON(gtk_builder_get_object (builder, "backToMenu2"));
      printAllAlertsBtn = GTK_BUTTON(gtk_builder_get_object (builder, "printAllAlertsBtn"));
      sendAlertButton = GTK_BUTTON(gtk_builder_get_object (builder, "sendAlertButton"));
      lineToFraudBtn = GTK_BUTTON(gtk_builder_get_object (builder, "lineToFraudBtn"));
      stationToFraudBtn = GTK_BUTTON(gtk_builder_get_object (builder, "stationToFraudBtn"));
      validateStn = GTK_BUTTON(gtk_builder_get_object (builder, "validateStn"));
      listLine = GTK_COMBO_BOX_TEXT(gtk_builder_get_object (builder, "listLine"));


      /* Affectation des signaux aux boutons*/
      g_signal_connect_swapped (G_OBJECT (mainWindow), "destroy", (GCallback)gtk_main_quit, NULL);
      g_signal_connect_swapped (G_OBJECT (exitMenu), "clicked", (GCallback)gtk_main_quit, NULL);
      g_signal_connect_swapped (G_OBJECT (sendAlert), "clicked", (GCallback)changePageToAlert, builder);
      g_signal_connect_swapped (G_OBJECT (printAlert), "clicked", (GCallback)changePageToPrintAlert, builder);
      g_signal_connect_swapped (G_OBJECT (backToMenu), "clicked", (GCallback)backToMenuEvent, builder);
      g_signal_connect_swapped (G_OBJECT (backToMenu2), "clicked", (GCallback)backToMenuEvent, builder);
      g_signal_connect_swapped (G_OBJECT (printAllAlertsBtn), "clicked", (GCallback)changePageToAllAlerts, builder);
      g_signal_connect_swapped (G_OBJECT (sendAlertButton), "clicked", (GCallback)giveAlert, builder);
      g_signal_connect_swapped (G_OBJECT (printAlertsByLine), "clicked", (GCallback)changePageToLineToFraud, builder);
      g_signal_connect_swapped (G_OBJECT (printAlertsByStation), "clicked", (GCallback)changePageToStationToFraud, builder);
      g_signal_connect_swapped (G_OBJECT (lineToFraudBtn), "clicked", (GCallback)printAlertByLine, builder);
      g_signal_connect_swapped (G_OBJECT (stationToFraudBtn), "clicked", (GCallback)printAlertByStation, builder);
      g_signal_connect_swapped (G_OBJECT (validateStn), "clicked", (GCallback)insertStationsInList2, builder);
      g_signal_connect_swapped (G_OBJECT (listLine), "changed", (GCallback)insertStationsInList, builder);

      /* Affichage de la fenêtre principale. */
      gtk_widget_show_all (mainWindow);
      gtk_main();

      return 0;
    }
