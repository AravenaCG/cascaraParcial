#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "duenio.h"
#include "automovil.h"
#include "validar.h"
#include "estacionamiento.h"


/** \brief busca un texto en la lista
 * @param  listaDuenios el array donde busca
 * @param  len cantidad de elementos en el array
 * @return retorno :posicion donde se encontro o -1 si no se encontro
 *
 */
int due_BuscarChar(sDuenio listaDuenios[],int len, char texto[])
{
    int i;
    int retorno =-1;
    for (i=0; i<len; i++)
    {
        if (listaDuenios[i].flag_ocupado == 1 )
        {
            if (strcmp(listaDuenios[i].nombre, texto) == 0)
            {
                retorno = i;
                break;

            }
        }
    }
    return retorno;
}

/** \brief busca un id en la lista
 * @param  listaDuenios el array donde busca
 * @param  len cantidad de elementos en el array
 * @return retorno :posicion donde se encontro o -1 si no se encontro
 *
 */
int due_buscarIndexPorId(sDuenio listaDuenios[],int len,int id)
{
    int i;
    int retorno=-1;
    if (listaDuenios != NULL && len >0 && id >0 )
    {
        for (i=0; i<len; i++)
        {
            if (listaDuenios[i].flag_ocupado == INDICE_OCUPADO)
            {


                if (id == listaDuenios[i].idDuenio)
                {
                    retorno=i;
                    break;

                }
            }
        }
    }
    return retorno;
}


/** \brief modifica un elemento del array
 *
 * @param  index el indice en el array, es decir la posicion.
 * @param  len cantidad de elementos en el array
 * @param  id elementos a modificar en el array
 * @return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */
int due_modificar(sDuenio listaDuenios[], int len, int id )
{
    char bufferAuxiliar[50];
    int retorno=-1;
    int index = due_buscarIndexPorId(listaDuenios,len, id);
    if (index >=0 )
    {

        if (val_getUnsignedInt(bufferAuxiliar,"ingrese nueva TC:","TCinvalida",3,50)==0)
        {
            strcpy(listaDuenios[index].tc,bufferAuxiliar);
            retorno=0;
        }
    }
    return retorno;
}




/** \brief Agrega persona a la lista
 *
 * @param  index el indice en el array, es decir la posicion.
 * @param  limite cantidad de elementos en el array
 * @return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int due_AgregarDuenio(sDuenio listaDuenios[], int index, int limite)
{

    int retorno = -1;
    char bNombre[50];
    char bApellido[50];
    char bDireccion[50];
    char bTarjeta[50];


    if(listaDuenios != NULL && index >= 0 && index <limite)
    {
        if(val_getNombre(bNombre,"\nNOMBRE?\n","\nError:\n",3,50)==0 && val_getNombre(bApellido,"\nApellido?:\n","\nError!\n",3,50) == 0)
        {
            if  (val_getAlfanumerico(bDireccion,"\nDireccion?:\n","\nError:\n",3,50)==0 )
            {
                if(  getStringNumeros("\nIngrese el Nro de TC:\n", bTarjeta)==0)
                {
                    strncpy(listaDuenios[index].nombre,bNombre,50);
                    strncpy(listaDuenios[index].apellido,bApellido,50);
                    strncpy(listaDuenios[index].direccion,bDireccion,50);
                    strncpy(listaDuenios[index].tc,bTarjeta,50);
                    listaDuenios[index].idDuenio = due_generar_Proximo_Id(listaDuenios,limite);
                    listaDuenios[index].flag_ocupado = INDICE_OCUPADO;
                    //val_getUnsignedInt(bufferEdad, "\ningrese Edad:\n","\nNo Valida\n",3,4);
                    //edad_a_Validar = atoi(bufferEdad);
                    //val_validarEdad(&nuevaEdad, edad_a_Validar,3);
                    //listaDuenios[index].edad = nuevaEdad;
                    //val_getUnsignedInt(bufferDni,"\nIngrese el Dni: \n", "\n DNI no valido\n",3,10);
                    //dni_a_Validar = atoi(bufferDni);
                    //val_validarDni(&nuevoDni,dni_a_Validar,3);
                    //listaDuenios[index].dni = nuevoDni;


                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

/** \brief imprime la estructura
 *
 * \param listaDuenios es el array
 * \param limite la cantidad de elementos para el array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int due_PrintDuenios(sDuenio listaDuenios[], int limite)
{
    int retorno = -1;
    int i;
    if(listaDuenios != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaDuenios[i].flag_ocupado == INDICE_OCUPADO)
            {
                printf("\n-\nNombre:%s\n\nApellido:%s\n\nID DUENIO:%d\n DIRECCION: %s \n\nTARJETA: %s \n\n ",listaDuenios[i].nombre,listaDuenios[i].apellido,listaDuenios[i].idDuenio,listaDuenios[i].direccion,listaDuenios[i].tc);
            }
        }

    }
    return retorno;
}

/** \brief pone el estado del elemento en libre para "borrarlo"
 *
 * \param listaDuenios es el array que recibe
 * \param limite la cantidad de elementos para el array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int due_Borrar(sDuenio listaDuenios[], int idABorrar,int limite)
{
    int retorno = -1;
    int i = 0;

    if(listaDuenios != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaDuenios[i].flag_ocupado == INDICE_OCUPADO && listaDuenios[i].idDuenio == idABorrar)
            {
                listaDuenios[i].flag_ocupado = INDICE_LIBRE;
                printf("\nPersona Eliminada!!!\n");
                retorno=0;
            }
        }

    }



    return retorno;
}


/**-------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------*/
/** \brief busca un texto en la lista
 * @param  listaAutomoviles el array donde busca
 * @param  len cantidad de elementos en el array
 * @return retorno :posicion donde se encontro o -1 si no se encontro
 *
 */

int auto_BuscarChar(sAutomovil listaAutomoviles[],int len, char texto[])
{
    int i;
    int retorno =-1;
    for (i=0; i<len; i++)
    {
        if (listaAutomoviles[i].flag_ocupado == 1 )
        {
            if (strcmp(listaAutomoviles[i].patente, texto) == 0)
            {
                retorno = i;
                break;

            }
        }
    }
    return retorno;
}





/** \brief Agrega persona a la lista
 *
 * @param  index el indice en el array, es decir la posicion.
 * @param  limite cantidad de elementos en el array
 * @return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int auto_AgregarAuto(sAutomovil listaAutomoviles[], sDuenio listaDuenios[],int index, int limite)
{

    int retorno = -1;
    char bpatente[50];
    char bMarca[50];
    char nuevoHorario[50];
    char bIdDuenio[50];

    if(listaAutomoviles != NULL && index >= 0 && index <limite)
    {
        if (val_getAlfanumerico(bpatente,"\nIngrese Patente:\n","\nError:\n",3,50)!=-1)
        {
            if (val_getUnsignedInt(bMarca,"\nIngrese Marca: 1)ALPHA_ROMEO    1\n 2)FERRARI     \n 3)BMW     \n 4)OTRO  \n","\nError\n",3,50)!= -1)
            {
                if (val_getUnsignedInt(nuevoHorario,"\ningrese Horario:\n","\nError!:\n",3,50)!=-1)
                {
                    if (val_getUnsignedInt(bIdDuenio,"\nIngrese Nro ID de Dueño:\n","\nError\n",3,50)!=-1)
                    {
                        listaAutomoviles[index].flag_ocupado = INDICE_OCUPADO;
                        listaAutomoviles[index].idAutomovil = auto_generar_Proximo_Id(listaAutomoviles,limite);
                        strcmpi(listaAutomoviles[index].patente, bpatente);

                        switch(atoi(bMarca))
                        {
                        case 1:
                            listaAutomoviles[index].marca = ALPHA_ROMEO;
                            break;
                        case 2:
                            listaAutomoviles[index].marca = FERRARI;
                            break;
                        case 3:
                            listaAutomoviles[index].marca = BMW;
                            break;
                        case 4:
                            listaAutomoviles[index].marca = OTRO;
                            break;
                        }
                        listaAutomoviles[index].horario = atoi(nuevoHorario);
                        if (due_BuscarChar(listaDuenios,limite,bIdDuenio)!=-1)
                        {
                            listaAutomoviles[index].idDuenio_Relacionable = atoi(bIdDuenio);
                        }


                        retorno=0;
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief imprime la estructura
 *
 * \param listaAutomoviles es el array
 * \param limite la cantidad de elementos para el array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int auto_PrintAutos(sAutomovil listaAutomoviles[], int limite)
{
    int retorno = -1;
    int i;
    if(listaAutomoviles != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaAutomoviles[i].flag_ocupado == INDICE_OCUPADO)
            {
                printf("\n-\nMARCA:%d\n\nPATENTE:%s\n\nHORARIO:%d\n\n ",listaAutomoviles[i].marca, listaAutomoviles[i].patente,listaAutomoviles[i].horario);
            }
        }

    }
    return retorno;
}

/** \brief pone el estado del elemento en libre para "borrarlo"
 *
 * \param listaAutomoviles es el array que recibe
 * \param limite la cantidad de elementos para el array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int auto_Borrar(sAutomovil listaAutomoviles[], int id,int limite)
{
    int retorno = -1;
    int i = 0;

    if(listaAutomoviles != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaAutomoviles[i].flag_ocupado == INDICE_OCUPADO && listaAutomoviles[i].idAutomovil == id)
            {
                listaAutomoviles[i].flag_ocupado = INDICE_LIBRE;
                printf("\nPersona Eliminada!!!\n");
                retorno=0;
            }
        }

    }



    return retorno;
}


/** \brief cuenta la cantidad de personas para distintos segmentos segun la edad de las mismas
 *
 * \param listaAutomoviles es el array a recorrer
 * \param contador1 puntero a donde se va a almacenar el contador para
 * \param contador2 puntero a donde se va a almacenar el contador para
 * \param contador3 puntero a donde se va a almacenar el contador para
  * \param contador4 puntero a donde se va a almacenar el contador para
 * \param limite es la cantidad de elementos a recorrer del array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int auto_ContarbyMarca(sAutomovil listaAutomoviles[], int *contador1, int *contador2, int *contador3, int *contador4,int limite)
{
    int retorno = -1;
    int i = 0;
    *contador1 = 0;
    *contador2=0;
    *contador3=0;
    *contador4=0;

    if(listaAutomoviles != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaAutomoviles[i].flag_ocupado == INDICE_OCUPADO && listaAutomoviles[i].marca == 1)
            {
                *contador1= *contador1 + 1;
                retorno=0;
            }
            if(listaAutomoviles[i].flag_ocupado == INDICE_OCUPADO && listaAutomoviles[i].marca == 2 )
            {
                *contador2=*contador2 +1;
                retorno=0;
            }
            if(listaAutomoviles[i].flag_ocupado == INDICE_OCUPADO && listaAutomoviles[i].marca ==3 )
            {
                *contador3=*contador3+1;
                retorno=0;

            }
            if(listaAutomoviles[i].flag_ocupado == INDICE_OCUPADO && listaAutomoviles[i].marca ==4 )
            {
                *contador4=*contador4+1;
                retorno=0;

            }

        }

    }

    return retorno;
}





/** \brief compara los elementos en .nombre del array segun el indice y  reordena alfabeticamente
 *
 * \param listaAutomoviles es el array que contiene los elementos a ordenar
 * \param limite es la cantidad de elementos que contiene ese array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

void auto_ordenar_x_Hora(sAutomovil listaAutomoviles[],int limite)
{
    char auxPatente[20];
    int auxhorario;
    int auxMarca;

    int i,j;
    for( i=0; i<limite-1; i++)
    {
        for(j = i+1; j<limite; j++)
        {
            if(listaAutomoviles[i].flag_ocupado == INDICE_OCUPADO && listaAutomoviles[j].flag_ocupado == INDICE_OCUPADO)
            {

                if (listaAutomoviles[i].horario > listaAutomoviles[j].horario)
                {
                    auxhorario = listaAutomoviles[i].horario;
                    listaAutomoviles[i].horario = listaAutomoviles[j].horario;
                    listaAutomoviles[j].horario= auxhorario;
                }
                if (listaAutomoviles[i].horario == listaAutomoviles[j].horario)
                {


                    if(strcmp(listaAutomoviles[i].patente,listaAutomoviles[j].patente)>0)
                    {
                        strcpy(auxPatente,listaAutomoviles[i].patente);
                        strcpy(listaAutomoviles[i].patente,listaAutomoviles[j].patente);
                        strcpy(listaAutomoviles[j].patente,auxPatente);

                        auxMarca = listaAutomoviles[i].marca;
                        listaAutomoviles[i].marca = listaAutomoviles[j].marca;
                        listaAutomoviles[j].marca= auxMarca;
                    }
                }
            }

        }
    }
}

