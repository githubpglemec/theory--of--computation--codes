#include <stdio.h>

// Define the states of the NFA as an enum
typedef enum {
    S, A, B, C, D  // states
} State;

int main() {
    // Initialize the current state to the start state S
    State current_state = S;

    // Read input string from user
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Loop through the input string and transition the NFA accordingly
    for (int i = 0; input[i] != '\0'; i++) {
        switch (current_state) {
            case S:
                if (input[i] == '1') {
                    current_state = A;
                }
                break;
            case A:
                if (input[i] == '1') {
                    current_state = B;
                } else {
                    current_state = S;
                }
                break;
            case B:
                if (input[i] == '0') {
                    current_state = C;
                } else {
                    current_state = S;
                }
                break;
            case C:
                if (input[i] == '0') {
                    current_state = D;
                } else {
                    current_state = S;
                }
                break;
            case D:
                // Stay in accepting state on any input
                break;
        }
    }

    // Check if we ended up in an accepting state
    if (current_state == D) {
        printf("string accepted", input);
    } else {
        printf("string rejected", input);
    }

    return 0;
}
