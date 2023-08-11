#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 100

char tape[MAX_LENGTH];
int head;
int state;

void initializeTape(char input[]) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        tape[i] = input[i];
    }
    tape[i] = '\0';
    head = 0;
    state = 0;
}

void moveHead(char direction) {
    if (direction == 'R') {
        head++;
    } else if (direction == 'L') {
        head--;
    }
}

void complement() {
    while (true) {
        switch (state) {
            case 0:
                if (tape[head] == '0') {
                    tape[head] = '1';
                    moveHead('R');
                    state = 0;
                } else if (tape[head] == '1') {
                    tape[head] = '0';
                    moveHead('R');
                    state = 0;
                } else if (tape[head] == '\0') {
                    return;
                } else {
                    printf("Invalid input\n");
                    return;
                }
                break;
        }

        if (tape[head] == '\0') {
            return;
        }
    }
}

int main() {
    char input[MAX_LENGTH];

    printf("Enter a binary number: ");
    scanf("%s", input);

    initializeTape(input);

    complement();

    printf("Complement: %s\n", tape);

    return 0;
}
