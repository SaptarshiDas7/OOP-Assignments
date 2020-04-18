#include<iostream>
#include<stdlib.h>
using namespace std;

class Shape2D
{
	public:
		virtual float area()=0;
		virtual float peri()=0;
};

class Circle:public Shape2D
{
	float r;
	public:
		Circle(float a=0)
		{
			r=a;
		}
		float peri()
		{
			return 44/7.0*r;
		}
		float area()
		{
			return 22/7.0*r*r;
		}
};

class Rectangle:public Shape2D
{
	float l;
	public:
		Rectangle(float l=0)
		{
			this->l=l;
		}
		float peri()
		{
			return 4*l;
		}
		float area()
		{
			return l*l;
		}
};

int main()
{
	Shape2D *arr[5];
	Circle C1(7);
	Circle C2(15.4);
	Circle C3(10);
	Rectangle R1(5);
	Rectangle R2(4.2);
	arr[0]=&C1;
	arr[1]=&C2;
	arr[2]=&C3;
	arr[3]=&R1;
	arr[4]=&R2;
	cout<<"Perimeter\t"<<"Area"<<endl;
	
	for(int i=0;i<5;i++)
	{
		cout<<(arr[i]->peri())<<"\t\t"<<(arr[i]->area())<<endl;
	}
	return 0;
}
