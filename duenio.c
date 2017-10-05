#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "duenio.h"

/** \brief idAutoincrementable
 *
 * \param arrayLista recibe puntero al inicio del array
 * \param len es la cantidad de elementos del array
 * \return retorna el ultimo valor para utilizar en Id
 *
 */

int due_generar_Proximo_Id(sDuenio listaDuenios[], int len)
{
    static int ultimoValorIdAutoincrementable = -1;
    ultimoValorIdAutoincrementable ++;
    return ultimoValorIdAutoincrementable;

}


/** \brief Inicializa la lista
 *
 * \param arrayLista recibe puntero al inicio del array
 * \param limite es la cantidad de elementos del array
 * \return retorno : -1 (error) ; 0 (funciona correctamente)
 *
 */

int due_InitLista(sDuenio  listaDuenios[], int limite)
{
    int retorno = -1;
    int i;

    if( listaDuenios != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            listaDuenios[i].flag_ocupado = INDICE_LIBRE;
            retorno=0;
        }

    }

    return retorno;
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int due_obtenerEspacioLibre(sDuenio  listaDuenios[],int limite)
{

    int retorno = -1;
    int i;
    if(listaDuenios != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaDuenios[i].flag_ocupado == INDICE_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;

}


