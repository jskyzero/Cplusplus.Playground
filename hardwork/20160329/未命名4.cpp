#include<iostream>
#include<vector>
using namespace std;


class test{
public:
     int v;
   /*���캯��*/
     test():v(0){}
     test(const int &a):v(a){}
     test(const test &t1):v(t1.v){} 
    
   /*��������С�ں� < */
     //�Ƚ���������Ĵ�С 
     bool operator<(const test &t1) const{ 
         return (v < t1.v);
     }
     //�Ƚ϶����int�Ĵ�С 
     bool operator<(const int &t1) const{ 
         return (v < t1);
     }
     //��Ԫ�������Ƚ�int�Ͷ���Ĵ�С 
     friend inline bool operator<(const int &a, const test & t1){
         return (a < t1.v);
     }
    
   /*�������ظ�ֵ�� = */
     //����丳ֵ 
     test & operator=(const test &t1){
         v = t1.v;
         return *this;
     }
     //int��ֵ������ 
     test & operator=(const int &t1){
         v = t1;
         return *this;
     }
    
   /*�������ؼӺ� + */
     //������� int 
     test operator+(const int & a){
         test t1;
         t1.v = v + a;
         return t1;
     }
     //����Ӷ��� 
     test operator+(test &t1){
         test t2;
         t2.v = v + t1.v;
         return t2;
     }
    
   /*�������ؼӵȺ� += */  
     //������϶��� 
     test &operator+=(const test &t1){
         v += t1.v;
         return *this;
     }  
     //�������int
     test &operator+=(const int &a){
         v += a;
         return *this;
     }


   /*��������˫�Ⱥ� == */  
     //����==���� 
     bool operator==(const test &t1)const{
         return (v == t1.v);
     }  
     //����==int
     bool operator==(const int &t1)const{
         return (v == t1);
     }  
    
   /*�������� ����>> ���<< */
     /*��Ԫ�������������*/
     friend inline ostream & operator << (ostream & os, test &t1){
         cout << "class t(" << t1.v << ")" << endl;
         return os;
     }
     /*��Ԫ�������������*/
     friend inline istream & operator >> (istream & is, test &t1){
         cin >> t1.v;
         return is;
     }
};


int main(){
     test t0, t1(3);
     test t2(t1);
     cout << t0 << t1 << t2;
     cin >> t1;
     t2 = t1;
     t2 += t1;
     t1 += 10;
     cout << t2;
     if(t1 < t2) cout << "t1 < t2"; 
     else if(t1 == t2) cout << "t1 = t2";
     else /* t1 > t2*/ cout << "t1 > t2"; 
     cout <<endl;
     system("pause");
     return 0;
}

