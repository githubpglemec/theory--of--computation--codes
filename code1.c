#include<stdio.h>
#define max 30
int main()
{
    char str[max], state = 'a';
    int i;
    printf("Enter the string");
    scanf("%s",str);
    for(i=1; str[i]!='\0'; i++)
    {
        switch (state)
        {
        case 'a':
            if(str[i]=='0')
                state = 'b';
            else if(str[i]=='1')
                state = 'a';
            break;

        case 'b':
            if(str[i]=='0')
                state = 'b';
            else if(str[i]=='1')
                state = 'c';
            break;

        case 'c':
            if(str[i]=='0')
                state = 'b';
            else if(str[i]=='1')
                state = 'a';
            break;
        default:
            break;
        }
    }
    if(state == 'c')
        printf("Input string is accepted as reached to final state: %c\n",state);
    else
        printf("Rejected final state:%c",state);
}
