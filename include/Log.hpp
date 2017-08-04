#ifndef LOG_HPP
#define LOG_HPP
#endif

#include <memory>
#include <ctime>
#include <cmath>
#include <fstream>

class Log {
private:
    Log();
    Log(const Log & t_another) = delete;
    void operator=(const Log & t_another) = delete;
    static std::shared_ptr<Log> ptr;
    std::string fileName;
    int  fileID;
    long long  fileSize ;
public:
    static std::shared_ptr<Log> getInstance( void ) ;
    void write( std::string name ,std::string str) ;
};
