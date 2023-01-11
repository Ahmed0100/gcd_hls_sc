SYSTEMC_HOME = /usr/local/systemc-2.3.1
TARGET_ARCH = linux64
SYSTEMC_INC_DIR = $(SYSTEMC_HOME)/include
SYSTEMC_LIB_DIR = $(SYSTEMC_HOME)/lib-$(TARGET_ARCH)

EXE = behavioural_gcd
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj
VCD_DIR = vcd

SRC = $(wildcard $(SRC_DIR)/*.cpp)
INC = $(wildcard $(INC_DIR)/*.h)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
VCD = $(wildcard $(VCD_DIR)/*.vcd)

CPPFLAGS = -I$(INC_DIR) -I$(SYSTEMC_INC_DIR)
CFLAGS = -Wall
LDFLAGS = -L$(SYSTEMC_LIB_DIR) -pthread
LDLIBS = -lsystemc -lm

CC = g++

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) $(SYSTEMC_LIB_DIR)/libsystemc.a
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm $(EXE) $(OBJ) $(VCD)