#include<iostream>
#include<conio.h>
using namespace std;
class tollbooth
{
	private:
		unsigned int total_Car=0;
		unsigned int paying_Car=0;
		double cash=0.0;
	public:
		tollbooth(){}
		tollbooth(unsigned int tc, unsigned int pc)
		{
			this->total_Car=tc;
			this->paying_Car=pc;
		}
		void setdata(unsigned tc, unsigned pc)
		{
			total_Car=tc;
			paying_Car=pc;
		}
		unsigned int get_totalCar()
		{
			return total_Car;
		}
		unsigned int get_payingCar()
		{
			return paying_Car;
		}
		void payingCar_cash()
		{
			total_Car++;
			paying_Car++;
			cash+=0.5;
		}
		void nopayCar()
		{
			total_Car++;
		}
		void showdata()
		{
			cout<<"Total cars: "<<total_Car<<endl;
			cout<<"Paying cars: "<<paying_Car<<endl;
			cout<<"Cash: "<<cash<<"$"<<endl;
		}
	
};
int main()
{
	tollbooth bot;
	char c;
	bool Exit_program=false;
	while(Exit_program==false)
	{
		if(kbhit)
		{
			c=getch();
			switch(c)
			{
				case 97://97=a
					{
						cout<<"Car +1"<<endl;
						cout<<"Paying Car +1"<<endl;
						bot.payingCar_cash();
						break;
					}
				case 100://100=d
					{
						cout<<"Car +1"<<endl;
						bot.nopayCar();
						break;
					}
				case 101://101=e
					{
						cout<<"---------------"<<endl;
						bot.showdata();
						Exit_program=true;
						break;
					}
				default:
					Exit_program=true;
					break;
			}
		}
	}
	return 0;
}
