#include <stdio.h>

// Define the states of the PDA
enum State {
    Q0, // Initial state
    Q1, // Reads 'a' and pushes 'X' onto the stack
    Q2, // Reads 'b' and doesn't push or pop
    Q3, // Reads 'c' and pops 'X' from the stack
    Q4, // Reads 'c' and doesn't push or pop
    Q5  // Final state
};

// Function to check if the input string belongs to L
void checkLanguage(char input[]) {
    // Initialize the PDA
    enum State currentState = Q0;
    int stackTop = -1;

    // Process each character of the input string
    for (int i = 0; input[i] != '\0'; i++) {
        char currentChar = input[i];

        // Perform transitions based on the current state and input symbol
        switch (currentState) {
            case Q0:
                if (currentChar == 'a') {
                    currentState = Q1;
                    stackTop++;
                } else {
                    printf("Rejected!\n");
                    return;
                }
                break;
            case Q1:
                if (currentChar == 'a') {
                    currentState = Q1;
                    stackTop++;
                } else if (currentChar == 'b') {
                    currentState = Q2;
                } else {
                    printf("Rejected!\n");
                    return;
                }
                break;
            case Q2:
                if (currentChar == 'b') {
                    currentState = Q2;
                } else if (currentChar == 'c') {
                    currentState = Q3;
                    stackTop--;
                } else {
                    printf("Rejected!\n");
                    return;
                }
                break;
            case Q3:
                if (currentChar == 'c') {
                    currentState = Q3;
                    stackTop--;
                } else {
                    printf("Rejected!\n");
                    return;
                }
                break;
            default:
                printf("Rejected!\n");
                return;
        }
    }

    // Check if the PDA has reached the final state and the stack is empty
    if (currentState == Q3 && stackTop == -1) {
        printf("Accepted!\n");
    } else {
        printf("Rejected!\n");
    }
}

int main() {
    char input[100];

    printf("Enter an input string: ");
    scanf("%s", input);

    checkLanguage(input);

    return 0;
}
