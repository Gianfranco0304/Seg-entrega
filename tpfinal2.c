#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Función para convertir un número decimal a binario
void decimalabinario(int n) {
    int numBinario[32]; // Array para almacenar el número binario
    int i = 0; // Contador para el array binario

    while (n > 0) {
        numBinario[i] = n % 2; // Almacenar el residuo de n dividido por 2
        n = n / 2; // Actualizar n para la próxima iteración
        i++;
    }

    for (int j = i - 1; j >= 0; j--) // Imprimir el array binario en orden inverso
        printf("%d", numBinario[j]);
}

// Función para convertir un número binario a decimal
int binarioadecimal(char *numBinario) {
    int decimal = 0;
    int length = strlen(numBinario);

    // Iterar sobre cada bit en la cadena binaria
    for (int i = 0; i < length; i++) {
        // Si el bit es '1', añadir 2^(posición desde la derecha) al resultado decimal
        if (numBinario[length - 1 - i] == '1') {
            decimal += pow(2, i);
        }
    }

    return decimal;
}

// Función para convertir un número decimal a hexadecimal
void decimalahexadecimal(int n) {
    char numHexadecimal[32]; // Array para almacenar el número hexadecimal
    int i = 0; // Contador para el array hexadecimal

    while (n > 0) {
        int temp = n % 16; // Obtener el residuo de n dividido por 16
        if (temp < 10) {
            numHexadecimal[i] = temp + 48; // Convertir a carácter '0'-'9'
        } else {
            numHexadecimal[i] = temp + 87; // Convertir a carácter 'a'-'f'
        }
        n = n / 16; // Actualizar n para la próxima iteración
        i++;
    }

    for (int j = i - 1; j >= 0; j--) // Imprimir el array hexadecimal en orden inverso
        printf("%c", numHexadecimal[j]);
}

// Función para convertir un número hexadecimal a decimal
int hexadecimaladecimal(char *numHexadecimal) {
    int decimal = 0;
    int length = strlen(numHexadecimal);

    // Iterar sobre cada dígito en la cadena hexadecimal
    for (int i = 0; i < length; i++) {
        char digit = numHexadecimal[length - 1 - i];
        int value;
        if (digit >= '0' && digit <= '9') {
            value = digit - '0';
        } else if (digit >= 'a' && digit <= 'f') {
            value = digit - 'a' + 10;
        } else if (digit >= 'A' && digit <= 'F') {
            value = digit - 'A' + 10;
        } else {
            return -1; // Error: carácter no válido en la cadena hexadecimal
        }
        decimal += value * pow(16, i);
    }

    return decimal;
}

// Función para convertir un número binario a hexadecimal
void binarioahexadecimal(char *numBinario) {
    int decimal = binarioadecimal(numBinario);
    decimalahexadecimal(decimal);
}

// Función para convertir un número hexadecimal a binario
void hexadecimalabinario(char *numHexadecimal) {
    int decimal = hexadecimaladecimal(numHexadecimal);
    decimalabinario(decimal);
}

int main() {
    int opcion, num;
    char numBinario[33]; // Array para almacenar el número binario de hasta 32 bits
    char numHexadecimal[33]; // Array para almacenar el número hexadecimal
    bool bandera = false;

    while (!bandera) {
        printf("Seleccione la operación que desee realizar:\n");
        printf("1. De decimal a binario\n");
        printf("2. De binario a decimal\n");
        printf("3. De decimal a hexadecimal\n");
        printf("4. De hexadecimal a decimal\n");
        printf("5. De binario a hexadecimal\n");
        printf("6. De hexadecimal a binario\n");
        printf("7. Salida de la aplicacion\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                do {
                    printf("De decimal a binario\n");
                    printf("Ingrese el número decimal: ");
                    scanf("%d", &num);
                    printf("El número binario es: ");
                    decimalabinario(num);
                    printf("\n");

                    printf("\n¿Qué desea hacer a continuación?\n");
                    printf("1. Convertir otro número decimal a binario\n");
                    printf("2. Hacer otra operación\n");
                    printf("3. Salir\n");
                    printf("Opción: ");
                    scanf("%d", &opcion);

                    if (opcion == 2 || opcion == 3) {
                        break;
                    }
                } while (opcion == 1);

                if (opcion == 3) {
                    bandera = true;
                }
                break;

            case 2:
                do {
                    printf("De binario a decimal\n");
                    printf("Ingrese el número binario: ");
                    scanf("%32s", numBinario);
                    num = binarioadecimal(numBinario);
                    printf("El número decimal es: %d\n", num);

                    printf("\n¿Qué desea hacer a continuación?\n");
                    printf("1. Convertir otro número binario a decimal\n");
                    printf("2. Hacer otra operación\n");
                    printf("3. Salir\n");
                    printf("Opción: ");
                    scanf("%d", &opcion);

                    if (opcion == 2 || opcion == 3) {
                        break;
                    }
                } while (opcion == 1);

                if (opcion == 3) {
                    bandera = true;
                }
                break;

            case 3:
                do {
                    printf("De decimal a hexadecimal\n");
                    printf("Ingrese el número decimal: ");
                    scanf("%d", &num);
                    printf("El número hexadecimal es: ");
                    decimalahexadecimal(num);
                    printf("\n");

                    printf("\n¿Qué desea hacer a continuación?\n");
                    printf("1. Convertir otro número decimal a hexadecimal\n");
                    printf("2. Hacer otra operación\n");
                    printf("3. Salir\n");
                    printf("Opción: ");
                    scanf("%d", &opcion);

                    if (opcion == 2 || opcion == 3) {
                        break;
                    }
                } while (opcion == 1);

                if (opcion == 3) {
                    bandera = true;
                }
                break;

            case 4:
                do {
                    printf("De hexadecimal a decimal\n");
                    printf("Ingrese el número hexadecimal: ");
                    scanf("%32s", numHexadecimal);
                    num = hexadecimaladecimal(numHexadecimal);
                    printf("El número decimal es: %d\n", num);

                    printf("\n¿Qué desea hacer a continuación?\n");
                    printf("1. Convertir otro número hexadecimal a decimal\n");
                    printf("2. Hacer otra operación\n");
                    printf("3. Salir\n");
                    printf("Opción: ");
                    scanf("%d", &opcion);

                    if (opcion == 2 || opcion == 3) {
                        break;
                    }
                } while (opcion == 1);

                if (opcion == 3) {
                    bandera = true;
                }
                break;

            case 5:
                do {
                    printf("De binario a hexadecimal\n");
                    printf("Ingrese el número binario: ");
                    scanf("%32s", numBinario);
                    printf("El número hexadecimal es: ");
                    binarioahexadecimal(numBinario);
                    printf("\n");

                    printf("\n¿Qué desea hacer a continuación?\n");
                    printf("1. Convertir otro número binario a hexadecimal\n");
                    printf("2. Hacer otra operación\n");
                    printf("3. Salir\n");
                    printf("Opción: ");
                    scanf("%d", &opcion);

                    if (opcion == 2 || opcion == 3) {
                        break;
                    }
                } while (opcion == 1);

                if (opcion == 3) {
                    bandera = true;
                }
                break;

            case 6:
                do {
                    printf("De hexadecimal a binario\n");
                    printf("Ingrese el número hexadecimal: ");
                    scanf("%32s", numHexadecimal);
                    printf("El número binario es: ");
                    hexadecimalabinario(numHexadecimal);
                    printf("\n");

                    printf("\n¿Qué desea hacer a continuación?\n");
                    printf("1. Convertir otro número hexadecimal a binario\n");
                    printf("2. Hacer otra operación\n");
                    printf("3. Salir\n");
                    printf("Opción: ");
                    scanf("%d", &opcion);

                    if (opcion == 2 || opcion == 3) {
                        break;
                    }
                } while (opcion == 1);

                if (opcion == 3) {
                    bandera = true;
                }
                break;

            case 7:
                printf("Salida de la aplicacion\n");
                bandera = true;
                break;

            default:
                printf("Opción no válida. Por favor, intente de nuevo.\n");
                break;
        }
    }

    return 0;

}

