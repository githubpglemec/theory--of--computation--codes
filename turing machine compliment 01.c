#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Enumerations for the states of the Turing machine
enum State {
    STATE_START,
    STATE_PROCESS,
    STATE_HALT
};

// Function to simulate the Turing machine
void simulateTuringMachine(char* tape) {
    int length = strlen(tape);
    int head = 0;
    enum State currentState = STATE_START;

    while (currentState != STATE_HALT) {
        switch (currentState) {
            case STATE_START:
                if (tape[head] == '0') {
                    tape[head] = '1';
                } else if (tape[head] == '1') {
                    tape[head] = '0';
                }

                head++;
                currentState = STATE_PROCESS;
                break;

            case STATE_PROCESS:
                if (head >= length) {
                    currentState = STATE_HALT;
                } else {
                    currentState = STATE_START;
                }
                break;

            case STATE_HALT:
                break;
        }
    }
}

int main() {
    char tape[MAX_LENGTH];
    printf("Enter the binary number: ");
    scanf("%s", tape);

    simulateTuringMachine(tape);

    printf("Complement: %s\n", tape);

    return 0;
}

