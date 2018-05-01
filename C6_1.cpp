#include <iostream>
using namespace std;
class Int
{
	private:
		int number=0;
	public:
		Int(){};
		Int(int n)
		{
			this->number=n;
		}
		void setdata(int n)
		{
			number=n;
		}
		int getdata()
		{
			return number;
		}
		void showdata()
		{
			cout<<number<<endl;
		}
		Int adding(Int ,Int);
};
int main ()
{
	Int n,n1(1),n2(2);
	cout<<"Number 1: ";
	n1.showdata();
	cout<<"Number 2: ";
	n2.showdata();
	n.adding(n1, n2);
	cout<<"Result (Number 1 + Number 2): ";
	n.showdata();
	return 0;
}
Int Int::adding(Int a, Int b)
{
	number=a.getdata()+b.getdata();
}
