#include<iostream>
using namespace std;

class Complex
{
	int x;
	int y;
	public:
		Complex(int a,int b)
		{
			x=a;
			y=b;
		}
		
		int operator > (Complex &C)
		{
			int a=C.x*C.x+C.y*C.y;
			int b=x*x+y*y;
			if(a>b)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		friend ostream & operator <<(ostream &os,Complex &); 
};

ostream & operator <<(ostream &os,Complex &C)
{
	os<<C.x<<" + "<<C.y<<"i";
	return os;
};

template<typename T>
void max(T &a,T &b)
{
	cout<<"Maximum is: ";
	if(a>b)
	{
		cout<<a;
	}
	else
	{
		cout<<b;
	}
	cout<<endl;
}

template<typename A>
void max(char a[],char b[])
{
	cout<<"\nMaximum is: ";
	int flag=1;
	for(int i=0;a[i]!='\0' && b[i]!='\0';i++)
	{
		if(a[i]>b[i])
		{
			puts(a);
			flag=0;
			break;
		}
		else
		{
			puts(b);
			flag=0;
			break;
		}
	}
	if(flag==1)
	{
		puts(a);
	}
}

int main()
{
	Complex A(1,2);
	Complex B(2,3);
	int a=2,b=4;
	max(a,b);
	max(A,B);
	char p[]="abc";
	char q[]="atb";
	max(p,q);
	return 0;	
}
