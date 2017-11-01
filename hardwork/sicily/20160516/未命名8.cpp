#include <iostream> 
#include<string>
#include <iostream> 
#include <vector> 
#include <algorithm>


class Sequence :public std::vector<int>
{
public:
	bool find(int value)
	{
	for (iterator it = begin(); it!=end(); ++it)
	{
		if(*it == value) return 1;
	}
	return 0;	
	}
	int &at(int pos)
	{
	iterator it = begin();
	pos--;
	while(pos--)it++;
	return *it;
	}
	void insert( int value)
	{
		iterator it = end();
		vector<int>::insert(it,value);
	}
	void insert(int pos, int value)
	{
		iterator it = end();
		while(pos--)it--;
		vector<int>::insert(it,value);
	}

	void reverse()
	{
		std::reverse(begin(),end());
	}
	void reverse(int fir, int las)
	{
		iterator it1 = begin();
		while(fir--)it1++;
		iterator it2 = it1;
		while(las--)it2++;
		std::reverse(it1,it2);
	}
	void replace(int value1, int value2)
	{
		for (iterator it = begin(); it!=end(); ++it)
	{
		if(*it == value1) *it = value2;
	}
	}

	void show()
	{
		for (iterator it = begin(); it!=end(); ++it)
	{
		std::cout << *it ;
	}
	std::cout << std::endl;
	}
};
using namespace std;
int main()
{
	Sequence seq1;
  seq1.insert(1);
  seq1.insert(2);
  seq1.insert(3);
  seq1.insert(4);
Sequence seq2;
seq2.insert(3);
seq2.insert(4);
seq2.insert(5);

 std::cout <<seq1.size()<<endl;      
 cout <<seq1.empty()<<endl;//    false
 cout <<seq1.find(5)<<endl;//    false (because 5 is not in the sequence)
 cout <<seq1.at(3)<<endl;//      return the reference of third element
 cout <<seq1.front()<<endl;//    1 
 cout <<seq1.back()<<endl;//     4
 seq1.insert(6);seq1.show();//  the sequence became {1,2,3,3,6} 
 seq1.insert(2,4);seq1.show();// the sequence became {1,2,4,3,3} 
 }
	
 /*
  seq1.insert(6);seq1.show();//  the sequence became {1,2,3,3,6} 
 seq1.insert(2,4);seq1.show();// the sequence became {1,2,4,3,3} 
 seq1.clear();seq1.show();//     the sequence became {}
 seq1.reverse();seq1.show();//    the sequence became {3,3,2,1}
 seq1.reverse(1,2);seq1.show();// the sequence became {1,3,2,3}
 seq1.replace(3,5);seq1.show();//the sequence became {1,2,5,5}
 seq1.swap(seq2);seq1.show();//seq1 became {3,4,5} and seq2 became {1,2,3,3}
 */
