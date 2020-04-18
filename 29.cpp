#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class Book
{
	public:
		string isbn;
		string title;
		string A[5];
		int price;
		
		Book()
		{
		}
		
		void get()
		{
			for(int i=0;i<2;i++)
			{
				isbn=isbn+char(rand()%10+65);
			}
			for(int i=0;i<10;i++)
			{
				title=title+char(rand()%26+65);
			}
			for(int i=0;i<5;i++)
			{
				string a="";
				for(int j=0;j<10;j++)
				{
					a=a+char(rand()%26+65);
				}
				A[i]=a;
				a.clear();	
			}
			price=rand()%500+500;
		}
		
		int cost()
		{
			return price;
		}
};


class BookStore
{
	public:
		Book A[100];
		string B[100];
		
		BookStore()
		{
			for(int i=0;i<100;i++)
			{
				A[i].get();
			}
		}
	
		void books()
		{
			int k=0;
			for(int i=0;i<100;i++)
			{
				for(int j=0;i<100;i++)
				{
					if(B[j]!=A[i].isbn)
					{
						B[k]=B[j];
						k++;
					}
				}
			}
		}
		
		int noOfCopies(string a)
		{
			int c=0;
			for(int i=0;i<100;i++)
			{
				if(a==A[i].isbn)
				{
					c++;
				}
			}
			return c;
		}
		
		int cost()
		{
			int price=0;
			for(int i=0;i<100;i++)
			{
				price=price+A[i].price;
			}
			return price;
		}
};

int main()
{
	BookStore P;
	for(int i=0;i<100;i++)
	{
		cout<<P.A[i].title<<endl<<"No. of copies= "<<P.noOfCopies(P.A[i].isbn)<<endl;
	}
	cout<<"Total cost of all th books= "<<P.cost();
	return 0;
}
