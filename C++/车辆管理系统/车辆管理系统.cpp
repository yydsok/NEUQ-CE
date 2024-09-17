#include<windows.h>
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
#include<windows.h>
using namespace std;
#define N 200          //�������洢��200
#define OilPrice 8.0  //�ͼ�8Ԫÿ��
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
    int temp_num;                  //��ʱ���
    string temp_pnum;                  //��ʱ���ƺ�
    string temp_made;             //��ʱ���칫˾
    Time temp_buytime;                     //��ʱ����ʱ�䣨���ٸ��£�
    string temp_type[3]={"��ͳ�","С�γ�","����"};  //��ʱ�ͺ�(1-��ͳ�,2-С�γ�,3-����)   
    int temp_types;
    double temp_km;                 //��ʱ�ܹ�����
    int temp_cost;                           //��ʱ����ά������
	int temp_RoadFee;                   //��ʱ��·��
	double temp_OilKm;                  //��ʱ������/����
	int people;         //��ʱ����ؿ�������ͳ���    
	int coach;          //��ʱ������С�γ���
	int weight; 
};
void Time::show_time()
{
	cout<<year<<"/"<<month<<"/"<<day;
}
void Time::set_time()
{
	cout<<"year: ";           //����ʱ�� 
	cin>>year;
	cout<<"month: ";
	cin>>month;
    cout<<"day: ";
	cin>>day;
}
class Manager;
temp temp_plus;
class Cars:public Time,public temp            //������
{
public:
	int num;                  //���
    string pnum;                  //���ƺ�
    string made;             //���칫˾
    Time buytime;                     //����ʱ�䣨���ٸ��£�
    int type;                      //�ͺ�(1-��ͳ�,2-С�γ�,3-����)        ��������
    double km;                 //�ܹ�����
    int cost;                       //����ά������
	int RoadFee;                   //��·��
	double OilKm;                  //������/����
	int AllCount;               //�ۼ��ܷ���
	friend Manager;            //��Ԫ���� Manager
	Cars *next; 
};
class Manager               //�ܵ���
{
private:
   	int top;        //��¼��ǰ��������
   	int people[N];         //����ؿ�������ͳ���    
	int coach[N];          //������С�γ���
	int weight[N];        //��������������
public:
	Manager(){top = 0;}//������ʼֵΪ0  ��������
	void add();     //��ӳ���
	void search();  //��ѯ����
	void show();    //��ʾ������Ϣ��
    void edit();    //�༭����
    void delet();   //ɾ������
    void sum();     //ͳ����Ϣ
    void read();    //����������Ϣ
    void write();   //������Ϣ����
    void jiemian(); //�ܽ���
    void lianbiao();   //�����ʼ��
    void menu();
	int count(int b,int c,int d,int a,int e=8,int f=7); 
    Cars car[N];             //������
    friend Cars;
    Manager *next;
    
};
//  ��ʼ Manager�ĺ��� 
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
	return (e*f*a)+(b*12+c)*d;  //�����ܷ���
}
void Manager::menu()
{
    int a;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"|             ȷ���Ƿ��˳�ϵͳ 1-ȷ��  2-ȡ��             |"<<endl;
	cout<<"----------------------------------------------------------"<<endl; 
	cin>>a;
	while(!( a==1 || a==2 )) 
				{
					cout<<"-------------------------------------------"<<endl;
					cout<<"|            ����ָ��Ŵ������� :        |"<<endl;
					cout<<"-------------------------------------------"<<endl;
					cin>>a;
				}
	if(a==1)
	{
		cout<<"--------------------------------------"<<endl;
		cout<<"|           �˳��ɹ�������            |"<<endl;
		cout<<"--------------------------------------"<<endl; 
		Sleep(500);
		system("cls") ;        //��������
	cout<<"***********************************"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*    |                        |   *"<<endl;
	cout<<"*    |      ��ӭ�´�ʹ��      |   *"<<endl;
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
			cout<<"|          ȡ���ɹ� !!!          |"<<endl;
			cout<<"---------------------------------"<<endl;
		cout<<"-------------------------------------"<<endl;
	    cout<<"|         �����������������:        |"<<endl;
	    cout<<"--------------------------------------"<<endl;
	    char z=getch();        //��������һ���ַ�֮����ý��溯��
	    system("cls") ;        //��������
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
	if(top != 0)      //top��¼��ǰ������Ŀ
	{
	    do    
	    {
	    	    cout<<"*************************************************************************************"<<endl;
		        cout<<"���         ���ƺ�        ������           ����ʱ��          �ͺ�            ����  "<<endl;
		        cout<<setw(3)<<p->num<<setw(13)<<p->pnum<<setw(15)<<p->made<<setw(16);
			    cout<<p->buytime;
			    if(p->type == 1 )
			    cout<<setw(15)<<"��ͳ�"<<setw(15)<<"�ؿ���: "<<setw(2)<<people[j]<<endl;
			    else if(p->type == 2 )
			    cout<<setw(15)<<"С�γ�"<<setw(15)<<"������: "<<setw(2)<<coach[j]<<endl;
			    else
			    cout<<setw(15)<<"�� �� "<<setw(15)<<"������: "<<setw(2)<<weight[j]<<endl;
			    cout<<"--------------------------------------------------------------------------------------------"<<endl;
			    cout<<"�ܹ���      ��·��      ά����        �ͺ�       �ܷ���"<<endl;
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
			cout<<"|          ������Ϊ�գ�����      |"<<endl;
			cout<<"----------------------------------"<<endl;
		    cout<<endl;
		}                            
		cout<<"--------------------------------------"<<endl; 
	    cout<<"|         �����������������:        |"<<endl;
	    cout<<"--------------------------------------"<<endl;
	    char z=getch();        //��������һ���ַ�֮����ý��溯��
	    system("cls") ;        //��������
	    jiemian();
}

void Manager::add()         //��ӳ���    �����ܵ���֮�е�add����
{
	int a = 0, x, y,sm;        // x���������
    while(1)
	{
		lianbiao();
		if(top < N)         //�ж�top��ǰ�Ѵ泵����С���������洢��N
		{
            cout<<"����������ӵĳ�����Ϣ"<<endl;
            cout<<"������ţ�";
            cin>>x;
	        for(int j=0; j<top;j++)         //�жϱ���Ƿ��ظ�
			{
				if (car[j].num==x)     
				{
					cout<<"---------------------------------------------------------"<<endl;
					cout<<"|          ����ظ�,���ʧ��! ������ת������������       |"<<endl;
					cout<<"---------------------------------------------------------"<<endl;
                    a++;       //����ظ�++����ʱa��Ϊ0
                    break;
				}
			}
			if(a==0)                 //��ʱ��Ų��ظ�
			{ 
			    temp_plus.temp_num=x;
				car[top].num = x;
                cout<<"���ƺţ�";
                cin>>car[top].pnum; 
				temp_plus.temp_pnum=car[top].pnum; 
                cout<<"�������칫˾��";
                cin>>car[top].made;
                temp_plus.temp_made=car[top].made;
                cout<<"����ʱ�䣺��/��/��"<<endl;
                car[top].buytime.set_time();
                temp_plus.temp_buytime.year=car[top].buytime.year;
                temp_plus.temp_buytime.month=car[top].buytime.month;
                temp_plus.temp_buytime.day=car[top].buytime.day;
				cout<<"��·�ѣ�";
				cin>>car[top].RoadFee;
                temp_plus.temp_RoadFee=car[top].RoadFee;
				cout<<"�����ͺ�(1-��ͳ�,2-С�γ�,3-����)��";
                cin>>car[top].type;
				while(!(car[top].type==1||car[top].type==2||car[top].type==3)) //�ж�����ָ���Ƿ�Ϊ1-3
				{
					cout<<"����ָ��Ŵ���,���䣺";
					cin>>car[top].type;
				}
				cout<<"�ܹ�������";
                cin>>car[top].km;
                temp_plus.temp_km=car[top].km;
                if( car[top].type==1)    //��ʱ��1-��ͳ���
				{
					cout<<"����ؿ�����";
                    cin>>people[top];
                    temp_plus.people=people[top];
                    car[top].cost = 2000;   //����ά������
					car[top].OilKm = 0.1;   //������/����
				}
				else if( car[top].type == 2 )   //��ʱ��2-С�γ�
				{
					cout<<"��������";
                    cin>>coach[top];
                    temp_plus.coach=coach[top];
                    car[top].cost = 1000;
					car[top].OilKm = 0.05;
				}
				else                            //��ʱ��3-����
				{
					cout<<"��������";
                    cin>>weight[top];
                    temp_plus.weight=weight[top];
                    car[top].cost = 1500;
					car[top].OilKm = 0.15;
				}
				cout<<endl;
				car[top].AllCount=count(car[top].km,car[top].buytime.year,car[top].buytime.month,car[top].cost,7,8);
				//car[top].AllCount =(OilPrice * car[top].OilKm * car[top].km) +(((car[top].buytime.year*12)+car[top].buytime.month)*car[top].cost);  //�����ܷ���
				cout<<"-----------------------------------------"<<endl;
				cout<<"|              ��Ϣȷ�� !!!             |"<<endl;
				cout<<"-----------------------------------------"<<endl;
				cout<<"������ţ�"<<temp_plus.temp_num<<"      ";
				cout<<"���ƺ�: "<<temp_plus.temp_pnum<<"      "<<endl;
				cout<<"�������칫˾��"<<temp_plus.temp_made<<"   ";
				cout<<"����ʱ��: "<<temp_plus.temp_buytime<<endl;
				cout<<"��·�ѣ� "<<temp_plus.temp_RoadFee<<endl;
				cout<<"�ܹ�������"<<temp_plus.temp_km;
				cout<<"���ͣ�"; 
				if( car[top].type==1)
				{
					cout<<temp_plus.temp_type[0]<<"      "<<"����ά�����ã�"<<car[top].cost<<endl;
					cout<<"����������/����)��"<<car[top].OilKm<<"      ";
					cout<<"����ؿ�����"<<temp_plus.people<<endl;
				}
				if( car[top].type==2)
				{
					cout<<temp_plus.temp_type[1]<<"      "<<"����ά�����ã�"<<car[top].cost<<endl;
					cout<<"����������/����)��"<<car[top].OilKm<<"       ";
					cout<<"��������"<<temp_plus.coach<<endl;
				}
				if( car[top].type==3)
				{
					cout<<temp_plus.temp_type[2]<<"      "<<"����ά�����ã�"<<car[top].cost<<endl;
					cout<<"����������/����)��"<<car[top].OilKm<<"       ";
					cout<<"��������"<<temp_plus.weight<<endl;
				}
				cout<<"1.ȷ��     2.ȡ�� "<<endl;
				cin>>sm;
				while(!( sm==1 || sm==2 )) 
				{
					cout<<"-------------------------------------------"<<endl;
					cout<<"|            ����ָ��Ŵ������� :        |"<<endl;
					cout<<"-------------------------------------------"<<endl;
					cin>>sm;
				}
			    if(sm==1)
				{
					write();      //���ó�����Ϣ���̺���,�����涨��
					cout<<"-------------------------------"<<endl;
				    cout<<"|          �洢�ɹ� !!!       |"<<endl;
				    cout<<"-------------------------------"<<endl;
				    lianbiao();
				    top++;        //����������һ1
				}
				else if(sm==2)
				{
					cout<<"--------------------------------"<<endl;
					cout<<"|          ȡ���ɹ� ����        |"<<endl;
					cout<<"--------------------------------"<<endl;
					car[top].type =0;
				}
                cout<<"�Ƿ������ӳ�����(1-��,2-��)��";
                cin>>y;
				while(!( y==1 || y==2 ))    
				{
					cout<<"-------------------------------------------"<<endl;
					cout<<"|          ����ָ��Ŵ������� :          |"<<endl;
					cout<<"-------------------------------------------"<<endl;
					cin>>y;
				}
                if(y == 2)
				{
					cout<<"---------------------------------------------"<<endl;
					cout<<"|           ������ת������������....         |"<<endl;
					cout<<"---------------------------------------------"<<endl;
					break;
				}
			}
			else       //��ʱ����ظ�
				break;
		}
		else                    //top>N
		{
			cout<<"-----------------------------------------"<<endl;
			cout<<"|     ������Ϣ������,��������ӳ��� !    |"<<endl;
			cout<<"|          ������ת������������....      |"<<endl;
			cout<<"-----------------------------------------"<<endl;
			break;
		}
	}
	Sleep(1000);   //�ӳ�1��
	system("cls") ;//��������
	jiemian();     //�����ܽ��溯��
}
 
void Manager::search()        //��ѯ����
{
	int choose,m,n,a=0;
	char i,t[20];
	Cars *p,*head;
	head=&car[0];
	lianbiao();
	if(top == 0)   //����Ϊ���޷���ѯ 
		{
			cout<<"-----------------------------------------------------------"<<endl;
			cout<<"|         ������Ϣ��Ϊ�գ�ϵͳ�����ع��ܽ���....           |"<<endl;
			cout<<"-----------------------------------------------------------"<<endl;
			Sleep(600);
			system("cls");
			jiemian();
		}
	cout<<"***********************************"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*    |  1.���������칫˾��ѯ  |   *"<<endl;
	cout<<"*    |  2.����Ų�ѯ          |   *"<<endl;
	cout<<"*    |  3.������ѯ          |   *"<<endl;
	cout<<"*    --------------------------   *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"*                                 *"<<endl;
	cout<<"***********************************"<<endl;
	cout<<" ���������ѡ�";
	while(1)
	{
		cin>>i;      
		cout<<endl;
		if(i=='1'||i=='2'||i=='3')
		{
		   break;
		}
		else
		cout<<"�������,���䣺";	
	}
	
	if(i=='1')
	{
		cout<<"���������ѯ���������칫˾��";
		cin>>t;
	}
	else if(i =='2')
	{
		cout<<"���������ѯ�ĳ�����ţ�";
		cin>>n;
	}
	else if(i == '3')
	{
		cout<<"���������ѯ�ĳ����ͺ�(1-��ͳ�,2-С�γ�,3-����)��";
		cin>>m;
	}
	for(p=head;p!=NULL;p=p->next)
	{
		if(p->made==t || p->num==n || p->type==m)   //string�ַ����Ƚ�.
		{  
		    cout<<"**************************************************************************"<<endl;
			cout<<"���        ���ƺ�         ������        ����ʱ��       �ͺ�         ���� "<<endl; 
			a++;             //ʹa��Ϊ0       
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
				cout<<setw(14)<<"��ͳ�"<<setw(14)<<"�ؿ���:"<<people[j]<<endl;  //�������
			else if(car[j].type == 2 )
				cout<<setw(14)<<"С�γ�"<<setw(14)<<"������: "<<coach[j]<<endl;  
			else
				cout<<setw(14)<<"�� ��"<<setw(14)<<"������:"<<weight[j]<<endl;
			cout<<"----------------------------------------------------------------------------"<<endl;
			cout<<"----------------------------------------------------------------------------"<<endl;
			cout<<"**************************************************************************"<<endl;
			cout<<"�ܹ���        ��·��        ά����         �ͺ�         �ܷ���"<<endl;
			cout<<setw(2)<<p->km<<setw(15)<<p->RoadFee<<setw(16)<<p->cost;
			cout<<setw(14)<<p->OilKm<<setw(16)<<p->AllCount<<endl;			
		}
		j++;
	}
	if(a!=0)
	{
		cout<<"---------------------------------------------------------"<<endl;
		cout<<"|             �Ƿ�����޸�?(1-��,2-��)��                 |"<<endl;
		cout<<"---------------------------------------------------------"<<endl;
		cin>>choose;
		if(choose == 1)
		edit();        //���ñ༭���ܺ���
	}
	else             //����a++�ĺ���δ�ɹ���������1��2��3�Ĳ�ѯ���û��
	{
		if(i=='1')
		{
			cout<<"--------------------------------------------------"<<endl;
			cout<<"|               �������칫˾�����ڣ�              |"<<endl;
			cout<<"--------------------------------------------------"<<endl;
		} 
		if(i=='2') 
		{
			cout<<"---------------------------------------------------"<<endl;
			cout<<"|                ������Ų����ڣ�                  |"<<endl;
			cout<<"---------------------------------------------------"<<endl;
		}
		else if (i=='3') 
		{
			cout<<"----------------------------------------------------"<<endl;
			cout<<"|                �����ͺŲ����ڣ�                   |"<<endl;
			cout<<"----------------------------------------------------"<<endl;
		}
	}
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"|                    ����������ع���������                   |"<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
    char zz=getch();   //�޻��Ե�ȡһ���ַ�
    Sleep(700);
   	system("cls") ;//��������
    jiemian();         //���ý��溯��
}

void Manager::edit()    //�༭���������޸ĳ���      
{
	int i, j, a = 0,sm,q;
	lianbiao();
	Cars *p,*head;
	head=&car[0];
	if(top == 0)   //����Ϊ���޷��༭ 
		{
			cout<<"---------------------------------------------------------------"<<endl;
	        cout<<"|            ������Ϣ��Ϊ�գ�����������ع���������            |"<<endl;
	        cout<<"---------------------------------------------------------------"<<endl;
            char zz=getch();   //�޻��Ե�ȡһ���ַ�
            Sleep(500);
   	        system("cls") ;//��������
            jiemian();         //���ý��溯��
		}
		    cout<<"------------------------------------------------------------"<<endl;
			cout<<"|               ������Ϣ���������³������                 |"<<endl; 
			cout<<"------------------------------------------------------------"<<endl;
			
			for(int i=0;i<top;i++)
			{
				cout<<setw(10)<<car[i].num;
			}
			cout<<endl;
	cout<<"-------------------------------------------------"<<endl;
	cout<<"|         ������������Ҫ�޸ĵĳ�����Ϣ��         |"<<endl;
	cout<<"-------------------------------------------------"<<endl;
	while(1)
	{
		cout<<"������ţ�";
		cin>>i;
		for(j = 0; j < top; j++)
		{
			if(car[j].num == i)  //�����д˱�ŵĳ�
			{
				cout<<"���ƺţ�";
                cin>>temp_plus.temp_pnum;
                cout<<"���칫˾��";
                cin>>temp_plus.temp_made;
                cout<<"����ʱ��: ��/��/��"<<endl;
                car[j].set_time();
                cout<<"�ͺ�(1-��ͳ���2-С�γ���3-����)��";
                cin>>temp_plus.temp_types;
				while(!(temp_plus.temp_types==1||temp_plus.temp_types==2||temp_plus.temp_types==3)) //�ж��Ƿ�����
				{
				    cout<<"---------------------------------------------------"<<endl;
					cout<<"               ������Ϣ����������1-3��           "<<endl;
					cout<<"---------------------------------------------------"<<endl;
					cin>>temp_plus.temp_types;
				}
				cout<<"�ܹ�������";
                cin>>temp_plus.temp_km;
				cout<<"��·�ѣ�";
				cin>>temp_plus.temp_RoadFee;
				if( temp_plus.temp_types == 1 )    //��ʱ��1-��ͳ�
				{
					cout<<"����ؿ�����";
                    cin>>temp_plus.people;
                    temp_plus.temp_cost = 2000;
					temp_plus.temp_OilKm = 0.1;
				}
				else if(temp_plus.temp_types == 2 )   //��ʱ��2-С�γ�
				{
					cout<<"��������";
                    cin>>temp_plus.coach;
                    temp_plus.temp_cost = 1000;
					temp_plus.temp_OilKm = 0.05;
				}
				else                        //��ʱ��3-����
				{
					cout<<"��������";
                    cin>>temp_plus.weight;
                    temp_plus.temp_cost = 1500;
					temp_plus.temp_OilKm = 0.15;
				}
				cout<<endl;
				cout<<"---------------------------------------------"<<endl;
			    cout<<"|               ��Ϣȷ�� !!!                 |"<<endl;
			    cout<<"---------------------------------------------"<<endl;
				cout<<"������ţ�"<<temp_plus.temp_num<<"      ";
				cout<<"���ƺ�: "<<temp_plus.temp_pnum<<"      "<<endl;
				cout<<"�������칫˾��"<<temp_plus.temp_made<<"      ";
				cout<<"����ʱ��: "<<temp_plus.temp_buytime<<endl;
				cout<<"��·�ѣ� "<<temp_plus.temp_RoadFee<<"      "<<"�ܹ�������"<<temp_plus.temp_km<<endl;
				cout<<"���ͣ�"; 
				if( temp_plus.temp_types==1)
				{
					cout<<temp_plus.temp_type[0]<<"      ";
					cout<<"����ؿ�����"<<temp_plus.people<<endl;
				}
				if( temp_plus.temp_types==2)
				{
					cout<<temp_plus.temp_type[1]<<"      ";
					cout<<"��������"<<temp_plus.coach<<endl;
				}
				if( temp_plus.temp_types==3)
				{
					cout<<temp_plus.temp_type[2]<<"      ";
					cout<<"��������"<<temp_plus.weight<<endl;
				}
				cout<<"--------------------------------------------------"<<endl;
				cout<<"|                1.ȷ��      2.ȡ��               |"<<endl;
				cout<<"--------------------------------------------------"<<endl;
				cin>>sm;
				while(!( sm==1 || sm==2 )) 
				{
				    cout<<"-------------------------------------------"<<endl;
					cout<<"|            ����ָ��Ŵ������� :        |"<<endl;
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
					write();      //���ô��̺���
				    a++;         //�ɹ����һ
				}
				else if(sm==2)
				{
					
					cout<<"------------------------------------------------------"<<endl;
					cout<<"|           ȡ���޸� ������������ҳ��.....           |"<<endl;
					cout<<"------------------------------------------------------"<<endl;
					Sleep(700);
					system("cls") ;        //��������
					jiemian();
				}
			}
		}
		if(a == 0)      //δ��ɹ���˵���д���
		{
			cout<<"-------------------------------------------------"<<endl;
		    cout<<"|    �˱�Ų����ڣ����ܽ����޸ģ�����������!    |"<<endl;
		    cout<<"-------------------------------------------4------"<<endl;
		}
		
		else
		{
			cout<<"--------------------------------------------------------"<<endl;
		    cout<<"|          �޸ĳɹ���ϵͳ������������....               |"<<endl;
		    cout<<"--------------------------------------------------------"<<endl;
		    Sleep(700);
		    system("cls") ;        //��������
			break;               //����whileѭ��
		}
	}
Sleep(700);   //�ӳ�0.7��
jiemian();
}
 
void Manager::delet()        //ɾ������
{
	int i, a = 0;       //a�����ж�ѭ���Ƿ�ɹ�
	int j;
	Cars *p,*head;
	head=&car[0];
	while(1)
	{
		if(top == 0)   //����Ϊ���޷�ɾ��
		{
			cout<<"-----------------------------------------------------------"<<endl;
			cout<<"|         ������Ϣ��Ϊ�գ�ϵͳ�����ع��ܽ���....           |"<<endl;
			cout<<"-----------------------------------------------------------"<<endl;
			break;         //����whileѭ��
		}
		else          //��Ϊ��
		{
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"|               ������Ϣ���������³������                 |"<<endl; 
			cout<<"------------------------------------------------------------"<<endl;
			for(int i=0;i<top;i++)
			{
				cout<<setw(10)<<car[i].num;
			}
			cout<<endl;
			cout<<"��������Ҫɾ���ĳ�����ţ�";
			cin>>i;
			for( j = 0; j <top; j++)        //forѭ������ɾ�����д��̵���Ϣ
			{
				if(car[j].num == i)   //������Ŵ���
				{
					if(top==1)
						car[0].type=0;      //��һ������ʹ���Ϊ0					
					else                    //top������1
					{
						if( car[top - 1].type == 1 )    //�жϳ���ʱcar�����ﴢ�������һ�����1-��ͳ�
						{
							people[j] = people[j+1];         //people�ؿ���
						    car[j].cost = 2000;         
						    car[j].OilKm = 0.1;       
						}
					    else if(car[top - 1].type == 2 )    //�жϳ���ʱcar�����ﴢ�������һ�����2-С�γ�
						{
							coach[j] = coach[top - 1];  
						    car[j].cost = 1000;   
						    car[j].OilKm = 0.05;
						}
					    else if(car[top - 1].type == 3 )   //�жϳ���ʱcar�����ﴢ�������һ�����3-����
						{
						    weight[j] = weight[j+1];
						    car[j].cost = 1500;
						    car[j].OilKm = 0.15;
						}
						 car[j].num = car[top-1].num;          //ʹ���е����ݾ���һ
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
					write();   //���̺���
					lianbiao();
				}
			}		
			if(a == 0)
			{
				cout<<"----------------------------------------------------------"<<endl;
		    	cout<<"|        �˱�Ų����ڣ����ܽ���ɾ�������������룡         |"<<endl;
		    	cout<<"----------------------------------------------------------"<<endl;
			}
			
			else
			{
			    cout<<"------------------------------------------------------------"<<endl;
				cout<<"|           ɾ���ɹ���ϵͳ�����ع��ܽ���....                |"<<endl;
				cout<<"------------------------------------------------------------"<<endl;
			    Sleep(800);         //�ӳ�0.8�롣
				system("cls") ;        //�������� 
				break;
			}
		}
	}
     Sleep(700);   //�ӳ�0.7��
     system("cls") ;        //��������
     jiemian();
}
 
void Manager::write()        //������Ϣ����
{
	ofstream write;
	write.open("d:\\b.txt",ios::out);   //�������ʽ���ļ�
	if(write)
	{
		for(int i = 0; i <=top; i++)
		{
			write<<endl;
			write<<car[i].num<<" "<<car[i].pnum<<" "<<car[i].made<<" ";
			write<<car[i].buytime.year<<" "<<car[i].buytime.month<<" "<<car[i].buytime.day;
			write<<" "<<car[i].type<<" ";
		    if(car[i].type == 1)
				write<<people[i];//����   �ؿ���
		    else if(car[i].type == 2)
		     	write<<coach[i];//����    ������
		    else
			    write<<weight[i];//����    ������ 
		    write<<" "<<car[i].km<<" "<<car[i].RoadFee<<" "<<car[i].cost<<" "<<car[i].OilKm<<" "<<car[i].AllCount;
		}
	}
}

void Manager::read()            ///����������Ϣ
{
	while(1)
	{
		ifstream read("d:\\b.txt",ios::in);
	    if(read)
		{
		    while(!read.eof())   //�ļ�����������������
			{
		        read>>car[top].num>>car[top].pnum>>car[top].made;
				read>>car[top].buytime.year>>car[top].buytime.month>>car[top].buytime.day>>car[top].type;
		        if(car[top].type == 1)
			        read>>people[top];//��ȡ   �ؿ���
		        else if(car[top].type == 2)
			        read>>coach[top];//��ȡ    ������
		        else
			        read>>weight[top];//��ȡ    ������ 
		        read>>car[top].km>>car[top].RoadFee>>car[top].cost>>car[top].OilKm>>car[top].AllCount;
		        if(car[top].type==1||car[top].type==2||car[top].type==3)
		            top++;
			}
			read.close();           //�ر��ļ�
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
		if( car[j].type == 1 ) c1++;      //ͳ�ƴ�ͳ�������
		else if(car[j].type == 2) c2++;      //ͳ��С�γ�������
		else if(car[j].type==3) c3++;      //ͳ�ƿ���������
	}
	top=c1+c2+c3;
	lianbiao();
	cout<<"*********************************************"<<endl;
	cout<<"*                                           *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          | ��ӭ���복������ϵͳ |         *"<<endl;
	cout<<"*          |      1.��ӳ���      |         *"<<endl;
	cout<<"*          |      2.��ѯ����      |         *     \t\t�ܳ���\t"<<top<<endl;
	cout<<"*          |      3.��ʾ����      |         *    \t\t��ͳ�\t"<<c1<<endl;
	cout<<"*          |      4.�༭����      |         *    \t\tС�γ�\t"<<c2<<endl;
	cout<<"*          |      5.ɾ������      |         *    \t\t�� �� \t"<<c3<<endl;
	cout<<"*          |      0.�˳�ϵͳ      |         *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*          -------------------------        *"<<endl;
	cout<<"*                                           *"<<endl;
	cout<<"*********************************************"<<endl;
	cout<<endl;
	cout<<"------------------------------------------------------"<<endl;
	cout<<"            ����������Ҫ������ѡ��                     "<<endl;
	cout<<"------------------------------------------------------"<<endl;
	char i;
	cin>>i;
	while(!(i=='1'||i=='2'||i=='3'||i=='4'||i=='5'||i=='0'))
	{
		cout<<"-----------------------------------------------"<<endl;
		cout<<"|           �������,����������               |"<<endl;
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
    int temp_num;                  //���
    char temp_pnum[20];                  //���ƺ�
    char temp_made[20];             //���칫˾
    Time temp_buytime;                     //����ʱ�䣨���ٸ��£�
    int temp_type;                      //�ͺ�(1-��ͳ�,2-С�γ�,3-����)        ��������
    double temp_km;                 //�ܹ�����
    int temp_cost;                           //����ά������
	int iemp_RoadFee;                   //��·��
	double temp_OilKm;                  //������/����
	double temp_AllCount;               //�ۼ��ܷ���
	Cars car[N];
	Manager a;
	a.jiemian();
	return 0;
}
 
 
 
