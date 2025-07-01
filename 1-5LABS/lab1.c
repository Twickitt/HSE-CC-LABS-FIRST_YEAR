#include <stdio.h>

// Функция для вычисления суммы ряда с заданным epsilon
double sum_with_precision(double x, double epsilon) {
    double sum = 0.0;   
    double term = 1.0;  // Первый член ряда
    int n = 0;          // Номер текущего члена ряда

    // Суммируем члены ряда, пока текущий член не станет меньше epsilon
    while (term > epsilon || term < -epsilon) { // Проверка модуля терма без fabs()
        sum += term;        
        n++;                // Переход к следующему члену ряда
        term = term * x;    // Вычисление следующего члена ряда
    }

    return sum;
}

// Функция для вычисления суммы ряда с заданным количеством членов
double sum_with_n_terms(double x, int N) {
    double sum = 0.0;   
    double term = 1.0;  

    // Суммируем заданное количество членов ряда
    for (int n = 0; n < N; n++) {
        sum += term;        // Добавляем текущий член ряда
        term = term * x;    // Вычисление следующего члена ряда
    }

    return sum;
}

// Функция для ввода корректного значения x
double input_x() {
    double x;
    while (1) {
        printf("Введите значение x (диапазон: -1 < x < 1): ");
        scanf("%lf", &x);

        if (x > -1 && x < 1) {
            if (x == 1 || x == -1 ) {
                printf("Ошибка: при x = 1 ряд расходится. Повторите ввод.\n");
            } else {
                return x; // Корректное значение x
            }
        } else {
            printf("Ошибка: значение x должно принадлежать интервалу (-1, 1). Повторите ввод.\n");
        }
    }
}

// Функция для ввода корректного значения epsilon
double input_epsilon() {
    double epsilon;
    while (1) {
        printf("Введите значение точности epsilon (положительное число): ");
        scanf("%lf", &epsilon);

        if (epsilon > 0) {
            return epsilon;
        } else {
            printf("Ошибка: точность должна быть положительным числом. Повторите ввод.\n");
        }
    }
}

// Функция для ввода корректного значения кол-ва членов
int input_n_terms() {
    int N;
    while (1) {
        printf("Введите количество членов ряда (положительное целое число): ");
        scanf("%d", &N);

        if (N > 0) {
            return N;
        } else {
            printf("Ошибка: количество членов ряда должно быть положительным целым числом. Повторите ввод.\n");
        }
    }
}
// Основной блок для ввода способа вычисления и т.д
int main() {
    double x = input_x();             
    double epsilon;                   
    int N;                            
    int choice;                      

    // Запрос выбора способа вычисления
    while (1) {
        printf("\nВыберите способ вычисления:\n");
        printf("1. Сумма ряда с заданной точностью\n");
        printf("2. Сумма ряда для заданного количества членов\n");
        printf("Введите номер способа (1 или 2): ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Ввод точности для вычисления суммы с заданной точностью
            epsilon = input_epsilon();
            double sum1 = sum_with_precision(x, epsilon);
            printf("Сумма ряда с заданной точностью (epsilon = %.10f): %.10f\n", epsilon, sum1);
            break;
        } else if (choice == 2) {
            // Ввод количества членов для вычисления суммы ряда
            N = input_n_terms();
            double sum2 = sum_with_n_terms(x, N);
            printf("Сумма ряда для %d членов: %.10f\n", N, sum2);
            break;
        } else {
            printf("Ошибка: неверный выбор. Повторите ввод.\n");
        }
    }

    return 0;
}