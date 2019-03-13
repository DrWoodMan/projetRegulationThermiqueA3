PROJET = test.exe

CFLAGS = -g -Wall -Wextra -Os -std=gnu11
LDFLAGS = -lm 

SRC = $(wildcard *.c)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(NOM)))

all: $(PROJET)

remake: clean $(PROJET)

$(PROJET) : $(OBJ)
	gcc obj/* $(LDFLAGS) -o $@

obj/%.o: %.c
	gcc -c $< -I. -o $@ $(CFLAGS)

clean:
	rm obj/*.o *.out *.gch -f

clear:
	rm obj/*.o *.gch -f