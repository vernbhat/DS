#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define size 20

typedef struct stack
{
    float items[size];
    int top;
} st;

void push(char c, st *s)
{
    if (s->top == size - 1)
        return;
    s->top++;
    s->items[s->top] = c;
}

char pop(st *s)
{
    char c;
    if (s->top == -1)
        return;
    c = s->items[s->top];
    s->top--;
    return c;
}

float cal(float a, float b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '$':
    case '^':
        return pow(a, b);
    }
}

void evaluate(char po[])
{
    st s;
    float op1, op2, res;
    int i = 0;
    char c, op;
    s.top = -1;
    while ((c = po[i++]) != '\0')
    {
        if (isalnum(c))
            push(c - '0', &s);
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            res = cal(op1, op2, c);
            push(res, &s);
        }
    }
    res = pop(&s);
    if (s.top != -1)
    {
        printf("Invalid exp\n");
        return;
    }
    printf("Answer is %f\n", res);
}

int main()
{
    char po[20];
    printf("Enter in postfix manner :");
    scanf("%s", po);
    evaluate(po);
    return 0;
}