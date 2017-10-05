#ifndef DUENIO_H_INCLUDED
#define DUENIO_H_INCLUDED

typedef struct {
    int idDuenio;
    int flag_ocupado;
    char nombre[50];
    char apellido[50];
    char direccion[50];
    char tc[50];




}sDuenio;

#endif // DUENIO_H_INCLUDED


#define INDICE_LIBRE 0
#define INDICE_OCUPADO 1

int due_InitLista(sDuenio  listaDuenios[], int limite);
int due_obtenerEspacioLibre(sDuenio  listaDuenios[],int limite);
int due_generar_Proximo_Id(sDuenio listaDuenios[], int len);



