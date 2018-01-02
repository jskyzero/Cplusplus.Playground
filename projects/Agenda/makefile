# Makefile
# Jskyzero
#

CC := g++-4.8
FLAGS := -std=c++0x
INC_DIR := include
SRC_DIR := src
BIN_DIR := bin
BUILD_DIR := build
INCLUDE := -I./$(INC_DIR)


$(BIN_DIR)/main:   $(SRC_DIR)/AgendaService.cpp $(SRC_DIR)/AgendaUI.cpp $(SRC_DIR)/Agenda.cpp $(SRC_DIR)/Date.cpp $(SRC_DIR)/Meeting.cpp $(SRC_DIR)/Storage.cpp $(SRC_DIR)/User.cpp $(INC_DIR)/Path.hpp 
	@mkdir -p $(BIN_DIR) 
	$(CC) $(FLAGS) $(INCLUDE)  $(SRC_DIR)/Log.cpp $(SRC_DIR)/AgendaService.cpp $(SRC_DIR)/AgendaUI.cpp $(SRC_DIR)/Agenda.cpp $(SRC_DIR)/Date.cpp $(SRC_DIR)/Meeting.cpp $(SRC_DIR)/Storage.cpp $(SRC_DIR)/User.cpp $(INC_DIR)/Path.hpp -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)

