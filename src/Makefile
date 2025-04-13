CC = g++
CXXFLAGS = -lgtest -lgtest_main -pthread

.PHONY: all pack test clean doc run sttdev 

#TODO: přeloží projekt – včetně programu pro profiling
all:

#TODO: zabalí projekt tak, aby mohl být odevzdán
pack:

#TODO: smaže všechny soubory, co nemají být odevzdány
clean: 

#TODO: spustí testy matematické knihovny
test:
	@cd tests && $(CC) tests.cpp -o $@ $(CXXFLAGS)
	@cd tests && ./$@

#TODO: spustí generování dokumentace
doc: 

#TODO: spustí program
run: 

#TODO: spustí překlad programu pro výpočet směrodatné odchylky na profiling    
stddev:
	@cd profiling && $(CC) stddev.cpp -o $@
	@cd profiling && ./$@
