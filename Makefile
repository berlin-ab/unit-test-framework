build: src/testunit.c src/testunit/suite.c  src/testunit/group.c
	# Make build output directories
	mkdir -p build-output/lib;
	mkdir -p build-output/include;
	
	# Copy header files over
	cp src/testunit.h build-output/include/testunit.h
	
	# Create the shared object  
	gcc -Wall -shared src/testunit.c src/testunit/suite.c src/testunit/group.c \
		-o build-output/lib/libtestunit.so

test: clean build
	# Make test output directory
	mkdir -p test-output;
	
	# Create test
	gcc -Wall test/test.c -I build-output/include -L build-output/lib -l testunit -o test-output/test.o
	
	# Run test
	./test-output/test.o

clean: 
	rm -rf test-output/
	rm -rf build-output/
	
