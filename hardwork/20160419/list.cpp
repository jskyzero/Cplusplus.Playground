
#include <iostream>
#include <list>
using namespace std;
int main()
{
    char cTemp;
    list<char> charlist;
    
        charlist.push_front('a');
        charlist.push_back('f');
        charlist.push_front('b');
        charlist.push_front('c');
        charlist.push_front('d');
        charlist.push_back('e');
    
    cout << "list old:" <<endl;
    list<char>::iterator it;
    for(it=charlist.begin();it!=charlist.end();it++)
    {
        cout << *it << endl;//�������Ԫ��
    }
    /*list<char>::iterator itstart=charlist.begin();
    charlist.insert(++itstart,'A');//����ֵ
    cout << "list old" << endl;
    for(it=charlist.begin();it!=charlist.end();it++)
    {
        cout << *it << endl;//�������Ԫ��
    } */
    return 0;
}
