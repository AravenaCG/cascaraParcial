#ifndef AUTOMOVIL_H_INCLUDED
#define AUTOMOVIL_H_INCLUDED

typedef struct {
    int idAutomovil;
    int flag_ocupado;
    char patente[50];
    int marca;
    int horario;
    int idDuenio_Relacionable;



}sAutomovil;

#endif // AUTOMOVIL_H_INCLUDED

#define ALPHA_ROMEO 1
#define FERRARI 2
#define BMW 3
#define OTRO 4

#define INDICE_LIBRE 0
#define INDICE_OCUPADO 1


int auto_InitLista(sAutomovil  listaAutomoviles[], int limite);
int auto_obtenerEspacioLibre(sAutomovil  listaAutomoviles[],int limite);
int auto_generar_Proximo_Id(sAutomovil listaAutomoviles[], int len);
