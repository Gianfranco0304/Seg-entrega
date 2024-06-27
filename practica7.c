#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para convertir un carácter binario a un valor hexadecimal
char binario_a_hexadecimal(char *binario) {
    int decimal = 0;
    int base = 1;

    // Convertir el binario a decimal
    for (int i = strlen(binario) - 1; i >= 0; i--) {
        if (binario[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    // Convertir el decimal a hexadecimal
    if (decimal < 10) {
        return decimal + '0';
    } else {
        return decimal - 10 + 'A';
    }
}

// Función principal para convertir un binario largo a hexadecimal
void convertir_binario_a_hexadecimal(char *binario, char *hexadecimal) {
    int len = strlen(binario);
    int j = 0;

    // Procesar el binario en grupos de 4 bits
    for (int i = len % 4; i < len; i += 4) {
        char grupo[5] = "0000";

        // Copiar los bits en el grupo
        if (i != 0) {
            strncpy(grupo, binario + i - 4, 4);
        } else {
            strncpy(grupo + (4 - len % 4), binario, len % 4);
        }
        grupo[4] = '\0';

        // Convertir el grupo a un valor hexadecimal
        hexadecimal[j++] = binario_a_hexadecimal(grupo);
    }
    hexadecimal[j] = '\0';
}

int main() {
    char binario[65];
    char hexadecimal[17];

    // Solicitar el número binario al usuario
    printf("Introduce un número binario: ");
    scanf("%64s", binario);

    // Convertir el binario a hexadecimal
    convertir_binario_a_hexadecimal(binario, hexadecimal);

    // Imprimir el resultado
    printf("El número hexadecimal es: %s\n", hexadecimal);

    return 0;
}