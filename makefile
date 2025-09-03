# very basic makefile to get started

dbg?=0

CXX = g++
CXXFLAGS = -Wall -pedantic

ifeq (${dbg},1)
  CXXFLAGS+=-g
else
  CXXFLAGS+=-O3
endif


SRCS := $(wildcard ./src/*.cpp)
OBJS := $(patsubst ./src/%.cpp,./build/obj/%.o,$(SRCS))


all: ./build/texed


dirs:
	mkdir -p ./build/obj


./build/texed: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $< -lncurses

./build/obj/%.o: ./src/%.cpp | dirs
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f texed
	rm -rf ./build/

.PHONY: dirs clean
