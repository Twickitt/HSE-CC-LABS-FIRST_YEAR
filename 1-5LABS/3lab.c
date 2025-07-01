#include <stdio.h>

int inputArray(int arr[][10], int N) {
    int k; // Размер массива
    int ch;

    do {
        printf("Введите целочисленный размер матрицы не больше 10 и не меньше 2: ");
        scanf("%d", &k);
        while ((ch = getchar()) != '\n' && ch != EOF) {
            printf("\n Введите целочисленный размер матрицы не больше 10 и не меньше 2: \n");
            while ((ch = getchar()) != '\n' && ch != EOF);
            scanf("%d", &k);
        }
    } while (k > N || k < 2); // Проверка ввода (от 2 до N)

    printf("Введите элементы массива:\n");

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &arr[i][j]);
            while ((ch = getchar()) != '\n' && ch != EOF) {
                printf(" Введите элементы через enter: \n");
                while ((ch = getchar()) != '\n' && ch != EOF);
                scanf("%d", &arr[i][j]);
            }
        }      // Ввод массива
    }
    return k; // размер матрицы
}

void output(int arr[][10], int k) {
    printf("Матрица:\n");

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Функция, выводящая элементы в порядке диагонального обхода
void ord(int arr[][10], int n) {
    printf("Вывод элементов в нужном порядке:\n");

    // Перебор всех диагоналей, начиная с левого нижнего угла
    for (int d = 0; d < 2 * n - 1; d++) {
        if (d % 2 == 0) {
            // Нечётные диагонали: снизу вверх
            int row = (d < n) ? n - 1 - d : 0;  // ? возвращает значение своего слева если оно не равно null 
            int col = (d < n) ? 0 : d - (n - 1);
            while (row < n && col < n) {
                printf("%d ", arr[row][col]);
                row++;
                col++;
            }
        } else {
            // Чётные диагонали: сверху вниз
            int col = (d < n) ? 0 : d - (n - 1);
            int row = (d < n) ? n - 1 - d : 0;
            while (row < n && col < n) {
                printf("%d ", arr[row][col]);
                row++;
                col++;
            }
        }
    }
    printf("\n");
}

int main() {
    int arr[10][10];

    // Ввод размера и элементов матрицы
    int n = inputArray(arr, 10);

    // Вывод исходной матрицы
    output(arr, n);

    // Диагональный обход в заданном порядке
    ord(arr, n);

    return 0;
}
