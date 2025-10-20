#include "cli.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void clear_buffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

int ask_for_int(char *message) {
    int temp = 0;
    bool is_user_input_valid = false;
    while (!is_user_input_valid) {
        printf("%s\n", message);
        if (scanf("%d", &temp) > 0) {
            is_user_input_valid = true;
        }
        clear_buffer();
    }
    return temp;
}

char* ask_for_char(char *message) {
    char * temp = malloc(sizeof(char) * 15);
    printf("%s\n", message);
    scanf("%s", temp);
    clear_buffer();
    return temp;
}

    