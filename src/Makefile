CC = g++
CXXFLAGS = -lgtest -lgtest_main -pthread

.PHONY: all calc stddev pack-calc pack-stddev test clean doc run

# make 		  - builds binaries for stddev and calculator apps, creates their installers
all: build 

build:
	@mkdir -p ../build
	@cd ../build && cmake .. -DBUILD_CALCULATOR=ON -DBUILD_STDDEV=OFF && cmake --build . && cpack -G DEB

	@mkdir -p ../build-stddev
	@cd ../build-stddev && cmake .. -DBUILD_CALCULATOR=OFF -DBUILD_STDDEV=ON && cmake --build . && cpack -G DEB
	
# Build terminal stddev program
stddev:
	@echo "Building stddev..."
	@mkdir -p ../build-stddev
	@rm -rf ../build-stddev/*
	@cd ../build-stddev && cmake .. -DBUILD_CALCULATOR=OFF -DBUILD_STDDEV=ON
	@cd ../build-stddev && cmake --build .
# ../build-stddev/src/profiling/stddev - pro spusteni

# Package GUI calculator
pack:
# TODO

# Remove build artifacts
clean:
	@rm -f profiling/stddev tests/test
	@rm -rf ../build/ ../build-stddev/

# Run math library tests
test:
	@cd tests && $(CC) *.cpp -o $@ $(CXXFLAGS) && ./$@ 

# Generate documentation
doc: 
	@cd ../ && doxygen Doxyfile

# Run the GUI calculator
run: 
	../build/calculator

### END OF FILE MAKEFILE ###