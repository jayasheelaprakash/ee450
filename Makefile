.PHONY : clean

VPATH := src lib obj
SRC := $(wildcard src/*.c)
OBJ := $(SRC:src/%.c=obj/%.o)
CFLAGS := -Wall -Wstrict-prototypes -std=c11

client : $(OBJ)
	mkdir -p bin
	gcc -o ./bin/$@ $+
	


obj/%.o : src/%.c 
	mkdir -p obj
	gcc -c $^  -o $@ $(CFLAGS) -I include

clean :
	rm -rf obj bin
