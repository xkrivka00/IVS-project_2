CC = g++
CXXFLAGS = -lgtest -lgtest_main -pthread

.PHONY: all pack test clean doc run stddev

#TODO: Compiles the project – including the program for profiling
all:

#TODO: Packages the project for submission
pack:

#TODO: Removes all files that should not be submitted
clean: 
	@rm -f profiling/stddev 

#TODO: Runs tests for the math library
test:
	@cd tests && $(CC) tests.cpp -o $@ $(CXXFLAGS)
	@cd tests && ./$@

#TODO: Generates the documentation
doc: 

#TODO: Runs the main program
run: 

#TODO: Compiles the standard deviation program in the profiling directory    
stddev:
	@cd profiling && $(CC) stddev.cpp -o $@
	@cd profiling && ./$@

 ### END OF FILE MAKEFILE ###