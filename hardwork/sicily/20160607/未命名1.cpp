/**
 * file     :   jsoncpp_test.cpp
 * author   :   eliteYang
 * email    :   elite_yang@163.com
 * blog     :   http://www.cppfasn.org
 * desc     :   json cpp test
 */
 
#include <fstream>
#include <string>
#include "json.h"
 
int main()
{
    std::ifstream ifs;
    ifs.open("test.json");
 
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(ifs, root, false))
    { return -1; }
 
    Json::Value add_value = root["address"];
    for (int i = 0; i < add_value.size(); ++i)
    {
        Json::Value temp_value = add_value[i];
        std::string strName = temp_value["name"].asString();
        std::string strMail = temp_value["email"].asString();
        std::cout << "name: " << strName << " email: " << strMail << std::endl;
 
        // use value array[index]
        //Json::Value temp_value = add_value[i];
        //std::string strName = add_value[i]["name"].asString();
        //std::string strMail = add_value[i]["email"].asString();
        //std::cout << "name: " << strName << " email: " << strMail << std::endl;
    }
 
    system("Pause");
 
    return 0;
}
