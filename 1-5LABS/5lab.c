#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define length 330
#define words 300
#define word_len 10

void proc(char *sl);

int main() {
    char input[length];
    char word[words][word_len + 1]; // для хранения слов 
    int count = 0;

    printf("Введите строку из слов(не более 30 слов размером 10 символов(не включая пробелы))\n");
    fgets(input, length, stdin);
    input[strcspn(input, "\n")] = '\0';
    printf("Строка(исходная) \"%s\"\n", input); // вывод исходной строки 

    // разделяем строку на слова
    char *str = strtok(input, " .");  
    while (str != NULL) {
        strncpy(word[count++], str, word_len);
        str = strtok(NULL, " .");
    }

    if (count <2) {
        printf("Введите минимум 2 слова\n");
        return 1;
    }

    printf("Результат:");
    for (int i = 0; i < count - 1; i++) {
       proc(word[i]);
       printf("%s", word[i]); 
    }
    printf("\n");

    return(0);
}

void proc(char *sl) {
    int len = strlen(sl);
    char lasts = sl[len -1];
    char proc[word_len + 1];
    int k = 0;

    int seen[256] = {0};
    for ( int i = 0; i < len; i++) {
        if (sl[i] != lasts || !seen[(unsigned char)lasts]) {
            proc[k++] = sl[i];
            seen[(unsigned char)sl[i]] = 1;
        }
    }
    proc[k] = '\0';
    strcpy(sl, proc);
}