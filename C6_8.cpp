#include <iostream>
using namespace std;
class object
{
	private:
		static unsigned int count;
		unsigned int serial;
	public:
		object()
		{
			count+=1;
			serial=count;
		}
		void respond();
		
};
int main()
{
	object o1, o2, o3;
	//o1.respond();
	o2.respond();
	//o3.respond();
	return 0;
}
void object::respond()
{
	cout<<"I am object number "<<serial<<endl;
}
unsigned int object::count=0;
