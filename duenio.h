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


/**informes imprimir todo(sEntidad1* array, SEntidad2* array, int lenEntidad1,int lenEntidad2)
{
    int indexE2;
    for (indexE2=0;indexE2<lenEntidad2;indexE2++)
    {
        if (arrayEntidad2[indexE2].flag_ocupado == ENTIDAD2_OCUPADO)
        {
            int idE1 = arrayEntidad2[indexE2].idEntidad1;
            int indexE1= enti1_buscarIndicePorId(arrayEntidad1,lenEntidad1,idE1);

            printf("%d\t%s |
                   %d\t%s , arrayEntidad1[indexE1].id,arrayEntidad1[indexE1].a.arrayEntidad2[indexE2].id")
        }
    }

}
