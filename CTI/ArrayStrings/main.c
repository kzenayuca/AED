#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 5       // Número máximo de palabras
#define MAX_LENGTH 50     // Longitud máxima de cada palabra

// Función para calcular la longitud de una cadena
int string_length(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Función para concatenar dos cadenas
void string_concat(char* dest, const char* src) {
    // Mover el puntero `dest` al final de la cadena existente
    while (*dest != '\0') {
        dest++;
    }

    // Copiar los caracteres de `src` a `dest`
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    // Agregar el terminador nulo
    *dest = '\0';
}

// Función para construir una oración concatenando las palabras
char* StringBuilder(char** words, int count) {
    int totalLength = 0;

    // Calcular la longitud total necesaria para la oración
    for (int i = 0; i < count; i++) {
        totalLength += string_length(words[i]) + 1; // +1 para el espacio o '\0'
    }

    // Reservar memoria para la oración resultante
    char* result = (char*)malloc(totalLength * sizeof(char));
    if (result == NULL) {
        printf("Error: No se pudo asignar memoria\n");
        exit(1);
    }

    result[0] = '\0'; // Inicializar la cadena como vacía

    // Construir la oración concatenando palabras
    for (int i = 0; i < count; i++) {
        string_concat(result, words[i]);
        if (i < count - 1) {
            string_concat(result, " "); // Agregar un espacio entre palabras
        }
    }

    return result;
}

int main() {
    // Arreglo de punteros a cadenas
    char* arr[MAX_WORDS];

    // Reservar memoria para cada palabra y copiar "Hola"
    for (int i = 0; i < MAX_WORDS; i++) {
        arr[i] = (char*)malloc(MAX_LENGTH * sizeof(char));
        if (arr[i] == NULL) {
            printf("Error: No se pudo asignar memoria para la palabra %d\n", i);
            exit(1);
        }

        // Copiar "Hola" manualmente
        char* temp = "Hola";
        int j = 0;
        while (temp[j] != '\0') {
            arr[i][j] = temp[j];
            j++;
        }
        arr[i][j] = '\0'; // Terminar la cadena con '\0'
    }

    // Llamar a la función para construir la oración
    char* sentence = StringBuilder(arr, MAX_WORDS);

    // Mostrar el resultado
    printf("Resultado: %s\n", sentence);

    // Liberar memoria asignada
    for (int i = 0; i < MAX_WORDS; i++) {
        free(arr[i]);
    }
    free(sentence);

    return 0;
}

