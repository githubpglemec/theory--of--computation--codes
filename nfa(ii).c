// nfa 2
#include <stdio.h>

// Define the states of the NFA as an enum
typedef enum {
    S, A, B  // non-accepting and accepting states
} State;

int main() {
    int i;
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
                current_state = A;
                break;
            case A:
                current_state = B;
                break;
            default:
                // If we reach an accepting state, we stay in that state
                // and continue reading the input until the end
                break;
        }
    }

    // Check if we ended up in an accepting state
    if (current_state == B && i >= 1) {
        printf("string accepted", input);
    } else {
        printf("string rejected", input);
    }

    return 0;
}
