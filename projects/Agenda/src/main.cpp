#include"Date.hpp"
#include"User.hpp"
#include"Meeting.hpp"
#include"Storage.hpp"
#include"AgendaService.hpp"
#include<iostream>
//TEST(DateTEST,Date::dateToString)
//{
//  
//}3;acdfpu
int main() 
{
  Date date1(2016,2,12,23,12);
  Date date2(2017,2,12,23,13);
  User user1("name","***","email","phone");
  std::vector<std::string> it;
  std::vector<std::string>::iterator ite = it.begin();
  std::string str = "people";
  it.insert(ite,1,str);
  Meeting d(user1.getName(),it,date1,date2,"title");
  
  std::cout <<std::endl
    <<std::endl
    <<std::endl
    <<std::endl
    <<std::endl;


  //std::shared_ptr<Storage> p = Storage::getInstance();
  //p->createUser(user1);
  //p->createMeeting(d);
    AgendaService a;
    a.userRegister("name","***","email","phone");



  //::testing::InitGoogleTest(&argv,argv);
  //return RUN_ALL_TESTS();
}

/*
$(BIN_DIR)/main: $(BUILD_DIR)/Agenda.o $(BUILD_DIR)/Date.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Meeting.o $(BUILD_DIR)/Path.o $(BUILD_DIR)/Storage.o $(BUILD_DIR)/AgendaService.o $(BUILD_DIR)/AgendaUI.o
  @mkdir -p $(BIN_DIR)
  $(CC) $(FLAGS) $(INCLUDE) $(BUILD_DIR)/Agenda.o $(BUILD_DIR)/Date.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Meeting.o $(BUILD_DIR)/Path.o $(BUILD_DIR)/Storage.o $(BUILD_DIR)/AgendaService.o $(BUILD_DIR)/AgendaUI.o  -o $@ 

$(BUILD_DIR)/Date.o: $(SRC_DIR)/Date.cpp 
  @mkdir -p $(BUILD_DIR)
  $(CC) $(FLAGS) $(INCLUDE) $(SRC_DIR)/Date.cpp -c -o $@

$(BUILD_DIR)/User.o: $(SRC_DIR)/User.cpp 
  @mkdir -p $(BUILD_DIR)
  $(CC) $(FLAGS) $(INCLUDE) $(SRC_DIR)/User.cpp -c -o $@

$(BUILD_DIR)/Meeting.o: $(SRC_DIR)/Meeting.cpp 
  @mkdir -p $(BUILD_DIR)
  $(CC) $(FLAGS) $(INCLUDE) $(SRC_DIR)/Meeting.cpp -c -o $@

$(BUILD_DIR)/Path.o: $(INC_DIR)/Path.hpp 
  @mkdir -p $(BUILD_DIR)
  $(CC) $(FLAGS) $(INCLUDE) $(INC_DIR)/Path.hpp -c -o $@

$(BUILD_DIR)/Storage.o: $(SRC_DIR)/Storage.cpp 
  @mkdir -p $(BUILD_DIR)
  $(CC) $(FLAGS) $(INCLUDE) $(SRC_DIR)/Storage.cpp -c -o $@

$(BUILD_DIR)/AgendaService.o: $(SRC_DIR)/AgendaService.cpp 
  @mkdir -p $(BUILD_DIR)
  $(CC) $(FLAGS) $(INCLUDE) $(SRC_DIR)/AgendaService.cpp -c -o $@

$(BUILD_DIR)/AgendaUI.o: $(SRC_DIR)/AgendaUI.cpp 
  @mkdir -p $(BUILD_DIR)
  $(CC) $(FLAGS) $(INCLUDE) $(SRC_DIR)/AgendaUI.cpp -c -o $@

$(BUILD_DIR)/Agenda.o: $(SRC_DIR)/Agenda.cpp 
  @mkdir -p $(BUILD_DIR)
  $(CC) $(FLAGS) $(INCLUDE) $(SRC_DIR)/Agenda.cpp -c -o $@
*/
