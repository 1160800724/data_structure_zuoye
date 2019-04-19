#include<iostream>

using namespace std;
#define k 8

typedef  int Losertree[k];
struct exnode{
int key;
};

typedef exnode External[k+1];


void Adjust(Losertree &ls,int s,External &b){
int t=(s+k)/2;
while(t>0){
    if(b[s].key>b[ls[t]].key){//sָ���µ�ʤ�ߣ���ls[t]ָ�����
        int tem=s;
        s=ls[t];
        ls[t]=tem;

    }
    t/=2;//���ϼ����Ƚ�

}

ls[0]=s;

}

void Create_losertree(Losertree &ls,External &b){
for(int i=0;i!=k;++i){//����ls���ߵĳ�ֵ��Ϊk�� kλ�õĹؼ����Ѿ�����Ϊ��-1��
    ls[i]=k;
}
for(int i=0;i!=k;++i){//һ�δӴ洢���һ���ؼ��ʿ�ʼ���е���
    Adjust(ls,i,b);
}
}







void k_merge(Losertree &ls,External &b,int r[8][4])
{
    for(int i=0;i!=k;++i){//�Ƚ����鲢�εĵ�һ���ؼ��֣�����洢����
        b[i].key=r[i][0];
    }
    b[k].key=-1;//����һ����Сֵ����Ϊ����������ʱ�ã�
    Create_losertree(ls,b);
    int next0=1,next1=1,next2=1,next3=1,next4=1,next5=1,next6=1,next7=1;
    while(b[ls[0]].key!=1000){//��1000������ʱ��˵���鲢�Ѿ����
        int q=ls[0];
        cout<<b[q].key<<"  ";//���һ����ѡ�����Ĺؼ���
    switch (q){ //q��¼����С�ؼ������ڵĹ鲢�Σ�Ȼ�������鲢���ж�����һ���ؼ��֣�
    case 0:
        b[q].key=r[q][next0];
        ++next0;
        break;
    case 1:
        b[q].key=r[q][next1];
        ++next1;
        break;
    case 2:
        b[q].key=r[q][next2];
        ++next2;
        break;
    case 3:
        b[q].key=r[q][next3];
        ++next3;
         break;
    case 4:
        b[q].key=r[q][next4];
        ++next4;
        break;
    case 5:
        b[q].key=r[q][next5];
        ++next5;
        break;
    case 6:
        b[q].key=r[q][next6];
        ++next6;
        break;
    case 7:
        b[q].key=r[q][next7];
        ++next7;
        break;

    }
    Adjust(ls,q,b);//�ٽ��е�����




    }



}

int main()
{

int r[8][4]={
10,15,16,1000,
9,20,38,1000,
20,20,30,1000,
6,15,25,1000,
8,15,50,1000,
9,11,16,1000,
90,100,110,1000,
17,18,20,1000
};

Losertree ls;
External b;
cout<<"�鲢�ηֱ�Ϊ��"<<endl<<"R1:10,15,16"<<endl<<"R2:9,20,38"<<endl<<"R3:20,20,30"<<endl<<"R4:6,15,25"<<endl
<<"R5:8,15,50"<<endl<<"R6:9,11,16"<<endl<<"R7:90,100,110"<<endl<<"R8:7,18,20"<<endl<<"�İ����������������Ϊ��"<<endl;
k_merge(ls,b,r);





return 0;
}
