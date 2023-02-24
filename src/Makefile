all: build viz

build:
	g++ main.cpp -Wall

run:
	./a.out

viz:
	./a.out > fh.dot
	dot -Tpng fh.dot -o fh.png

clean:
	rm -f a.out fh.dot fh.png
