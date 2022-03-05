#include<string.h>
#include <stdio.h>
#define size 5
struct queue 
{
    int id[size];
    int priority[size];
    char name[10][size];
    int f,r,cnt;
};
typedef struct queue que; 
void enqueue(que *);
void disp(que );
void descend(que *);
void ascend(que *);
int main()
{
    int ch;
    que q;
    q.f=0;
    q.r=-1;
    q.cnt=0;
    while(1)
    {
         printf("\n1.enqueue\n2.asce de\n3.descend pri\nenter ur choice\n");
            scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue(&q);
                    disp(q);
                    break;
            case 2:ascend(&q);
                    disp(q);
                    break;
            case 3:descend(&q);
                    disp(q);
                    break;
        }
    }
    return 0;
}
void enqueue(que *q)
{
    int id,priority,j;
    char name[10];
    if(q->cnt==size)
    {
        printf("fulll\n");
        return;
    }
    else
    {
        printf("enter the job id\n");
            scanf("%d",&id);
        printf("enter the job priority\n");
            scanf("%d",&priority);
        printf("enter the job name\n");
            scanf("%s",name);
        j=q->r;
         while(j>=0 && priority<q->priority[j])
        {
            q->priority[j+1]=q->priority[j];
            q->id[j+1]=q->id[j];
            strcpy(q->name[j+1],q->name[j]);
            j--;
        }
        q->priority[j+1]=priority;
        q->id[j+1]=id;
        strcpy(q->name[j+1],name);
        q->r++;
        q->cnt++;
    }
}
void disp(que q)
{
    int i=0,j=0;
    if(q.cnt==0 )
    {
        printf("empty\n");
        return;
        
    }
    else
    {
        printf("job id\tjob name\tjob priority\n");
        for(i=q.f;i<=q.r;i++)
            printf("%d\t%s\t\t%d\n",q.id[i],q.name[i],q.priority[i]);
    }
}
void ascend(que *q)
{
    if(q->cnt==0)
    {
        printf("empty\n");
        return;
    }
    else
    {
        printf("deleted %s job\n",q->name[q->f]);
        q->f++;
        q->cnt--;
    }
}
void descend(que *q)
{
    if(q->cnt==0)
    {
        printf("empty\n");
        return;
    }
    else
    {
        printf("deleted %s job\n",q->name[q->r]);
        q->r--;
        q->cnt--;
    }
}