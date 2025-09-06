# very basic makefile to get started

dbg?=0

CXX = g++
CXXFLAGS = -Wall -Werror -pedantic

ifeq (${dbg},1)
  CXXFLAGS+=-g
else
  CXXFLAGS+=-O3
endif


SRCS := $(wildcard ./src/*.cpp)
OBJS := $(patsubst ./src/%.cpp,./build/obj/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

BUILD_DIR ?= ./build

all: $(BUILD_DIR)/bin/texed


$(BUILD_DIR)/bin/texed: $(OBJS)
	$(CXX) $^ -o $@ -lncurses

$(BUILD_DIR)/obj/%.o: ./src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -Iinclude -MMD -MP


$(BUILD_DIR):
	@mkdir -p ./build/obj ./build/bin


-include $(DEPS)


clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean all
