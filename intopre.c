#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define size 20

typedef struct stack1
{
    char items[size];
    int top;
} opr;

typedef struct stack2
{
    char items[10][size];
    int top;
} opn;

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
}

void push( char c, opr *s)
{
    if(s->top ==size-1)
        printf("stack full\n");
    else
        s->top++;
    s->items[s->top] = c;
}

char pop(opr *s)
{
    char c;
    if(s->top ==-1)
        printf("stack empty\n");
    else
        c = s->items[s->top];
    s->top--;
    return c;
}

void push1( char c[], opn *s)
{
    if(s->top ==size-1)
        printf("stack full\n");
    else
        s->top++;
    strcpy(s->items[s->top], c);
    
}

char* pop1(opn *s)  //   char[]
{
    char *c; //    char c[10]
    if(s->top ==-1)
    {
        printf("stack empty\n");
	}
    else
        c = s->items[s->top];   // strcpy(c, s->item[s->top])
    s->top--;
    return c;   // return c;
}

void par(opr *optr, opn *opnd)
{
    char t[2], exp[20], *op1, *op2, op;
    op = pop(optr);
    t[0] = op;
    t[1] = '\0';
    op2 = pop1(opnd);
    op1 = pop1(opnd);
    strcpy(exp, t);
    strcat(exp, op1);
    strcat(exp, op2);
    push1(exp, opnd);
}

void intopre(char in[], char pre[])
{
    opr s;
    opn s1;
    char c,temp[2];
    int i=0;
    s.top = -1;
    s1.top=-1;
    while((c =in[i++]) !='\0')
    {
        if(isalnum(c))
        {
            temp[0]= c;    //  pos[j++]= c
            temp[1]='\0';
            push1(temp,&s1);
        }
        else
        {
            while(s.top != -1 && stprec(s.items[s.top]) > inprec(c))
            {
                if(c ==')')
                {
                    while(s.items[s.top] !='(')
                        par(&s,&s1);
                    // po[j++] = pop(&s);
                    pop(&s);// s.top--
                    break;
                }
                else
                    par(&s,&s1); // po[j++] = pop(&s);
            }
            if(c!=')')
                push(c,&s);
        }
    }
    while(s.top !=-1)
        par(&s,&s1); //po[j++] = pop(&s);
    // printf("Prefix :%s\n", s1.item[s1.top]);
    strcpy(pre, s1.items[s1.top]);
}

int main()
{
    char in[20], pre[20];
    printf("Enter infix expression\n");
    scanf("%s", in);
    intopre(in, pre);
    printf("Prefix expression : %s\n", pre);
    return 0;
}