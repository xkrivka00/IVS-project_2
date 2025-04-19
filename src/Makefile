CC = g++
CXXFLAGS = -lgtest -lgtest_main -pthread

.PHONY: all pack test clean doc run stddev

# Checks if build directory exists and removes content, then runs cmake
build:
	@cd .. && cd ./build
	@mkdir -p ./build
	@rm -rf ./build/*
	@cmake .. && cmake --build .
	@cp ./src/calculator/calculator ../../../

#TODO: Compiles the project – including the program for profiling
all: build

#TODO: Packages the project for submission
pack:

#TODO: Removes all files that should not be submitted
clean: 
	@rm -f profiling/stddev tests/test
	@rm -rf build/*

#TODO: Runs tests for the math library
test:
	@cd tests && $(CC) *.cpp -o $@ $(CXXFLAGS) && ./$@ 

#TODO: Generates the documentation
doc: 

#TODO: Runs the main program
run: 

#TODO: Compiles the standard deviation program in the profiling directory    
stddev:
	@cd profiling && $(CC) *.cpp -o $@ && ./$@

 ### END OF FILE MAKEFILE ###