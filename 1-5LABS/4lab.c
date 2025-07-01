#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// Функция создания и заполнения массива
void arr(float** arr, int * size) {
    printf("Введите размер массива: ");
    scanf("%d", size);

    if (*size <= 0) {
        printf("Размер массива должен быть больше нуля\n");
        exit(1);
        
    }

    *arr = (float*)malloc(*size * sizeof(float));  // выделяем память
    if (*arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }

    printf("Введите элементы массива через пробел: ");
    for (int i = 0; i < *size; i++) {
        scanf("%f", &(*arr)[i]);
    }
}

// Функция вывода массива
void printArr(float* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.3f ", arr[i]);
    }

       printf("\n");
}

// Функция модификации массива: удаление отрицательных элементов после последнего минимального
void modifyArr(float* arr, int* size) {
    if (*size == 0) return;

    // Находим индекс последнего минимального элемента
    float minEl = FLT_MAX;
    int lastMinInd = -1;

    for (int i = 0; i < *size; i++) {
        if (arr[i] <= minEl) {
            minEl = arr[i];
            lastMinInd = i;
        }
    }

    // Удаляем отрицательные элементы после последнего минимального
    int writeInd = lastMinInd + 1;

    for (int i = lastMinInd + 1; i < *size; i++) {
        if (arr[i] >= 0) {
            arr[writeInd] = arr[i];
            writeInd += 1;
        }
    }

    // Обновляем размер массива
    *size = writeInd;
}

int main() {
    float* array = NULL;
    int size = 0;

    // Создание и заполнение массива
    arr(&array, &size);

    // Вывод исходного массива
    printf("Исходный массив: ");
    printArr(array, size);

    // Модификация массива
    modifyArr(array, &size);

    // Вывод измененного массива
    printf("Измененный массив: ");
    printArr(array, size);

    // Освобождение памяти
    free(array);
    return 0;
}
