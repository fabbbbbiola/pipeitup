all: pipe.c
	gcc -o pipe pipe.c

clean:
	rm *o
	rm *~

run: all
	./pipe
