#include <stdio.h>

// Define the states
enum state {a, b, c, d};

// Define the outputs
enum output {x1, x2, x3};

// Define the transition function
enum state transition(enum state current_state, int input) {
    switch (current_state) {
        case a:
            if (input == 0) {
                return b;
            } else {
                return b;
            }
        case b:
            if (input == 0) {
                return b;
            } else {
                return d;
            }
        case c:
            if (input == 0) {
                return c;
            } else {
                return d;
            }
        case d:
            if (input == 0) {
                return d;
            } else {
                return d;
            }
        default:
            return a;
    }
}

// Define the output function
enum output output_function(enum state current_state) {
    switch (current_state) {
        case a:
            return x2;
        case b:
            return x1;
        case c:
            return x2;
        case d:
            return x3;
        default:
            return x1;
    }
}

int main() {
    enum state current_state = a;
    int input;
    enum output output;

    printf("Enter input (0 or 1):\n");
    scanf("%d", &input);

    current_state = transition(current_state, input);
    output = output_function(current_state);

    printf("Current state: %c\n", current_state + 'a');
    printf("Output: %c\n", output + 'x');

    return 0;
}
