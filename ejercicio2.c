#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100

// Convierte palabras a minuscula y elimina caracteres alfanumericos
void limpiar_palabra(char *palabra, char *limpia) {
    int j = 0;
    for (int i = 0; palabra[i] != '\0'; i++) {
        if (isalnum(palabra[i])) {
            limpia[j++] = tolower(palabra[i]);
        }
    }
    limpia[j] = '\0';
}

// Verifica si es un palindromo
int es_palindromo(const char *palabra) {
    int i = 0;
    int j = strlen(palabra) - 1;
    while (i < j) {
        if (palabra[i] != palabra[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    FILE *archivo = fopen("input.txt", "r");
    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    char palabra[MAX_WORD_LEN];
    char limpia[MAX_WORD_LEN];
    char palindromo_mas_largo[MAX_WORD_LEN] = "";
    
    while (fscanf(archivo, "%s", palabra) == 1) {
        limpiar_palabra(palabra, limpia);
        if (es_palindromo(limpia)) {
            if (strlen(limpia) > strlen(palindromo_mas_largo)) {
                strcpy(palindromo_mas_largo, limpia);
            }
        }
    }

    fclose(archivo);

    if (strlen(palindromo_mas_largo) > 0) {
        printf("El palíndromo más largo es: %s\n", palindromo_mas_largo);
    } else {
        printf("No se encontraron palíndromos en el archivo.\n");
    }

    return 0;
}
