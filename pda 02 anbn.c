#include <stdio.h>

// Enumerations for the states of the PDA
enum State {
    STATE_INITIAL,
    STATE_A,
    STATE_AB,
    STATE_REJECT
};

// Function to simulate the PDA for the given input string
void simulatePDA(const char* input) {
    enum State currentState = STATE_INITIAL;
    int i = 0;
    char symbol = input[i];

    while (symbol != '\0') {
        switch (currentState) {
            case STATE_INITIAL:
                if (symbol == 'a') {
                    currentState = STATE_A;
                } else {
                    currentState = STATE_REJECT;
                }
                break;

            case STATE_A:
                if (symbol == 'a') {
                    currentState = STATE_A;
                } else if (symbol == 'b') {
                    currentState = STATE_AB;
                } else {
                    currentState = STATE_REJECT;
                }
                break;

            case STATE_AB:
                if (symbol == 'b') {
                    currentState = STATE_AB;
                } else {
                    currentState = STATE_REJECT;
                }
                break;

            case STATE_REJECT:
                printf("String rejected.\n");
                return;
        }

        symbol = input[++i];
    }

    if (currentState == STATE_AB) {
        printf("String accepted.\n");
    } else {
        printf("String rejected.\n");
    }
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    simulatePDA(input);

    return 0;
}

