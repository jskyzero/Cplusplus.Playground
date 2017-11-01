#include<iostream>
#include<string>
#include <ctime>
#include <iomanip>
#include<list>

const time_t DefaultTime = 1451608957;
using namespace std;

class  PayInformation
{
private:
	string Time_; //��¼ʱ��
	__int64 Number_; //��¼��Ŀ
	string Explanation_; //��¼��ע
public:
	PayInformation(string Time, __int64 Number, string Explanation); //Ĭ�Ϲ��캯��
	friend ostream&  operator<<(ostream & out, const PayInformation& temp); //�������������
};
//Ĭ�Ϲ��캯��
PayInformation::PayInformation(string Time = ctime(&DefaultTime), __int64 Number = 0, string Explanation = "")
{
	Time_ = Time;
	Number_ = Number;
	Explanation_ = Explanation;
}
//�������������
ostream&  operator<<(ostream & out, const PayInformation& temp)
{
	out << temp.Time_ << "   ";
	out << setw(15) << right << temp.Number_;
	out << temp.Explanation_ << endl;
	return out;
}
int main()
{
	system("mode con cols=141 lines=40"); //���ô��ڴ�С
	PayInformation q(ctime(&DefaultTime),20,"");
	cout << q;
	return 0;
} 

