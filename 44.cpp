#include<iostream>
#include<math.h>

using namespace std;

class Shape
{
    public:
    	virtual void getArea()=0;
    	virtual void getVolume()=0;
    	virtual int check()=0;
};

class TwoDShape:public Shape
{
    public:
    	virtual void getArea()=0;
    	virtual int check()=0;
};

class ThreeDShape:virtual public Shape
{
    public:
	    virtual void getArea()=0;
	    virtual void getVolume()=0;
	    virtual int check()=0;
};

class Circle:public TwoDShape
{
	int r;
    public:
	    Circle(int a=0)
	    {
	            r=a;
	    }
	    
	    void getArea()
	    {
	    	cout<<"Name of shape:Circle"<<endl;
	    	cout<<"Area="<<22/7.0*r*r;
		}
		
		virtual void getVolume()
		{
		}
		
		int check()
		{
			return 2;
		}
};

class Triangle:virtual public TwoDShape
{
    int a,b,c;
    public:
	    Triangle(int a=0,int b=0,int c=0)
	    {
	        this->a=a;
	        this->b=b;
	        this->c=c;
	    }
	    
	    void getArea()
	    {
	        float s=(a+b+c)/2.0;
	        float p=4*s*(s-a)*(s-b)*(s-c);
	        p=pow(p,0.5);
	        cout<<"Name of shape:Triangle"<<endl;
	        cout<<"Area="<<p<<endl;
	    }
	    
	    int check()
		{
			return 2;
		}
};

class Ellipse:virtual public TwoDShape
{
    int a,b;
    public:
	    Ellipse(int a=0,int b=0)
	    {
	            this->a=a;
	            this->b=b;
	    }
	
	    void getArea()
	    {
	            cout<<"Name of shape:Ellipse"<<endl;
	            cout<<"Area="<<22/7.0*a*b<<endl;
	    }
	    
		int check()
		{
			return 2;
		}
};

class Sphere:virtual public ThreeDShape
{
	int r;
	public:
		Sphere(int a=0)
		{
			r=a;
		}
		
		void getArea()
		{
			cout<<"Name of shape:Sphere"<<endl;
			cout<<"Area="<<22/7.0*4*r*r<<endl;
		}
		
		void getVolume()
		{
			cout<<"Volume="<<22/7.0*4/3*r*r*r<<endl;
		}
		
		int check()
		{
			return 3;
		}
};

class Cube:virtual public ThreeDShape
{
		int a,b,c;
	    public:
		    Cube(int a=0,int b=0,int c=0)
		    {
		        this->a=a;
		        this->b=b;
		        this->c=c;
		    }
		    
		    void getArea()
		    {
		    	cout<<"Name of shape:Cube"<<endl;
		    	cout<<"Area="<<6*a*a<<endl;
			}
			
			void getVolume()
			{
				cout<<"Volume="<<a*a*a;
			}
			
			int check()
			{
				return 3;
			}
};

int main()
{
	Shape *arr[5];
	Circle C(7);
	Triangle T(4,2,3);
	Ellipse E(2,7);
	Sphere S(14);
	Cube A(5);

	arr[0]=&C;
	arr[1]=&T;
	arr[2]=&E;
	arr[3]=&S;
	arr[4]=&A;
	
	for(int i=0;i<5;i++)
	{
		arr[i]->getArea();
		if(arr[i]->check()==3)
		{
			arr[i]->getVolume();
		}
	}
	return 0;
}
