#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define N 5    //������
using namespace std;


typedef struct node1
{
    int bgn;
    int end;
    double weight;
}Edge[N*(N-1)/2+1];
int n_edge=N*(N-1)/2;

//��������
typedef struct node2
{
    int v;//�������
    int x;//���������
    int y;//����������
}Vertex[N];
bool Graph[N][N]={0};
void path(Vertex ver)//ȫ�ֱ�����N��5 ���Ա���ֻ������5�����꣬Ҫ��ֱ�Ӱ�N���˾���
{
    cout<<"�밴����˳�����붥������ֵ"<<endl;
    int key;
    for(int i=0;i<N;i++){
        ver[i].v=i;
        cin>>key;
        ver[i].x=key;
        cin>>key;
        ver[i].y=key;
    }
}
void DataError(int a)
{
    if(a>1000||a<0)
    {
        cout<<"���ݴ��󣡣�0<=x,y<=1000��"<<endl;
        exit(0);
    }
}

//�߸�ֵ
void EnWeight(Edge &edg,Vertex ver)
{
    int k=0;
    for(int i=0;i<N;i++)
    {//ͷΪi
        for(int j=0;j<i;j++)
        {//βΪj
            edg[k].bgn=ver[i].v;
            edg[k].end=ver[j].v;
            edg[k].weight=sqrt(pow(ver[i].x-ver[j].x,2)+pow(ver[i].y-ver[j].y,2));
            k++;
        }
    }
}
bool cmp(node1 a,node1 b)
{
    return a.weight<b.weight;
}
//����
void Range(Edge &edg)
{
    sort(edg,edg+n_edge,cmp);
}

int Find(int father[],int f)
{
    while(father[f]>-1)  f=father[f];
    return f;
}
double Kruskal(Edge edg)
{
    int father[n_edge],bnf,edf,i,linked=0;
    double sum=0;
    for(i=0;i<n_edge;i++)   father[i]=-1;
    for(i=0;i<n_edge&&linked<N-1;i++)
    {
        if(edg[i].weight>=1000)
        {
            cout<<"no!"<<endl;
            exit(0);
        }
        bnf=Find(father,edg[i].bgn);
        edf=Find(father,edg[i].end);
        if(bnf!=edf)
        {
            father[bnf]=edf;
            linked++;
            if(edg[i].weight>=10)
            {//��Ҫ����
                sum+=edg[i].weight;
                Graph[edg[i].bgn][edg[i].end]=true;
            }
        }
    }
    return sum;
}
int main()
{
    Edge edg;
    Vertex ver;
    double sum;
    path(ver);
    EnWeight(edg,ver);//����Ȩֵ�������
    Range(edg);//����
    sum=Kruskal(edg);
    sum*=100;
    cout<<"���Ų������£�"<<endl;
    for(int i=0;i<N;i++)
        for(int j=0;j<i;j++)
            if(Graph[i][j])
                printf("(%d,%d)-(%d,%d)\n",ver[i].x,ver[i].y,ver[j].x,ver[j].y);
    cout<<"�����Ϊ��"<<sum<<endl;
    return 0;
}
