#include<iostream>
using namespace std;

class Base1
{
	public:
};

class Base2
{
	public:
};

class derived:public Base1,public Base2
{
	public:
};

int main()
{
	derived d1;
	return 0;
}
