// Problem#: 18323
// Submission#: 4710460
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream> 
#include<string>
#include <iostream> 
#include <list> 
using namespace std;
class Sequence{
private:
    list<int>n;
public:
Sequence() {
}
int size()
{
    return n.size();
}
bool empty()
{
    return n.empty();
}
bool find(int value)
{
    
    for (list<int>::iterator it = n.begin(); it!=n.end(); ++it)
    {
        if(*it == value) return 1;
    }
    return 0;
    
}
int &at(int pos)
{   
    int N = 0;
    if(pos > n.size()) return N;
    list<int>::iterator it = n.begin();
    while(pos--)it++;
    return (*(it));
}
int front()
{
    if(n.empty())return 0;
    return n.front();
}
int back()
{   if(n.empty())return 0;
    return n.back();
}
void insert(int value)
{
    n.push_back(value);
}
void insert(int pos, int value)
{
    list<int>::iterator it = n.begin();
    while(pos--)it++;
    n.insert(it,value);
}
void clear()
{
    n.clear();
}
void reverse()
{
    n.reverse();
}
void reverse(int fir, int las)
{
    list<int>::iterator it1 = n.begin();
    while(fir--)it1++;
    list<int>::iterator it2 = n.begin();
    while(las--)it2++;
    list<int>temp(it1,it2);
    temp.reverse();
    for(list<int>::iterator it3 = temp.begin(); it3!=temp.end(); it3++,it1++)
    {
        *it1 = *it3;
    }
}
void replace(int value1, int value2)
{   
    for (list<int>::iterator it = n.begin(); it!=n.end(); ++it)
    {
        if(*it == value1) *it = value2;
    }
}
void swap(Sequence &seq2)
{
    n.swap(seq2.n);
}
void show()
{   if(n.empty())return ;
    for (list<int>::iterator it = n.begin(); it!=n.end(); ++it)
    {
        cout << *it;
    }
    cout << endl;
}
};                                 



int main()
{
	Sequence seq1;	
	seq1.insert(1);
	seq1.insert(2);
	seq1.insert(3);
	seq1.insert(4);
 cout <<seq1.size()<<endl;      
 cout <<seq1.empty()<<endl;//    false
 cout <<seq1.find(5)<<endl;//    false (because 5 is not in the sequence)
 cout <<seq1.at(3)<<endl;//      return the reference of third element
 cout <<seq1.front()<<endl;//    1 
 cout <<seq1.back()<<endl;//     4
 cout <<seq1.at(3)<<endl;
 seq1.reverse(1,3);
 seq1.show();
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

