#ifndef ESTACIONAMIENTO_H_INCLUDED
#define ESTACIONAMIENTO_H_INCLUDED



#endif // ESTACIONAMIENTO_H_INCLUDED

int due_AgregarDuenio(sDuenio listaDuenios[], int index, int limite);
int due_PrintDuenios(sDuenio listaDuenios[], int limite);
int due_Borrar(sDuenio listaDuenios[], int idABorrar,int limite);
int due_buscarIndexPorId(sDuenio listaDuenios[],int len, int id);
int due_modificar(sDuenio listaDuenios[], int len, int id );
int auto_BuscarChar(sAutomovil listaAutomoviles[],int len, char texto[]);
int auto_AgregarAuto(sAutomovil listaAutomoviles[], sDuenio listaDuenios[],int index, int limite);
int auto_PrintAutos(sAutomovil listaAutomoviles[], int limite);
int auto_Borrar(sAutomovil listaAutomoviles[], int id,int limite);
int auto_ContarbyMarca(sAutomovil listaAutomoviles[], int *contador1, int *contador2, int *contador3, int *contador4 ,int limite);
void auto_graficoBarras(int cont18,int cont19a35,int cont35);
void auto_ordenar_x_Hora(sAutomovil listaAutomoviles[],int limite);
int auto_BuscarChar(sAutomovil listaAutomoviles[],int len, char texto[]);
