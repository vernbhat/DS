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

void push(opr *s, char c)
{
    s->top++;
    s->items[s->top] = c;
}

void push1(opn *s, char c[])
{
    s->top++;
    strcpy(s->items[s->top], c);
}

char pop(opr *s)
{
    char c = s->items[s->top--];
    return c;
}

char *pop1(opn *s)
{
    char *c = s->items[s->top--];
    return c;
}

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

void par(opr *optr,opn *opnd)
{
    char op,t[2],exp[20],*op1,*op2;
    op=pop(optr);
    t[0]=op;
    t[1]='\0';
    op2=pop1(opnd);
    op1=pop1(opnd);
    strcpy(exp,t);
    strcat(exp,op1);
    strcat(exp,op2);
    push1(opnd,exp);
}

void inpre(char in[],char pre[])
{
    char t[2],c;
    int i=0;
    opn s1;
    opr s;
    s.top=-1;
    s1.top=-1;
    while((c=in[i++])!='\0')
    {
        if(isalnum(c))
        {
            t[0]=c;
            t[1]='\0';
            push1(&s1,t);
        }
        else
        {
            while(s.top!=-1&&stprec(s.items[s.top])>inprec(c))
            {
                if(c==')')
                {
                    while(s.items[s.top]!='(')
                        par(&s,&s1);
                    pop(&s);
                    break;
                }
                else par(&s,&s1);
            }
            if(c!=')')
                push(&s,c);
        }
    }
    while(s.top!=-1)
        par(&s,&s1);
    strcpy(pre,s1.items[s1.top]);
}

int main()
{
    char in[20],pre[20];
    printf("Enter the infix exp: ");
    scanf("%s",in);
    inpre(in,pre);
    printf("Prefix exp : %s\n",pre);
    return 0;
}