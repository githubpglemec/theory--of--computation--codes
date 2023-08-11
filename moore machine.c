#include <stdio.h>
#include <string.h>

enum State {
    STATE_A,
    STATE_B,
    STATE_C
};

int main() {
    char input[100];
    char output[100] = "";
    enum State state = STATE_A;
    printf("Enter input string: ");
    scanf("%s", input);
    int len = strlen(input);
    if (len < 2) {
        printf("Input string is too short\n");
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (i >= 2 && input[i-2] == '1' && input[i-1] == '0') {
            state = STATE_B;
        } else if (i >= 2 && input[i-2] == '1' && input[i-1] == '1') {
            state = STATE_C;
        } else {
            state = STATE_A;
        }
        switch (state) {
            case STATE_A:
                strcat(output, "c");
                break;
            case STATE_B:
                strcat(output, "a");
                break;
            case STATE_C:
                strcat(output, "b");
                break;
        }
    }
    printf("Output: %s\n", output);
    return 0;
}
