#include <iostream>
using namespace std;
class employee
{
	private:
		int emp_number;
		float emp_compensation;
	public:
		employee()
		{
			emp_number=0;
			emp_compensation=0.0;
		}
		employee(int numb, float comp)
		{
			this->emp_number=numb;
			this->emp_compensation=comp;
		}
		~employee(){};
		void set_empInfo();
		void show_employee_data();
};
int main ()
{
	employee e[3];
	cout<<"Enter Employee's information: "<<endl;
	for(int i=1; i<=3; i++)
	{
		e[i].set_empInfo();
	}
	cout<<"Successful!"<<endl;
	cout<<"Show Employee's information: "<<endl;
	for(int i=1; i<=3; i++)
	{
		e[i].show_employee_data();
	}
	
	return 0;
}
void employee::set_empInfo()
{
	cout<<"Employee's Number: ";	cin>>emp_number;	cout<<endl;
	cout<<"Employee's Compensation: ";	cin>>emp_compensation;	cout<<endl;
}
void employee::show_employee_data()
{
	cout<<"Employee's number: "<<emp_number<<endl;
	cout<<"Employee's compentation: "<<emp_compensation<<endl;
}
