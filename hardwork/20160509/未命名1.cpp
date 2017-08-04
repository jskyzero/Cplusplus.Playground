// Problem#: 18271
// Submission#: 4697068
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#pragma once 
#include<iostream>
#include<cstring>
using namespace std;


class base
{
char *name;
int age;
public:
base(){age = 0; name = NULL;}
void setname(char arr[])
{
    int n = sizeof(arr);
    name = new char [n+1];
    strcpy(name, arr);
}
void setage(int age)
{
    this->age = age;
}
char* getname()
{
    return name;
}
int getage()
{
    return age;
}
};
class leader : virtual public base
{
    
public:
	char * job_;
    char * dep_;
	leader(){
		job_= NULL;
		dep_=NULL;
	}
    void setdep(char * dep)
    {
    int n = sizeof(dep);
    dep_ = new char [n+1];
    strcpy(dep_, dep);  
    }
    void setjob(char * job)
    {
    int n = sizeof(job);
    job_ = new char [n+1];
    strcpy(job_, job);  
    }
    char* getdep()
{
    return dep_;
}
char* getjob()
{
    return job_;
}
 }; 
 class engineer: virtual public base
 {
    
public:
	char *major_;
    char *prof_;
	engineer(){
		major_ = NULL;
		prof_ = NULL;
	}
    void setmajor(char *major)
    {
    int n = sizeof(major);
    major_ = new char [n+1];
    strcpy(major_, major);
    }
    void setprof(char *prof)
    {
    int n = sizeof(prof);
    prof_ = new char [n+1];
    strcpy(prof_, prof);
    }
    char* getmajor()
{
    return major_;
}
char* getprof()
{
    return prof_;
}
 };
 class chairman :  public engineer,  public leader
{	public:
    chairman(){
	}
};                                 
int main()
{
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
int n;
cin>>n;
for (int i=0;i<n;i++)
{
char name[20],job[20],dep[20],major[20],prof[20];
            int age;
cin>>name>>age>>job>>dep>>major>>prof;
chairman man;
man.setname(name);
man.setage(age);
man.setjob(job);
man.setdep(dep);
man.setmajor(major);
man.setprof(prof);
 
cout<<"name: "<<man.getname()<<" age: "<<man.getage()<<" dep: "<<man.getdep()
<<" job: "<<man.getjob()<<endl;
cout<<"prof: "<<man.getprof()<<" major: "<<man.getmajor()<<endl;
}
return 0;
}
