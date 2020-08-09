target := earthlings
flags := -std=c99 -l SDL2 -l SDL2_image -l SDL2_ttf
src := $(wildcard src/*.c)

all: $(target)

$(target): main.c $(src)
	gcc $^ $(flags) -o $@

clean:
	rm -fv $(target)

