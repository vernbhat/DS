#include <stdio.h>
#include <stdlib.h>
int size,n = 0;
void insert(int *a)
{
    if (n == size)
    {
        printf("Array full\n");
        return;
    }
    printf("Enter element\n");
    scanf("%d", &*(a + n));
    n++;
}
void dis(int *a)
{
    if (n == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Displaying\n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
}
int search(int *a, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (*(a + i) == key)
            return i + 1;
    }
    return -1;
}
void sort(int *a)
{
    int t, i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                t = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = t;
            }
        }
}
void insertbypos(int *a, int pos)
{
    int ele, i;
    printf("Enter the element\n");
    scanf("%d", &ele);
    for (i = n - 1; i >= pos - 1; i--)
        *(a + i + 1) = *(a + i);
    *(a + i + 1) = ele;
    n++;
}
void insertbyorder(int *a)
{
    int i, key;
    printf("Enter the element\n");
    scanf("%d", &key);
    for (i = n - 1; i >= 0 && *(a + i) > key; i--)
        *(a + i + 1) = *(a + i);
    *(a + i + 1) = key;
    n++;
}
void deletebypos(int *a, int pos)
{
    int i;
    printf("Deleted is %d\n", *(a + pos - 1));
    for (i = pos - 1; i < n; i++)
        *(a + i) = *(a + i + 1);
    n--;
}
void deletebykey(int *a)
{
    int i, key, j = -1;
    printf("Enter the element to be deleted\n");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (*(a + i) == key)
        {
            for (j = i; j < n; j++)
                *(a + j) = *(a + j + 1);
        }
    }
    if (j == -1)
        printf("Element not found\n");
    else
    {
        printf("Deleted is %d\n", key);
        n--;
    }
}
void reverse(int *a)
{
    int t, i, j = n - 1;
    for (i = 0; i < n / 2; i++)
    {
        t = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = t;
        j--;
    }
}
int main()
{
    int *a, ch, pos, key;
    printf("Enter the size\n");
    scanf("%d",&size);
    a = (int *)malloc(size * sizeof(int));
    while (1)
    {
        printf("\n1:Insert\n2:Display\n3:Search\n4:Sort\n5:Insert by pos\n6:Insert by order\n7:Delete by pos\n8:Delete by ele\n9:Reverse\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(a);
            dis(a);
            break;
        case 2:
            dis(a);
            break;
        case 3:
            printf("Enter the element to be searched\n");
            scanf("%d", &key);
            pos = search(a, key);
            if (pos == -1)
                printf("Element not found\n");
            else
                printf("Element found at pos %d\n", pos);
            break;
        case 4:
            if (n == 0 || n == 1)
                continue;
            else
                sort(a);
            dis(a);
            break;
        case 5:
            printf("Enter the pos to which element to be added\n");
            scanf("%d", &pos);
            if (pos > 0 && pos <= n + 1 && n < size)
                insertbypos(a, pos);
            else
                printf("Element cannot be added\n");
            dis(a);
            break;
        case 6:
            if (n < size)
                insertbyorder(a);
            else
                printf("Array full\n");
            dis(a);
            break;
        case 7:
            printf("Enter the position\n");
            scanf("%d", &pos);
            if (pos < 1 || pos > n || n == 0)
                printf("Element cannot be deleted\n");
            else
                deletebypos(a, pos);
            dis(a);
            break;
        case 8:
            if (n == 0)
                ;
            else
                deletebykey(a);
            dis(a);
            break;
        case 9:
            if (n == 0 || n == 1)
                continue;
            else
                reverse(a);
            dis(a);
            break;
        }
    }
}