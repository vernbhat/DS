#include <stdio.h>
#include <stdlib.h>
typedef struct Queue
{
    int size;
    int *items;
    int f, r, count;
} que;
void enqueue(que *q)
{
    int item, i;
    if (q->count == q->size)
    {
        printf("Queue is full\n");
        return;
    }
    printf("Enter item\n");
    scanf("%d", &item);
    q->r++;
    for (i = q->count - 1; item < q->items[i]; i--)
        q->items[i + 1] = q->items[i];
    q->items[i + 1] = item;
    q->count++;
}
void dequeue(que *q)
{
    if (q->count == 0)
        return;
    printf("Deleted is %d\n", q->items[q->f]);
    q->f++;
    if (q->f > q->r)
    {
        q->r = -1;
        q->f = 0;
    }
    q->count--;
}
void dis(que *q)
{
    int i = 1, j = q->f;
    if (q->count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    while (i <= q->count)
    {
        printf("%d ", q->items[j]);
        j++;
        i++;
    }
    printf("\n");
}
int main()
{
    int ch;
    que q;
    printf("Enter the size\n");
    scanf("%d", &q.size);
    q.items = (int *)malloc(q.size * sizeof(que));
    q.r = -1;
    q.f = 0;
    q.count = 0;
    while (1)
    {
        printf("\n1:Enqueue\n2:Dequeue\n3:Display\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(&q);
            dis(&q);
            break;
        case 2:
            dequeue(&q);
            dis(&q);
            break;
        case 3:
            dis(&q);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}