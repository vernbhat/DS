#include<stdio.h>
#include<stdlib.h>
int n=0;

typedef struct Node
{
    int info;
    struct Node * link;
} * node;

node create(node nn)
{
    nn=(node)malloc(sizeof(struct Node));
    printf("Enter info\n");
    scanf("%d",&nn->info);
    nn->link=NULL;
    n++;
    return nn;
}

node insertfront(node p)
{
    node nn;
    nn=create(nn);
    nn->link=p;
    return nn;
}

node insertrear(node p)
{
    node t=p,nn;
    nn=create(nn);
    if(p==NULL)
        return nn;
    while(t->link!=NULL)
        t=t->link;
    t->link=nn;
    return p;
}

void dis(node p)
{
    if(p==NULL)
    {
        printf("Empty\n");
        return;
    }
    printf("Displaying Nodes\n");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->link;
    }
    printf("\n");
}

node deletefront(node p)
{
    node nd=p;
    if(p==NULL)
        return p;
    n--;
    printf("Deleted is %d\n",p->info);
    p=p->link;
    free(nd);
    return p;
}

node deleterear(node p)
{
    node t=p,q=NULL;
    if(p==NULL)
        return p;
    n--;
    while(t->link!=NULL)
    {
        q=t;
        t=t->link;
    }
    printf("Deleted is %d\n",t->info);
    if(q==NULL)
    {
        free(p);
        return NULL;
    }
    q->link=NULL;
    free(t);
    return p;
}

int search(node p,int key)
{
    int i=1;
    node t=p;
    while(t!=NULL)
    {
        if(t->info==key)
            return i;
        t=t->link;
        i++;
    }
    return -1;
}

void sort(node p)
{
    node t;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        t=p;
        for(j=0;j<n-i-1;j++)
        {   if(t->info>t->link->info)
            {
                int temp=t->info;
                t->info=t->link->info;
                t->link->info=temp;
            }
            t=t->link;
        }
    }
}

node insertbyorder(node p)
{
    node nn,t=p,q=NULL;
    nn=create(nn);
    while(t!=NULL&&t->info<nn->info)
    {
        q=t;
        t=t->link;
    }
    if(q==NULL)
    {
        nn->link=p;
        return nn;
    }
    q->link=nn;
    nn->link=t;
    return p;

}

node insertbypos(node p,int pos)
{
    node t=p,q=NULL,nn;
    int i=1;
    nn=create(nn);
    while(t!=NULL&&i!=pos)
    {    
        q=t;
        i++;
        t=t->link;
    }
    if(q==NULL)
    {
        nn->link=p;
        return nn;
    }
    q->link=nn;
    nn->link=t;
    return p;
}

node deletebyele(node p)
{
    node t=p,q=NULL;
    int ele;
    printf("Enter the element to be deleted\n");
    scanf("%d",&ele);
    while(t!=NULL&&ele!=t->info)
    {
        q=t;
        t=t->link;
    }
    if(t==NULL)
    {
        printf("Element not found\n");
        return p;
    }
    n--;
    if(q==NULL)
        p=p->link;
    else
        q->link=t->link;
    printf("Deleted is %d\n",t->info);
    free(t);
    return p;
}

node deletebypos(node p,int pos)
{
    int i=1;
    node t=p,q=NULL;
    n--;
    while(i!=pos)
    {
        q=t;
        t=t->link;
        i++;
    } 
    if(pos==1)
        p=p->link;  
    else  
        q->link=t->link;
    printf("Deleted is %d\n",t->info);
    free(t);
    return p;
}

node reverse(node p)
{
    node t=NULL,r=NULL;
    while(p!=NULL)
    {
        t=p;
        p=p->link;
        t->link=r;
        r=t;
    }
    return r;
}

int main()
{
    node p=NULL;
    int ch,key,pos;
    while(1)
    {
        printf("\n1:Insert front\n2:Insert rear\n3:Display\n4:Delete front\n5:Delete rear\n6:Search\n7:Sort\n8:Insert by order\n9:Insert by position\n10:Delete by key\n11:Delete by position\n12:Reverse\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:p=insertfront(p);
                dis(p);
                break;
            case 2: p=insertrear(p);
                dis(p);
                break;
            case 3: dis(p);
                break;
            case 4:p=deletefront(p);
                dis(p);
                break;
            case 5:p=deleterear(p);
                dis(p);
                break;
            case 6:if(p==NULL)
                {
                    printf("Empty\n");
                    break;
                }
                printf("Enter the element to be searched\n");
                scanf("%d",&key);
                pos=search(p,key);
                if(pos==-1)
                    printf("%d is not found\n",key);
                else
                    printf("%d is found at %d position\n",key,pos);
                break;
            case 7:sort(p);
                printf("Sorting\n");
                dis(p);
                break;
            case 8:sort(p);
                p=insertbyorder(p);
                dis(p);
                break;
            case 9:printf("Enter the position\n");
                scanf("%d",&pos);
                if(pos>0&&pos<=n+1)
                {
                    p=insertbypos(p,pos);
                    dis(p);
                }
                else
                    printf("Invalid position\n");
                break;
            case 10:if(p==NULL)
                {
                    printf("Empty\n");
                    break;
                }
                p=deletebyele(p);
                dis(p);
                break;
            case 11:if(p==NULL)
                {
                    printf("Empty\n");
                    break;
                }
                printf("Enter the position\n");
                scanf("%d",&pos);
                if(pos>0&&pos<=n)
                {
                    p=deletebypos(p,pos);
                    dis(p);
                }
                else
                    printf("Invalid position\n");
                break;
            case 12:p=reverse(p);
                dis(p);
                break;
            default: exit(0);
        } 
    }  
    return 0;
}