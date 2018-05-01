#include <iostream>
using namespace std;
class angle
{
	private:
		int degrees;
		float minutes;
		char direction;
	public:
		angle()
		{
			degrees=0;
			minutes=0.0f;
		}
		~angle(){};
		void set_longitude();
		void set_latitude();
		void set_angle();
		void show_angle();
};
int main()
{
	char choice;
	angle a;
	bool exit_program=false;
	do
	{
		a.set_angle();
		cout<<"-----------------------"<<endl;
		a.show_angle();
		cout<<"Do you want to continue?"<<endl;
		cout<<"Yes(y) or No(n)"<<endl;
		cout<<"Your choice: ";
		cin>>choice;
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
					break;
				}
		}
	}while(exit_program==false);
	return 0;
}
void angle::set_longitude()
{
	bool check_dir=false;
	char c;
	cout<<"Enter Longitude Angle value: "<<endl;
	do
	{
		do
		{
			cout<<"degrees: ";	cin>>degrees;	cout<<endl;
			if(degrees>180)
			{
				cout<<"The Degrees value must be smaller than 180!"<<endl;
				cout<<"Please Enter again!"<<endl;
			}
		}while(degrees>180);
		do
		{
			cout<<"minutes: ";	cin>>minutes;	cout<<endl;
			if(minutes<0)
			{
				cout<<"The Minutes value must be bigger than 0!"<<endl;
				cout<<"Please Enter again!"<<endl;
			}
		}while(minutes>=0);	
		for(;minutes>=60; minutes-=60)
		{
			degrees+=1;
		}
		if(degrees>180)
		{
			cout<<"The Degrees value must be smaller than 180!"<<endl;
		}
	}while(degrees>180);
	do
	{
		cout<<"direction: ";cin>>c;	cout<<endl;
		switch(c)
		{
			case 'e':
				{
					direction='E';
					check_dir=true;
					break;
				}
			case 'w':
				{
					direction='W';
					check_dir=true;
					break;
				}
			default:
				{
					cout<<"The Longitude direction is Invalid!"<<endl;
					cout<<"<e> for <East>"<<endl;
					cout<<"<w> for <West>"<<endl;
					cout<<"Please enter again!"<<endl;
					break;
				}
		}
	}while(check_dir==false);
}
void angle::set_latitude()
{
	bool check_dir=false;
	char c;
	cout<<"Enter Latitude Angle value: "<<endl;
	do
	{		
		do
		{
			cout<<"degrees: ";	cin>>degrees;	cout<<endl;
			if(degrees>90)
			{
				cout<<"The Degrees value must be smaller than 90!"<<endl;
				cout<<"Please enter again!"<<endl;
			}
		}while(degrees>90);
		do
		{
			cout<<"minutes: ";	cin>>minutes;	cout<<endl;
			if(minutes<0)
			{
				cout<<"The Minutes value must be bigger than 0!"<<endl;
				cout<<"Please Enter again!"<<endl;
			}
		}while(minutes>=0);
		for(;minutes>=60; minutes-=60)
		{
			degrees+=1;
		}
		if(degrees>90)
		{
			cout<<"The Latitude Angle is Invalid";
		}
	}while(degrees>90);
	do
	{
		cout<<"direction: ";cin>>c;	cout<<endl;
		switch(c)
		{
			case 's':
				{
					direction='S';
					check_dir=true;
					break;
				}
			case 'n':
				{
					direction='N';
					check_dir=true;
					break;
				}
			default:
				{
					cout<<"The Latitude direction is Invalid!"<<endl;
					cout<<"<s> for <South>"<<endl;
					cout<<"<n> for <North>"<<endl;
					cout<<"Please enter again!"<<endl;
					break;
				}
		}
	}while(check_dir==false);
}
void angle::set_angle()
{
	bool check_dir=false;
	char c;
	cout<<"Enter Angle value: "<<endl;
	cout<<"degrees: ";	cin>>degrees;	cout<<endl;
	do
	{
		cout<<"minutes: ";	cin>>minutes;	cout<<endl;
		if(minutes<0)
		{
			cout<<"The Minutes value must be bigger than 0!"<<endl;
			cout<<"Please Enter again!"<<endl;
		}
	}while(minutes<0);
	do
	{
		cout<<"direction: ";cin>>c;	cout<<endl;
		switch(c)
		{
			case 'e':
				{
					direction='E';
					check_dir=true;
					break;
				}
			case 'w':
				{
					direction='W';
					check_dir=true;
					break;
				}
			case 's':
				{
					direction='S';
					check_dir=true;
					break;
				}
			case 'n':
				{
					direction='N';
					check_dir=true;
					break;
				}
			default:
				{
					cout<<"The direction is Invalid!"<<endl;
					cout<<"<e> for <East>"<<endl;
					cout<<"<w> for <West>"<<endl;
					cout<<"<s> for <South>"<<endl;
					cout<<"<n> for <North>"<<endl;
					cout<<"Please enter again!"<<endl;
					break;
				}
		}
	}while(check_dir==false);
}
void angle::show_angle()
{
	cout<<"Your Angle is: ";
	cout<<degrees<<'\xF8'<<" "<<minutes<<"' "<<direction<<endl;
}
