# Mostly copied from Artful Bytes example Makefile
###########################################################
# Toolchain
###########################################################
CC = gcc
RM = rm

###########################################################
# Directories
###########################################################
ROOT = .
SRC_DIR = $(ROOT)
OBJ_DIR = $(ROOT)/obj
BIN_DIR = $(ROOT)/bin


###########################################################
# Files
###########################################################
TARGET =  $(BIN_DIR)/main
SOURCES = $(wildcard *.c)
OBJECT_NAMES = $(SOURCES:.c=.o)
OBJECTS = $(patsubst %,$(OBJ_DIR)/%,$(OBJECT_NAMES))

###########################################################
# Build
###########################################################
$(TARGET): $(OBJECTS)
	@echo "Linking $^"
	@mkdir -p $(dir $@)
	$(CC)   -o $(TARGET) $^

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $^"
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $^

###########################################################
# Phony targets
###########################################################
.PHONY: all clean asm

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(OBJECTS)
