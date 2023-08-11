#include<stdio.h>
#include<string.h>

// Function to perform leftmost derivation
void leftmostDerivation(char *input, int length) {
    printf("Leftmost Derivation:\n");
    int i = 0;
    printf("A");
    while (i < length) {
        if (input[i] == 'a') {
            printf("->aA");
            i++;
        } else if (input[i] == 'l') {
            printf("->λ");
            i++;
        }
    }
    printf("\n");
}

// Function to perform rightmost derivation
void rightmostDerivation(char *input, int length) {
    printf("Rightmost Derivation:\n");
    int i = length - 1;
    printf("A");
    while (i >= 0) {
        if (input[i] == 'a') {
            printf("->aA");
            i--;
        } else if (input[i] == 'l') {
            printf("->λ");
            i--;
        }
    }
    printf("\n");
}

int main() {
    char input[100];

    printf("Enter the input string: ");
    scanf("%s", input);

    int length = strlen(input);

    leftmostDerivation(input, length);
    rightmostDerivation(input, length);

    return 0;
}
