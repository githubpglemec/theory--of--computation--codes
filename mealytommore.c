#include <stdio.h>
#define max 10

void main() {
    char str[max], state='A';
    int i;
    printf("Enter the string:");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++) // changed loop condition
    {
        switch(state)
        {
            case 'A':
                if(str[i]=='0')
                {
                    state='A';
                    // printf("C"); // removed unnecessary printf
                }
                else if(str[i]=='1')
                {
                    state='B';
                }
                break;
            case 'B':
                if(str[i]=='0')
                {
                    state='D';
                }
                else if(str[i]=='1')
                {
                    state='C';
                }
                break;
            case 'C': // added missing case
                if(str[i]=='0')
                {
                    state='A';
                }
                else if(str[i]=='1')
                {
                    state='B';
                }
                break;
            case 'D':
                state='A';
                break; // moved curly brace after break statement
        }
        if(state=='B')
        {
            printf("C");
        }
        else if(state=='D')
        {
            printf("A");
        }
        else if(state=='C')
        {
            printf("B");
        }
    }
}
