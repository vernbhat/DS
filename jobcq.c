#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 6
struct Queue
{
   int id[size];
   char name[10][size];
   int time[size];
   int f, r;
   int cnt;
};

typedef struct Queue QUE;
void Insert( QUE *);
void Delete(QUE *);
void Disp(QUE *);


int main()
{
  int ch;
  QUE Q;
  Q.f= 0; Q.r = -1;  Q.cnt=0;
  for(;;)
  {
    printf("Enter choice:\n1:Insert\n2:Delete\n3:Display\n");
    scanf("%d", &ch);
    switch(ch)
    {
       case 1: Insert(&Q);break;
       case 2:  Delete(&Q); break;
       case 3:   Disp(&Q); break;
       default:  exit(0);
    }
  }
  return 0;
}
void Insert(QUE *Q)
{
  int id,time;
  char name[10];
  if(Q->cnt==size)
  {
    printf("Queue Full\n");
    return;
  }
  printf("Enter job id:");
  scanf("%d", &id);
  printf("Enter job name:");
  scanf("%s", name);
  printf("Enter time required:");
  scanf("%d", &time);
  Q->r= (Q->r+1)%size ;
  Q->id[Q->r] = id;
  strcpy(Q->name[Q->r] , name);
  Q->time[Q->r] = time;
  Q->cnt++;
 }
 void Delete(QUE *Q)
 {
   if(Q->cnt==0)
   {
      printf("Queue Empty\n");
      return;
   }
   printf("Deleted Job id : %d\n",Q->id[Q->f]);
   Q->f= (Q->f+1)%size;
   Q->cnt--;
 }

 void Disp(QUE *Q)
 {  int i,j;
    if(Q->cnt==0)
    {
      printf("Queue Empty\n");
      return;
    }   
    j=Q->f;
    printf("Job_Id\tJob_Name\tTime_Required\n");
    for(i=1; i<=Q->cnt; i++)
    {
      printf("%d\t%s\t\t%d\n", Q->id[j],Q->name[j],Q->time[j]);
      j=(j+1)%size;
    }

 }