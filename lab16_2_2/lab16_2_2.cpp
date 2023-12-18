#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>

int main() {
    setlocale(LC_CTYPE, "ukr"); //Українізація

    int N; // Розмір матриці
    do {
        printf("Введiь розмiр матрицi N (N <= 10): ");
        scanf_s("%d", &N);
    } while (N > 10 || N <= 0);

    // Динамічне виділення пам'яті для матриці
    float** matrix = (float**)malloc(N * sizeof(float*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (float*)malloc(N * sizeof(float));
    }

    // Рандомне заповнення матриці
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = (float)(rand() % 200) / 10.0 - 10; // Випадкове число від -10 до 9.9
        }
    }
    printf("Матриця :\n");
    //Виведення матриці
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("[%.1f] ", matrix[i][j]);
        }
        printf("\n");
    }

    // Знаходження кількості позитивних елементів у кожному стовпці
    printf("Кiлькiсть позитивних елементiв у кожному стовпцi:\n");
    for (int j = 0; j < N; j++) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (matrix[i][j] > 0) {
                count++;
            }
        }
        printf("Стовпець %d: %d \n", j + 1, count);
    }

    // Звільнення виділеної пам'яті
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}