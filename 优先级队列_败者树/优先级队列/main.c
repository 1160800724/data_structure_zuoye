#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 50
typedef struct
{
    int key;
    int import;
    int counts;
}elementtype;
typedef struct asd
{
    elementtype element[maxsize];
    int n;
}*HEAP;
void MaxHeap(HEAP heap)
{
    heap->n=0;
}
bool HeapEmpty(HEAP heap)
{
    return (!heap->n);//��Ϊ1���ǿ�Ϊ0
}
bool HeapFull(HEAP heap)
{
    return (heap->n==maxsize-1);//����Ϊ1������Ϊ0
}
void Insert(HEAP heap,elementtype elementt,int *b)
{
    int i;

    if(!HeapFull(heap))
    {
        i=1+heap->n;
        while((i!=1)&&(elementt.import>heap->element[i/2].import))
        {
            heap->element[i]=heap->element[i/2];
            i=i/2;
        }
    }
    heap->element[i]=elementt;
    (*b)++;
    heap->element[i].counts=*b;
    heap->n++;
}
void DeleteMax(HEAP heap)
{
    int parent=1,child=2;
    elementtype tmp;
    if(!HeapEmpty(heap))
    {
        tmp=heap->element[heap->n--];

        while(child<=heap->n)
        {
            if((child<heap->n)&&(heap->element[child].import<heap->element[child+1].import))
                child++;
            if((heap->element[child].import==heap->element[child+1].import)&&(heap->element[child].counts>heap->element[child+1].counts))
                child=3;
            if(tmp.import>heap->element[child].import) break;
            heap->element[parent]=heap->element[child];
            parent=child;
            child*=2;
        }
        heap->element[parent]=tmp;
    }
}
int main()
{
    int *b=malloc(sizeof(int)),a=0,c=1;
    *b=0;
    elementtype ele;
    HEAP heap=malloc(sizeof(struct asd));
    MaxHeap(heap);
    while(c){
    printf("��������ѡ��Ĺ��ܣ�\n1����������\n2�����һ������\n3��������������\n");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        printf("������������\n");
        scanf("%d",&ele.key);
        printf("��������̵����ȼ�");
        scanf("%d",&ele.import);
        Insert(heap,ele,b);
        break;
    case 2:
        if(HeapEmpty(heap))
        {
            printf("��ǰ���������\n");
            break;
        }
        else
        {
           printf("����������Ϊ��%d\n",heap->element[1].key);
           DeleteMax(heap);
           break;
        }
    case 3:
        c=0;
    }
    }
    return 0;
}
