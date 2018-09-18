
build: src/testunit.c
	mkdir -p build-output;
	cp src/testunit.h build-output/testunit.h  
	gcc -Wall -shared src/testunit.c -o build-output/libtestunit.so

test: clean build
	mkdir -p test-output;
	gcc -Wall test/test.c -I build-output -L build-output -l testunit -o test-output/test.o
	./test-output/test.o

clean: 
	rm -rf test-output/
	rm -rf build-output/
	
