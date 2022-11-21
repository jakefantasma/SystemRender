CC = g++ 
BUILD = build
BIN = debug.exe

LIBS = -lopengl32 -lglu32 -lfreeGLUT

%.o : %.cpp
	$(CC) -c $< -o "$(BUILD)\\$@" 

main.o : main.cpp

all: main.o
	$(CC) -g $(BUILD)\\*.o -o "$(BUILD)\\$(BIN)" $(LIBS)

run:
	cmd /c start cmd /k .\$(BUILD)\\$(BIN)


config : 
	mkdir $(BUILD)
	mkdir "includes"
clean: 
	cd  $(BUILD) && rm -f *.o *.exe
