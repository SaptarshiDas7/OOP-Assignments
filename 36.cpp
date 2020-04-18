#include<iostream>
#include<stdlib.h>

using namespace std;

class Array
{
	public:
		int *buf;
		int len;
		Array(int n=0)
		{
			buf=new int[n];
			len=n;
		}

		int &operator[](int n)
		{
			if(n>len)
			{
				cout<<"Overflow\n";
				return buf[0];
			}
			return buf[n];
		}
};

class Table
{
	public:
		Array *p;
		int r,c;
		Table(int t=0,int n=0)
		{
			p=new Array[t];
			r=t;
			c=n;
			for(int i=0;i<r;i++)
			{
			    p[i].buf=new int[c];
			    p[i].len=c;
			    
			}
		}

		Array & operator [](int n)
		{
			return p[n];	
		}

		friend istream & operator >>(istream &is,Table &T);
		friend ostream & operator <<(ostream &os,Table &T);
};

istream & operator >>(istream &is,Table &T)
{
	for(int i=0;i<T.r;i++)
	{
		for(int j=0;j<T.c;j++)
		{
			is>>T.p[i].buf[j];
		}
	}
	return is;
} 
ostream & operator <<(ostream &os,Table &T)
{
	for(int i=0;i<T.r;i++)
	{
		for(int j=0;j<T.c;j++)
		{
			os<<T.p[i].buf[j]<<"\t";
		}
		cout<<endl;
	}
	return os;
}


int main()
{
Table t(4, 5), t1(4, 5);
cout<<"Enter the elements of 1st table:"<<endl;
cin >> t;
t[0][0] = 5;
int x = t[2][3];
t1 = t;
cout << t << endl << t1<<endl<<"x="<<x;
return 0;
}
