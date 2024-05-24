CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS =  main.cpp stlstackqueue.cpp stlstackqueue2.cpp
EXEC1 = main
EXEC2 = stlstackqueue
EXEC3 = stlstackqueue2

.PHONY: all clean

all: $(EXEC1) $(EXEC2) $(EXEC3)

# Compilación de permutacion.cpp
$(EXEC1): main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

$(EXEC2): stlstackqueue.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

$(EXEC3): stlstackqueue2.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXEC1) $(EXEC2) $(EXEC3)
