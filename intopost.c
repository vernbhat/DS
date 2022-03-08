#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 20

typedef struct stack
{
    int items[size];
    int top;
} st;

int stprec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 6;
    case '(':
        return 0;
    }
    return -1;
}

int inprec(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 7;
    case '(':
        return 8;
    case ')':
        return 0;
    }
    return -1;
}

void intopost(char in[], char po[])
{
    st s;
    int i = 0, j = 0;
    char c;
    s.top = -1;
    // for (int i = 0; i < strlen(in); i++)
    while ((c=in[i++])!='\0')
    {
        //c = in[i];
        if (isalnum(c))
            po[j++] = c;
        else
        {
            while (s.top != -1 && stprec(s.items[s.top]) > inprec(c))
            {
                if (c == ')')
                {
                    while (s.items[s.top] != '(')
                        po[j++] = s.items[s.top--];
                    s.top--;
                    break;
                }
                else
                    po[j++] = s.items[s.top--];
            }
            if (c != ')')
                s.items[++s.top] = c;
        }
    }
    while (s.top != -1)
        po[j++] = s.items[s.top--];
    po[j] = '\0';
}

int main()
{
    char in[20], po[20];
    printf("Enter infix expression\n");
    scanf("%s", in);
    // printf("infix is %s",in);
    intopost(in, po);
    printf("Postfix expression is %s\n", po);
    return 0;
}