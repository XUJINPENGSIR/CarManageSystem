#include<windows.h>  
#include<iostream>  
#include<fstream>  
#include<iomanip>  
#include<conio.h>
#include<string>  
using namespace std;  
#define N 20          //�������洢��20  
#define OilPrice 8.0  //�ͼ�8Ԫÿ��  
class Manager;  
class Cars  
{  
private:  
    int num;        //���  
    string pnum;       //���ƺ�  
    char made[20];  //���칫˾  
    double time;    //����ʱ�䣨���ٸ��£�  
    int type;       //�ͺ�(1-��ͳ�,2-С�γ�,3-����)  
    double km;      //�ܹ�����  
    int cost;       //����ά������  
    int RoadFee;    //��·��  
    double OilKm;   //������/����  
    double AllCount;//�ۼ��ܷ���  
    friend Manager;  
};  
class Manager  
{  
private:  
    Cars car[N];  
    int people[N];  //����ؿ�������ͳ���  
    int coach[N];   //������С�γ���  
    int weight[N];  //��������������  
    int top;        //��¼��ǰ��������  
public:  
    Manager(){top = 0;}//������ʼֵΪ0  
    void add();     //��ӳ���  
    void search();  //��ѯ����  
    void show();    //��ʾ������Ϣ��  
    void edit();    //�༭����  
    void delet();   //ɾ������  
    void sum();     //ͳ����Ϣ  
    void read();    //����������Ϣ  
    void write();   //������Ϣ����  
    void jiemian(); //�ܽ���  
};  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::add()         //////////��ӳ���  
{  
    int a = 0, x, y;  
    while(1)  
    {  
        if(top < N)  
        {  
            cout<<"����������ӵĳ�����Ϣ"<<endl;  
            cout<<"������ţ�";  
            cin>>x;  
            for(int j = 0; j < top; j++)  
            {  
                if ( car[j].num == x )     //����ظ�  
                {  
                    cout<<"����ظ�,���ʧ��! ������ת������������"<<endl;  
                    a++;  
                    break;  
                }  
            }  
            if(a == 0)     //��ʱ��Ų��ظ�  
            {   
                car[top].num = x;  
                cout<<"���ƺţ�";  
                cin>>car[top].pnum;  
                cout<<"�������칫˾��";  
                cin>>car[top].made;  
                cout<<"����ʱ�䣺";  
                cin>>car[top].time;  
                cout<<"��·�ѣ�";  
                cin>>car[top].RoadFee;  
                cout<<"�����ͺ�(1-��ͳ�,2-С�γ�,3-����)��";  
                cin>>car[top].type;  
                while(!(car[top].type==1||car[top].type==2||car[top].type==3)) //�ж�����ָ���Ƿ�Ϊ1-3  
                {  
                    cout<<"����ָ��Ŵ���,���䣺";  
                    cin>>car[top].type;  
                }  
                cout<<"�ܹ�������";  
                cin>>car[top].km;  
                if( car[top].type == 1 )    //��ʱ��1-��ͳ�  
                {  
                    cout<<"����ؿ�����";  
                    cin>>people[top];  
                    car[top].cost = 2000;  
                    car[top].OilKm = 0.1;  
                }  
                else if( car[top].type == 2 )   //��ʱ��2-С�γ�  
                {  
                    cout<<"��������";  
                    cin>>coach[top];  
                    car[top].cost = 1000;  
                    car[top].OilKm = 0.05;  
                }  
                else                            //��ʱ��3-����  
                {  
                    cout<<"��������";  
                    cin>>weight[top];  
                    car[top].cost = 1500;  
                    car[top].OilKm = 0.15;  
                }  
                car[top].AllCount =(OilPrice * car[top].OilKm * car[top].km) + (car[top].time *car[top].cost);  //�����ܷ���  
                top++;        //����������һ  
                write();      //���ó�����Ϣ���̺���  
                cout<<"�Ƿ������ӳ�����(1-��,2-��)��";  
                cin>>y;  
                while(!( y==1 || y==2 ))  
                {  
                    cout<<"����ָ��Ŵ�������:";  
                    cin>>y;  
                }  
                if(y == 2)  
                {  
                    cout<<"������ת������������"<<endl;  
                    break;  
                }  
            }  
            else       //��ʱ����ظ�  
                break;  
        }  
        else  
        {  
            cout<<"������Ϣ������,��������ӳ���!"<<endl;  
            cout<<"������ת������������"<<endl;  
            break;  
        }  
    }  
Sleep(1000);   //�ӳ�1��  
jiemian();  //���ý��溯��
}  
  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::search()        //////////��ѯ����  
{  
    int choose,m,n,a = 0;  
    char i,t[20];  
    cout<<"****************************"<<endl;  
    cout<<"*  1.���������칫˾��ѯ    *"<<endl;  
    cout<<"*  2.����Ų�ѯ            *"<<endl;  
    cout<<"*  3.������ѯ            *"<<endl;  
    cout<<"****************************"<<endl;  
    cout<<" ���������ѡ�";  
    while(1)  
    {  
        cin>>i;  
        cout<<endl;  
        if(i=='1'||i=='2'||i=='3')  
            break;  
        cout<<"�������,���䣺";  
    }  
    if(i == '1')  
    {cout<<"���������ѯ���������칫˾��";  
        cin>>t;}  
    else if(i == '2')  
    {cout<<"���������ѯ�ĳ�����ţ�";  
        cin>>n;}  
    else if(i == '3')  
    {cout<<"���������ѯ�ĳ����ͺ�(1-��ͳ�,2-С�γ�,3-����)��";  
        cin>>m;}  
    for(int j = 0; j < top; j++)  
        if(strcmp(car[j].made, t) == 0||car[j].num == n||car[j].type == m)  
        {cout<<"��� ���ƺ� ������ ����ʱ��  �ͺ�     ����   �ܹ��� ��·�� ά����  �ͺ�  �ܷ���"<<endl;break;}  
    for( j = 0; j < top; j++)  
        if(strcmp(car[j].made, t) == 0||car[j].num == n||car[j].type == m)   
        {  
            cout<<setw(4)<<car[j].num<<setw(7)<<car[j].pnum<<setw(7)<<car[j].made<<setw(7)<<car[j].time;  
            if(car[j].type == 1 )  
                cout<<setw(9)<<"��ͳ�"<<setw(8)<<"�ؿ���:"<<people[j];  
            else if(car[j].type == 2 )  
                cout<<setw(9)<<"С�γ�"<<setw(9)<<"������: "<<coach[j];  
            else  
                cout<<setw(8)<<"�� ��"<<setw(9)<<"������:"<<weight[j];  
            cout<<setw(6)<<car[j].km<<setw(7)<<car[j].RoadFee<<setw(7)<<car[j].cost<<setw(7)<<car[j].OilKm<<setw(8)<<car[j].AllCount<<endl;  
            a++;  
        }  
    if(a != 0)  
    {  
        cout<<"�Ƿ�����޸�?(1-��,2-��)��";  
        cin>>choose;  
        if(choose == 1)  
        edit();  
    }  
    else  
    {  
        if(i=='1') cout<<"�������칫˾�����ڣ�"<<endl;  
        if(i=='2') cout<<"������Ų����ڣ�"<<endl;  
        else if (i=='3') cout<<"�����ͺŲ����ڣ�"<<endl;  
    }  
    cout<<"����������ع���������"<<endl;  
    char zz=getch();  
    jiemian();  
}  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::show()         //////////��ʾ������Ϣ��  
{  
    if(top != 0)  
    {  
        cout<<"********************************************************************************"<<endl;  
        cout<<"��� ���ƺ� ������ ����ʱ��  �ͺ�     ����   �ܹ��� ��·�� ά����  �ͺ�  �ܷ���"<<endl;  
  
        for(int j = 0; j < top; j++)  
        {  
            cout<<setw(4)<<car[j].num<<setw(7)<<car[j].pnum<<setw(7)<<car[j].made<<setw(7)<<car[j].time;  
            if(car[j].type == 1 )  
               cout<<setw(9)<<"��ͳ�"<<setw(8)<<"�ؿ���:"<<setw(2)<<people[j];  
            else if(car[j].type == 2 )  
               cout<<setw(9)<<"С�γ�"<<setw(8)<<"������:"<<setw(2)<<coach[j];  
            else  
               cout<<setw(9)<<"�� �� "<<setw(8)<<"������:"<<setw(2)<<weight[j];  
            cout<<setw(6)<<car[j].km<<setw(7)<<car[j].RoadFee<<setw(7)<<car[j].cost<<setw(7)<<car[j].OilKm<<setw(8)<<car[j].AllCount<<endl;  
        }  
        cout<<"********************************************************************************"<<endl;  
    }  
    else  
        cout<<"������Ϊ�գ�"<<endl;   
    cout<<"�����������������:";  
    char z=getch();  
    jiemian();  
}  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::edit()         ////////////�༭����  
{  
    int i, j, a = 0;  
    cout<<"������������Ҫ�޸ĵĳ�����Ϣ��"<<endl;  
    while(1)  
    {  
        cout<<"������ţ�";  
        cin>>i;  
        for(j = 0; j < top; j++)  
        {  
            if(car[j].num == i)  //�����д˱�ŵĳ�  
            {  
                cout<<"���ƺţ�";  
                cin>>car[j].pnum;  
                cout<<"���칫˾��";  
                cin>>car[j].made;  
                cout<<"����ʱ�䣺";  
                cin>>car[j].time;  
                cout<<"�ͺ�(1-��ͳ���2-С�γ���3-����)��";  
                cin>>car[j].type;  
                while(!(car[j].type==1||car[j].type==2||car[j].type==3))  
                {  
                    cout<<"������Ϣ����������1-3��";  
                    cin>>car[j].type;  
                }  
                cout<<"�ܹ�������";  
                cin>>car[j].km;  
                cout<<"��·�ѣ�";  
                cin>>car[j].RoadFee;  
                if( car[j].type == 1 )    //��ʱ��1-��ͳ�  
                {  
                    cout<<"����ؿ�����";  
                    cin>>people[j];  
                    car[j].cost = 2000;  
                    car[j].OilKm = 0.1;  
                }  
                else if( car[j].type == 2 )   //��ʱ��2-С�γ�  
                {  
                    cout<<"��������";  
                    cin>>coach[j];  
                    car[j].cost = 1000;  
                    car[j].OilKm = 0.05;  
                }  
                else     //��ʱ��3-����  
                {  
                    cout<<"��������";  
                    cin>>weight[j];  
                    car[j].cost = 1500;  
                    car[j].OilKm = 0.15;  
                }  
                write();  
                a++;  
            }  
        }  
        if(a == 0)  
            cout<<"�˱�Ų����ڣ����ܽ����޸ģ����������룡"<<endl;  
        else  
        {  
            cout<<"�޸ĳɹ���ϵͳ������������..."<<endl;  
            break;  
        }  
    }  
Sleep(1000);   //�ӳ�1��  
jiemian();  
}  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::delet()        //////////////////ɾ������  
{  
    int i, a = 0;  
    while(1)  
    {  
        if(top == 0)  
        {  
            cout<<"������Ϣ��Ϊ�գ�ϵͳ�����ع��ܽ���..."<<endl;  
            break;  
        }  
        else  
        {  
            cout<<"��������Ҫɾ���ĳ�����ţ�";  
            cin>>i;  
            for(int j = 0; j < top; j++)  
            {  
                if(car[j].num == i)   //������Ŵ���  
                {  
                    if(top==1)  
                        car[0].type=0;  
                    else  
                    {  
                        if( car[top - 1].type == 1 )    //�жϳ���ʱcar�����ﴢ�������һ�����1-��ͳ�  
                        {  
                            people[j] = people[top - 1];///////// �� �����һ������ �� ///////  
                            car[j].cost = 2000;         ///////// �� ������Ҫɾ���� �� ///////  
                            car[j].OilKm = 0.1;       ///////// �� �������ݵ�λ�� �� ///////  
                        }  
                        else if(car[top - 1].type == 2 )    //�жϳ���ʱcar�����ﴢ�������һ�����2-С�γ�  
                        {  
                            coach[j] = coach[top - 1];    
                            car[j].cost = 1000;     
                            car[j].OilKm = 0.05;  
                        }  
                        else   //�жϳ���ʱcar�����ﴢ�������һ�����3-����  
                        {  
                            weight[j] = weight[top - 1];  
                            car[j].cost = 1500;  
                            car[j].OilKm = 0.15;  
                        }  
                        car[j].num = car[top - 1].num;          ///////// �� �����  �� ///////  
                        car[j].pnum = car[top - 1].pnum;        ///////// �� һ����  �� ///////  
                        strcpy(car[j].made, car[top - 1].made); ///////// �� �ݸ���  �� ///////  
                        car[j].time = car[top - 1].time;        ///////// �� ��Ҫɾ  �� ///////  
                        car[j].type = car[top - 1].type;        ///////// �� ������  �� ///////  
                        car[j].km = car[top - 1].km;            ///////// �� ������  �� ///////  
                        car[j].RoadFee = car[top - 1].RoadFee;  ///////// �� ��λ��  �� ///////  
                        car[j].AllCount = car[top-1].AllCount;  ///////// ��         �� ///////  
                    }  
                    top--;   //��ʱɾ���������ݳ�����ɣ�����������һ  
                    a++;  
                    write();  
                }  
            }  
            if(a == 0)  
                cout<<"�˱�Ų����ڣ����ܽ���ɾ�������������룡"<<endl;  
            else  
            {  
                cout<<"ɾ���ɹ���ϵͳ�����ع��ܽ���..."<<endl;  
                break;  
            }  
        }  
    }  
Sleep(1000);   //�ӳ�1��  
jiemian();  
}  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::write()        //////////////////������Ϣ����  
{  
    ofstream write;  
    write.open("d:\\a.txt",ios::out);  
    if(write)  
    {  
        for(int i = 0; i < top; i++)  
        {//���δ���  ���   ��     ���ƺ�     ��    ������     ��    ����ʱ��      ��    �ͺ�     ��   
            write<<endl;  
        write<<car[i].num<<" "<<car[i].pnum<<" "<<car[i].made<<" "<<car[i].time<<" "<<car[i].type<<" ";  
        if(car[i].type == 1)  
            write<<people[i];//����   �ؿ���  
        else if(car[i].type == 2)  
            write<<coach[i];//����    ������  
        else  
            write<<weight[i];//����    ������   
        //���δ���  �ܹ���   ��    ��·��      ��      ά����      ��    �ͺ�      ��     �ܷ���  
        write<<" "<<car[i].km<<" "<<car[i].RoadFee<<" "<<car[i].cost<<" "<<car[i].OilKm<<" "<<car[i].AllCount;  
        }  
    }  
    else cout<<"write failed"<<endl;  
}  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::read()            ///////////////////����������Ϣ  
{  
    while(1)  
    {  
        ifstream read("d:\\a.txt",ios::in);  
        if(read)  
        {  
            while(!read.eof())  
            {//���ζ�ȡ    ���   ��     ���ƺ�    ��   ������    ��  ����ʱ��    ��   �ͺ�  
                read>>car[top].num>>car[top].pnum>>car[top].made>>car[top].time>>car[top].type;  
                if(car[top].type == 1)  
                    read>>people[top];//��ȡ   �ؿ���  
				else if(car[top].type == 2)  
                    read>>coach[top];//��ȡ    ������  
                else  
                    read>>weight[top];//��ȡ    ������   
               //���ζ�ȡ   �ܹ���   ��   ��·��   ��    ά����    ��   �ͺ�    ��   �ܷ���  
                read>>car[top].km>>car[top].RoadFee>>car[top].cost>>car[top].OilKm>>car[top].AllCount;  
                if(car[top].type==1||car[top].type==2||car[top].type==3)  
                    top++;  
            }  
            read.close();  
            break;  
        }  
        else   
        {  
            ofstream o("d:\\a.txt");  
            o.close();  
        }  
    }  
}  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::jiemian()            ////////////////�ܽ���  
{  
    int c1=0,c2=0,c3=0;  
    top=0;  
    read();  
    system("cls");  
    for(int j = 0; j < top; j++)  
        if( car[j].type == 1 )c1++;      //ͳ�ƴ�ͳ�������  
        else if(car[j].type == 2)c2++;      //ͳ��С�γ�������  
        else if(car[j].type==3)c3++;      //ͳ�ƿ���������  
    top=c1+c2+c3;  
    cout<<"***********************************"<<endl;  
    cout<<"*        ��ӭ���복������ϵͳ     *"<<endl;  
    cout<<"*            1.��ӳ���           *"<<endl;  
    cout<<"*            2.��ѯ����           *\t\t�ܳ���\t"<<top<<endl;  
    cout<<"*            3.��ʾ����           *\t\t��ͳ�\t"<<c1<<endl;  
    cout<<"*            4.�༭����           *\t\tС�γ�\t"<<c2<<endl;  
    cout<<"*            5.ɾ������           *\t\t�� �� \t"<<c3<<endl;  
    cout<<"*            0.�˳�ϵͳ           *"<<endl;  
    cout<<"***********************************"<<endl;  
    cout<<"����������Ҫ������ѡ��:";  
    char i;  
    cin>>i;  
    while(!(i=='1'||i=='2'||i=='3'||i=='4'||i=='5'||i=='0'))  
    {  
        cout<<"�������,����������:";  
        char i=getch();  
        cout<<endl;  
    }  
  
    switch(i)  
    {  
    case '1':add();break;  
    case '2':search();break;  
    case '3':show();break;  
    case '4':edit();break;  
    case '5':delet();break;  
    case '0':return;  
    }  
}  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
int main()  
{    
    system("color 4a");  
    Manager a;  
    a.jiemian();  
	system("pause");
    return 0;  
}  
