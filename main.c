#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duenio.h"
#include "automovil.h"
#include "estacionamiento.h"
#define LEN_DUENIO  50
#define LEN_AUTOMOVIL 50
#include "validar.h"

int main()
{

    char bufferInt[50];
    char buffId[50];
    char bufferIdAutoEgreso[50];
    int idAutoEgreso;
    int id;


    sDuenio listaDuenios[LEN_DUENIO];
    sAutomovil listaAutomoviles[LEN_AUTOMOVIL];
    due_InitLista(listaDuenios, LEN_DUENIO);
    auto_InitLista(listaAutomoviles,LEN_AUTOMOVIL);

    do
    {
        val_getUnsignedInt(bufferInt,"\n1- Agregar Usuario \n2- Modificar Tarjeta \n3- Ingreso Auto\n4- Egreso Auto \n\n5- Informes \n","error",2,40);
        switch(atoi(bufferInt))
        {
        case 1:
            due_AgregarDuenio(listaDuenios,due_obtenerEspacioLibre(listaDuenios,LEN_DUENIO),LEN_DUENIO);
            break;

        case 2:
            val_getUnsignedInt(buffId,"\nIngrese el Id a modificar:\n","no valido",3,LEN_DUENIO);
            id=atoi(buffId);
            due_modificar(listaDuenios,LEN_DUENIO,id);
            break;

        case 3:
            auto_AgregarAuto(listaAutomoviles,listaDuenios,auto_obtenerEspacioLibre(listaAutomoviles,LEN_AUTOMOVIL),LEN_AUTOMOVIL);
            break;

        case 4:
            val_getUnsignedInt(bufferIdAutoEgreso,"\nIngrese el Id a borrar:\n","no valido",3,LEN_AUTOMOVIL);
            idAutoEgreso=atoi(bufferIdAutoEgreso);

            auto_Borrar(listaAutomoviles,idAutoEgreso,LEN_AUTOMOVIL);
            break;

        case 5:
             due_PrintDuenios(listaDuenios,LEN_DUENIO);


            break;
        }
    }
    while(atoi(bufferInt) != 9);

    return 0;
}
