//nfa (i)
#include <stdio.h>

// Define the states of the NFA as an enum
typedef enum {
    S, A, B, C, D, // non-accepting states
    ACCEPT        // accepting state
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
                if (input[i] == '1') {
                    current_state = C;
                } else {
                    current_state = S;
                }
                break;
            case C:
                if (input[i] == '1') {
                    current_state = D;
                } else {
                    current_state = S;
                }
                break;
            case D:
                if (input[i] == '0') {
                    current_state = ACCEPT;
                } else {
                    current_state = S;
                }
                break;
            default:
                // If we reach an accepting state, we stay in that state
                // and continue reading the input until the end
                break;
        }
    }

    // Check if we ended up in an accepting state
    if (current_state == ACCEPT) {
        printf("Input string '%s' contains the substring '1110' so is accepted\n", input);
    } else {
        printf("Input string '%s' does not contain the substring '1110' so is rejected\n", input);
    }

    return 0;
}
