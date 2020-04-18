#include<iostream>
#include<stdlib.h>
using namespace std;

class Employee
{
	string name;
	int sal;
	
	public:
	Employee()
	{
	}
	void get()
	{
		for(int i=0;i<10;i++)
		{
			name=name+char(rand()%26+65);
		}
		sal=rand()%1000+10000;
	}
	virtual void printDetails()
	{
		cout<<"Name of Employee: "<<name<<endl;
		cout<<"Salary: "<<sal<<endl;
	}
};

class Manager:public Employee
{
	int type;
	int all;
	
	public:
		Manager()
		{
		}
		void get()
		{
			Employee::get();
			type=rand()%3+1;
			all=rand()%3000+5000;
		}
		void printDetails()
		{
			Employee::printDetails();
			cout<<"Manager is of type "<<type<<endl;
			cout<<"Allowance: "<<all<<endl;
		}
};

class Clerk:public Employee
{
	int type;
	int all;
	
	public:
		Clerk()
		{
		}
		void get()
		{
			Employee::get();
			type=rand()%3+1;
			all=rand()%3000+5000;
		}
		void printDetails()
		{
			Employee::printDetails();
			cout<<"Clerk is of type "<<type<<endl;
			cout<<"Allowance: "<<all<<endl;
		}	
};

int main()
{
	Employee E;
	Manager M;
	Clerk P;
	
	E.get();
	E.printDetails();
	cout<<endl;
	
	M.get();
	M.printDetails();
	cout<<endl;
	
	P.get();
	P.printDetails();
	cout<<endl;
	
	Employee A,B;
	Manager C,D;
	Clerk R,S;
	
	Employee *ptr[6];
	ptr[0]=&A;
	ptr[1]=&B;
	ptr[2]=&C;
	ptr[3]=&D;
	ptr[4]=&R;
	ptr[5]=&S;
	
	for(int i=0;i<6;i++)
	{
		ptr[i]->get();
	}

	for(int i=0;i<6;i++)
	{
		ptr[i]->printDetails();
		cout<<endl;
	}
	return 0;
}
