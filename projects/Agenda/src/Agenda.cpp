#include "AgendaUI.hpp"
#include <signal.h>
#include <iostream>
#include <unistd.h>
//#include"gtest/gtest.h"
AgendaUI aui;

void f(int signum) {
  switch (signum) {
    case SIGINT:
    std::cout<<"\nEXIX   SAVING FILE";
    aui.~AgendaUI();
    break;
    default :
    break;
  };
  return ;
}
  

int main(int argc, char** argv) {
  signal(SIGINT,f);
     aui.OperationLoop();
  
  //::testing::InitGoogleTest(&argc,argv);
  //return RUN_ALL_TESTS();
  
 }

/*
#include<time.h>
#include<stdlib.h> 
 int checkDay1(int year, int month) 
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

TEST(data,dateToString)
{  int num = 10000;
  while(num--){
  std::string s;
  srand(time(NULL));
  int n = rand();
    char *p = new char[4];
    sprintf(p,"%04d",n%9000+1000);
    s+=p;s+="-";
    sprintf(p,"%02d",n%12+1);
    s+=p;s+="-";
    sprintf(p,"%02d",n%(checkDay1(n%1000,n%12+1)+1));
    s+=p;s+="/";
    sprintf(p,"%02d",n%24);
    s+=p;s+=":";
    sprintf(p,"%02d",n%60);
    s+=p;
  EXPECT_EQ(s,Date::dateToString(Date(s)));
  } */
 /*std::string str = "2016-02-12/12:50";
  Date d1(2016,2,02,2,5);
  Date d2("2016-02-12/12:50");
  Date d3("2016-02-12/11:50");
  Date d4("2016-02-12/11:60");
  Date d5("2016-02-12/24:50");
  Date d6("2016-02-29/24:50");
  std::cout << " d1      " << Date::dateToString(d1)<< std::endl;
  std::cout << " d2      " << Date::dateToString(d2)<< std::endl;
  std::cout << " d3      " << Date::dateToString(d3)<< std::endl;
  std::cout << " d4      " << Date::dateToString(d4)<< std::endl;
  std::cout << " d5      " << Date::dateToString(d5)<< std::endl;
  std::cout << " d6      " << Date::dateToString(d6)<< std::endl;

  std::cout << " d1 <= da2 " << ( d1 <= d2 ) << std::endl;
  std::cout << " d1 >= da2 " << ( d1 >= d2 ) << std::endl;
  std::cout << " d1 <  da2 " << ( d1 <  d2 ) << std::endl;
  std::cout << " d1 >  da2 " << ( d1 >  d2 ) << std::endl;
  std::cout << " d1 == da2 " << ( d1 == d2 ) << std::endl;
  std::cout << " d3 < da2 " << ( d3 < d2 ) << std::endl;*/
