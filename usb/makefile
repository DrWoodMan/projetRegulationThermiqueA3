PROJET = usb.exe

CFLAGS = -g -Wall -Wextra -Os -std=gnu11
LDFLAGS = -lm lib\i386\ftd2xx.lib

SRC = $(wildcard *.c)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(NOM)))

all: $(PROJET)

remake: clean $(PROJET)

$(PROJET) : $(OBJ)
	gcc obj/*.o $(LDFLAGS) -o $@

obj/%.o: %.c
	gcc -c $< -I. -o $@ $(CFLAGS)

clean:
	rm obj/*.o $(PROJET) *.gch -f

clear:
	rm obj/*.o *.gch -f