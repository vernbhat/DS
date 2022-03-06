#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int rno;
    char name[10];
    int m[3];
    float avg;
} std;

void getDetails(int n, std *s)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter the reg no. of student %d\n", i + 1);
        scanf("%d", &(s + i)->rno);
        printf("Enter the name\n");
        scanf("%s", (s + i)->name);
        printf("Enter the marks in sub 1\n");
        scanf("%d", &(s + i)->m[0]);
        printf("Enter the marks in sub 2\n");
        scanf("%d", &(s + i)->m[1]);
        printf("Enter the marks in sub 3\n");
        scanf("%d", &(s + i)->m[2]);
    }
}

void calAvg(int n, std *s)
{
    int min;
    int i, j;
    for (i = 0; i < n; i++)
    {
        min = (s + i)->m[0];
        for (j = 0; j < 3; j++)
        {
            if (min > (s + i)->m[j])
                min = (s + i)->m[j];
        }
        int total = (s + i)->m[0] + (s + i)->m[1] + (s + i)->m[2];
        (s + i)->avg = (total - min) / 2.0;
    }
}

void dis(int n, std *s)
{
    printf("Reg_No\tName\tS1_Marks\tS2_Marks\tS3_Marks\tAverage\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%f\n", (s + i)->rno, (s + i)->name, (s + i)->m[0], (s + i)->m[1], (s + i)->m[2], (s + i)->avg);
    printf("\n");
}

int main()
{
    std *s;
    int ch, n;
    printf("Enter the size\n");
    scanf("%d", &n);
    s = (std *)malloc(n * sizeof(struct student));
    for (;;)
    {
        printf("1:Enter details\n2:Calculate average\n3:Display\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            getDetails(n, s);
            break;
        case 2:
            calAvg(n, s);
            break;
        case 3:
            dis(n, s);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}