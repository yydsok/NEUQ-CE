#include<windows.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
using namespace std;
#define N 20          //�������洢��20
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
}; 
struct temp
{
    int temp_num;                  //��ʱ���
    string temp_pnum;                  //��ʱ���ƺ�
    string temp_made;             //��ʱ���칫˾
    Time temp_buytime;                     //��ʱ����ʱ�䣨���ٸ��£�
    int temp_type;                      //��ʱ�ͺ�(1-��ͳ�,2-С�γ�,3-����)        ��������
    double temp_km;                 //��ʱ�ܹ�����
    int temp_cost;                           //��ʱ����ά������
	int iemp_RoadFee;                   //��ʱ��·��
	double temp_OilKm;                  //��ʱ������/����
	double temp_AllCount;               //��ʱ�ۼ��ܷ���
};
temp temp_plus;
void Time::show_time()
{
	cout<<year<<" ��"<<month<<" ��"<<day<<" ��";
}
void Time::set_time()
{
	cout<<"��� ��";
	cin>>year;
	cout<<"�·� �� ";
	cin>>month;
    cout<<"�� �� ";
	cin>>day;
	
}
class Manager;
class Cars:public Time             //������
{
public:
	int num;                  //���
    string pnum;                  //���ƺ�
    string made;             //���칫˾
    Time buytime;                     //����ʱ�䣨���ٸ��£�
    int type;                      //�ͺ�(1-��ͳ�,2-С�γ�,3-����)        ��������
    double km;                 //�ܹ�����
    int cost;                           //����ά������
	int RoadFee;                   //��·��
	double OilKm;                  //������/����
	double AllCount;               //�ۼ��ܷ���
	friend Manager;
};
class Manager               //�ܵ���
{
private:
	Cars car[N];             //������
	int people[N];         //����ؿ�������ͳ���    
	int coach[N];          //������С�γ���
	int weight[N];        //��������������
	int top;        //��¼��ǰ��������
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
};
 
void Manager::add()         //��ӳ���    �����ܵ���֮�е�add����
{
	int a = 0, x, y;        // x���������
    while(1)
	{
		if(top < N)         //�ж�top��ǰ�Ѵ泵����С���������洢��N
		{
            cout<<"����������ӵĳ�����Ϣ"<<endl;
            cout<<"������ţ�";
            cin>>x;
	        for(int j=0; j<top;j++)         //�жϱ���Ƿ��ظ�
			{
				if (car[j].num==x)     
				{
					cout<<"����ظ�,���ʧ��! ������ת������������"<<endl;
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
                car[top].set_time();
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
                if( car[top].type==1)    //��ʱ��1-��ͳ���
				{
					cout<<"����ؿ�����";
                    cin>>people[top];
                    car[top].cost = 2000;   //����ά������
					car[top].OilKm = 0.1;   //������/����
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
				car[top].AllCount =(OilPrice * car[top].OilKm * car[top].km) +(((car[top].buytime.year*12)+car[top].buytime.month)*car[top].cost);  //�����ܷ���
				top++;        //����������һ
				cout<<"��Ϣȷ�ϣ�";
				write();      //���ó�����Ϣ���̺���,�����涨��
                cout<<"�Ƿ������ӳ�����(1-��,2-��)��";
                cin>>y;
				while(!( y==1 || y==2 ))    
				{
					cout<<"����ָ��Ŵ������� : ";
					cin>>y;
				}
                if(y == 2)
				{
					cout<<" ������ת������������.... "<<endl;
					break;
				}
			}
			else       //��ʱ����ظ�
				break;
		}
		else                    //top>N
		{
			cout<<"������Ϣ������,��������ӳ��� ! "<<endl;
			cout<<"������ת������������...."<<endl;
			break;
		}
	}
	Sleep(1000);   //�ӳ�1��
	jiemian();     //�����ܽ��溯��
}
 
void Manager::search()        //��ѯ����
{
	int choose,m,n,a=0;
	char i,t[20];
	cout<<"****************************"<<endl;
	cout<<"*                          *"<<endl;
	cout<<"*  1.���������칫˾��ѯ    *"<<endl;
	cout<<"*  2.����Ų�ѯ            *"<<endl;
	cout<<"*  3.������ѯ            *"<<endl;
	cout<<"*                          *"<<endl;
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
	
	
	for(int j=0;j<top;j++)
		if((car[j].made,t)==0 || car[j].num==n || car[j].type==m)   //strcmp�Ƚϣ���ͬ����0��С�ڸ�������������
		{
			cout<<"���   ���ƺ�    ������  ����ʱ��    �ͺ�     ����     �ܹ��� ��·�� ά����  �ͺ�  �ܷ���"<<endl;
		    break;
		}
	for(int j=0;j<top;j++)
		if((car[j].made, t)==0 || car[j].num==n || car[j].type==m) 
		{
			cout<<setw(0)<<car[j].num<<setw(13)<<car[j].pnum<<setw(9)<<car[j].made<<setw(6);
			car[j].show_time();  //ǰ�ĸ�
			
			if(car[j].type==1 )
				cout<<setw(13)<<"��ͳ�"<<setw(8)<<"�ؿ���:"<<people[j];  //�������
			else if(car[j].type == 2 )
				cout<<setw(13)<<"С�γ�"<<setw(9)<<"������: "<<coach[j];  
			else
				cout<<setw(13)<<"�� ��"<<setw(9)<<"������:"<<weight[j];
			
			cout<<setw(6)<<car[j].km<<setw(7)<<car[j].RoadFee<<setw(8)<<car[j].cost<<setw(7)<<car[j].OilKm<<setw(9)<<car[j].AllCount<<endl;			
			a++;        //ʹa��Ϊ0
		}
	if(a!=0)
	{
		cout<<"�Ƿ�����޸�?(1-��,2-��)��";
		cin>>choose;
		if(choose == 1)
		edit();        //���ñ༭���ܺ���
	}
	else             //����a++�ĺ���δ�ɹ���������1��2��3�Ĳ�ѯ���û��
	{
		if(i=='1') cout<<"�������칫˾�����ڣ�"<<endl;
		if(i=='2') cout<<"������Ų����ڣ�"<<endl;
		else if (i=='3') cout<<"�����ͺŲ����ڣ�"<<endl;
	}
	cout<<"����������ع���������"<<endl;
    char zz=getch();   //�޻��Ե�ȡһ���ַ�
    jiemian();         //���ý��溯��
}
 
void Manager::show()         //��ʾ������Ϣ��
{
	if(top != 0)      //top��¼��ǰ������Ŀ
	{
		cout<<"********************************************************************************"<<endl;
		cout<<"���   ���ƺ�    ������  ����ʱ��    �ͺ�     ����     �ܹ��� ��·�� ά����  �ͺ�  �ܷ���"<<endl;
 
		for(int j = 0; j < top; j++)         //ʹ��forѭ����Ӧ�����j��������
		{
			cout<<setw(0)<<car[j].num<<setw(13)<<car[j].pnum<<setw(9)<<car[j].made<<setw(6);
			car[j].show_time();
			if(car[j].type == 1 )
			   cout<<setw(13)<<"��ͳ�"<<setw(8)<<"�ؿ���:"<<setw(2)<<people[j];
			else if(car[j].type == 2 )
			   cout<<setw(13)<<"С�γ�"<<setw(8)<<"������:"<<setw(2)<<coach[j];
			else
			   cout<<setw(13)<<"�� �� "<<setw(8)<<"������:"<<setw(2)<<weight[j];
			cout<<setw(6)<<car[j].km<<setw(7)<<car[j].RoadFee<<setw(8)<<car[j].cost<<setw(7)<<car[j].OilKm<<setw(9)<<car[j].AllCount<<endl;
		}
		cout<<"********************************************************************************"<<endl;
	}
	else                               
		cout<<"������Ϊ�գ�"<<endl;
	cout<<"�����������������:";
	char z=getch();        //��������һ���ַ�֮����ý��溯��
	jiemian();
}
 
void Manager::edit()    //�༭���������޸ĳ���      
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
                cout<<"����ʱ�䣺     ��      ��     ��";
                car[j].show_time();
                cout<<"�ͺ�(1-��ͳ���2-С�γ���3-����)��";
                cin>>car[j].type;
				
				while(!(car[j].type==1||car[j].type==2||car[j].type==3)) //�ж��Ƿ�����
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
				else                        //��ʱ��3-����
				{
					cout<<"��������";
                    cin>>weight[j];
                    car[j].cost = 1500;
					car[j].OilKm = 0.15;
				}
				
				write();                  //���ô��̺���
				a++;         //�ɹ����һ
			}
			
		}
		if(a == 0)      //δ��ɹ���˵���д���
			cout<<"�˱�Ų����ڣ����ܽ����޸ģ����������룡"<<endl;
		else
		{
			cout<<"�޸ĳɹ���ϵͳ������������..."<<endl;
			break;               //����whileѭ��
		}
	}
Sleep(1000);   //�ӳ�1��
jiemian();
}
 
void Manager::delet()        //ɾ������
{
	int i, a = 0;       //a�����ж�ѭ���Ƿ�ɹ�
	while(1)
	{
		if(top == 0)   //����Ϊ���޷�ɾ��
		{
			cout<<"������Ϣ��Ϊ�գ�ϵͳ�����ع��ܽ���...."<<endl;
			break;         //����whileѭ��
		}
		else          //��Ϊ��
		{
			cout<<"��������Ҫɾ���ĳ�����ţ�";
			cin>>i;
			for(int j = 0; j < top; j++)        //forѭ������ɾ�����д��̵���Ϣ
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
						car[j].num = car[j+1].num;          //ʹ���е����ݾ���һ
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
					write();   //���̺���
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
		        read>>car[top].num>>car[top].pnum>>car[top].made>>car[top].buytime.year>>car[top].buytime.month>>car[top].buytime.day>>car[top].type;
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
		    ofstream o("d:\\a.txt");      
		    o.close();
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
	cout<<"************************************"<<endl;
	cout<<"*        ��ӭ���복������ϵͳ      *"<<endl;
	cout<<"*            1.��ӳ���            *"<<endl;
	cout<<"*            2.��ѯ����            *\t\t�ܳ���\t"<<top<<endl;
	cout<<"*            3.��ʾ����            *\t\t��ͳ�\t"<<c1<<endl;
	cout<<"*            4.�༭����            *\t\tС�γ�\t"<<c2<<endl;
	cout<<"*            5.ɾ������            *\t\t�� �� \t"<<c3<<endl;
	cout<<"*            0.�˳�ϵͳ            *"<<endl;
	cout<<"************************************"<<endl;
	cout<<"����������Ҫ������ѡ��:";
	char i;
	cin>>i;
	while(!(i=='1'||i=='2'||i=='3'||i=='4'||i=='5'||i=='0'))
	{
		cout<<"�������,����������:";
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
	Manager a;
	a.jiemian();
	return 0;
}
 
 
 
