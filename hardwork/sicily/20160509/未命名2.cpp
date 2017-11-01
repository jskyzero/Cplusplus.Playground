#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class base
{
char *name;
int age;
public:
base(){
age=0;
name=NULL;}
void setname(char *arr){
    int len=strlen(arr);
    name=new char[len+1];
    strcpy(name,arr);
}
void setage(int t){
    age=t;
}
char* getname(){
    return name;
}
int getage(){
    return age;
}
};
class leader:virtual public base{
    public:
char *job;
char *dep;
leader(){
    job=NULL;
    dep=NULL;
}
void setjob(char arr[]){
    int len=strlen(arr);
job=new char[len+1];
    strcpy(job,arr);
}
void setdep(char *arr){
    int len=strlen(arr);
dep=new char[len+1];
    strcpy(dep,arr);
}
char* getjob(){
    return job;
}
char* getdep(){
    return dep;
}   
};
class engineer:virtual public base{
public:
char *  prof;
char * major;
engineer(){
    prof=NULL;
major=NULL;
}
void setmajor(char* arr){
    int len=strlen(arr);
major=new char[len+1];
    strcpy(major,arr);
}
void setprof(char* arr){
    int len=strlen(arr);
prof=new char[len+1];
    strcpy(prof,arr);
}
char* getprof(){
    return prof;
}
char* getmajor(){
    return major;
}
};
class chairman:public engineer,public leader{
    public:
     chairman(){
        
     };
};

