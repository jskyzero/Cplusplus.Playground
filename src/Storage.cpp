#include"Storage.hpp"
#include"Path.hpp"
#include"Date.hpp"
#include"Meeting.hpp"
#include"User.hpp"

#include<iostream>
#include<fstream>

std::shared_ptr<Storage> Storage::m_instance= nullptr;

Storage::Storage() {
  readFromFile();
}

  /**is
  *   read file content into memory
  *   @return if success, true will be returned
  */
bool Storage::readFromFile(void) {
    std::ifstream in1;
    std::ifstream in2;
    std::string str;
    
    
    in1.open(Path::userPath);
    if(!in1) return false;
    //if(!in1.eof())std::getline(in1,str,'\n');
    while ( !in1.eof() && std::getline(in1,str,'\n') ) {
      std::string a[4]; int n = 0;
      for(int i = 0 ; i <  str.length(); i++ ) {
        if(str[i] == ',' && str[i+1] == '"') {
          n++;
          continue; 
        } 
        if(str[i] == '"') continue;
        else a[n] += str[i];
      }
      User user1(a[0],a[1],a[2],a[3]);
      m_userList.push_back(user1);
    }
    in1.close();
    
    in2.open(Path::meetingPath);
    if(!in2) return false;
    //if(!in2.eof())std::getline(in2,str,'\n');
    while ( !in2.eof() && std::getline(in2,str,'\n') ) {
      std::string b[5]; int n = 0;
      for(int i = 0 ; i <  str.length(); i++ ) {
        if(str[i] == ',' && str[i+1] == '"') {n++;continue;}
        if(str[i] == '"') continue;
        else b[n] += str[i];
      }
      std::string temp;
      std::vector<std::string> v;
      for(int i = 0 ; i <  b[1].length(); i++ ) {
        if(b[1][i] == '&') {v.push_back(temp);temp="";}
        else temp += b[1][i]; 
        if(i == b[1].length()-1){v.push_back(temp);temp="";}
      }
      Meeting temp2(b[0],v,b[2],b[3],b[4]);
      m_meetingList.push_back(temp2);
    }
    in2.close();
    
    return true;
    }

  /**
  *   write file content from memory
  *   @return if success, true will be returned
  */
  bool Storage::writeToFile(void)
  {
    std::ofstream out1;
    std::ofstream out2;
    std::string str;
  
    //std::cout << "write\n";
    out1.open(Path::userPath);
    if(!out1.is_open()){
      //std::cout<<"write open\n";
      return false;}
    
    //out1 << "\"<username>\",\"<password>\",\"<email>\",\"<phone>\"\n";
    
     for(auto it =  m_userList.begin(); it != m_userList.end(); it++) {
      str = "";
      str+='"';str+=it->getName();str+='"';str+=',';
      str+='"';str+=it->getPassword();str+='"';str+=',';
      str+='"';str+=it->getEmail();str+='"';str+=',';
      str+='"';str+=it->getPhone();str+='"';str+='\n';
      out1<<str;
    }
    out1.close();
    
    out2.open(Path::meetingPath);
    if(!out2) return false;
    out2.clear();
    //out2<<"\"<sponsor>\",\"<particpators>\",\"<startDate>\",\"<endDate>\",\"<title>\"\n";
    for(auto it2 = m_meetingList.begin(); it2 != m_meetingList.end();it2++) {
      str = "";
      str+='"';str+=it2->getSponsor();str+='"';str+=',';
      
      str+='"';
      auto v = it2->getParticipator();
      for(int i = 0 ; i < v.size(); i++) {
        if(i!=0) str+="&";
        str+=v[i];
      }
      str+='"';str+=',';
      str+='"';str+=Date::dateToString(it2->getStartDate());str+='"';str+=',';
      str+='"';str+=Date::dateToString(it2->getEndDate());str+='"';str+=',';
      str+='"';str+=it2->getTitle();str+='"';str+='\n';
      out2 << str;
    }
    out2.close();
    m_dirty = 0;
    return true;
  }


  /**
  * get Instance of storage
  * @return the pointer of the instance
  */
 std::shared_ptr<Storage> Storage::getInstance(void)
{
  if(nullptr == m_instance) m_instance.reset( new Storage);
  return m_instance;
}
  /**
  *   destructor
  */
  Storage::~Storage()
  {
    sync();
  }

  // CRUD for User & Meeting
  // using C++11 Function Template and Lambda Expressions

  /**
  * create a user
  * @param a user object
  */
  void Storage::createUser(const User & t_user)
  {
    m_userList.push_back(t_user);
    m_dirty = 1;
    writeToFile();
  }

  /**
  * query users
  * @param a lambda function as the filter
  * @return a list of fitted users
  */
  std::list<User> Storage::queryUser(std::function<bool(const User &)> filter) const
  {
    std::list<User> temp;
    for(auto it =  m_userList.begin(); it != m_userList.end(); it++) {
      if( filter(*it) ) 
        temp.push_back(*it);
    }
    return temp;
  }

  /**
  * update users
  * @param a lambda function as the filter
  * @param a lambda function as the method to update the user
  * @return the number of updated users
  */
  int Storage::updateUser(std::function<bool(const User &)> filter,
                 std::function<void(User &)> switcher)
  {
    int n = 0;
    for(auto it =  m_userList.begin(); it != m_userList.end(); it++) {
      if( filter(*it) ){ 
        switcher(*it);n++;}
    }
    m_dirty = 1;
    writeToFile();
    return n;
  }

  /**
  * delete users
  * @param a lambda function as the filter
  * @return the number of deleted users
  */
  int Storage::deleteUser(std::function<bool(const User &)> filter)
  {
    int n = 0;
    for(auto it =  m_userList.begin(); it != m_userList.end(); it++) {
      if( filter(*it) ) {
        it = m_userList.erase(it);
        it--;
        n++;}}
    m_dirty = 1;
    writeToFile();
    return n;
  }

  /**
  * create a meeting
  * @param a meeting object
  */
  void Storage::createMeeting(const Meeting & t_meeting)
  {
    m_meetingList.push_back(t_meeting);
    m_dirty = 1;
    writeToFile();
  
  }
  /**
  * query meetings
  * @param a lambda function as the filter
  * @return a list of fitted meetings
  */
  std::list<Meeting> Storage::queryMeeting(std::function<bool(const Meeting &)> filter) const
  {
    std::list<Meeting> temp;
    for(auto it = m_meetingList.begin(); it != m_meetingList.end();it++) {
      if(filter(*it))
      temp.push_back(*it);
    }
    return temp;
  }

  /**
  * update meetings
  * @param a lambda function as the filter
  * @param a lambda function as the method to update the meeting
  * @return the number of updated meetings
  */
  int Storage::updateMeeting(std::function<bool(const Meeting &)> filter,
                    std::function<void(Meeting &)> switcher)
  {
    int n= 0;
    for(auto it = m_meetingList.begin(); it != m_meetingList.end();it++) {
      if(filter(*it)) {
        switcher(*it);
        n++;}
    }
    m_dirty = 1;
    writeToFile();
    return n;
  }

  /**
  * delete meetings
  * @param a lambda function as the filter
  * @return the number of deleted meetings
  */
  int Storage::deleteMeeting(std::function<bool(const Meeting &)> filter)
  {
    int n = 0;
    for(auto it = m_meetingList.begin(); it != m_meetingList.end();it++) {
      if(filter(*it)){
        it = m_meetingList.erase(it);
        it--;
        n++;}
    }
    m_dirty = 1;
    writeToFile();
    return n;
  }

  /**
  * sync with the file
  */
  bool Storage::sync(void)
  {
    if(writeToFile()) {
      m_dirty = 0;
      return 1;
    }
    else return 0;
  }
