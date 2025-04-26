CC = g++
CXXFLAGS = -lgtest -lgtest_main -pthread


# make 		  - builds binaries for stddev and calculator apps
# make calc   - builds binary for calculator app
# make stddev - builds binary for stddev cli app

# make pack-calc   - packs the calculator app into a .deb file (for now)
# make pack-stddev - packs the stddev cli app into a .deb file (for now)

.PHONY: all calc stddev pack-calc pack-stddev test clean doc run

all: build stddev
# Build GUI calculator
build:
	@echo "Building DEB and EXE installers..."

	# Build calculator and create DEB
	@mkdir -p ../build
	@rm -rf ../build/*
	@cd ../build && cmake .. -DBUILD_CALCULATOR=ON -DBUILD_STDDEV=OFF
	@cd ../build && cmake --build .
	@cd ../build && cpack -G DEB

	# Build calculator and create EXE
	@mkdir -p ../build-calculator-windows
	@rm -rf ../build-calculator-windows/*
	@cd ../build-calculator-windows && cmake .. -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=../cmake/Toolchain-mingw64.cmake -DBUILD_CALCULATOR=ON -DBUILD_STDDEV=OFF
	@cd ../build-calculator-windows && cmake --build .
	@cd ../build-calculator-windows && cpack -G NSIS
	
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
	@echo "Generating docs... (not yet implemented)"

# Run the GUI calculator
run: 
	../build/calculator

### END OF FILE MAKEFILE ###