IDIR =include
CXX=g++
CXXFLAGS=-O3 -I$(IDIR)
CC=gcc
CFLAGS=-O3 -I$(IDIR)

ODIR=obj
CDIR=src

LIBS=

_DEPS = quicksort.h KMP.h bench.hpp benchable.hpp KMPBench.hpp QuicksortBench.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = quicksort.o KMP.o bench.o KMPBench.o QuicksortBench.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(CDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(CDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

benchmark: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) -Wl,-rpath,./lib $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
