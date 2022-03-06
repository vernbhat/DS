#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define size 20

typedef struct stack
{
    char items[size];
    int top;
} st;

// void strrev(char c[],char a[])
// {
// 	int i=0,j=0;
// 	while(c[i]!='\0')
// 		i++;
// 	i--;
// 	while(i>=0)
// 	{
// 		a[j]=c[i];
// 		j++;
// 		i--;
// 	}
//    a[j]='\0';
// }

void push(char c, st *s)
{
    s->top++;
    s->items[s->top] = c;
}

char pop(st *s)
{
    char c = s->items[s->top];
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
    int i = strlen(po) - 1;
    char c, op;
    s.top = -1;
    while (i>=0)
    {
        c = po[i];
        if (isalnum(c))
            push(c - '0', &s);
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            res = cal(op1, op2, c);
            push(res, &s);
        }
        i--;
    }
    res = pop(&s);
    printf("Answer is %f\n", res);
}

int main()
{
    char po[20], c[20];
    printf("Enter in prefix manner :");
    scanf("%s", po);
    // strrev(po,c);
    // printf("%s\n",c);
    evaluate(po);
    return 0;
}