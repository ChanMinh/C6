#include<iostream>
using namespace std;
class time
{
	private:
		unsigned int hours;
		unsigned int minutes;
		unsigned int seconds;
	public:
		time()
		{
			hours=0;
			minutes=0;
			seconds=0;
		}
		~time(){};
		time(unsigned int h, unsigned m, unsigned s)
		{
			this->hours=h;
			this->minutes=m;
			this->seconds=s;
		}
		void set_time(unsigned int s)
		{
			seconds=s;
		}
		void set_time(unsigned int m, unsigned s)
		{
			minutes=m;
			seconds=s;
		}
		void set_time(unsigned int h, unsigned m, unsigned int s)
		{
			hours=h;
			minutes=m;
			seconds=s;
		}
		int get_hours()
		{
			return hours;
		}
		int get_minutes()
		{
			return minutes;
		}
		int get_seconds()
		{
			return seconds;
		}
		time add_time(time, time);
		void showdata()
		{
			cout<<"Time: "<<hours<<":"<<minutes<<":"<<seconds<<endl;
		}
};
int main()
{
	time t1, t2, t3;
	t1.set_time(3,50,12);
	t1.showdata();
	t2.set_time(4,23,4);
	t2.showdata();
	t3.add_time(t1,t2);
	t3.showdata(); 
	
	return 0;
}
time time::add_time(time a, time b)
{
	seconds=a.get_seconds()+b.get_seconds();
	if(seconds>=60)
	{
		seconds-=60;
		minutes+=1;
	}
	minutes=a.get_minutes()+b.get_minutes()+minutes;
	if(minutes>=60)
	{
		minutes-=60;
		hours+=1;
	}
	hours=a.get_hours()+b.get_hours()+hours;
	if(hours>=12)
	{
		hours=0;
	}
}
