
CC = g++
OBJ := main.o
TOP_DIR := $(PWD)
OBJ_DIR := $(TOP_DIR)/obj
BIN_DIR := $(TOP_DIR)/bin
SUB_DIR:=src/Factory src/Bridge src/Decorator

export CC OBJ OBJ_DIR TOP_DIR BIN_DIR

all: CHECKDIR $(SUB_DIR)

CHECKDIR:
	mkdir -p $(SUB_DIR) $(BIN_DIR)

$(SUB_DIR): ECHO
	make -C $@
ECHO:
	@echo $(SUB_DIR)
	@echo begin compile


clean :
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)	