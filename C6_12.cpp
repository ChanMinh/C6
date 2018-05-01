#include <iostream>
#include <cmath>
using namespace std;
class fraction
{
	private:
			int numerator;
			int denominator;
	public:
		fraction()
		{
			numerator=0;
			denominator=1;
		};
		~fraction(){};
		void get_fraction(int num, int den)
		{
			this->numerator=num;
			this->denominator=den;
		}
		void set_numerator(int num)
		{
			numerator=num;
		}
		void set_denominator(int den)
		{
			denominator=den;
		}
		int get_numerator()
		{
			return numerator;
		}
		int get_denominator()
		{
			return denominator;
		}
		void set_fraction();
		fraction multi_fraction(fraction, fraction);
		fraction add_fraction(fraction, fraction);
		void show_multi_table();
		void lowterms();
		void show_fraction();
};
class fraction_multiply_table
{
	private:
		int denominator;
	public:
		fraction_multiply_table()
		{
			denominator=1;
		}
		fraction_multiply_table(int dem)
		{
			this->denominator=dem;
		}
		void set_multy_table(int dem)
		{
			denominator=dem;
		}
		void show_multi_table();
};
int main()
{
	int n;
	fraction f;
	cout<<"Enter denominator: ";	cin>>n;
	f.set_denominator(n);
	f.show_multi_table();
	return 0;
}
void fraction::set_fraction()
{
	char c;
	//cout<<"Enter fraction (a/b): ";	
	cin>>numerator>>c>>denominator;
}
void fraction::show_fraction()
{
	cout<<numerator<<"/"<<denominator;
}
fraction fraction::add_fraction(fraction a, fraction b)
{
	numerator=(a.get_numerator()*b.get_denominator()+b.get_numerator()*a.get_denominator());
	denominator=a.get_denominator()*b.get_denominator();
}
fraction fraction::multi_fraction(fraction f1, fraction f2)
{
	//fraction f;
	numerator=f1.get_numerator()*f2.get_numerator();
	denominator=f1.get_denominator()*f2.get_denominator();
	//return f;
}
void fraction::lowterms()
{
	long tnum, tden, temp, gcd;
	tnum=abs(numerator);
	tden=abs(denominator);
	if(tden==0)
	{
		cout<<"Illegal fraction: division by 0; exit(1);";
	}
	else
	{
		if(tnum==0)
		{
			numerator=0;
			denominator=1;
			return;
		}
	}
	while(tnum!=0)
	{
		if(tnum<tden)
		{
			temp=tnum;
			tnum=tden;
			tden=temp;
		}
		tnum=tnum-tden;
	}
	gcd=tden;
	numerator=numerator/gcd;
	denominator=denominator/gcd;
}
void fraction::show_multi_table()
{
	fraction **f = new fraction*[denominator];
	for(int i=1; i<denominator; i++)
	{
		f[i] = new fraction[denominator];
		f[i][0].set_numerator(i);
		f[i][0].set_denominator(denominator);
		f[i][0].lowterms();
	}
	for(int i = 1; i < denominator;i++)
	{
		f[i][0].show_fraction();
		cout<<"\t";
		for(int j = 1; j< denominator;j++)
		{
			f[i][j].multi_fraction(f[i][0], f[j][0]);
			f[i][j].lowterms();
			f[i][j].show_fraction();
			cout<<"\t";
		}
		cout<<endl;
	}
	delete []f;
};
