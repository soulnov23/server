CC = g++
PROJ_PATH = $(shell pwd)
TARGET_NAME = server
MODULES = lib src
OBJ_DIR = $(PROJ_PATH)/objs

all : $(MODULES)
	$(MAKE) -C $(OBJ_DIR) TARGET_NAME="$(TARGET_NAME)" all
	@echo "make done!"

lib :
	$(MAKE) -C $(PROJ_PATH)/lib OBJ_DIR="$(OBJ_DIR)" all

src :
	$(MAKE) -C $(PROJ_PATH)/src OBJ_DIR="$(OBJ_DIR)" all

.PHONY : clean $(MODULES)

clean :
	$(MAKE) -C $(PROJ_PATH)/objs TARGET_NAME="$(TARGET_NAME)" clean
	$(MAKE) -C $(PROJ_PATH)/lib clean
	$(MAKE) -C $(PROJ_PATH)/src clean
	rm -rf $(TARGET_NAME) server_cli core.*
	@echo "clean done!"

