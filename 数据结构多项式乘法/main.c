#include <stdio.h>
#include <stdlib.h>
struct polynode
{
    double coef;
    int exp;
    struct polynode * link;
};
char compare(int a,int b)
{
    if (a==b)
    {
        return '=';
    }
    else if (a>b)
    {
        return '>';
    }
    else
    {
        return '<';
    }
}
typedef struct polynode * polypointer;
polypointer attach (float c,int e,polypointer d)
{
    polypointer x;
    x=(polypointer)malloc(sizeof(struct polynode));
    x->coef=c;
    x->exp=e;
    d->link=x;
    return x;
}
polypointer polyadd(polypointer a,polypointer b)
{
    polypointer p,q,d,c;
    int x;
    p=a->link;q=b->link;
    c=(polypointer)malloc(sizeof(struct polynode));d=c;
    while ((p!=NULL)&&(q!=NULL))
    {

        switch(compare(p->exp,q->exp))
               {
               case '=':
                x=p->coef+q->coef;
                if(x!=0)
                {
                    d=attach(x,p->exp,d);
                }
                p=p->link;q=q->link;
                break;
               case '>':
                d=attach(p->coef,p->exp,d);
                p=p->link;
                break;
               case '<':
                d=attach(q->coef,q->exp,d);
                q=q->link;
                break;
               }
    }
               while (p!=NULL)
               {
                   d=attach(p->coef,p->exp,d);
                   p=p->link;
               }
               while (q!=NULL)
               {
                   d=attach(q->coef,q->exp,d);
                   q=q->link;
               }
               d->link=NULL;
               return c;
}
polypointer multi(polypointer a,polypointer b)
{
    polypointer c,d,e,h,re;
    double x=0;
    int y=0;
    re=(polypointer)malloc(sizeof(struct polynode));
    re->coef=0;re->exp=0;re->link=NULL;
    c=a->link;
    while (c!=NULL)
    {
        d=b->link;
        e=(polypointer)malloc(sizeof(struct polynode));
        h=e;
        while(d!=NULL)
        {
             x=(c->coef)*(d->coef);
             y=(c->exp)+(d->exp);
             e=attach (x,y,e);//e->link��ʼ��ֵ
             d=d->link;
        }
        c=c->link;
        re=polyadd(h,re);
    }
    return re;
}
void print(polypointer a)
{
    polypointer b;
    int fl=1;
    b=a->link;
    while(b!=NULL)
    {
        if(fl==1){
        printf("%lfx^%d",b->coef,b->exp);
        }
        else{
        printf("+%lfx^%d",b->coef,b->exp);
        }
        b=b->link;
        fl++;
    }
}
int main()
{
    struct polynode *A,*B,*x,*y,*f;
    double a;
    int b;
    A=(polypointer)malloc(sizeof(struct polynode));
    B=(polypointer)malloc(sizeof(struct polynode));
    x=A;y=B;
    printf("�밴���ݴ��ɸߵ��͵�˳��ֱ��������ʽA���������ϵ��Ϊ0ʱ���������\n");
    while (1)
    {
        printf("���������ʽ��ϵ����");
        scanf("%lf",&a);
        if (a==0)
        {
            printf("�������������ʽΪ��\n");
            print(A);
            break;
        }
        printf("���������ʽ���ݴ�");
        scanf("%d",&b);
        x=attach (a,b,x);
    }
    x->link=NULL;
    printf("\n�밴���ݴ��ɸߵ��͵�˳��ֱ��������ʽB���������ϵ��Ϊ0ʱ���������\n");
    while (1)
    {
        printf("���������ʽ��ϵ����");
        scanf("%lf",&a);
        if (a==0)
        {
            printf("�������������ʽΪ��\n");
            print(B);
            printf("\n");
            break;
        }
        printf("���������ʽ���ݴ�:");
        scanf("%d",&b);
        y=attach (a,b,y);
    }
    y->link=NULL;
    f=multi(A,B);
    printf("(");
    print(A);
    printf(")");
    printf("*");
    printf("(");
    print(B);
    printf(")");
    printf("=");
    print(f);
    return 0;
}
