
#include <iostream>
using namespace std;

void f3(int x)         //EX9_2.cpp
{
	switch (x) {
	case 1: throw 3.4;	      // 抛出double型异常
	case 2: throw 2.5f; 	      // 抛出float型异常
	case 3: throw 1;   	      // 抛出int型异常
	}
	cout << "End of f3" << endl;
}

void f2(int x)
{
	try {
		f3(x);
	}
	catch (int) {	//int型异常的处理代码
		cout << "An int exception occurred!--from f2" << endl;
		throw 2.5f; 
	}
	
		catch (int) {  	            // int型异常的处理代码
		cout << "An int exception occurred!--from f3" << endl;
	}
	
	catch (float) {  	            // float型异常的处理代码
		cout << "A float exception occurred!--from f3" << endl;
	}
	catch (float) { 	//float型异常的处理代码
 		cout << "A float exception occurred!--from f2" << endl;
	}
	catch (double) { 	            // double型异常的处理代码
		cout << "A double exception occurred!--from f3" << endl;
	}
	cout << "End of f1" << endl;
	cout << "End of f2" << endl;
}

void f1(int x)
{
	try {
		f2(x);
	}
	catch (int) {  	            // int型异常的处理代码
		cout << "An int exception occurred!--from f1" << endl;
	}
	catch (float) {  	            // float型异常的处理代码
		cout << "A float exception occurred!--from f1" << endl;
	}
	catch (double) { 	            // double型异常的处理代码
		cout << "A double exception occurred!--from f1" << endl;
	}
	cout << "End of f1" << endl;
}

int main()
{
	int response;
	for (int i = 1; i < 4; i++){
		//int i=1;
		f1(i);

}
	cout << "End of main" << endl;

	getchar();
     return 0;

}

