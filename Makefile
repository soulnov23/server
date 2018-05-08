CC = g++
PROJ_PATH = $(shell pwd)
TARGET_NAME = server
TARGET_CLIENT = client
MODULES = lib src
OBJ_DIR = $(PROJ_PATH)/obj

all : $(MODULES)
	$(MAKE) -C $(OBJ_DIR) TARGET_NAME="$(TARGET_NAME)" all
	@cp -f $(TARGET_NAME) $(TARGET_CLIENT)
	@echo "make done!"

lib :
	$(MAKE) -C $(PROJ_PATH)/lib OBJ_DIR="$(OBJ_DIR)" all

src :
	$(MAKE) -C $(PROJ_PATH)/src OBJ_DIR="$(OBJ_DIR)" all

.PHONY : clean $(MODULES)

clean :
	$(MAKE) -C $(PROJ_PATH)/obj TARGET_NAME="$(TARGET_NAME)" clean
	$(MAKE) -C $(PROJ_PATH)/lib clean
	$(MAKE) -C $(PROJ_PATH)/src clean
	rm -rf $(TARGET_NAME) $(TARGET_CLIENT) core.*
	@echo "clean done!"