#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"
#include "automovil.h"

/** \brief idAutoincrementable
 *
 * \param arrayLista recibe puntero al inicio del array
 * \param len es la cantidad de elementos del array
 * \return retorna el ultimo valor para utilizar en Id
 *
 */
int auto_generar_Proximo_Id(sAutomovil listaAutomoviles[], int len)
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



int auto_InitLista(sAutomovil  listaAutomoviles[], int limite)
{
    int retorno = -1;
    int i;

    if( listaAutomoviles != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            listaAutomoviles[i].flag_ocupado = INDICE_LIBRE;
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
int auto_obtenerEspacioLibre(sAutomovil  listaAutomoviles[],int limite)
{

    int retorno = -1;
    int i;
    if(listaAutomoviles != NULL && limite > 0)
    {
        for(i=0; i<limite ; i++)
        {
            if(listaAutomoviles[i].flag_ocupado == INDICE_LIBRE)
            {
                retorno =  i;
                break;
            }
        }

    }
    return retorno;

}



