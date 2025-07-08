#include <stdlib.h>
#include <stdio.h>

// Функция для создания массива
void createArray(int *arr, int size) {
    printf("Введите целочисленные элементы массива: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Функция для вывода массива
void printArray(int *arr, int size) {
    printf("Массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция для нахождения максимального модуля элементов в диапазоне [X, Y]
int maxElm(int *arr, int size, int X, int Y) {
    int maxAbs = -1; // -1 означает, что ничего не найдено
    for (int i = 0; i < size; i++) {
        if (arr[i] >= X && arr[i] <= Y) {
            int absValue = abs(arr[i]);
            if (absValue > maxAbs) {
                maxAbs = absValue;
            }
        }
    }
    return maxAbs;
}

// Функция для нахождения среднего арифметического элементов между первым и последним нечётными
double avgBetween(int *arr, int size) {
    double firstIdx = -1, lastIdx = -1;
    double sum = 0;
    int count = 0;

    // Найти первый и последний индексы нечётных элементов
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) { // Проверка на нечётность
            if (firstIdx == -1) {
                firstIdx = i;
            }
            lastIdx = i;
        }
    }

    // Если нечётных элементов нет или их недостаточно
    if (firstIdx == -1 || lastIdx == -1 || firstIdx == lastIdx) {
        return 0; // Среднее арифметическое не вычисляется
    }

    // Вычислить сумму и количество элементов между ними
    for (int i = firstIdx + 1; i < lastIdx; i++) {
        sum += arr[i];
        count++;
    }

    if (count == 0) return 0; // Если нет эл между

    return sum / count; // Среднее арифметическое
}

int main() {
    int k, X, Y;

    // Ввод размера массива
    printf("Введите размер массива: ");
    scanf("%d", &k);

    int *B = (int *)malloc(k * sizeof(int)); // Динамическое выделение памяти

    // Создание и вывод массива
    createArray(B, k);
    printArray(B, k);

    // Ввод пороговых значений X и Y
    printf("Введите значения X и Y: ");
    scanf("%d %d", &X, &Y);

    // Решение первого задания
    int maxAbs = maxElm(B, k, X, Y);
    if (maxAbs != -1) {
        printf("Максимальный модуль в диапазоне [%d, %d]: %d\n", X, Y, maxAbs);
    } else {
        printf("Элементы в диапазоне [%d, %d] отсутствуют.\n", X, Y);
    }

    // Решение второго задания
    double avg = avgBetween(B, k);
    if (avg != 0) {
        printf("Среднее арифметическое элементов между первым и последним нечётными: %.2f\n", avg);
    } else {
        printf("Среднее арифметическое не может быть вычислено.\n");
    }

    free(B); // Освобождение памяти
    return 0;
}