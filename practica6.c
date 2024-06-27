#include <stdio.h>
#include <string.h>
#include <math.h>

// Función para convertir un número decimal a binario
void decimalToBinary(int n) {
    int binaryNum[32]; // Array para almacenar el número binario
    int i = 0; // Contador para el array binario

    if (n == 0) {
        printf("0");
        return;
    }

    while (n > 0) {
        binaryNum[i] = n % 2; // Almacenar el residuo de n dividido por 2
        n = n / 2; // Actualizar n para la próxima iteración
        i++;
    }

    for (int j = i - 1; j >= 0; j--) // Imprimir el array binario en orden inverso
        printf("%d", binaryNum[j]);
}

// Función para convertir un número binario a decimal
int binaryToDecimal(const char *binaryNum) {
    int decimal = 0;
    int length = strlen(binaryNum);

    // Iterar sobre cada bit en la cadena binaria
    for (int i = 0; i < length; i++) {
        // Si el bit es '1', añadir 2^(posición desde la derecha) al resultado decimal
        if (binaryNum[length - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }

    return decimal;
}

int main() {
    int opcion, num;
    char binaryNum[33]; // Array para almacenar el número binario de hasta 32 bits

    while (1) {
        printf("Seleccione la operación que desee realizar:\n");
        printf("1. De decimal a binario\n");
        printf("2. De binario a decimal\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        if (opcion == 1 || opcion == 2) {
            break; // Salir del bucle si la opción es válida
        } else {
            printf("Opción no válida, por favor intente de nuevo.\n");
        }
    }

    switch (opcion) {
        case 1: 
            printf("De decimal a binario\n");
            printf("Ingrese el número decimal: ");
            scanf("%d", &num);
            printf("El número binario es: ");
            decimalToBinary(num);
            printf("\n");
            break;

        case 2:
            printf("De binario a decimal\n");
            printf("Ingrese el número binario: ");
            scanf("%32s", binaryNum);
            num = binaryToDecimal(binaryNum);
            printf("El número decimal es: %d\n", num);
            break;
    }

    return 0;
}





#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>



// Función para convertir un número decimal a binario
void decimalToBinary(int n) {
    int binaryNum[32]; // Array para almacenar el número binario
    int i = 0; // Contador para el array binario


    while (n > 0) {
        binaryNum[i] = n % 2; // Almacenar el residuo de n dividido por 2
        n = n / 2; // Actualizar n para la próxima iteración
        i++;
    }


    for (int j = i - 1; j >= 0; j--) // Imprimir el array binario en orden inverso
        printf("%d", binaryNum[j]);
}


// Función para convertir un número binario a decimal
int binaryToDecimal(char *binaryNum) {
    int decimal = 0;
    int length = strlen(binaryNum);


    // Iterar sobre cada bit en la cadena binaria
    for (int i = 0; i < length; i++) {
        // Si el bit es '1', añadir 2^(posición desde la derecha) al resultado decimal
        if (binaryNum[length - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }


    return decimal;




}


int main() {
    int opcion, num;
    char binaryNum[33]; // Array para almacenar el número binario de hasta 32 bits
    bool bandera;
    bandera = false;

    while (!bandera)
        {

    printf("Seleccione la operación que desee realizar:\n");
    printf("1. De decimal a binario\n");
    printf("2. De binario a decimal\n");
    printf("3. Salida de la aplicacion\n");
    printf("Opción: ");
    scanf("%d", &opcion);


    
        switch (opcion) {
        case 1:
            printf("De decimal a binario\n");
            printf("Ingrese el número decimal: ");
            scanf("%d", &num);
            printf("El número binario es: ");
            decimalToBinary(num);
            printf("\n");
            break;


        case 2:
            printf("De binario a decimal\n");
            printf("Ingrese el número binario: ");
            scanf("%32s", binaryNum);
            num = binaryToDecimal(binaryNum);
            printf("El número decimal es: %d\n", num);
            break;


        case 3:
            printf("Salida de la aplicacion\n");
            bandera = true;
             break;
    }


    }


   // printf("opcion no valida, vuelva a ingresar el numero\n");
   
    return 0;
}
