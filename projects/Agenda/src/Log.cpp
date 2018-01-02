#ifndef LOG_HPP
#include "Log.hpp"
#endif
#include<iostream>
#include<ctime>
#include<cmath>
#include<fstream>


std::shared_ptr<Log> Log::ptr = nullptr;
Log::Log(){
    fileName = "Operating";
    fileID = 0;
    fileSize = 10 * pow(2,1);
}
std::shared_ptr<Log> Log::getInstance( void ) {
        if( ptr == nullptr ) ptr.reset(new Log);
        return ptr;
}

void Log::write( std::string name ,std::string str) {

    std::string file = "";
    std::string timeStr = "";
    char *p = new char[4];
    std::ofstream o;
    long long  size = fileSize+1;

    while(size >= fileSize) {
        fileID++;
        file+=fileName;  sprintf(p,"%04d",fileID); file+=p; 
        file+=".Log";
        o.open(file,std::fstream::app);
        if(!o.is_open()) return;
        o.seekp(0,o.end);
        size = o.tellp();
    }

    time_t t; time(&t);
    timeStr += ctime(&t);
    o   << timeStr 
        << name     << "   "
        << str      << "   "
        << std::endl;
    o.close();
    return ;  
}
