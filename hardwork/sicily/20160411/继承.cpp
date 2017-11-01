#include<iostream>
#include<cstring>
 using namespace std;
 class a 
	{ 	
		public:
		int A;
		a(){A = 1;}
	};
	class ab :public a
	{
		public:
		int B = 2;
		friend ostream & operator<<(ostream & os , ab & temp );
	};
	ostream & operator<< (ostream & os , ab & temp){
		os << temp.A << endl<< temp.B << endl ;
		return os;
	}
 
int main()
{
	
	
	ab ab1;
	cout << ab1;
	
}
