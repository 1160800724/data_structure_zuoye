#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct line
{
    char name[20];
    char brand[20];
    float price;
    int num;
    struct line *next;
};
typedef struct line LINE;
LINE * struct_line();
void output();
void increase_new_shopping(LINE *lin);
void decrease_old_shopping(LINE *lin);
void update_shopping(LINE *lin);
void lookfor_the_infomation(LINE *lin);
void shengxupailie(LINE *lin);

int cnt=1;//��¼�ڵ�

void output_bin(LINE* lin)
{
    LINE *pr=lin;
    FILE* fp;
    if((fp=fopen("E:\\shangpin.bin","wb"))==NULL)
    {
        printf("Failure to open shangpin.bin!\n");
        return;
    }
    fputc(cnt,fp);
    while(pr!=NULL)
    {
        fwrite(pr,sizeof(LINE),1,fp);
        pr=pr->next;
    }
}

void input_bin(LINE*lin)
{
    LINE *pr=lin;
    FILE* fp;
    if((fp=fopen("E:\\shangpin.bin","rb"))==NULL)
    {
        printf("Failure to open shangpin.bin!\n");
        return;
    }
    cnt=fgetc(fp);
    int i;
    for(i=0;i<cnt;i++)
    {
        fread(pr,sizeof(LINE),1,fp);
        LINE *l=malloc(sizeof(LINE));
        pr->next=l;
        pr=l;
    }
}


int main()
{
    int a;
    LINE *lin=malloc(sizeof(LINE));
    do
    {
        output();
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            lin=struct_line();
            break;
        case 2:
            increase_new_shopping(lin);
            break;
        case 3:
            decrease_old_shopping(lin);
            break;
        case 4:
            update_shopping(lin);
            break;
        case 5:
            lookfor_the_infomation(lin);
            break;
        case 6:
            shengxupailie(lin);
            break;
        case 7:
            output_bin(lin);
            break;
        case 8:
            input_bin(lin);
            break;
        }

    }while(a>=0);
    return 0;
}
void output()
{
    printf("��ѡ����Ҫ���еĲ�����\n");
    printf("1����ʼ�������µ����ݱ��\n");
    printf("2���������е���Ʒ����\n");
    printf("3��ɾ�����е���Ʒ����\n");
    printf("4�����������������Ʒ��Ϣ\n");
    printf("5��������Ʒ���Ʋ�ѯ�����Ʒ��Ϣ\n");
    printf("6��������Ʒ�۸��������������\n");
    printf("7������Ӫҵ����������Ϣ�����ļ�\n");
    printf("8����ʼӪҵ�����ļ��ж�������\n");
    printf("-1���������������\n");
}
LINE * struct_line()//�Ա�ͷ��ʼ��
{
    LINE *lines=malloc(sizeof(LINE));
    lines->brand;
    lines->name;
    lines->num=0;
    lines->price=0;
    lines->next=NULL;
    return lines;
}
void increase_new_shopping(LINE *lin)//��������Ʒ���ಢ��������
{
    LINE *l=malloc(sizeof(LINE));
    printf("����������Ʒ���ƣ�\n");
    scanf("%s",&l->name);
    printf("����������ƷƷ�ƣ�\n");
    scanf("%s",&l->brand);
    printf("����������Ʒ������\n");
    scanf("%d",&l->num);
    printf("����������Ʒ�۸�\n");
    scanf("%f",&l->price);
    l->next=lin->next;
    lin->next=l;
    cnt++;
}
void decrease_old_shopping(LINE *lin)
{
    char a[12];
    LINE *l=lin;
    printf("��������Ҫɾ���Ļ������ƣ�\n");
    scanf("%s",a);
    while (l->next!=NULL)
    {
        if (strcmp(a,l->next->name)==0)
        {
            l->next=l->next->next;
            free(l->next);
            break;
        }
        l=l->next;
        if (l->next==NULL)
        {
            printf("��Ʒ�б�Ϊ�ջ��б����޴���Ʒ\n");
            break;
        }
    }
}
void update_shopping(LINE *lin)
{
    LINE *l=lin;
    int b;
    char *a=NULL;
    printf("������Ҫ���µ���Ʒ�����ƣ�\n");
    gets(a);
    while(l->next!=NULL)
    {
        if (a==l->next->name)
        {
            b=l->num;
            printf("��������Ʒ����������\n");
            scanf("%d",&l->num);
            if(l->num<0)
            {
                printf("�������������\n");
                l->num=b;
            }
            break;
        }
        l=l->next;
        if (l->next==NULL)
        {
            printf("�б����޴���Ʒ��\n");
            break;
        }
    }
}
void lookfor_the_infomation(LINE *lin)
{
    char *a=malloc(20*sizeof(char));
    LINE *l=lin;
    printf("������Ҫ��ѯ����Ʒ���ƣ�\n");
    scanf("%s",a);
    while (l->next!=NULL)
    {
        if(strcmp(a,l->next->name)==0)
        {
            printf("��Ʒ������Ϊ��%s\n",l->next->name);
            printf("��Ʒ��Ʒ��Ϊ��%s\n",l->next->name);
            printf("��Ʒ�ļ۸�Ϊ��%f\n",l->next->price);
            printf("ʣ����Ʒ������Ϊ��%d\n",l->next->num);
            break;
        }
        l=l->next;
        if(l->next==NULL)
        {
            printf("�ֿ����޴���Ʒ����Ʒ�����������\n");
            break;
        }
    }
    free(l);
}
void shengxupailie(LINE *lin)
{
    LINE *start=malloc(sizeof(LINE));
    LINE *tail=malloc(sizeof(LINE));
    LINE *a=malloc(sizeof(LINE));
    tail=lin;
    start->next=lin;
    while(tail->next!=NULL)
    {
        LINE *min=tail->next,*p=tail->next->next;
        while(p!=NULL)
        {
            if(p->price<min->price)
                min=p;
            p=p->next;
        }
        strcpy(a->brand,min->brand);
        strcpy(a->name,min->name);
        a->num=min->num;
        a->price=min->price;
        strcpy(min->brand,tail->next->brand);//min->brand=tail->next->brand;
        strcpy(min->name,tail->next->name);//min->name=tail->next->name;
        min->num=tail->next->num;
        min->price=tail->next->price;
        strcpy(tail->next->brand,a->brand);//tail->next->brand=a->brand;
        strcpy(tail->next->name,a->name);//tail->next->name=a->name;
        tail->next->num=a->num;
        tail->next->price=a->price;
        tail=tail->next;
    }
    lin=start->next;
    free(start);
}





