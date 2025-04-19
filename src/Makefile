CC = g++
CXXFLAGS = -lgtest -lgtest_main -pthread


# make 		  - builds binaries for stddev and calculator apps
# make calc   - builds binary for calculator app
# make stddev - builds binary for stddev cli app

# make pack-calc   - packs the calculator app into a .deb file (for now)
# make pack-stddev - packs the stddev cli app into a .deb file (for now)

.PHONY: all calc stddev pack-calc pack-stddev test clean doc run

all: calc stddev
# Build GUI calculator
calc:
	@echo "Building calculator..."
	@mkdir -p ../build-calculator
	@rm -rf ../build-calculator/*
	@cd ../build-calculator && cmake .. -DBUILD_CALCULATOR=ON -DBUILD_STDDEV=OFF
	@cd ../build-calculator && cmake --build .
	@cp ../build-calculator/calculator ../

# Build terminal stddev program
stddev:
	@echo "Building stddev..."
	@mkdir -p ../build-stddev
	@rm -rf ../build-stddev/*
	@cd ../build-stddev && cmake .. -DBUILD_CALCULATOR=OFF -DBUILD_STDDEV=ON
	@cd ../build-stddev && cmake --build .
	@cp ../build-stddev/src/profiling/stddev ../

# Package GUI calculator
pack-calc:
	@echo "Packaging calculator..."
	@cd ../build-calculator && cpack

# Package CLI stddev
pack-stddev:
	@echo "Packaging stddev..."
	@cd ../build-stddev && cpack
# Remove build artifacts
clean:
	@rm -f profiling/stddev tests/test
	@rm -rf ../build-calculator/ ../build-stddev/
	@rm -f ../calculator ../stddev

# Run math library tests
test:
	@cd tests && $(CC) *.cpp -o $@ $(CXXFLAGS) && ./$@ 

# Generate documentation
doc: 
	@echo "Generating docs... (not yet implemented)"

# Run the GUI calculator
run: 
	../calculator

### END OF FILE MAKEFILE ###