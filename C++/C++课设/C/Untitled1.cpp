#include<windows.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
using namespace std;
#define N 20          //车辆最大存储量20
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
}; 
struct temp
{
    int temp_num;                  //临时编号
    string temp_pnum;                  //临时车牌号
    string temp_made;             //临时制造公司
    Time temp_buytime;                     //临时购买时间（多少个月）
    int temp_type;                      //临时型号(1-大客车,2-小轿车,3-卡车)        公共变量
    double temp_km;                 //临时总公里数
    int temp_cost;                           //临时基本维护费用
	int iemp_RoadFee;                   //临时养路费
	double temp_OilKm;                  //临时耗油量/公里
	double temp_AllCount;               //临时累计总费用
};
temp temp_plus;
void Time::show_time()
{
	cout<<year<<" 年"<<month<<" 月"<<day<<" 日";
}
void Time::set_time()
{
	cout<<"年份 ：";
	cin>>year;
	cout<<"月份 ： ";
	cin>>month;
    cout<<"日 ： ";
	cin>>day;
	
}
class Manager;
class Cars:public Time             //汽车类
{
public:
	int num;                  //编号
    string pnum;                  //车牌号
    string made;             //制造公司
    Time buytime;                     //购买时间（多少个月）
    int type;                      //型号(1-大客车,2-小轿车,3-卡车)        公共变量
    double km;                 //总公里数
    int cost;                           //基本维护费用
	int RoadFee;                   //养路费
	double OilKm;                  //耗油量/公里
	double AllCount;               //累计总费用
	friend Manager;
};
class Manager               //总的类
{
private:
	Cars car[N];             //汽车数
	int people[N];         //最大载客量（大客车）    
	int coach[N];          //箱数（小轿车）
	int weight[N];        //载重量（卡车）
	int top;        //记录当前车辆数量
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
};
 
void Manager::add()         //添加车辆    调用总的类之中的add函数
{
	int a = 0, x, y;        // x代表车辆编号
    while(1)
	{
		if(top < N)         //判断top当前已存车辆数小于汽车最大存储数N
		{
            cout<<"请输入需添加的车辆信息"<<endl;
            cout<<"车辆编号：";
            cin>>x;
	        for(int j=0; j<top;j++)         //判断编号是否重复
			{
				if (car[j].num==x)     
				{
					cout<<"编号重复,添加失败! 即将跳转至功能主界面"<<endl;
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
                car[top].set_time();
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
                if( car[top].type==1)    //此时是1-大客车，
				{
					cout<<"最大载客量：";
                    cin>>people[top];
                    car[top].cost = 2000;   //基本维护费用
					car[top].OilKm = 0.1;   //耗油量/公里
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
				car[top].AllCount =(OilPrice * car[top].OilKm * car[top].km) +(((car[top].buytime.year*12)+car[top].buytime.month)*car[top].cost);  //计算总费用
				top++;        //车辆总数加一
				cout<<"信息确认：";
				write();      //调用车辆信息存盘函数,在下面定义
                cout<<"是否继续添加车辆？(1-是,2-否)：";
                cin>>y;
				while(!( y==1 || y==2 ))    
				{
					cout<<"输入指令号错误，重输 : ";
					cin>>y;
				}
                if(y == 2)
				{
					cout<<" 即将跳转至功能主界面.... "<<endl;
					break;
				}
			}
			else       //此时编号重复
				break;
		}
		else                    //top>N
		{
			cout<<"车辆信息库已满,不能再添加车辆 ! "<<endl;
			cout<<"即将跳转至功能主界面...."<<endl;
			break;
		}
	}
	Sleep(1000);   //延迟1秒
	jiemian();     //调用总界面函数
}
 
void Manager::search()        //查询车辆
{
	int choose,m,n,a=0;
	char i,t[20];
	cout<<"****************************"<<endl;
	cout<<"*                          *"<<endl;
	cout<<"*  1.按车辆制造公司查询    *"<<endl;
	cout<<"*  2.按编号查询            *"<<endl;
	cout<<"*  3.按类别查询            *"<<endl;
	cout<<"*                          *"<<endl;
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
	
	
	for(int j=0;j<top;j++)
		if((car[j].made,t)==0 || car[j].num==n || car[j].type==m)   //strcmp比较，相同返回0，小于负数，大于正数
		{
			cout<<"编号   车牌号    制造商  购买时间    型号     特性     总公里 养路费 维护费  油耗  总费用"<<endl;
		    break;
		}
	for(int j=0;j<top;j++)
		if((car[j].made, t)==0 || car[j].num==n || car[j].type==m) 
		{
			cout<<setw(0)<<car[j].num<<setw(13)<<car[j].pnum<<setw(9)<<car[j].made<<setw(6);
			car[j].show_time();  //前四个
			
			if(car[j].type==1 )
				cout<<setw(13)<<"大客车"<<setw(8)<<"载客量:"<<people[j];  //输出特性
			else if(car[j].type == 2 )
				cout<<setw(13)<<"小轿车"<<setw(9)<<"车厢数: "<<coach[j];  
			else
				cout<<setw(13)<<"卡 车"<<setw(9)<<"载重量:"<<weight[j];
			
			cout<<setw(6)<<car[j].km<<setw(7)<<car[j].RoadFee<<setw(8)<<car[j].cost<<setw(7)<<car[j].OilKm<<setw(9)<<car[j].AllCount<<endl;			
			a++;        //使a不为0
		}
	if(a!=0)
	{
		cout<<"是否进行修改?(1-是,2-否)：";
		cin>>choose;
		if(choose == 1)
		edit();        //调用编辑功能函数
	}
	else             //上述a++的函数未成功，最上面1，2，3的查询结果没有
	{
		if(i=='1') cout<<"车辆制造公司不存在！"<<endl;
		if(i=='2') cout<<"车辆编号不存在！"<<endl;
		else if (i=='3') cout<<"车辆型号不存在！"<<endl;
	}
	cout<<"按任意键返回功能主界面"<<endl;
    char zz=getch();   //无回显的取一个字符
    jiemian();         //调用界面函数
}
 
void Manager::show()         //显示车辆信息库
{
	if(top != 0)      //top记录当前车辆数目
	{
		cout<<"********************************************************************************"<<endl;
		cout<<"编号   车牌号    制造商  购买时间    型号     特性     总公里 养路费 维护费  油耗  总费用"<<endl;
 
		for(int j = 0; j < top; j++)         //使用for循环对应输出，j代表车辆数
		{
			cout<<setw(0)<<car[j].num<<setw(13)<<car[j].pnum<<setw(9)<<car[j].made<<setw(6);
			car[j].show_time();
			if(car[j].type == 1 )
			   cout<<setw(13)<<"大客车"<<setw(8)<<"载客量:"<<setw(2)<<people[j];
			else if(car[j].type == 2 )
			   cout<<setw(13)<<"小轿车"<<setw(8)<<"车厢数:"<<setw(2)<<coach[j];
			else
			   cout<<setw(13)<<"卡 车 "<<setw(8)<<"载重量:"<<setw(2)<<weight[j];
			cout<<setw(6)<<car[j].km<<setw(7)<<car[j].RoadFee<<setw(8)<<car[j].cost<<setw(7)<<car[j].OilKm<<setw(9)<<car[j].AllCount<<endl;
		}
		cout<<"********************************************************************************"<<endl;
	}
	else                               
		cout<<"车辆库为空！"<<endl;
	cout<<"按任意键返回主界面:";
	char z=getch();        //从输出获得一个字符之后调用界面函数
	jiemian();
}
 
void Manager::edit()    //编辑车辆，既修改车辆      
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
                cout<<"购买时间：     年      月     日";
                car[j].show_time();
                cout<<"型号(1-大客车，2-小轿车，3-卡车)：";
                cin>>car[j].type;
				
				while(!(car[j].type==1||car[j].type==2||car[j].type==3)) //判断是否有误
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
				else                        //此时是3-卡车
				{
					cout<<"载重量：";
                    cin>>weight[j];
                    car[j].cost = 1500;
					car[j].OilKm = 0.15;
				}
				
				write();                  //调用存盘函数
				a++;         //成功后加一
			}
			
		}
		if(a == 0)      //未存成功，说明有错误
			cout<<"此编号不存在，不能进行修改，请重新输入！"<<endl;
		else
		{
			cout<<"修改成功！系统将返回主界面..."<<endl;
			break;               //跳出while循环
		}
	}
Sleep(1000);   //延迟1秒
jiemian();
}
 
void Manager::delet()        //删除车辆
{
	int i, a = 0;       //a用来判断循环是否成功
	while(1)
	{
		if(top == 0)   //车库为空无法删除
		{
			cout<<"车辆信息库为空！系统将返回功能界面...."<<endl;
			break;         //跳出while循环
		}
		else          //不为空
		{
			cout<<"请输入需要删除的车辆编号：";
			cin>>i;
			for(int j = 0; j < top; j++)        //for循环用来删除所有存盘的信息
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
						car[j].num = car[j+1].num;          //使所有的数据均减一
						car[j].pnum, car[j+1].pnum;
					    car[j].made, car[j+1].made; 
					    car[j].buytime = car[j+1].buytime;        
					    car[j].type = car[j+1].type;        
					    car[j].km = car[j+1].km;            
					    car[j].RoadFee = car[j+1].RoadFee;  
					    car[j].AllCount = car[j+1].AllCount;
						car[j+1].type=0;
					}					
					a++;
					write();   //存盘函数
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
		        read>>car[top].num>>car[top].pnum>>car[top].made>>car[top].buytime.year>>car[top].buytime.month>>car[top].buytime.day>>car[top].type;
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
		    ofstream o("d:\\a.txt");      
		    o.close();
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
	cout<<"************************************"<<endl;
	cout<<"*        欢迎进入车辆管理系统      *"<<endl;
	cout<<"*            1.添加车辆            *"<<endl;
	cout<<"*            2.查询车辆            *\t\t总车辆\t"<<top<<endl;
	cout<<"*            3.显示车辆            *\t\t大客车\t"<<c1<<endl;
	cout<<"*            4.编辑车辆            *\t\t小轿车\t"<<c2<<endl;
	cout<<"*            5.删除车辆            *\t\t卡 车 \t"<<c3<<endl;
	cout<<"*            0.退出系统            *"<<endl;
	cout<<"************************************"<<endl;
	cout<<"请输入你需要操作的选项:";
	char i;
	cin>>i;
	while(!(i=='1'||i=='2'||i=='3'||i=='4'||i=='5'||i=='0'))
	{
		cout<<"输入错误,请重新输入:";
		cin>>i;           
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
	Manager a;
	a.jiemian();
	return 0;
}
 
 
 
