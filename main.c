#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const char *inventory[] = {"hydraulic pump", "plc module", "servomotor"};
    int inventory_count = 3;
    char input[100];

    srand(time(NULL)); // seed random generator

    printf("hey. welcome to the spare parts inventory\n\n");
    printf("which part do you need?\n");

    while (true) {

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        // special question
        if (strcmp(input, "do you actually have any parts?") == 0 ||
            strcmp(input, "is there anything in stock at all") == 0) {

            printf("we have %d part(s)\n", inventory_count);
            for (int i = 0; i < inventory_count; i++) {
                printf("%s\n", inventory[i]);
            }
            continue;
        }

        // random availability: 0 = no, 1 = yes
        bool available = rand() % 2;

        if (available) {
            printf("good news! we have a %s in stock :) bye!\n", input);
            break;
        } else {
            printf("sorry, we don't have any %s right now :(\n", input);
        }
    }

    return 0;
}
