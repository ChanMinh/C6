#include <iostream>
using namespace std;
struct sfraction
{
	int numerator;
	int denominator;
};
class cfraction
{
	private:
			int numerator;
			int denominator;
	public:
		cfraction()
		{
			numerator=0;
			denominator=1;
		};
		~cfraction(){};
		void set_fraction(sfraction f);
		int get_numerator()
		{
			return numerator;
		}
		int get_denominator()
		{
			return denominator;
		}
		void set_fraction();
		cfraction add_fraction(cfraction, cfraction);
		void show_fraction();
};
int main()
{
	char choice;
	cfraction f1, f2, f3;
	bool exit_program=false;
	do
	{
		cout<<"Enter first fraction: ";	f1.set_fraction();	cout<<endl;
		cout<<"Enter second fraction: ";f2.set_fraction();	cout<<endl;
		f3.add_fraction(f1,f2);
		cout<<"Result (fraction 1 + fraction 2): ";	f3.show_fraction();	cout<<endl;
		cout<<"Do you want to continue: "<<endl;
		cout<<"Yes(y) or No(n)?"<<endl;
		cout<<"Your choice: ";	cin>>choice;
		switch(choice)
		{
			case 'y':
				{
					exit_program=false;
					break;
				}
			default:
				{
					exit_program=true;
				}
		}	
	}while(exit_program==false);
	return 0;
}
void cfraction::set_fraction(sfraction f)
{
	this->numerator=f.numerator;
	this->denominator=f.denominator;
}
void cfraction::set_fraction()
{
	char c;
	//cout<<"Enter fraction (a/b): ";	
	cin>>numerator>>c>>denominator;
}
void cfraction::show_fraction()
{
	cout<<numerator<<"/"<<denominator;
}
cfraction cfraction::add_fraction(cfraction a, cfraction b)
{
	numerator=(a.get_numerator()*b.get_denominator()+b.get_numerator()*a.get_denominator());
	denominator=a.get_denominator()*b.get_denominator();
}
