SRC:= $(wildcard *.c)
OBJ:= $(patsubst %.c, %.o, $(SRC))

node_list: $(OBJ)
	gcc -o $@ $^

clean:
	rm *.o
