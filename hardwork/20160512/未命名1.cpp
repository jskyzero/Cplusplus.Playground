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
	string Time_; //记录时间
	__int64 Number_; //记录数目
	string Explanation_; //记录备注
public:
	PayInformation(string Time, __int64 Number, string Explanation); //默认构造函数
	friend ostream&  operator<<(ostream & out, const PayInformation& temp); //重载输出操作符
};
//默认构造函数
PayInformation::PayInformation(string Time = ctime(&DefaultTime), __int64 Number = 0, string Explanation = "")
{
	Time_ = Time;
	Number_ = Number;
	Explanation_ = Explanation;
}
//重载输出操作符
ostream&  operator<<(ostream & out, const PayInformation& temp)
{
	out << temp.Time_ << "   ";
	out << setw(15) << right << temp.Number_;
	out << temp.Explanation_ << endl;
	return out;
}
int main()
{
	system("mode con cols=141 lines=40"); //设置窗口大小
	PayInformation q(ctime(&DefaultTime),20,"");
	cout << q;
	return 0;
} 

