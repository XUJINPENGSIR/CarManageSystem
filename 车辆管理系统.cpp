#include<windows.h>  
#include<iostream>  
#include<fstream>  
#include<iomanip>  
#include<conio.h>
#include<string>  
using namespace std;  
#define N 20          //车辆最大存储量20  
#define OilPrice 8.0  //油价8元每升  
class Manager;  
class Cars  
{  
private:  
    int num;        //编号  
    string pnum;       //车牌号  
    char made[20];  //制造公司  
    double time;    //购买时间（多少个月）  
    int type;       //型号(1-大客车,2-小轿车,3-卡车)  
    double km;      //总公里数  
    int cost;       //基本维护费用  
    int RoadFee;    //养路费  
    double OilKm;   //耗油量/公里  
    double AllCount;//累计总费用  
    friend Manager;  
};  
class Manager  
{  
private:  
    Cars car[N];  
    int people[N];  //最大载客量（大客车）  
    int coach[N];   //箱数（小轿车）  
    int weight[N];  //载重量（卡车）  
    int top;        //记录当前车辆数量  
public:  
    Manager(){top = 0;}//车辆初始值为0  
    void add();     //添加车辆  
    void search();  //查询车辆  
    void show();    //显示车辆信息库  
    void edit();    //编辑功能  
    void delet();   //删除车辆  
    void sum();     //统计信息  
    void read();    //读出车辆信息  
    void write();   //车辆信息存盘  
    void jiemian(); //总界面  
};  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::add()         //////////添加车辆  
{  
    int a = 0, x, y;  
    while(1)  
    {  
        if(top < N)  
        {  
            cout<<"请输入需添加的车辆信息"<<endl;  
            cout<<"车辆编号：";  
            cin>>x;  
            for(int j = 0; j < top; j++)  
            {  
                if ( car[j].num == x )     //编号重复  
                {  
                    cout<<"编号重复,添加失败! 即将跳转至功能主界面"<<endl;  
                    a++;  
                    break;  
                }  
            }  
            if(a == 0)     //此时编号不重复  
            {   
                car[top].num = x;  
                cout<<"车牌号：";  
                cin>>car[top].pnum;  
                cout<<"车辆制造公司：";  
                cin>>car[top].made;  
                cout<<"购买时间：";  
                cin>>car[top].time;  
                cout<<"养路费：";  
                cin>>car[top].RoadFee;  
                cout<<"车辆型号(1-大客车,2-小轿车,3-卡车)：";  
                cin>>car[top].type;  
                while(!(car[top].type==1||car[top].type==2||car[top].type==3)) //判断输入指令是否为1-3  
                {  
                    cout<<"输入指令号错误,重输：";  
                    cin>>car[top].type;  
                }  
                cout<<"总公里数：";  
                cin>>car[top].km;  
                if( car[top].type == 1 )    //此时是1-大客车  
                {  
                    cout<<"最大载客量：";  
                    cin>>people[top];  
                    car[top].cost = 2000;  
                    car[top].OilKm = 0.1;  
                }  
                else if( car[top].type == 2 )   //此时是2-小轿车  
                {  
                    cout<<"车厢数：";  
                    cin>>coach[top];  
                    car[top].cost = 1000;  
                    car[top].OilKm = 0.05;  
                }  
                else                            //此时是3-卡车  
                {  
                    cout<<"载重量：";  
                    cin>>weight[top];  
                    car[top].cost = 1500;  
                    car[top].OilKm = 0.15;  
                }  
                car[top].AllCount =(OilPrice * car[top].OilKm * car[top].km) + (car[top].time *car[top].cost);  //计算总费用  
                top++;        //车辆总数加一  
                write();      //调用车辆信息存盘函数  
                cout<<"是否继续添加车辆？(1-是,2-否)：";  
                cin>>y;  
                while(!( y==1 || y==2 ))  
                {  
                    cout<<"输入指令号错误，重输:";  
                    cin>>y;  
                }  
                if(y == 2)  
                {  
                    cout<<"即将跳转至功能主界面"<<endl;  
                    break;  
                }  
            }  
            else       //此时编号重复  
                break;  
        }  
        else  
        {  
            cout<<"车辆信息库已满,不能再添加车辆!"<<endl;  
            cout<<"即将跳转至功能主界面"<<endl;  
            break;  
        }  
    }  
Sleep(1000);   //延迟1秒  
jiemian();  //调用界面函数
}  
  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::search()        //////////查询车辆  
{  
    int choose,m,n,a = 0;  
    char i,t[20];  
    cout<<"****************************"<<endl;  
    cout<<"*  1.按车辆制造公司查询    *"<<endl;  
    cout<<"*  2.按编号查询            *"<<endl;  
    cout<<"*  3.按类别查询            *"<<endl;  
    cout<<"****************************"<<endl;  
    cout<<" 请输入你的选项：";  
    while(1)  
    {  
        cin>>i;  
        cout<<endl;  
        if(i=='1'||i=='2'||i=='3')  
            break;  
        cout<<"输入错误,重输：";  
    }  
    if(i == '1')  
    {cout<<"请输入需查询车辆的制造公司：";  
        cin>>t;}  
    else if(i == '2')  
    {cout<<"请输入需查询的车辆编号：";  
        cin>>n;}  
    else if(i == '3')  
    {cout<<"请输入需查询的车辆型号(1-大客车,2-小轿车,3-卡车)：";  
        cin>>m;}  
    for(int j = 0; j < top; j++)  
        if(strcmp(car[j].made, t) == 0||car[j].num == n||car[j].type == m)  
        {cout<<"编号 车牌号 制造商 购买时间  型号     特性   总公里 养路费 维护费  油耗  总费用"<<endl;break;}  
    for( j = 0; j < top; j++)  
        if(strcmp(car[j].made, t) == 0||car[j].num == n||car[j].type == m)   
        {  
            cout<<setw(4)<<car[j].num<<setw(7)<<car[j].pnum<<setw(7)<<car[j].made<<setw(7)<<car[j].time;  
            if(car[j].type == 1 )  
                cout<<setw(9)<<"大客车"<<setw(8)<<"载客量:"<<people[j];  
            else if(car[j].type == 2 )  
                cout<<setw(9)<<"小轿车"<<setw(9)<<"车厢数: "<<coach[j];  
            else  
                cout<<setw(8)<<"卡 车"<<setw(9)<<"载重量:"<<weight[j];  
            cout<<setw(6)<<car[j].km<<setw(7)<<car[j].RoadFee<<setw(7)<<car[j].cost<<setw(7)<<car[j].OilKm<<setw(8)<<car[j].AllCount<<endl;  
            a++;  
        }  
    if(a != 0)  
    {  
        cout<<"是否进行修改?(1-是,2-否)：";  
        cin>>choose;  
        if(choose == 1)  
        edit();  
    }  
    else  
    {  
        if(i=='1') cout<<"车辆制造公司不存在！"<<endl;  
        if(i=='2') cout<<"车辆编号不存在！"<<endl;  
        else if (i=='3') cout<<"车辆型号不存在！"<<endl;  
    }  
    cout<<"按任意键返回功能主界面"<<endl;  
    char zz=getch();  
    jiemian();  
}  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::show()         //////////显示车辆信息库  
{  
    if(top != 0)  
    {  
        cout<<"********************************************************************************"<<endl;  
        cout<<"编号 车牌号 制造商 购买时间  型号     特性   总公里 养路费 维护费  油耗  总费用"<<endl;  
  
        for(int j = 0; j < top; j++)  
        {  
            cout<<setw(4)<<car[j].num<<setw(7)<<car[j].pnum<<setw(7)<<car[j].made<<setw(7)<<car[j].time;  
            if(car[j].type == 1 )  
               cout<<setw(9)<<"大客车"<<setw(8)<<"载客量:"<<setw(2)<<people[j];  
            else if(car[j].type == 2 )  
               cout<<setw(9)<<"小轿车"<<setw(8)<<"车厢数:"<<setw(2)<<coach[j];  
            else  
               cout<<setw(9)<<"卡 车 "<<setw(8)<<"载重量:"<<setw(2)<<weight[j];  
            cout<<setw(6)<<car[j].km<<setw(7)<<car[j].RoadFee<<setw(7)<<car[j].cost<<setw(7)<<car[j].OilKm<<setw(8)<<car[j].AllCount<<endl;  
        }  
        cout<<"********************************************************************************"<<endl;  
    }  
    else  
        cout<<"车辆库为空！"<<endl;   
    cout<<"按任意键返回主界面:";  
    char z=getch();  
    jiemian();  
}  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::edit()         ////////////编辑功能  
{  
    int i, j, a = 0;  
    cout<<"请依次输入需要修改的车辆信息："<<endl;  
    while(1)  
    {  
        cout<<"车辆编号：";  
        cin>>i;  
        for(j = 0; j < top; j++)  
        {  
            if(car[j].num == i)  //车库有此编号的车  
            {  
                cout<<"车牌号：";  
                cin>>car[j].pnum;  
                cout<<"制造公司：";  
                cin>>car[j].made;  
                cout<<"购买时间：";  
                cin>>car[j].time;  
                cout<<"型号(1-大客车，2-小轿车，3-卡车)：";  
                cin>>car[j].type;  
                while(!(car[j].type==1||car[j].type==2||car[j].type==3))  
                {  
                    cout<<"输入信息有误，请输入1-3：";  
                    cin>>car[j].type;  
                }  
                cout<<"总公里数：";  
                cin>>car[j].km;  
                cout<<"养路费：";  
                cin>>car[j].RoadFee;  
                if( car[j].type == 1 )    //此时是1-大客车  
                {  
                    cout<<"最大载客量：";  
                    cin>>people[j];  
                    car[j].cost = 2000;  
                    car[j].OilKm = 0.1;  
                }  
                else if( car[j].type == 2 )   //此时是2-小轿车  
                {  
                    cout<<"车厢数：";  
                    cin>>coach[j];  
                    car[j].cost = 1000;  
                    car[j].OilKm = 0.05;  
                }  
                else     //此时是3-卡车  
                {  
                    cout<<"载重量：";  
                    cin>>weight[j];  
                    car[j].cost = 1500;  
                    car[j].OilKm = 0.15;  
                }  
                write();  
                a++;  
            }  
        }  
        if(a == 0)  
            cout<<"此编号不存在，不能进行修改，请重新输入！"<<endl;  
        else  
        {  
            cout<<"修改成功！系统将返回主界面..."<<endl;  
            break;  
        }  
    }  
Sleep(1000);   //延迟1秒  
jiemian();  
}  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::delet()        //////////////////删除车辆  
{  
    int i, a = 0;  
    while(1)  
    {  
        if(top == 0)  
        {  
            cout<<"车辆信息库为空！系统将返回功能界面..."<<endl;  
            break;  
        }  
        else  
        {  
            cout<<"请输入需要删除的车辆编号：";  
            cin>>i;  
            for(int j = 0; j < top; j++)  
            {  
                if(car[j].num == i)   //车辆编号存在  
                {  
                    if(top==1)  
                        car[0].type=0;  
                    else  
                    {  
                        if( car[top - 1].type == 1 )    //判断出此时car数组里储存在最后一组的是1-大客车  
                        {  
                            people[j] = people[top - 1];///////// （ 把最后一组数据 ） ///////  
                            car[j].cost = 2000;         ///////// （ 赋给将要删除的 ） ///////  
                            car[j].OilKm = 0.1;       ///////// （ 那组数据的位置 ） ///////  
                        }  
                        else if(car[top - 1].type == 2 )    //判断出此时car数组里储存在最后一组的是2-小轿车  
                        {  
                            coach[j] = coach[top - 1];    
                            car[j].cost = 1000;     
                            car[j].OilKm = 0.05;  
                        }  
                        else   //判断出此时car数组里储存在最后一组的是3-卡车  
                        {  
                            weight[j] = weight[top - 1];  
                            car[j].cost = 1500;  
                            car[j].OilKm = 0.15;  
                        }  
                        car[j].num = car[top - 1].num;          ///////// （ 把最后  ） ///////  
                        car[j].pnum = car[top - 1].pnum;        ///////// （ 一组数  ） ///////  
                        strcpy(car[j].made, car[top - 1].made); ///////// （ 据赋给  ） ///////  
                        car[j].time = car[top - 1].time;        ///////// （ 将要删  ） ///////  
                        car[j].type = car[top - 1].type;        ///////// （ 除的那  ） ///////  
                        car[j].km = car[top - 1].km;            ///////// （ 组数据  ） ///////  
                        car[j].RoadFee = car[top - 1].RoadFee;  ///////// （ 的位置  ） ///////  
                        car[j].AllCount = car[top-1].AllCount;  ///////// （         ） ///////  
                    }  
                    top--;   //此时删除车辆数据彻底完成，车辆总数减一  
                    a++;  
                    write();  
                }  
            }  
            if(a == 0)  
                cout<<"此编号不存在，不能进行删除，请重新输入！"<<endl;  
            else  
            {  
                cout<<"删除成功！系统将返回功能界面..."<<endl;  
                break;  
            }  
        }  
    }  
Sleep(1000);   //延迟1秒  
jiemian();  
}  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::write()        //////////////////车辆信息存盘  
{  
    ofstream write;  
    write.open("d:\\a.txt",ios::out);  
    if(write)  
    {  
        for(int i = 0; i < top; i++)  
        {//依次存入  编号   、     车牌号     、    制造商     、    购买时间      、    型号     、   
            write<<endl;  
        write<<car[i].num<<" "<<car[i].pnum<<" "<<car[i].made<<" "<<car[i].time<<" "<<car[i].type<<" ";  
        if(car[i].type == 1)  
            write<<people[i];//存入   载客量  
        else if(car[i].type == 2)  
            write<<coach[i];//存入    车厢数  
        else  
            write<<weight[i];//存入    载重量   
        //依次存入  总公里   、    养路费      、      维护费      、    油耗      、     总费用  
        write<<" "<<car[i].km<<" "<<car[i].RoadFee<<" "<<car[i].cost<<" "<<car[i].OilKm<<" "<<car[i].AllCount;  
        }  
    }  
    else cout<<"write failed"<<endl;  
}  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Manager::read()            ///////////////////读出车辆信息  
{  
    while(1)  
    {  
        ifstream read("d:\\a.txt",ios::in);  
        if(read)  
        {  
            while(!read.eof())  
            {//依次读取    编号   、     车牌号    、   制造商    、  购买时间    、   型号  
                read>>car[top].num>>car[top].pnum>>car[top].made>>car[top].time>>car[top].type;  
                if(car[top].type == 1)  
                    read>>people[top];//读取   载客量  
				else if(car[top].type == 2)  
                    read>>coach[top];//读取    车厢数  
                else  
                    read>>weight[top];//读取    载重量   
               //依次读取   总公里   、   养路费   、    维护费    、   油耗    、   总费用  
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
void Manager::jiemian()            ////////////////总界面  
{  
    int c1=0,c2=0,c3=0;  
    top=0;  
    read();  
    system("cls");  
    for(int j = 0; j < top; j++)  
        if( car[j].type == 1 )c1++;      //统计大客车的数量  
        else if(car[j].type == 2)c2++;      //统计小轿车的数量  
        else if(car[j].type==3)c3++;      //统计卡车的数量  
    top=c1+c2+c3;  
    cout<<"***********************************"<<endl;  
    cout<<"*        欢迎进入车辆管理系统     *"<<endl;  
    cout<<"*            1.添加车辆           *"<<endl;  
    cout<<"*            2.查询车辆           *\t\t总车辆\t"<<top<<endl;  
    cout<<"*            3.显示车辆           *\t\t大客车\t"<<c1<<endl;  
    cout<<"*            4.编辑车辆           *\t\t小轿车\t"<<c2<<endl;  
    cout<<"*            5.删除车辆           *\t\t卡 车 \t"<<c3<<endl;  
    cout<<"*            0.退出系统           *"<<endl;  
    cout<<"***********************************"<<endl;  
    cout<<"请输入你需要操作的选项:";  
    char i;  
    cin>>i;  
    while(!(i=='1'||i=='2'||i=='3'||i=='4'||i=='5'||i=='0'))  
    {  
        cout<<"输入错误,请重新输入:";  
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
