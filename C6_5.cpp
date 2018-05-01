#include <iostream>
using namespace std;
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
		}
		~cdate(){};
		cdate(unsigned int m,unsigned  int d,unsigned  int y)
		{
			this->day=d;
			this->month=m;
			this->year=y;
		}
		void setdate(sdate);
		void setdate();
		void showdate();
};
int main()
{
	cdate d1;
	d1.setdate();
	cout<<"Your birthday: ";
	d1.showdate();
	return 0;
}
bool check_date(int d,int m,int y)
{
	bool accepable=true;
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
	return accepable;
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
void cdate::setdate()
{
	bool checkdate=false;
	char c;
	do
	{
		cout<<"Enter your date (mm/dd/yyyy): ";
		cin>>month>>c>>day>>c>>year;
		checkdate=check_date(day, month, year);
		if(checkdate==false)
		{
			cout<<"Your date is Invalid!"<<endl;
			cout<<"Please Enter again!"<<endl;
		}
	}while(checkdate==false);	
}
void cdate::showdate()
{
	cout<<"(mm/dd/yyyy) :"<<month<<"/"<<day<<"/"<<year<<endl;
}
