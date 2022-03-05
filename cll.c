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
    nn->link=nn;
    n++;
    return nn;
}

node insertfront(node p)
{
    node nn;
    nn=create(nn);
    if(p==NULL)
        return nn;
    nn->link=p->link;
    p->link=nn;
    return p;
}

node insertrear(node p)
{
    node t=p,nn;
    nn=create(nn);
    if(p==NULL)
        return nn;
    nn->link=p->link;
    p->link=nn;
    return nn;
}

void dis(node p)
{
    node t=p;
    if(p==NULL)
    {
        printf("Empty\n");
        return;
    }
    printf("Displaying Nodes\n");
    do{
        t=t->link;
        printf("%d ",t->info);
    } while(t!=p);
    printf("\n");
}

node deletefront(node p)
{
    node nd;
    if(p==NULL)
        return p;
    n--;
    nd=p->link;
    printf("Deleted is %d\n",nd->info);
    p->link=nd->link;
    free(nd);
    if(n==0)                   //n=1  (1-1=0)
        return NULL;
    return p;
}

node deleterear(node p)
{
    node t=p,q=NULL;
    if(p==NULL)
        return p;
    n--;
    do{
        q=t;
        t=t->link;
    } while(t!=p);
    printf("Deleted is %d\n",t->info);
    if(q==p)
    {
        free(p);
        return NULL;
    }
    q->link=p->link;
    free(t);
    return q;
}

int search(node p,int key)
{
    int i=1;
    node t=p->link;
    do {
        if(t->info==key)
            return i;
        t=t->link;
        i++;
    } while(t!=p->link);
    return -1;
}

void sort(node p)
{
    node t;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        t=p->link;
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
    node nn,t,q=p;
    nn=create(nn);
    if(p==NULL)
        return nn;
    t=p->link;
    do{
        if(t->info<nn->info)
        {
            q=t;
            t=t->link;
        }
        else
            break;
    } while (t!=p->link);
    q->link=nn;
    nn->link=t;
    if(p->info<nn->info)
        return nn;
    return p;
}

node insertbypos(node p,int pos)
{
    node t=p,q=NULL,nn;
    int i=1;
    nn=create(nn);
    if(pos==1&&n==1)
        return nn;
    if(pos==1)
    {
        nn->link=p->link;
        p->link=nn;
        return p;
    }
    t=t->link;
    do {    
        q=t;
        i++;
        t=t->link;
    } while(t!=p->link&&i!=pos);
    q->link=nn;
    nn->link=t;
    if(pos==n)                  //n is incremented in create function So here n means n+1th pos
        return nn;
    return p;
}

node deletebyele(node p)
{
    node t=p->link,q=p;
    int ele;
    printf("Enter the element to be deleted\n");
    scanf("%d",&ele);
    do{
        if(t->info!=ele)
        {
            q=t;
            t=t->link;
        }
        else 
            break;
    } while(t!=p);
    if(t->info!=ele)
    {
        printf("Element not found\n");
        return p;
    }
    n--;
    if(p->info==ele)
        p=q;
    q->link=t->link;
    printf("Deleted is %d\n",t->info);
    free(t);
    if(n==0)
        return NULL;
    return p;
}

node deletebypos(node p,int pos)
{
    int i=1;
    node t=p->link,q=p;
    n--;
    do {
        if(i!=pos)
        {
            q=t;
            t=t->link;
            i++;
        }
        else 
            break;
    } while(t!=p);
    if(pos==n+1)
        p=q; 
    q->link=t->link;
    printf("Deleted is %d\n",t->info);
    free(t);
    if(n==0)
        return NULL;
    return p;
}

node reverse(node p)
{
    node l,q,r;
    q=p->link;
    l=q->link;
    r=0;
    while(q!=p)
    {
        r=q;
        q=l;
        l=l->link;
        q->link=r;
    }
    l->link=q;
    return l;
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
            case 12:if(p==NULL)
                    break;
                p=reverse(p);
                dis(p);
                break;
            default: exit(0);
        } 
    }  
    return 0;
}