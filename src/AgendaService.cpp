#include"AgendaService.hpp"
#include"Storage.hpp"
#include <list>
#include <string>


    /**
     * constructor
     */
    AgendaService::AgendaService()
    {
        startAgenda();
    }

    /**
     * destructor
     */
    AgendaService::~AgendaService()
    {
        quitAgenda();
    }

    /**
     * check if the username match password
     * @param userName the username want to Login
     * @param password the password user enter
     * @return if success, true will be returned
     */
    bool AgendaService::userLogIn(const std::string userName, const std::string password)
    {
        auto lambda = [&](const User & user)->bool{
            return (user.getName() == userName && user.getPassword() == password); 
        };
        auto func = lambda;
        if(!m_storage->queryUser(func).empty())m_Log->write(userName,"userLogIn");
        return (!m_storage->queryUser(func).empty());
    }

    /**
     * regist a user
     * @param userName new user's username
     * @param password new user's password
     * @param email new user's email
     * @param phone new user's phone
     * @return if success, true will be returned
     */
    bool AgendaService::userRegister(const std::string userName, const std::string password,
                      const std::string email, const std::string phone)
    {
        auto lambda = [&](const User & user)->bool{
            return (user.getName() == userName ); 
        };
        auto func = lambda;
        auto list = m_storage->queryUser(func);
        if(list.empty()) {
           User user(userName,password,email,phone);
            m_storage->createUser(user);
            m_Log->write(userName,"userRegister");
            return 1;
        } else return 0;
    }

    /**
     * delete a user
     * @param userName user's username
     * @param password user's password
     * @return if success, true will be returned
     */
    bool AgendaService::deleteUser(const std::string userName, const std::string password)
    {
        auto lambda = [&](const User & user)->bool{
            return (user.getName() == userName && user.getPassword() == password); 
        };
        auto func = lambda;
        if(m_storage->deleteUser(func) > 0 )  {
            auto l = listAllMeetings(userName);
            for(auto i = l.begin();i!=l.end();i++) 
                deleteMeeting(userName,i->getTitle());
            m_Log->write(userName,"deleteUser");
            return true;
        }else return false;
    }

    /**
     * list all users from storage
     * @return a user list result
     */
    std::list<User> AgendaService::listAllUsers(void) const
    {
        auto lambda = [&](const User & user)->bool{
            return 1; };
        auto func = lambda;
        m_Log->write("userName","listAllUsers");
        return m_storage->queryUser(func);
        
    }

    /**
     * create a meeting
     * @param userName the sponsor's userName
     * @param title the meeting's title
     * @param participator the meeting's participator
     * @param startData the meeting's start date
     * @param endData the meeting's end date
     * @return if success, true will be returned
     */
    bool AgendaService::createMeeting(const std::string userName, const std::string title,
                       const std::string startDate, const std::string endDate,
                       const std::vector<std::string> participator)
    {
        Date a(startDate); Date b(endDate);
        if(a >= b ) return 0;
        if(participator.empty()) return 0;
        for(auto same : participator) {        
        if(userName == same) return false;
    }   

        auto it = m_storage -> queryUser([userName](const User & user){return userName == user.getName();}); 
        if(it.empty()) return false;

        for(auto i = participator.begin(); i < participator.end();i++) {
            if(*i == userName) return 0;
            auto lambda = [&](const User & user)->bool{
            return (user.getName() == *i ); };
            auto func = lambda;
        if(m_storage->queryUser(func).empty()) return 0;
        }
        
        auto participator2 = participator;
        for(auto i1 : participator) {
            int num = 0;
            for(auto i2 : participator) {
                if(i1 == i2) num++;
            }
            if(num != 1) return 0;
        }

        auto lambda0 = [&](const Meeting & meeting)->bool{
        return (meeting.getTitle() == title);};
        auto func0 = lambda0;
        if(!m_storage->queryMeeting(func0).empty()) return 0;

        auto lambda1 = [&](const Meeting & meeting)->bool{
            bool test1 = (meeting.getSponsor() == userName || meeting.isParticipator(userName));
            bool test2;
            for(auto par : participator) {
            test2 = (meeting.getSponsor() == par || meeting.isParticipator(par));
        }
        return (
            (test1||test2)&&
            ((meeting.getStartDate() >= a && meeting.getStartDate() < b) ||
            (meeting.getEndDate() > a && meeting.getEndDate() <= b ) ||
            (meeting.getStartDate() <= a && meeting.getEndDate() >= b))
        );};
        auto func1 = lambda1;
        if(!m_storage->queryMeeting(func1).empty()) return 0;

        m_Log->write(userName,"createMeeting");
       Meeting meeting0(userName,participator,startDate,endDate,title);
       m_storage->createMeeting(meeting0); return 1;
    }

    /**
     * search meetings by username and title (user as sponsor or participator)
     * @param uesrName the user's userName
     * @param title the meeting's title
     * @return a meeting list result
     */
    std::list<Meeting> AgendaService::meetingQuery(const std::string userName,
                                    const std::string title) const
    {

        auto lambda = [&](const Meeting & meeting)->bool{
        return ((meeting.getSponsor() == userName  || meeting.isParticipator(userName))&& meeting.getTitle() == title);};
       auto func = lambda;
       m_Log->write(userName,"queryMeeting");
        return (m_storage->queryMeeting(func));
    }
    /**
     * search a meeting by username, time interval (user as sponsor or participator)
     * @param uesrName the user's userName
     * @param startDate time interval's start date
     * @param endDate time interval's end date
     * @return a meeting list result
     */
    std::list<Meeting> AgendaService::meetingQuery(const std::string userName,
                                    const std::string startDate,
                                    const std::string endDate) const
    {
        std::list<Meeting>result;
    Date start(startDate);
    Date end(endDate);
    if(!(Date::isValid(start) && Date::isValid(end))) return result;
    if(start > end) return result;
    return m_storage -> queryMeeting([&](const Meeting& m){
        return ( m.getSponsor() == userName || m.isParticipator( userName ) ) && 
        (((m.getStartDate() <= start)&&(start <= m.getEndDate())) || ( ( m.getStartDate() <= end ) && ( end <= m.getEndDate() ) ) 
            || ((m.getStartDate() >= startDate) && (m.getEndDate() <= endDate)) );
    });
    }

    /**
     * list all meetings the user take part in
     * @param userName user's username
     * @return a meeting list result
     */
    std::list<Meeting> AgendaService::listAllMeetings(const std::string userName) const
    {
        auto lambda = [&](const Meeting & meeting)->bool{
        return (meeting.getSponsor() == userName || meeting.isParticipator(userName));};
        auto func = lambda;
        m_Log->write(userName,"listAllMeetings");
        return (m_storage->queryMeeting(func));
    }


    /**
     * list all meetings the user sponsor
     * @param userName user's username
     * @return a meeting list result
     */
    std::list<Meeting> AgendaService::listAllSponsorMeetings(const std::string userName) const
    {
        auto lambda = [&](const Meeting & meeting)->bool{
        return (meeting.getSponsor() == userName );};
        auto func = lambda;
        m_Log->write(userName,"listAllSponsorMeetings");
        return (m_storage->queryMeeting(func));
    }

    /**
     * list all meetings the user take part in and sponsor by other
     * @param userName user's username
     * @return a meeting list result
     */
    std::list<Meeting> AgendaService::listAllParticipateMeetings(const std::string userName) const
    {
        auto lambda = [&](const Meeting & meeting)->bool{
        return (meeting.isParticipator(userName));};
        auto func = lambda;
        m_Log->write(userName,"listAllParticipateMeetings");
        return (m_storage->queryMeeting(func));
    }

    /**
     * delete a meeting by title and its sponsor
     * @param userName sponsor's username
     * @param title meeting's title
     * @return if success, true will be returned
     */
    bool AgendaService::deleteMeeting(const std::string userName, const std::string title)
    {
        auto lambda = [&](const Meeting & meeting)->bool{
            
        return ((meeting.getSponsor() == userName || meeting.isParticipator(userName))&& meeting.getTitle() == title);};
       auto func = lambda;
       m_Log->write(userName,"deleteMeeting");
       return m_storage->deleteMeeting(func);
    }

    /**
     * delete all meetings by sponsor
     * @param userName sponsor's username
     * @return if success, true will be returned
     */
    bool AgendaService::deleteAllMeetings(const std::string userName) {
        auto lambda = [&](const Meeting & meeting)->bool{
        return ((meeting.getSponsor() == userName));};
        auto func = lambda;
        m_Log->write(userName,"deleteAllMeetings");
        return m_storage->deleteMeeting(func);
    }

    /**
     * start Agenda service and connect to storage
     */
    void AgendaService::startAgenda(void)
    {
        m_storage = Storage::getInstance();
        m_Log = Log::getInstance();
    }

    /**
     * quit Agenda service
     */
    void AgendaService::quitAgenda(void)
    {
       
        m_storage->sync();
        //m_storage = nullptr;
    }