#include"Date.hpp"
#ifndef DATE_CPP
#define DATE_CPP
#endif

  int checkDay(int year, int month);

  /**
  * @brief default constructor
  */
  Date::Date() { m_year = 0; m_month = 0; m_day = 0; m_hour = 0; m_minute = 0; }
  
  /**
  * @brief constructor with arguments
  */
  Date::Date(int t_year, int t_month, int t_day, int t_hour, int t_minute){
      m_year = t_year; m_month = t_month; m_day = t_day; m_hour = t_hour; m_minute = t_minute;}

  /**
  * @brief constructor with a string
  * 0000-00-00/00:00
  */
  Date::Date(std::string dateString)
  {
    bool n = 1;

    if(dateString.length() != 16 ) n = 0;
    else if(!('-' == dateString[4] && '-' == dateString[7] 
      && '/' == dateString[10] && ':' == dateString[13] )) n = 0;
    else {for(int i =  0 ; i < 16 ; i++){
      if(i == 4 || i == 7 || i == 10 || i == 13) continue;
      else if(dateString[i] >= '0' && dateString[i] <= '9') continue;
      else {n = 0 ; break;}
    }}
    
    if(n){
    char* p = &dateString.substr(0,4)[0];
    m_year = atoi(p);
    p = &dateString.substr(5,2)[0];
    m_month = atoi(p);
    p = &dateString.substr(8,2)[0];
    m_day = atoi(p);
    p = &dateString.substr(11,2)[0];
    m_hour = atoi(p);
    p = &dateString.substr(14,2)[0];
    m_minute = atoi(p);
    /*Date temp(m_year,m_month,m_day,m_hour,m_minute );
    if(!isValid(temp)) {m_year = 0;m_month = 0;m_day = 0; m_hour = 0; m_minute = 0;}*/ 
    } else {m_year = 0;m_month = 0;m_day = 0; m_hour = 0; m_minute = 0;} 
  }
  /**
  * @brief return the year of a Date
  * @return   a integer indicate the year of a date
  */
  int Date::getYear(void) const{
      return m_year;}

  /**
  * @brief set the year of a date
  * @param a integer indicate the new year of a date
  */
  void Date::setYear(const int t_year){
    m_year = t_year;}

  /**
  * @brief return the month of a Date
  * @return   a integer indicate the month of a date
  */
  int Date::getMonth(void) const{
      return m_month;}

  /**
  * @brief set the month of a date
  * @param a integer indicate the new month of a date
  */
  void Date::setMonth(const int t_month){
      m_month = t_month;}

  /**
  * @brief return the day of a Date
  * @return   a integer indicate the day of a date
  */
  int Date::getDay(void) const{
      return m_day;}

  /**
  * @brief set the day of a date
  * @param a integer indicate the new day of a date
  */
  void Date::setDay(const int t_day){
      m_day = t_day;}

  /**
  * @brief return the hour of a Date
  * @return   a integer indicate the hour of a date
  */
  int Date::getHour(void) const{
      return m_hour;}

  /**
  * @brief set the hour of a date
  * @param a integer indicate the new hour of a date
  */
  void Date::setHour(const int t_hour){
      m_hour = t_hour;}

  /**
  * @brief return the minute of a Date
  * @return   a integer indicate the minute of a date
  */
  int Date::getMinute(void) const{
      return m_minute;}

  /**
  * @brief set the minute of a date
  * @param a integer indicate the new minute of a date
  */
  void Date::setMinute(const int t_minute){
      m_minute = t_minute;}

  /**
  *   @brief check whether the date is valid or not
  *   @return the bool indicate valid or not
  */
 bool Date::isValid(const Date t_date)
  {
      if( t_date.getYear() < 1000 || t_date.getYear() > 9999) return false;
      if( t_date.getMonth() > 12 || t_date.getMonth() < 1 ) return false;
      if( t_date.getDay() > checkDay(t_date.getYear(), t_date.getMonth()) || t_date.getDay() < 1) return false;
      if( t_date.getHour() >= 24 || t_date.getHour() < 0 ) return false ;
      if( t_date.getMinute() >= 60 || t_date.getMinute() < 0 ) return false;
      return true;
  }

  /**
  * @brief convert a string to date, if the format is not correct return
  * 0000-00-00/00:00
  * @return a date
  */
  Date Date::stringToDate(const std::string t_dateString){
  return Date(t_dateString);}

  /**
  * @brief convert a date to string, if the format is not correct return
  * 0000-00-00/00:00
  */
  std::string Date::dateToString(Date t_date)
  {
      std::string s;
      char *p = new char[4];
    
      if(!isValid(t_date)) {
          s = "0000-00-00/00:00";
          return s;
      }

      sprintf(p,"%04d",t_date.getYear());
      s+=p;s+="-";
      sprintf(p,"%02d",t_date.getMonth());
      s+=p;s+="-";
      sprintf(p,"%02d",t_date.getDay());
      s+=p;s+="/";
      sprintf(p,"%02d",t_date.getHour());
      s+=p;s+=":";
      sprintf(p,"%02d",t_date.getMinute());
      s+=p;return s;

  }

  /**
  *  @brief overload the assign operator
  */
  Date& Date::operator=(const Date &t_date)
  {
      m_year = t_date.getYear();
    m_month = t_date.getMonth();
    m_day = t_date.getDay();
    m_hour = t_date.getHour();
    m_minute = t_date.getMinute();
    return *this;
  }

  /**
  * @brief check whether the CurrentDate is equal to the t_date
  */
  bool Date::operator==(const Date &t_date) const
  {
      return (m_year == t_date.getYear()
          && m_month == t_date.getMonth()
          && m_day == t_date.getDay()
          && m_hour == t_date.getHour()
          && m_minute == t_date.getMinute());
  }

  /**
  * @brief check whether the CurrentDate is  greater than the t_date
  */
  bool Date::operator>(const Date &t_date) const
  {
      if(m_year > t_date.getYear()) return true;
      if(m_year == t_date.getYear()
          &&m_month > t_date.getMonth())return true;
      if(m_year == t_date.getYear()
          &&m_month == t_date.getMonth()
          &&m_day > t_date.getDay())return true;
      if(m_year == t_date.getYear()
          &&m_month == t_date.getMonth()
          &&m_day == t_date.getDay()
          &&m_hour > t_date.getHour())return true;
      if(m_year == t_date.getYear()
          &&m_month == t_date.getMonth()
          &&m_day == t_date.getDay()
          &&m_hour == t_date.getHour()
          &&m_minute > t_date.getMinute())return true;
      return false;
}

  /**
  * @brief check whether the CurrentDate is  less than the t_date
  */
  bool Date::operator<(const Date &t_date) const
  {
    return (t_date>*this);
   }

  /**
  * @brief check whether the CurrentDate is  greater or equal than the t_date
  */
  bool Date::operator>=(const Date &t_date) const {
    return !(*this < t_date);}

  /**
  * @brief check whether the CurrentDate is  less than or equal to the t_date
  */
  bool Date::operator<=(const Date &t_date) const {
       return !(*this > t_date);}

  int checkDay(int year, int month) 
  {
      int x = (( 0 == year % 4 && 0 != year % 100 )||(0 == year % 400)) ? 29:28;
      switch(month) {
          case 1:
          case 3:
          case 5:
          case 7:
          case 8:
          case 10:
          case 12:
              return 31;
          case 2:
              return x;
          default:
              return 30;
      }
  } 