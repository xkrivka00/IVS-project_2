SHELL := /bin/bash

CC=g++
CXXFLAGS = -pg -g -O0

SRC=stddev.cpp
EXE=stddev

INPUTS=10.txt 1000.txt 1000000.txt

GMON=gmon.out
GPROF_PREFIX=gmon
GPROF_TXT_PREFIX=gprof_output

.PHONY: all run clean

all: $(EXE)

$(EXE): $(SRC)
	$(CC) $(CXXFLAGS) -o $(EXE) $(SRC)

run: $(EXE)
	@for file in $(INPUTS); do \
		echo "Running on $$file..."; \
		./$(EXE) < $$file; \
		basename=$${file%.txt}; \
		mv $(GMON) $(GPROF_PREFIX)_$$basename.out; \
		gprof $(EXE) $(GPROF_PREFIX)_$$basename.out > $(GPROF_TXT_PREFIX)_$$basename.txt; \
	done

clean:
	rm -f $(EXE) $(GMON) $(GPROF_TXT_PREFIX)*.txt $(GPROF_PREFIX)_*.out
