#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombres[5][20];
    char nombre_a_buscar[20];
    int posicionNombreEncontrado = -1;
    int encontrado, i;

    // nombres[0] = "Carlos"; INCORRECTO

    strcpy(nombres[0], "Carlos");
    strcpy(nombres[1], "Ana");
    strcpy(nombres[2], "Pedro");
    strcpy(nombres[3], "Luis");
    strcpy(nombres[4], "Maria");

    printf("Ingrese el nombre a buscar\n");
    scanf("%s", &nombre_a_buscar);

    encontrado = 0;
    i = 0;
    while (encontrado == 0 && i < 5)
    {
        /*if(nombres[i] == nombre_a_buscar) INCORRECTO
        {

        }
        */
        if (strcmp(nombres[i], nombre_a_buscar) == 0)
        {
            encontrado = 1;
            posicionNombreEncontrado = i;
        }
        else
        {
            i = i + 1;
        }
    }

    if (encontrado == 0)
    {
        printf("El nombre no se encuentra en el arreglo");
    }
    else
    {
        printf("El nombre que buscaste y encontraste es %s", nombres[posicionNombreEncontrado]);
    }

    //otra forma
    if (posicionNombreEncontrado == -1)
    {
        printf("El nombre no se encuentra en el arreglo");
    }
    else
    {
        printf("El nombre que buscaste y encontraste es %s", nombres[posicionNombreEncontrado]);
    }
}