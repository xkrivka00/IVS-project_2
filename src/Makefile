CC = g++
CXXFLAGS = -lgtest -lgtest_main -pthread

TEAM = xkrivka00_xsemerv00_xjanotf00_260514

.PHONY: all calc stddev pack-calc pack-stddev test clean doc run

# make 		  - builds binaries for stddev and calculator apps, creates their installers
all: build 

build:
	@mkdir -p ../build
	@cd ../build && cmake .. -DBUILD_CALCULATOR=ON -DBUILD_STDDEV=OFF && cmake --build . && cpack -G DEB

	@mkdir -p ../build-stddev
	@cd ../build-stddev && cmake .. -DBUILD_CALCULATOR=OFF -DBUILD_STDDEV=ON && cmake --build . && cpack -G DEB
	
# Build terminal stddev program binary
stddev:
	@echo "Building stddev..."
	@mkdir -p ../build-stddev
	@rm -rf ../build-stddev/*
	@cd ../build-stddev && cmake .. -DBUILD_CALCULATOR=OFF -DBUILD_STDDEV=ON && cmake --build .

# Package GUI calculator
pack: clean all doc
	@mkdir -p ../../$(TEAM)/repo ../../$(TEAM)/install ../../$(TEAM)/doc
	@cp -a doxygen_output/. ../../$(TEAM)/doc
	@rm -rf doxygen_output
	@cp -a ../build/*.deb ../../$(TEAM)/install
	@cp -a ../build-stddev/*.deb ../../$(TEAM)/install
	@rm -rf ../build ../build-stddev
	@cp -a ../. ../../$(TEAM)/repo
	@cd ../.. && zip -r $(TEAM).zip $(TEAM) && rm -rf $(TEAM)

# Remove build artifacts
clean:
	@rm -f profiling/stddev tests/test 
	@rm -rf ../build/ ../build-stddev/ ../doxygen_output

# Run math library tests
test:
	@cd tests && $(CC) *.cpp -o $@ $(CXXFLAGS) && ./$@ 

# Generate documentation
doc: 
	cd .. && doxygen Doxyfile && rm -f warning_doxygen.txt

# Run the GUI calculator
run: 
	../build/calculator

### END OF FILE MAKEFILE ###