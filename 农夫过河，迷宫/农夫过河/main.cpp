#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

#define MAXSIZE 16
typedef int EntryType;
queue<int> q;


int farmer(int state)
{
    return ((state & 0x8) != 0);
}

int wolf(int state)
{
    return ((state & 0x4) != 0);
}

int cabbage(int state)
{
    return ((state & 0x2) != 0);
}

int goat(int state)
{
    return ((state & 0x1) != 0);
}

int is_safe(int state)//��ȫ����1������ȫ����0
{
    if((goat(state) == cabbage(state)) &&
        (goat(state) != farmer(state)))  // ���ͬ����ũ���ڳ�
        return(0);
    if((goat(state) == wolf(state)) &&
        (goat(state) != farmer(state)))  // ����ͬ����ũ���ڳ�
        return(0);
    return(1);
}

void river_crossing_problem()
{
    int route[16];           // ��¼�Ѿ����ǹ���״̬
    int state;               // ��¼��ǰʱ�̵�״̬��״̬��ŵĶ�������ʽ��״̬����
    int aftercross;          // ��¼���ǰ��ѡ�񣨶ɺӶ��󣩻ᵼ�µĽ��״̬
    int passenger;           // ��ʱ���������ڱ��ũ���ѡ�񣨶�Ӧ������λΪ1��ʾѡ�иó˿ͣ�

    int results[16]={0};     // ������
    int counter, i;

    q.push(0x00);

    for(int i = 0; i < 16; i++){
        route[i] = -1;
    }

    while((!q.empty()) /*&& (route[15] == -1)*/)
    {
        state=q.front();
        q.pop();
        for( passenger = 1; passenger<= 8; passenger <<= 1 )
        {
            if(((state & 0x08) != 0) == ((state & passenger) != 0)){
                aftercross = state^( 0x08|passenger );
                if(is_safe(aftercross) && (route[aftercross] == -1)){//route[after]!=-1��Ϊ�˱�֤�����ظ������Ѿ����й��Ĳ���
                    // ����ɺӺ�״̬��ȫ������״̬���
                    route[aftercross] = state;  // ����ǰ״̬��������¼��·�������У��±�����Ϊ����״ֵ̬��
                    q.push(aftercross);
                }
            }
        }
    }

    // ������Ӳ��ԣ�0��ʾ�ڶ��� 1��ʾ����������ʼ״̬Ϊ0000����ֹ״̬Ϊ1111
    if(route[15] != -1)
    {
        counter = 0;
        for(state = 15; state != 0; state = route[state]){
            results[counter] = state;
            counter++;
        }

        for(i = 0; i< counter; i++){
            state= results[i];
            aftercross = results[i+1];
            if(state & 0x08){
                cout<<"ũ����ϰ�������:";
            }
            else{
                cout<<"ũ��ӱ������ϰ�:";
            }
            switch(state^aftercross ){
            case 12:
                cout<<"���Ǵ�����"<<endl;
                break;
            case 10:
                cout<<"�Ѳ˴�����"<<endl;
                break;
            case 9:
                cout<<"���������"<<endl;
                break;
            default:
                cout<<"ʲôҲ����"<<endl;
                break;
            }
        }
    }
}

int main(void)
{
    river_crossing_problem();
    system("pause");
    return 0;
}
