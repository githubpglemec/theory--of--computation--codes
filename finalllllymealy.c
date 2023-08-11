#include <stdio.h>
#include <string.h>

enum State {
    STATE_A,
    STATE_B,
    STATE_C,
    STATE_D
};

int main() {
    char input[100];
    enum State state = STATE_A;
    printf("Enter input string: ");
    scanf("%s", input);
    int len = strlen(input);
    if (len < 2) {
        printf("Input string is too short\n");
        return 0;
    }
    for (int i = 0; i < len; i++) {
        switch (state) {
            case STATE_A:
                if (input[i] == 'a') {
                    state = STATE_B;
                    printf("0");
                } else if (input[i] == 'b') {
                    state = STATE_C;
                    printf("0");
                }
                break;
            case STATE_B:
                if (input[i] == 'a') {
                    state = STATE_D;
                    printf("1");
                } else {
                    state = STATE_A;
                    printf("0");
                }
                break;
            case STATE_C:
                if (input[i] == 'b') {
                    state = STATE_D;
                    printf("1");
                } else {
                    state = STATE_A;
                    printf("0");
                }
                break;
            case STATE_D:
                state = STATE_A;
                printf("1");
                break;
        }
    }
    printf("\n");
    return 0;
}
