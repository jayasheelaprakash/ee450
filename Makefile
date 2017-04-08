.PHONY : clean
.SILENT : clean 

VPATH := src lib obj
CLIENT_SRC := src/client.c  src/readfromfile.c  src/util.c
CLIENT_OBJ := $(CLIENT_SRC:src/%.c=obj/%.o)
CFLAGS := -Wall -Wstrict-prototypes -std=c11

client : $(CLIENT_OBJ)
	mkdir -p bin
	gcc -o ./bin/$@ $+
	


obj/%.o : src/%.c 
	mkdir -p obj
	gcc -c $^  -o $@ $(CFLAGS) 

clean :
	rm -rf obj bin
	echo "Cleaned Successfully"
