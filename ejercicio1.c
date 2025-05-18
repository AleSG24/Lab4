#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Encuentra la cantidad mas grande de 1s en una fila

void findLargestLine(int **matrix, int size, int *result) {
    int maxCount = -1;
    int rowIndex = -1;

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            rowIndex = i;
        }
    }

    result[0] = maxCount;
    result[1] = rowIndex;
}

//Reserva la matriz en memoria dinamica

void allocateMatrix(int ***matrix, int size) {
    *matrix = (int **)malloc(size * sizeof(int*));  

    if (*matrix == NULL) {
        perror("Error al reservar la memoria");
        return;
    }

    for (int i = 0; i < size; i++) {
        (*matrix)[i] = (int *)malloc(size * sizeof(int));
        if ((*matrix)[i] == NULL) {
            perror("Fallo al reservar memoria en fila");
        
        }
    }
}

//Llena la matriz

void fillMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++){
        int *fila = *(matrix + i);
        for (int j = 0; j < size; j++) {
            *(fila + j) = rand() % 2;
        }
    }

}

void printMatrix(int **matrix, int size){
    printf("Matrix(%dx%d):\n", size, size);
    for (int i = 0; i< size; i++){
        for (int j = 0; j < size; j++){
            printf(" %d", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int size){
    for(int i = 0; i < size; i++){
        free(matrix[i]);
    }
    free(matrix);
}

int main(){
    srand(time(NULL));
    int size, largestLine;
    int **matrix = NULL;
    printf("Ingrese el tamano que desea para la matriz\n");
    scanf("%d", &size);
    allocateMatrix(&matrix, size);
    fillMatrix(matrix, size);
    printMatrix(matrix, size);
    findLargestLine(matrix, size, &largestLine);

    printf("El tamano de la secuencia de 1s mas grande es de: %d\n", largestLine);

}