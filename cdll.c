#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *llink;
    struct Node *rlink;
} * node;

node create(node nn)
{
    nn = (node)malloc(sizeof(struct Node));
    printf("Enter info\n");
    scanf("%d", &nn->info);
    nn->llink = nn->rlink = nn;
    return nn;
}

void insertfront(node h)
{
    node nn = create(nn);
    nn->rlink = h->rlink;
    h->rlink = nn;
    nn->llink = h;
    nn->rlink->llink = nn;
    h->info++;
}

void insertrear(node h)
{
    node nn = create(nn);
    nn->llink = h->llink;
    nn->rlink = h;
    h->llink = nn;
    nn->llink->rlink = nn;
    h->info++;
}

void dis(node h)
{
    node tp = h;
    if (h->info == 0)
    {
        printf("Empty\n");
        return;
    }
    tp = tp->rlink;
    printf("Displaying\n");
    while (tp != h)
    {
        printf("%d ", tp->info);
        tp = tp->rlink;
    }
    printf("\n");
}

void deletefront(node h)
{
    node nd;
    if (h->info == 0)
        return;
    nd = h->rlink;
    printf("Deleted is %d\n", nd->info);
    h->rlink = nd->rlink;
    nd->rlink->llink = h;
    free(nd);
    h->info--;
}

void deleterear(node h)
{
    node nd = h->llink;
    if (h->info == 0)
        return;
    printf("Deleted is %d\n", nd->info);
    nd->llink->rlink = h;
    h->llink = nd->llink;
    h->info--;
    free(nd);
}

int search(node h, int key)
{
    node tp = h->rlink;
    for (int i = 0; i < h->info; i++)
    {
        if (tp->info == key)
            return (i + 1);
        tp = tp->rlink;
    }
    return -1;
}

void sort(node h)
{
    node tp;
    int i, j, temp;
    for (i = 0; i < h->info - 1; i++)
    {
        tp = h->rlink;
        for (j = 0; j < h->info - i - 1; j++)
        {
            if (tp->info > tp->rlink->info)
            {
                temp = tp->info;
                tp->info = tp->rlink->info;
                tp->rlink->info = temp;
            }
            tp = tp->rlink;
        }
    }
}

void insertbypos(node h, int pos)
{
    node tp = h->rlink;
    node nn = create(nn);
    int i = 1;
    while (i != pos)
    {
        tp = tp->rlink;
        i++;
    }
    tp->llink->rlink = nn;
    nn->llink = tp->llink;
    nn->rlink = tp;
    tp->llink = nn;
    h->info++;
}

void insertbyorder(node h)
{
    node tp = h->rlink;
    node nn = create(nn);
    while (tp != h && nn->info > tp->info)
        tp = tp->rlink;
    tp->llink->rlink = nn;
    nn->llink = tp->llink;
    nn->rlink = tp;
    tp->llink = nn;
    h->info++;
}

void deletebykey(node h, int key)
{
    node tp = h->rlink, q;
    while (tp != h)
    {
        if (tp->info == key)
            break;
        tp = tp->rlink;
    }
    if (tp == h)
    {
        printf("Element not found\n");
        return;
    }
    q = tp->llink;
    q->rlink = tp->rlink;
    tp->rlink->llink = q;
    printf("Deleted is %d\n", tp->info);
    free(tp);
    h->info--;
}

void deletebypos(node h, int pos)
{
    node nd = h->rlink, tp = h;
    int i = 1;
    while (i != pos)
    {
        tp = nd;
        nd = nd->rlink;
        i++;
    }
    tp->rlink = nd->rlink;
    nd->rlink->llink = tp;
    printf("Deleted is %d\n", nd->info);
    free(nd);
    h->info--;
}

void reverse(node h)
{
    node tp = h->rlink, ln = h->llink;
    int temp;
    for (int i = 0; i < h->info / 2; i++)
    {
        temp = tp->info;
        tp->info = ln->info;
        ln->info = temp;
        tp = tp->rlink;
        ln = ln->llink;
    }
}

int main()
{
    node h = (node)malloc(sizeof(struct Node));
    int ch, pos, key;
    h->info = 0;
    h->llink = h->rlink = h;
    while (1)
    {
        printf("\n1:Insert front\n2:Insert rear\n3:Display\n4:Delete front\n5:Delete rear\n6:Search\n7:Sort\n8:Insert by pos\n9:Insert byorder\n10:Delete by ele\n11:Delete by pos\n12:Reverse\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertfront(h);
            dis(h);
            break;
        case 2:
            insertrear(h);
            dis(h);
            break;
        case 3:
            dis(h);
            break;
        case 4:
            deletefront(h);
            dis(h);
            break;
        case 5:
            deleterear(h);
            dis(h);
            break;
        case 6:
            if (h->info == 0)
                break;
            printf("Enter the key\n");
            scanf("%d", &key);
            pos = search(h, key);
            if (pos == -1)
                printf("Element not found\n");
            else
                printf("Element is found at %d pos\n", pos);
            break;
        case 7:
            if (h->info == 0 || h->info == 1)
            {
                dis(h);
                break;
            }
            sort(h);
            dis(h);
            break;
        case 8:
            printf("Enter the position\n");
            scanf("%d", &pos);
            if (pos > 0 && pos <= h->info + 1)
            {
                insertbypos(h, pos);
                dis(h);
            }
            else
                printf("Invalid position\n");
            break;
        case 9:
            sort(h);
            insertbyorder(h);
            dis(h);
            break;
        case 10:
            if (h->info == 0)
            {
                printf("Empty\n");
                break;
            }
            printf("Enter the element to be deleted\n");
            scanf("%d", &key);
            deletebykey(h, key);
            dis(h);
            break;
        case 11:
            if (h->info == 0)
            {
                printf("Empty");
                break;
            }
            printf("Enter pos\n");
            scanf("%d", &pos);
            if (pos > 0 && pos <= h->info)
            {
                deletebypos(h, pos);
                dis(h);
            }
            else
                printf("Invalid position\n");
            break;
        case 12:
            if (h->info == 0 || h->info == 1)
            {
                dis(h);
                break;
            }
            reverse(h);
            dis(h);
            break;
        default:
            exit(0);
        }
    }
}