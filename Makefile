CC = g++
PROJ_PATH = $(shell pwd)
TARGET_NAME = server
MODULES = src
OBJ_DIR = $(PROJ_PATH)/objs

.PHONY : clean $(MODULES)

all : $(MODULES)
	$(MAKE) -C $(OBJ_DIR) TARGET_NAME="$(TARGET_NAME)" all
	@echo "make done!"

src :
	$(MAKE) -C $(PROJ_PATH)/src OBJ_DIR="$(OBJ_DIR)" all

clean :
	$(MAKE) -C $(PROJ_PATH)/objs TARGET_NAME="$(TARGET_NAME)" clean
	$(MAKE) -C $(PROJ_PATH)/src clean
	rm -rf $(TARGET_NAME) core.*
	@echo "clean done!"

