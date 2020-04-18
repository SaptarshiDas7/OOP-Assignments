#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class Complex
{
	float r;
	float i;
	public:
		Complex(float a,float b)
		{
			r=a;
			i=b;
		}
		void disp()
		{
			cout<<r;
			if(i!=0)
			{
				if(i<0)
					cout<<"-"<<-i<<"i";
				else
					cout<<"+"<<i<<"i";
			}
			cout<<endl;
		}
};

class Quadratic
{
	int a[3];
	public:
		Quadratic()
		{
			for(int i=0;i<3;i++)
			{
				a[i]=0;
			}
		}
		Quadratic(int p,int q,int r)
		{
			a[0]=p;
			a[1]=q;
			a[2]=r;
		}
		Quadratic operator +(Quadratic &A)
		{
			Quadratic C;
			for(int i=0;i<3;i++)
			{
				C.a[i]=A.a[i]+a[i];
			}
			return C;
		}
		int value(int x)
		{
			int sum=0;
			for(int i=0;i<3;i++)
			{
				sum=a[i]*pow(x,i);
			}
			return sum;
		}
		void roots()
		{
			float x=pow(a[1],2)-4*a[2]*a[0];
			float y=-a[1];
			y=y/2/a[2];
			if(x<0)
			{
				Complex P(y,pow(-x,0.5)/2/a[2]);
				Complex Q(y,-pow(-x,0.5)/2/a[2]);
				P.disp();
				Q.disp();
			}
			else
			{
				Complex P(y+pow(x,0.5)/2/a[2],0);
				Complex Q(y-pow(x,0.5)/2/a[2],0);
				P.disp();
				Q.disp();
			}
		}
		friend ostream & operator<<(ostream &os,Quadratic &Q);
		friend istream & operator>>(istream &is,Quadratic &Q);
};


ostream & operator<<(ostream &os,Quadratic &Q)
{
	for(int i=2;i>=0;i--)
	{
		os<<Q.a[i]<<"x^"<<i;
		if(i>0)
		{
			os<<"+";
		}
	}
	cout<<endl;
}

istream & operator>>(istream &is,Quadratic &Q)
{
	for(int i=0;i<3;i++)
	{
		cin>>Q.a[i];
	}
}

int main()
{
	Quadratic A(2,3,4);
	Quadratic B(1,-2,1);
	Quadratic C;
	C=A+B;
	Quadratic D;
	cout<<"Enter the coefficients of the equation:"<<endl;
	cin>>D;
	cout<<A<<B<<C<<D;
	cout<<"The roots of the 1st equation are:"<<endl;
	A.roots();	
	cout<<"The roots of the 2nd equation are:"<<endl;
	B.roots();	
}
