.PHONY: clean

runit: uos
	./uos

clean:
	-rm -f uos

CFLAGS = -Wall
