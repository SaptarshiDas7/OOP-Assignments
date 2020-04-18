#include<iostream>
#include<stdlib.h>
using namespace std;

class Person
{
	char name[20];
	int age;
	float height;
	public:
		Person()
		{
		}
		
		void get()
		{
			int i;
			for(i=0;i<10;i++)
			{
				name[i]=rand()%26+65;
			}
			name[i]='\0';
			age=rand()%5+18;
			height=rand()%80+120;
		}
		
		virtual void printDetails()
		{
			cout<<"Name of person: "<<name<<endl;
			cout<<"Age: "<<age<<"years"<<endl;
			cout<<"Height: "<<height<<"cm"<<endl;
		}
};


class Student:public Person
{
	int roll;
	int year;
	public:
		Student()
		{	
		}
		void get()
		{
			Person::get();
			roll=rand()%60+1;
			year=rand()%10+2010;
		}
		void printDetails()
		{
			Person::printDetails();
			cout<<"Roll: "<<roll<<endl;
			cout<<"Year of admission: "<<year<<endl;
		}
};

int main()
{
	Person D;
	Student I;
	D.get();
	I.get();	
	D.printDetails();
	cout<<endl;
	
	I.printDetails();
	cout<<endl;
	
	Person P,Q;
	Student S,A;
	Person *ptr[4];
	ptr[0]=&P;
	ptr[1]=&Q;
	ptr[2]=&S;
	ptr[3]=&A;
	
	for(int i=0;i<4;i++)
	{
		ptr[i]->get();
	}

	for(int i=0;i<4;i++)
	{
		ptr[i]->printDetails();
		cout<<endl;
	}
	return 0;
}
