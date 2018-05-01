#include <iostream>
using namespace std;
enum etype
{
	laborer,	
	secretary,	
	manager,	
	accountant,	
	executive,	
	researcher	
};
bool check_date(int, int, int);
struct sdate
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};
class cdate
{
	private:
		unsigned int day;
		unsigned int month;
		unsigned int year;
	public:
		cdate()
		{
			day=0;
			month=0;
			year=0;
		};
		void setdate(sdate);
		void setdate();
		void showdate();
};
class employee
{
	private:
		int emp_number;
		float emp_comp;
		cdate emp_date;
		etype emp_job;
	public:
		employee()
		{
			emp_number=0;
			emp_comp=0.0f;
		}
		~employee(){};
		void enterEmp_info();
		void showEmp_info();
};
int main()
{
	employee emp[3];
	for(int i=0; i<3; i++)
	{
		emp[i].enterEmp_info();
	}
	cout<<"Successful!"<<endl;
	for(int i=0; i<3; i++)
	{
		emp[i].showEmp_info();
	}
	return 0;
}
void cdate::setdate(sdate d)
{
	bool checkdate=false;
	checkdate=check_date(d.day, d.month, d.year);
	if(checkdate==true)
	{	
		day=d.day;
		month=d.month;
		year=d.year;
	}
	else
	{
		cout<<"Your date is Invalid!"<<endl;
	}
}
bool check_date(int d,int m,int y)
{
	bool accepable=true;
	if(d<0 || m<0 || y<0)
	{
		accepable=false;
	}
	else
	{
		switch(m)
		{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				{
					if(d>31)
					{
						accepable=false;
					}
					break;
				}
			case 4: case 6: case 9: case 11:
				{
					if(d>30)
					{
						accepable=false;
					}
					break;
				}
			case 2:
				{
					if(y%4==0 && d>29)
					{
						accepable=false;
					}
					if(y%4!=0 && d>28)
					{
						accepable=false;
					}
					break;
				}
			default:
				accepable=false;
				break;
		}
	}
	return accepable;
}
void cdate::setdate()
{
	char c;
	bool checkdate=false;
	do
	{
		cin>>day>>c>>month>>c>>year;
		checkdate=check_date(day, month, year);
		if (checkdate==false)
		{
			cout<<"Your date is invalid!"<<endl;
			cout<<"Please enter again."<<endl;
		}
	} while (checkdate==false);
	
}
void cdate::showdate()
{
	cout<<day<<"/"<<month<<"/"<<year<<endl;
}
void employee::enterEmp_info()
{
	cout<<"Enter Employee's Info"<<endl;
	cout<<"Employee's number: ";	cin>>emp_number;	cout<<endl;
	cout<<"Employee's compensation: ";	cin>>emp_comp;	cout<<endl;
	cout<<"Employee's hired date (dd/mm/yyyy): ";
	emp_date.setdate();	cout<<endl;
	char key=0;
	bool checkjob=false;
	do
	{
		cout<<"Employee's job: ";	cin>>key;
		//fflush(stdin);
		switch(key)
		{
			case 'l':
			{
				emp_job=laborer;
				checkjob=true;
				break;
			}
			case 's':
			{
				emp_job=secretary;
				checkjob=true;
				break;
			}	
			case 'm':
			{
				emp_job=manager;
				checkjob=true;
				break;
			}
			case 'a':
			{
				emp_job=accountant;
				checkjob=true;		
				break;
			}
			case 'e':
			{
				emp_job=executive;
				checkjob=true;
				break;
			}
			case 'r':
			{
				emp_job=researcher;
				checkjob=true;	
				break;
			}
			default:
				{
				cout<<"There is no employee type for that letter!"<<endl;
				cout<<"Acceptable Letters is:"<<endl;
				cout<<"<l> for <laborer>."<<endl;
				cout<<"<s> for <secretary>."<<endl;
				cout<<"<m> for <manager>."<<endl;
				cout<<"<a> for <accountance>."<<endl;
				cout<<"<e> for <executive>."<<endl;
				cout<<"<r> for <researcher>."<<endl;
				cout<<"Please enter again!"<<endl;
				checkjob=false;
				break;
				}
		}
	} while(checkjob==false);
}
void employee::showEmp_info()
{
	cout<<"-----------------------------------"<<endl;
	cout<<"Employee's Information"<<endl;
	cout<<"Employee's number: "<<emp_number<<endl;
	cout<<"Employee's compensation: "<<emp_comp<<endl;
	cout<<"Employee's hired date: ";emp_date.showdate();
	cout<<"Employee's job: ";
	switch(emp_job)
	{
		case laborer:
		{
			cout<<"Laborer"<<endl;
			break;
		}
		case secretary:
		{
			cout<<"Secretary"<<endl;
			break;
		}	
		case manager:
		{
			cout<<"Manager"<<endl;
			break;
		}
		case accountant:
		{
			cout<<"Accountant"<<endl;	
			break;
		}
		case executive:
		{
			cout<<"Executive"<<endl;
			break;
		}
		case researcher:
		{
			cout<<"Researcher"<<endl;
			break;
		}
	}
}
