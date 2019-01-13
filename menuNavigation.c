#include "menuNavigation.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backToMenuEvent(GtkBuilder *builder){
    GtkNotebook *notebook = NULL;
    notebook = GTK_NOTEBOOK(gtk_builder_get_object (builder, "notebook"));
    gtk_notebook_set_current_page(notebook, 0);
}

void changePageToAlert(GtkBuilder *builder){
    GtkNotebook *notebook = NULL;
    notebook = GTK_NOTEBOOK(gtk_builder_get_object (builder, "notebook"));
    gtk_notebook_set_current_page(notebook, 1);
}

void changePageToPrintAlert(GtkBuilder *builder){
    GtkNotebook *notebook = NULL;
    notebook = GTK_NOTEBOOK(gtk_builder_get_object (builder, "notebook"));
    gtk_notebook_set_current_page(notebook, 2);
}

void changePageToAllAlerts(GtkBuilder *builder){
    GtkNotebook *notebook = NULL;
    notebook = GTK_NOTEBOOK(gtk_builder_get_object (builder, "notebook"));
    gtk_notebook_set_current_page(notebook, 3);
}

void changePageToLineToFraud(GtkBuilder *builder){
    GtkNotebook *notebook = NULL;
    notebook = GTK_NOTEBOOK(gtk_builder_get_object (builder, "notebook"));
    gtk_notebook_set_current_page(notebook,4);
}

void changePageToStationToFraud(GtkBuilder *builder){
    GtkNotebook *notebook = NULL;
    notebook = GTK_NOTEBOOK(gtk_builder_get_object (builder, "notebook"));
    gtk_notebook_set_current_page(notebook, 5);
}
