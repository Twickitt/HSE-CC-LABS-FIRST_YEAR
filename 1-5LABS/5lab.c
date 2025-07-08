#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 330 
#define WORDS 30 
#define WORD_LEN 10 

// Функция для обработки слова
void rev(char *word) {
    int len = strlen(word);
    char lastsimb = word[len - 1]; // Последний символ в слове (-1 т.к. не учитывается символ конца строки)
    char rev[WORD_LEN + 1];
    int k = 0;

    // оставляю только первые вхождения символов  
    int seen[256] = {0}; // Массив для учета символов
    for (int i = 0; i < len; i++) {
        if (word[i] != lastsimb || seen[(char)lastsimb] == 0) {  
            rev[k] = word[i];
            k += 1;
            seen[(unsigned char)word[i]] = 1; // Помечаем символ как встреченный
        }
    }
    rev[k] = '\0';
    strcpy(word, rev);
}

// Основная программа
int main() {


    char string[LEN]; // Исходная строка
    char words[WORDS][WORD_LEN + 1]; // Для хранения слов
    int count = 0;

    printf("Введите строку(не более 30 слов по 10 символов каждое(не включая пробелы)): ");
    fgets(string, LEN, stdin);
    string[strcspn(string, "\n")] = '\0'; // заменяем \n на \0

    // Вывод исходной строки
    printf("Исходная строка: \"%s\"\n", string);

    // Разделяем строку на слова
    char *barr = strtok(string, " .");
    while (barr != NULL) {
        strncpy(words[count++], barr, WORD_LEN);
        words[count - 1][WORD_LEN] = '\0'; // Обеспечиваем завершение строки символом \0
        barr = strtok(NULL, " .");
    }

    if (count < 2) {
        printf("Строка должна содержать как минимум два слова.\n");
        return 1;
    }

    // Сохраняем последнее слово
    char lastword[WORD_LEN + 1];
    strncpy(lastword, words[count - 1], WORD_LEN);
    lastword[WORD_LEN] = '\0';

    // Обрабатываем все слова, кроме последнего и тех, что совпадают с ним
    printf("Обработанные слова: ");
    for (int i = 0; i < count - 1; i++) {
        // Проверяем, не совпадает ли слово с последним
        if (strcmp(words[i], lastword) != 0) {  
            rev(words[i]);
            printf("%s ", words[i]);
        }
    }
    printf("\n");

    return 0;
}
