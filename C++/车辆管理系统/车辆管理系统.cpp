#include<windows.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
#include<windows.h>
using namespace std;
#define N 200          //车辆最大存储量200
#define OilPrice 8.0  //油价8元每升
class Time
{
	public:
		Time()
		{
			year=0;
			month=0;
			day=0;
		}
	   int year;
	   int month;
	   int day;
       void set_time();
       void show_time();
       friend ostream& operator<<(ostream&output,Time&t);
}; 
ostream &operator<<(ostream& output,Time&t)
{
	output<<t.year<<"/" <<t.month<<"/"<<t.day;
	return output;
 } 
class temp
{
	public:
    int temp_num;                  //临时编号
    string temp_pnum;                  //临时车牌号
    string temp_made;             //临时制造公司
    Time temp_buytime;                     //临时购买时间（多少个月）
    string temp_type[3]={"大客车","小轿车","卡车"};  //临时型号(1-大客车,2-小轿车,3-卡车)   
    int temp_types;
    double temp_km;                 //临时总公里数
    int temp_cost;                           //临时基本维护费用
	int temp_RoadFee;                   //临时养路费
	double temp_OilKm;                  //临时耗油量/公里
	int people;         //临时最大载客量（大客车）    
	int coach;          //临时箱数（小轿车）
	int weight; 
};
void Time::show_time()
{
	cout<<year<<"/"<<month<<"/"<<day;
}
void Time::set_time()
{
	cout<<"year: ";           //输入时间 
	cin>>year;
	cout<<"month: ";
	cin>>month;
    cout<<"day: ";
	cin>>day;
}
class Manager;
temp temp_plus;
class Cars:public Time,public temp            //汽车类
{
public:
	int num;                  //编号
    string pnum;                  //车牌号
    string made;             //制造公司
    Time buytime;                     //购买时间（多少个月）
    int type;                      //型号(1-大客车,2-小轿车,3-卡车)        公共变量
    double km;                 //总公里数
    int cost;                       //基本维护费用
	int RoadFee;                   //养路费
	double OilKm;                  //耗油量/公里
	int AllCount;               //累计总费用
	friend Manager;            //友元函数 Manager
	Cars *next; 
};
class Manager               //总的类
{
private:
   	int top;        //记录当前车辆数量
   	int people[N];         //最大载客量（大客车）    
	int coach[N];          //箱数（小轿车）
	int weight[N];        //载重量（卡车）
public:
	Manager(){top = 0;}//车辆初始值为0  汽车总数
	void add();     //添加车辆
	void search();  //查询车辆
	void show();    //显示车辆信息库
    void edit();    //编辑功能
    void delet();   //删除车辆
    void sum();     //统计信息
    void read();    //读出车辆信息
    void write();   //车辆信息存盘
    void jiemian(); //总界面
    void lianbiao();   //链表初始化
    void menu();
	int count(int b,int c,int d,int a,int e=8,int f=7); 
    Cars car[N];             //汽车数
    friend Cars;
    Manager *next;
    
};
//  开始 Manager的函数 
void Manager::lianbiao()
{
	for(int i=0;i<top-1;i++)
	{
		car[i].next=&car[i+1];
	}
	car[top-1].next=NULL;
}
int Manager::count(int b,int c,int d,int a,int e,int f)
{
	return (e*f*a)+(b*12+c)*d;  //计算总费用
}
void Manager::menu()
{
    int a;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"|             确认是否退出系统 1-确定  2-取消             |"<<endl;
	cout<<"----------------------------------------------------------"<<endl; 
	cin>>a;
	while(!( a==1 || a==2 )) 
				{
					cout<<"-------------------------------------------"<<endl;
					cout<<"|            输入指令号错误，重输 :        |"<<endl;
					cout<<"-------------------------------------------"<<endl;
					cin>>a;
				}
	if(a==1)
	{
		cout<<"--------------------------------------"<<endl;
		cout<<"|           退出成功！！！            |"<<endl;
		cout<<"--------------------------------------"<<endl; 
		Sleep(500);
		system("cls") ;        //清屏函数
	cout<<"***********************************"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*    |                        |   *"<<endl;
	cout<<"*    |      欢迎下次使用      |   *"<<endl;
	cout<<"*    |                        |   *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"***********************************"<<endl;
	}
	if(a==2)
	{
			cout<<"---------------------------------"<<endl;
			cout<<"|          取消成功 !!!          |"<<endl;
			cout<<"---------------------------------"<<endl;
		cout<<"-------------------------------------"<<endl;
	    cout<<"|         按任意键返回主界面:        |"<<endl;
	    cout<<"--------------------------------------"<<endl;
	    char z=getch();        //从输出获得一个字符之后调用界面函数
	    system("cls") ;        //清屏函数
	    jiemian();
	}
}
void Manager::show()
{
	Cars *p,*head;
	head=&car[0];
	p=head;
	int j=0;
	lianbiao();
	if(top != 0)      //top记录当前车辆数目
	{
	    do    
	    {
	    	    cout<<"*************************************************************************************"<<endl;
		        cout<<"编号         车牌号        制造商           购买时间          型号            特性  "<<endl;
		        cout<<setw(3)<<p->num<<setw(13)<<p->pnum<<setw(15)<<p->made<<setw(16);
			    cout<<p->buytime;
			    if(p->type == 1 )
			    cout<<setw(15)<<"大客车"<<setw(15)<<"载客量: "<<setw(2)<<people[j]<<endl;
			    else if(p->type == 2 )
			    cout<<setw(15)<<"小轿车"<<setw(15)<<"车厢数: "<<setw(2)<<coach[j]<<endl;
			    else
			    cout<<setw(15)<<"卡 车 "<<setw(15)<<"载重量: "<<setw(2)<<weight[j]<<endl;
			    cout<<"--------------------------------------------------------------------------------------------"<<endl;
			    cout<<"总公里      养路费      维护费        油耗       总费用"<<endl;
			    cout<<setw(3)<<p->km<<setw(13)<<p->RoadFee<<setw(13)<<p->cost<<setw(13)<<p->OilKm<<setw(13)<<p->AllCount<<endl;
			    cout<<"*************************************************************************************"<<endl;
			    cout<<endl;
		        p=p->next;
		        j++;
	    }
	    
	    while(p!=NULL);
    }
		else  
		{
			cout<<"----------------------------------"<<endl;
			cout<<"|          车辆库为空！！！      |"<<endl;
			cout<<"----------------------------------"<<endl;
		    cout<<endl;
		}                            
		cout<<"--------------------------------------"<<endl; 
	    cout<<"|         按任意键返回主界面:        |"<<endl;
	    cout<<"--------------------------------------"<<endl;
	    char z=getch();        //从输出获得一个字符之后调用界面函数
	    system("cls") ;        //清屏函数
	    jiemian();
}

void Manager::add()         //添加车辆    调用总的类之中的add函数
{
	int a = 0, x, y,sm;        // x代表车辆编号
    while(1)
	{
		lianbiao();
		if(top < N)         //判断top当前已存车辆数小于汽车最大存储数N
		{
            cout<<"请输入需添加的车辆信息"<<endl;
            cout<<"车辆编号：";
            cin>>x;
	        for(int j=0; j<top;j++)         //判断编号是否重复
			{
				if (car[j].num==x)     
				{
					cout<<"---------------------------------------------------------"<<endl;
					cout<<"|          编号重复,添加失败! 即将跳转至功能主界面       |"<<endl;
					cout<<"---------------------------------------------------------"<<endl;
                    a++;       //如果重复++，此时a不为0
                    break;
				}
			}
			if(a==0)                 //此时编号不重复
			{ 
			    temp_plus.temp_num=x;
				car[top].num = x;
                cout<<"车牌号：";
                cin>>car[top].pnum; 
				temp_plus.temp_pnum=car[top].pnum; 
                cout<<"车辆制造公司：";
                cin>>car[top].made;
                temp_plus.temp_made=car[top].made;
                cout<<"购买时间：年/月/日"<<endl;
                car[top].buytime.set_time();
                temp_plus.temp_buytime.year=car[top].buytime.year;
                temp_plus.temp_buytime.month=car[top].buytime.month;
                temp_plus.temp_buytime.day=car[top].buytime.day;
				cout<<"养路费：";
				cin>>car[top].RoadFee;
                temp_plus.temp_RoadFee=car[top].RoadFee;
				cout<<"车辆型号(1-大客车,2-小轿车,3-卡车)：";
                cin>>car[top].type;
				while(!(car[top].type==1||car[top].type==2||car[top].type==3)) //判断输入指令是否为1-3
				{
					cout<<"输入指令号错误,重输：";
					cin>>car[top].type;
				}
				cout<<"总公里数：";
                cin>>car[top].km;
                temp_plus.temp_km=car[top].km;
                if( car[top].type==1)    //此时是1-大客车，
				{
					cout<<"最大载客量：";
                    cin>>people[top];
                    temp_plus.people=people[top];
                    car[top].cost = 2000;   //基本维护费用
					car[top].OilKm = 0.1;   //耗油量/公里
				}
				else if( car[top].type == 2 )   //此时是2-小轿车
				{
					cout<<"车厢数：";
                    cin>>coach[top];
                    temp_plus.coach=coach[top];
                    car[top].cost = 1000;
					car[top].OilKm = 0.05;
				}
				else                            //此时是3-卡车
				{
					cout<<"载重量：";
                    cin>>weight[top];
                    temp_plus.weight=weight[top];
                    car[top].cost = 1500;
					car[top].OilKm = 0.15;
				}
				cout<<endl;
				car[top].AllCount=count(car[top].km,car[top].buytime.year,car[top].buytime.month,car[top].cost,7,8);
				//car[top].AllCount =(OilPrice * car[top].OilKm * car[top].km) +(((car[top].buytime.year*12)+car[top].buytime.month)*car[top].cost);  //计算总费用
				cout<<"-----------------------------------------"<<endl;
				cout<<"|              信息确认 !!!             |"<<endl;
				cout<<"-----------------------------------------"<<endl;
				cout<<"车辆编号："<<temp_plus.temp_num<<"      ";
				cout<<"车牌号: "<<temp_plus.temp_pnum<<"      "<<endl;
				cout<<"车辆制造公司："<<temp_plus.temp_made<<"   ";
				cout<<"购买时间: "<<temp_plus.temp_buytime<<endl;
				cout<<"养路费： "<<temp_plus.temp_RoadFee<<endl;
				cout<<"总公里数："<<temp_plus.temp_km;
				cout<<"车型："; 
				if( car[top].type==1)
				{
					cout<<temp_plus.temp_type[0]<<"      "<<"基本维护费用："<<car[top].cost<<endl;
					cout<<"耗油量（升/公里)："<<car[top].OilKm<<"      ";
					cout<<"最大载客量："<<temp_plus.people<<endl;
				}
				if( car[top].type==2)
				{
					cout<<temp_plus.temp_type[1]<<"      "<<"基本维护费用："<<car[top].cost<<endl;
					cout<<"耗油量（升/公里)："<<car[top].OilKm<<"       ";
					cout<<"车厢数："<<temp_plus.coach<<endl;
				}
				if( car[top].type==3)
				{
					cout<<temp_plus.temp_type[2]<<"      "<<"基本维护费用："<<car[top].cost<<endl;
					cout<<"耗油量（升/公里)："<<car[top].OilKm<<"       ";
					cout<<"载重量："<<temp_plus.weight<<endl;
				}
				cout<<"1.确认     2.取消 "<<endl;
				cin>>sm;
				while(!( sm==1 || sm==2 )) 
				{
					cout<<"-------------------------------------------"<<endl;
					cout<<"|            输入指令号错误，重输 :        |"<<endl;
					cout<<"-------------------------------------------"<<endl;
					cin>>sm;
				}
			    if(sm==1)
				{
					write();      //调用车辆信息存盘函数,在下面定义
					cout<<"-------------------------------"<<endl;
				    cout<<"|          存储成功 !!!       |"<<endl;
				    cout<<"-------------------------------"<<endl;
				    lianbiao();
				    top++;        //车辆总数加一1
				}
				else if(sm==2)
				{
					cout<<"--------------------------------"<<endl;
					cout<<"|          取消成功 ！！        |"<<endl;
					cout<<"--------------------------------"<<endl;
					car[top].type =0;
				}
                cout<<"是否继续添加车辆？(1-是,2-否)：";
                cin>>y;
				while(!( y==1 || y==2 ))    
				{
					cout<<"-------------------------------------------"<<endl;
					cout<<"|          输入指令号错误，重输 :          |"<<endl;
					cout<<"-------------------------------------------"<<endl;
					cin>>y;
				}
                if(y == 2)
				{
					cout<<"---------------------------------------------"<<endl;
					cout<<"|           即将跳转至功能主界面....         |"<<endl;
					cout<<"---------------------------------------------"<<endl;
					break;
				}
			}
			else       //此时编号重复
				break;
		}
		else                    //top>N
		{
			cout<<"-----------------------------------------"<<endl;
			cout<<"|     车辆信息库已满,不能再添加车辆 !    |"<<endl;
			cout<<"|          即将跳转至功能主界面....      |"<<endl;
			cout<<"-----------------------------------------"<<endl;
			break;
		}
	}
	Sleep(1000);   //延迟1秒
	system("cls") ;//清屏函数
	jiemian();     //调用总界面函数
}
 
void Manager::search()        //查询车辆
{
	int choose,m,n,a=0;
	char i,t[20];
	Cars *p,*head;
	head=&car[0];
	lianbiao();
	if(top == 0)   //车库为空无法查询 
		{
			cout<<"-----------------------------------------------------------"<<endl;
			cout<<"|         车辆信息库为空！系统将返回功能界面....           |"<<endl;
			cout<<"-----------------------------------------------------------"<<endl;
			Sleep(600);
			system("cls");
			jiemian();
		}
	cout<<"***********************************"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*    |  1.按车辆制造公司查询  |   *"<<endl;
	cout<<"*    |  2.按编号查询          |   *"<<endl;
	cout<<"*    |  3.按类别查询          |   *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"***********************************"<<endl;
	cout<<" 请输入你的选项：";
	while(1)
	{
		cin>>i;      
		cout<<endl;
		if(i=='1'||i=='2'||i=='3')
		{
		   break;
		}
		else
		cout<<"输入错误,重输：";	
	}
	
	if(i=='1')
	{
		cout<<"请输入需查询车辆的制造公司：";
		cin>>t;
	}
	else if(i =='2')
	{
		cout<<"请输入需查询的车辆编号：";
		cin>>n;
	}
	else if(i == '3')
	{
		cout<<"请输入需查询的车辆型号(1-大客车,2-小轿车,3-卡车)：";
		cin>>m;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->made==t || p->num==n || p->type==m)   //string字符串比较.
		{  
		    cout<<"**************************************************************************"<<endl;
			cout<<"编号        车牌号         制造商        购买时间       型号         特性 "<<endl; 
			a++;             //使a不为0       
		    break;
		}
	}
 	for(p=head;p!=NULL;p=p->next)
	{
		int j=0;
		if(p->made==t || p->num==n || p->type==m) 
		{
			cout<<setw(2)<<p->num<<setw(14)<<p->pnum<<setw(15)<<p->made<<setw(14);
			  cout<<p->buytime;
			
			if(p->type==1 )
				cout<<setw(14)<<"大客车"<<setw(14)<<"载客量:"<<people[j]<<endl;  //输出特性
			else if(car[j].type == 2 )
				cout<<setw(14)<<"小轿车"<<setw(14)<<"车厢数: "<<coach[j]<<endl;  
			else
				cout<<setw(14)<<"卡 车"<<setw(14)<<"载重量:"<<weight[j]<<endl;
			cout<<"----------------------------------------------------------------------------"<<endl;
			cout<<"----------------------------------------------------------------------------"<<endl;
			cout<<"**************************************************************************"<<endl;
			cout<<"总公里        养路费        维护费         油耗         总费用"<<endl;
			cout<<setw(2)<<p->km<<setw(15)<<p->RoadFee<<setw(16)<<p->cost;
			cout<<setw(14)<<p->OilKm<<setw(16)<<p->AllCount<<endl;			
		}
		j++;
	}
	if(a!=0)
	{
		cout<<"---------------------------------------------------------"<<endl;
		cout<<"|             是否进行修改?(1-是,2-否)：                 |"<<endl;
		cout<<"---------------------------------------------------------"<<endl;
		cin>>choose;
		if(choose == 1)
		edit();        //调用编辑功能函数
	}
	else             //上述a++的函数未成功，最上面1，2，3的查询结果没有
	{
		if(i=='1')
		{
			cout<<"--------------------------------------------------"<<endl;
			cout<<"|               车辆制造公司不存在！              |"<<endl;
			cout<<"--------------------------------------------------"<<endl;
		} 
		if(i=='2') 
		{
			cout<<"---------------------------------------------------"<<endl;
			cout<<"|                车辆编号不存在！                  |"<<endl;
			cout<<"---------------------------------------------------"<<endl;
		}
		else if (i=='3') 
		{
			cout<<"----------------------------------------------------"<<endl;
			cout<<"|                车辆型号不存在！                   |"<<endl;
			cout<<"----------------------------------------------------"<<endl;
		}
	}
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"|                    按任意键返回功能主界面                   |"<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
    char zz=getch();   //无回显的取一个字符
    Sleep(700);
   	system("cls") ;//清屏函数
    jiemian();         //调用界面函数
}

void Manager::edit()    //编辑车辆，既修改车辆      
{
	int i, j, a = 0,sm,q;
	lianbiao();
	Cars *p,*head;
	head=&car[0];
	if(top == 0)   //车库为空无法编辑 
		{
			cout<<"---------------------------------------------------------------"<<endl;
	        cout<<"|            车辆信息库为空，按任意键返回功能主界面            |"<<endl;
	        cout<<"---------------------------------------------------------------"<<endl;
            char zz=getch();   //无回显的取一个字符
            Sleep(500);
   	        system("cls") ;//清屏函数
            jiemian();         //调用界面函数
		}
		    cout<<"------------------------------------------------------------"<<endl;
			cout<<"|               车辆信息库中有以下车辆编号                 |"<<endl; 
			cout<<"------------------------------------------------------------"<<endl;
			
			for(int i=0;i<top;i++)
			{
				cout<<setw(10)<<car[i].num;
			}
			cout<<endl;
	cout<<"-------------------------------------------------"<<endl;
	cout<<"|         请依次输入需要修改的车辆信息：         |"<<endl;
	cout<<"-------------------------------------------------"<<endl;
	while(1)
	{
		cout<<"车辆编号：";
		cin>>i;
		for(j = 0; j < top; j++)
		{
			if(car[j].num == i)  //车库有此编号的车
			{
				cout<<"车牌号：";
                cin>>temp_plus.temp_pnum;
                cout<<"制造公司：";
                cin>>temp_plus.temp_made;
                cout<<"购买时间: 年/月/日"<<endl;
                car[j].set_time();
                cout<<"型号(1-大客车，2-小轿车，3-卡车)：";
                cin>>temp_plus.temp_types;
				while(!(temp_plus.temp_types==1||temp_plus.temp_types==2||temp_plus.temp_types==3)) //判断是否有误
				{
				    cout<<"---------------------------------------------------"<<endl;
					cout<<"               输入信息有误，请输入1-3：           "<<endl;
					cout<<"---------------------------------------------------"<<endl;
					cin>>temp_plus.temp_types;
				}
				cout<<"总公里数：";
                cin>>temp_plus.temp_km;
				cout<<"养路费：";
				cin>>temp_plus.temp_RoadFee;
				if( temp_plus.temp_types == 1 )    //此时是1-大客车
				{
					cout<<"最大载客量：";
                    cin>>temp_plus.people;
                    temp_plus.temp_cost = 2000;
					temp_plus.temp_OilKm = 0.1;
				}
				else if(temp_plus.temp_types == 2 )   //此时是2-小轿车
				{
					cout<<"车厢数：";
                    cin>>temp_plus.coach;
                    temp_plus.temp_cost = 1000;
					temp_plus.temp_OilKm = 0.05;
				}
				else                        //此时是3-卡车
				{
					cout<<"载重量：";
                    cin>>temp_plus.weight;
                    temp_plus.temp_cost = 1500;
					temp_plus.temp_OilKm = 0.15;
				}
				cout<<endl;
				cout<<"---------------------------------------------"<<endl;
			    cout<<"|               信息确认 !!!                 |"<<endl;
			    cout<<"---------------------------------------------"<<endl;
				cout<<"车辆编号："<<temp_plus.temp_num<<"      ";
				cout<<"车牌号: "<<temp_plus.temp_pnum<<"      "<<endl;
				cout<<"车辆制造公司："<<temp_plus.temp_made<<"      ";
				cout<<"购买时间: "<<temp_plus.temp_buytime<<endl;
				cout<<"养路费： "<<temp_plus.temp_RoadFee<<"      "<<"总公里数："<<temp_plus.temp_km<<endl;
				cout<<"车型："; 
				if( temp_plus.temp_types==1)
				{
					cout<<temp_plus.temp_type[0]<<"      ";
					cout<<"最大载客量："<<temp_plus.people<<endl;
				}
				if( temp_plus.temp_types==2)
				{
					cout<<temp_plus.temp_type[1]<<"      ";
					cout<<"车厢数："<<temp_plus.coach<<endl;
				}
				if( temp_plus.temp_types==3)
				{
					cout<<temp_plus.temp_type[2]<<"      ";
					cout<<"载重量："<<temp_plus.weight<<endl;
				}
				cout<<"--------------------------------------------------"<<endl;
				cout<<"|                1.确认      2.取消               |"<<endl;
				cout<<"--------------------------------------------------"<<endl;
				cin>>sm;
				while(!( sm==1 || sm==2 )) 
				{
				    cout<<"-------------------------------------------"<<endl;
					cout<<"|            输入指令号错误，重输 :        |"<<endl;
					cout<<"-------------------------------------------"<<endl;
					cin>>sm;
				}
				if(sm==1)
				{
					car[j].pnum=temp_plus.temp_pnum;
					car[j].made=temp_plus.temp_made;
					car[j].buytime.year=temp_plus.temp_buytime.year;
                    car[j].buytime.month=temp_plus.temp_buytime.month;
                    car[j].buytime.day=temp_plus.temp_buytime.day;
                    car[j].RoadFee=temp_plus.temp_RoadFee;
                    car[j].km=temp_plus.temp_km;
                    car[j].type=temp_plus.temp_types;
                    people[j]=temp_plus.people;
                    coach[j]=temp_plus.coach;
                    weight[j]=temp_plus.weight;
                    car[j].cost=temp_plus.temp_cost;
					car[j].OilKm=temp_plus.temp_OilKm;
					write();      //调用存盘函数
				    a++;         //成功后加一
				}
				else if(sm==2)
				{
					
					cout<<"------------------------------------------------------"<<endl;
					cout<<"|           取消修改 ！即将返回至页面.....           |"<<endl;
					cout<<"------------------------------------------------------"<<endl;
					Sleep(700);
					system("cls") ;        //清屏函数
					jiemian();
				}
			}
		}
		if(a == 0)      //未存成功，说明有错误
		{
			cout<<"-------------------------------------------------"<<endl;
		    cout<<"|    此编号不存在，不能进行修改，请重新输入!    |"<<endl;
		    cout<<"-------------------------------------------4------"<<endl;
		}
		
		else
		{
			cout<<"--------------------------------------------------------"<<endl;
		    cout<<"|          修改成功！系统将返回主界面....               |"<<endl;
		    cout<<"--------------------------------------------------------"<<endl;
		    Sleep(700);
		    system("cls") ;        //清屏函数
			break;               //跳出while循环
		}
	}
Sleep(700);   //延迟0.7秒
jiemian();
}
 
void Manager::delet()        //删除车辆
{
	int i, a = 0;       //a用来判断循环是否成功
	int j;
	Cars *p,*head;
	head=&car[0];
	while(1)
	{
		if(top == 0)   //车库为空无法删除
		{
			cout<<"-----------------------------------------------------------"<<endl;
			cout<<"|         车辆信息库为空！系统将返回功能界面....           |"<<endl;
			cout<<"-----------------------------------------------------------"<<endl;
			break;         //跳出while循环
		}
		else          //不为空
		{
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"|               车辆信息库中有以下车辆编号                 |"<<endl; 
			cout<<"------------------------------------------------------------"<<endl;
			for(int i=0;i<top;i++)
			{
				cout<<setw(10)<<car[i].num;
			}
			cout<<endl;
			cout<<"请输入需要删除的车辆编号：";
			cin>>i;
			for( j = 0; j <top; j++)        //for循环用来删除所有存盘的信息
			{
				if(car[j].num == i)   //车辆编号存在
				{
					if(top==1)
						car[0].type=0;      //就一辆车，使其变为0					
					else                    //top不等于1
					{
						if( car[top - 1].type == 1 )    //判断出此时car数组里储存在最后一组的是1-大客车
						{
							people[j] = people[j+1];         //people载客量
						    car[j].cost = 2000;         
						    car[j].OilKm = 0.1;       
						}
					    else if(car[top - 1].type == 2 )    //判断出此时car数组里储存在最后一组的是2-小轿车
						{
							coach[j] = coach[top - 1];  
						    car[j].cost = 1000;   
						    car[j].OilKm = 0.05;
						}
					    else if(car[top - 1].type == 3 )   //判断出此时car数组里储存在最后一组的是3-卡车
						{
						    weight[j] = weight[j+1];
						    car[j].cost = 1500;
						    car[j].OilKm = 0.15;
						}
						 car[j].num = car[top-1].num;          //使所有的数据均减一
						car[j].pnum=car[top-1].pnum;
					    car[j].made=car[top-1].made;
					    car[j].buytime = car[top-1].buytime;        
					    car[j].type = car[top-1].type;        
					    car[j].km = car[top-1].km;            
					    car[j].RoadFee = car[top-1].RoadFee;  
					    car[j].AllCount = car[top-1].AllCount;
						car[j].type=0;
					}
					//top--;					
					a++;
					write();   //存盘函数
					lianbiao();
				}
			}		
			if(a == 0)
			{
				cout<<"----------------------------------------------------------"<<endl;
		    	cout<<"|        此编号不存在，不能进行删除，请重新输入！         |"<<endl;
		    	cout<<"----------------------------------------------------------"<<endl;
			}
			
			else
			{
			    cout<<"------------------------------------------------------------"<<endl;
				cout<<"|           删除成功！系统将返回功能界面....                |"<<endl;
				cout<<"------------------------------------------------------------"<<endl;
			    Sleep(800);         //延迟0.8秒。
				system("cls") ;        //清屏函数 
				break;
			}
		}
	}
     Sleep(700);   //延迟0.7秒
     system("cls") ;        //清屏函数
     jiemian();
}
 
void Manager::write()        //车辆信息存盘
{
	ofstream write;
	write.open("d:\\b.txt",ios::out);   //以输出方式打开文件
	if(write)
	{
		for(int i = 0; i <=top; i++)
		{
			write<<endl;
			write<<car[i].num<<" "<<car[i].pnum<<" "<<car[i].made<<" ";
			write<<car[i].buytime.year<<" "<<car[i].buytime.month<<" "<<car[i].buytime.day;
			write<<" "<<car[i].type<<" ";
		    if(car[i].type == 1)
				write<<people[i];//存入   载客量
		    else if(car[i].type == 2)
		     	write<<coach[i];//存入    车厢数
		    else
			    write<<weight[i];//存入    载重量 
		    write<<" "<<car[i].km<<" "<<car[i].RoadFee<<" "<<car[i].cost<<" "<<car[i].OilKm<<" "<<car[i].AllCount;
		}
	}
}

void Manager::read()            ///读出车辆信息
{
	while(1)
	{
		ifstream read("d:\\b.txt",ios::in);
	    if(read)
		{
		    while(!read.eof())   //文件不结束，还有内容
			{
		        read>>car[top].num>>car[top].pnum>>car[top].made;
				read>>car[top].buytime.year>>car[top].buytime.month>>car[top].buytime.day>>car[top].type;
		        if(car[top].type == 1)
			        read>>people[top];//读取   载客量
		        else if(car[top].type == 2)
			        read>>coach[top];//读取    车厢数
		        else
			        read>>weight[top];//读取    载重量 
		        read>>car[top].km>>car[top].RoadFee>>car[top].cost>>car[top].OilKm>>car[top].AllCount;
		        if(car[top].type==1||car[top].type==2||car[top].type==3)
		            top++;
			}
			read.close();           //关闭文件
	        break;
	    }
	    else 
		{
		    ofstream outfile("d:\\a.txt");      
		    outfile.close();
		}
	}
}
void Manager::jiemian()            
{	int c1=0,c2=0,c3=0;
	
	for(int j = 0; j <= top; j++)
	{
		if( car[j].type == 1 ) c1++;      //统计大客车的数量
		else if(car[j].type == 2) c2++;      //统计小轿车的数量
		else if(car[j].type==3) c3++;      //统计卡车的数量
	}
	top=c1+c2+c3;
	lianbiao();
	cout<<"*********************************************"<<endl;
	cout<<"*                                           *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          | 欢迎进入车辆管理系统 |         *"<<endl;
	cout<<"*          |      1.添加车辆      |         *"<<endl;
	cout<<"*          |      2.查询车辆      |         *     \t\t总车辆\t"<<top<<endl;
	cout<<"*          |      3.显示车辆      |         *    \t\t大客车\t"<<c1<<endl;
	cout<<"*          |      4.编辑车辆      |         *    \t\t小轿车\t"<<c2<<endl;
	cout<<"*          |      5.删除车辆      |         *    \t\t卡 车 \t"<<c3<<endl;
	cout<<"*          |      0.退出系统      |         *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*                                           *"<<endl;
	cout<<"*********************************************"<<endl;
	cout<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<"            请输入你需要操作的选项                     "<<endl;
	cout<<"------------------------------------------------------"<<endl;
	char i;
	cin>>i;
	while(!(i=='1'||i=='2'||i=='3'||i=='4'||i=='5'||i=='0'))
	{
		cout<<"-----------------------------------------------"<<endl;
		cout<<"|           输入错误,请重新输入               |"<<endl;
		cout<<"-----------------------------------------------"<<endl;
		cin>>i;           
	}
 
	switch(i)
	{
	case '1':add();
	break;
    case '2':search();
	break;
    case '3':show();
	break;
    case '4':edit();
	break;
    case '5':delet();
	break;
    case '0':menu();
	return;
	}
}
int main()
{   
    int temp_num;                  //编号
    char temp_pnum[20];                  //车牌号
    char temp_made[20];             //制造公司
    Time temp_buytime;                     //购买时间（多少个月）
    int temp_type;                      //型号(1-大客车,2-小轿车,3-卡车)        公共变量
    double temp_km;                 //总公里数
    int temp_cost;                           //基本维护费用
	int iemp_RoadFee;                   //养路费
	double temp_OilKm;                  //耗油量/公里
	double temp_AllCount;               //累计总费用
	Cars car[N];
	Manager a;
	a.jiemian();
	return 0;
}
 
 
 
