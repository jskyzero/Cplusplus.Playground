#include<AgendaUI.hpp>
#include<iostream>
#include<iomanip>
	AgendaUI::AgendaUI() {
		system("clear");
	}
	void AgendaUI::OperationLoop(void) {
        
        std::string t_operation = "";
        while(t_operation != "q") {
            //system("clear");
            std::cout << "------------------------Agenda------------------------" << std::endl;
            std::cout << "Action :                                              " << std::endl;
            std::cout << "l   - log in Agenda by user name and passworld        " << std::endl;
            std::cout << "r   - register an Agenda account                      " << std::endl;
            std::cout << "q   - quit Agenda                                     " << std::endl;
            std::cout << "------------------------------------------------------" << std::endl
            << std::endl;
            t_operation = getOperation();
            if("l" == t_operation) {
            userLogIn(); } else 
            if("r" == t_operation) {
            userRegister();} else 
            if("q" == t_operation) {
            quitAgenda(); } else 
            std::cout << "please check your inport" << std::endl;
            };
   }

   
    /**
     * constructor
     */
    void AgendaUI::startAgenda(void) {
        std::string str = "";
        std::cout << "------------------------Agenda------------------------" << std::endl;
        std::cout << "Action :                                              " << std::endl;
        std::cout << "o   - log out Agenda                                  " << std::endl;
        std::cout << "dc  - delete Agenda account                           " << std::endl;
        std::cout << "lu  - list all Agenda user                            " << std::endl;
        std::cout << "cm  - create a meeting                                " << std::endl;
        std::cout << "la  - list all meetings                               " << std::endl;
        std::cout << "las - list all sponsor meetings                       " << std::endl;
        std::cout << "lap - list all participate meetings                   " << std::endl;
        std::cout << "qm  - query meeting by title                          "<< std::endl;
        std::cout << "qt  - query meeting by time interval                  " << std::endl;
        std::cout << "dm  - delete meeting by title                         " << std::endl;
        std::cout << "da  - delete all meetings                             " << std::endl;
        std::cout << "------------------------------------------------------" << std::endl
        << std::endl;
    }

    /**
     * catch user's operation
     * @return the operation
     */
    std::string AgendaUI::getOperation() {
    	std::cout<< "Agenda : ~$";
    	std::string str;
    	std::cin >> str;
    	return str;
    }

    /**
     * execute the operation
     * @return if the operationloop continue
     */
    bool AgendaUI::executeOperation(std::string t_operation) {
        std::string str = t_operation; 
    	while ("o" != str) {
            while ("o" != str) {
                if("dc" == str){deleteUser();break;}
                if("lu" == str){listAllUsers();break;}
                if("cm" == str){createMeeting();break;}
                if("la" == str){listAllMeetings();break;}
                if("las" == str){listAllSponsorMeetings();break;}
                if("lap" == str){listAllParticipateMeetings();break;}
                if("qm" == str){queryMeetingByTitle();break;}
                if("qt" == str){queryMeetingByTimeInterval();break;}
                if("dm" == str){deleteMeetingByTitle();break;}
                if("da" == str){deleteAllMeetings();break;}
                std::cout << "please check your inport" << std::endl;
                break;
            }
            std::cout << "Agenda@" << m_userName << " : #";
            std::cin >> str;
       }
	}

    /**
     * user Login
     */
    void AgendaUI::userLogIn(void) {
    	std::cout<< std::endl;
    	std::cout<< "[log in] [user name] [password]" << std::endl;
    	std::cout<< "[log in] ";
    	std::cin >> m_userName>> m_userPassword;
    	std::cout<< "[log in] ";
    	if(m_agendaService.userLogIn(m_userName,m_userPassword)) 
    		std::cout<< "success!" << std::endl;
    	else
    		{std::cout<< "log in fail!" << std::endl; return;}
        startAgenda();
    	std::cout << "Agenda@" << m_userName << " : #";
        std::string str;
        std::cin >> str;
        std::cout <<"\n\n";
		executeOperation(str);

    }

    /**
     * user regist
     */
    void AgendaUI::userRegister(void) {
    	std::cout<< "[register] [user name] [password] [email] [phone]" << std::endl;
    	std::cout<< "[register] ";
    	std::string name, password, email, phone;
    	std::cin >> name >> password >> email >> phone;
        std::cout<< "[register] ";
    	if(m_agendaService.userRegister(name, password, email, phone)) 
    		std::cout<< "success!"<< std::endl;
    	else
    		std::cout<< "register fail!"<< std::endl;


    }

    /**
     * quit the Agenda
     */
    void AgendaUI::quitAgenda(void) {
    	std::cout << "thanks for using Agenda" << std::endl;
    }

    /**
     * user logout
     */
    void AgendaUI::userLogOut(void) {
        std::cout<<std::endl;
    }

    /**
     * delete a user from storage
     */
    void AgendaUI::deleteUser(void) {
        std::cout<<"[delete agenda account] ";
    	if(m_agendaService.deleteUser(m_userName,m_userPassword))
            std::cout<<"success!\n";
        else 
            std::cout<<"fail to delete agenda account!\n";
    }

    /**
     * list all users from storage
     */
    void AgendaUI::listAllUsers(void) {
    	std::cout<<"[list all users]\n\n";
        std::cout<<"name           email                    phone         \n";
    	auto l = m_agendaService.listAllUsers();
    	for(auto i = l.begin();i!= l.end();i++) {
    		std::cout<<std::setiosflags(std::ios::left)
            <<std::setw(15) <<i->getName()
            <<std::setw(25) <<i->getEmail()
            <<std::setw(15) << i->getPhone()
            <<"\n";
    	}
    } 

    /**
     * user create a meeting with someone else
     */
    void AgendaUI::createMeeting(void) {
        size_t n;
        std::string title,date1,date2;
        std::cout << "[create meeting] [the number of participators]\n";
        std::cout << "[create meeting] ";
        std::cin  >> n; std::vector<std::string> v;
        std::cout << "\n";
        for(int i = 0; i < n ;i++) {
        std::cout<<"[create meeting] [please enter the participator "<< i << "]\n"; 
        std::cout << "[create meeting] "; std::cin >> title; v.push_back(title); std::cout << "\n";}
        std::cout<<"[create meeting] [title][star time(yyyy-mm-dd/hh:mm)][end time(yyyy-mm-dd/hh:mm)]\n"; 
        std::cout<<"[create meeting] ";
        std::cin >> title >> date1 >> date2;
        std::cout<<"\n";
        std::cout << "[create meeting] ";
        if(m_agendaService.createMeeting(m_userName,title,date1,date2,v))
             std::cout<<"success!\n";
        else 
            std::cout<<"error!\n";
        }

    /**
     * list all meetings from storage
     */
        void AgendaUI::listAllMeetings(void) {  
        std::cout<<"[list all meetings]\n";
        printMeetings(m_agendaService.listAllMeetings(m_userName));
    }

    /**
     * list all meetings that this user sponsored
     */
    void AgendaUI::listAllSponsorMeetings(void) {
         std::cout<<"[list all sponsor meetings]\n";
         printMeetings(m_agendaService.listAllSponsorMeetings(m_userName));
    }

    /**
     * list all meetings that this user take part in
     */
    void AgendaUI::listAllParticipateMeetings(void) {
        std::cout<<"[list all sponsor meetings]\n";
         printMeetings(m_agendaService.listAllParticipateMeetings(m_userName));
    }

    /**
     * search meetings by title from storage
     */
    void AgendaUI::queryMeetingByTitle(void) {
        std::string str;
        std::cout<<"[queryMeeting] [title]\n";
        std::cout<<"[queryMeeting] ";
        std::cin >> str;
        std::cout<<"\n";
        printMeetings(m_agendaService.meetingQuery(m_userName,str));
    }

    /**
     * search meetings by timeinterval from storage
     */
    void AgendaUI::queryMeetingByTimeInterval(void) {
        std::string str1,str2;
        std::cout<<"[queryMeeting] [star time(yyyy-mm-dd/hh:mm)] [end time(yyyy-mm-dd/hh:mm)]\n";
        std::cout<<"[queryMeeting] ";
        std::cin >> str1 >> str2;
        std::cout<<"\n";
        printMeetings(m_agendaService.meetingQuery(m_userName,str1,str2));
    }

    /**
     * delete meetings by title from storage
     */
    void AgendaUI::deleteMeetingByTitle(void) {
        std::string str;
        std::cout<<"[delete meeting] [title]\n";
        std::cout<<"[delete meeting] ";
        std::cin >> str;
        std::cout<<"\n";
        std::cout<<"[delete meeting] ";
        if(m_agendaService.deleteMeeting(m_userName,str))
            std::cout<<"delete meeting success!\n";
        else 
            std::cout<<"delete meeting fail!\n";
    }

    /**
     * delete all meetings that this user sponsored
     */
    void AgendaUI::deleteAllMeetings(void) {
        std::cout<<"[delete meeting] ";
        if(m_agendaService.deleteAllMeetings(m_userName))
            std::cout<<"delete meeting success!\n";
        else 
            std::cout<<"delete meeting fail!\n";
    }

    /**
     * show the meetings in the screen
     */
    void AgendaUI::printMeetings(std::list<Meeting> t_meetings) {
            std::cout<<"\n";
            std::cout<<std::setiosflags(std::ios::left)
            <<std::setw(12) << "title"
            <<std::setw(12) << "sponsor"
            <<std::setw(20) << "start time"
            <<std::setw(20) << "end time"
            <<std::setw(20) << "participator"
            <<"\n";
                                
        for(auto i = t_meetings.begin();i!= t_meetings.end();i++) {
           
            std::string str = "";
            auto v = i->getParticipator();
            for(int n = 0 ; n < v.size(); n++) {
            if(n!=0) str+="&";
            str+=v[n];
            }
            std::cout<<std::setiosflags(std::ios::left)
            <<std::setw(12) <<i->getTitle()
            <<std::setw(12) <<i->getSponsor()
            <<std::setw(20) << Date::dateToString(i->getStartDate())
            <<std::setw(20) << Date::dateToString(i->getEndDate())
            <<std::setw(20) << str
            <<"\n";
        }
    }