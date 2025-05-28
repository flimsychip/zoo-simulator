# Name to be given to exec file
TARGET_EXEC := main

# Path to folder to contain build files (.o and .d)
BUILD_DIR := ./build
# Path to folder containing source files (.cpp)
# I removed functionality for nested source files, so dis just local
SRC_DIRS := ./src

# Specifies c++ compiler
CXX := g++
# Specifies c++ compilation flags
CXXFLAGS := -std=c++20 -Wall

# Find all the C++ files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, 
# but we want to send the * directly to the find command.
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

# Prepends BUILD_DIR and appends .o to every src file
# As an example, ./your_dir/hello.cpp turns into ./build/./your_dir/hello.o
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
# As an example, ./build/hello.o turns into ./build/hello.d
DEPS := $(OBJS:.o=.d)

# The -MMD and -MP flags together generate makefile dependencies
# These files will have .d instead of .o as the output.
CPPFLAGS := -MMD -MP

# The final build step (this links all .o files together)
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C++ source (each .o file)
$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
# Sort will remove all duplicate header targets
-include $(sort $(DEPS))
