src_dir := src
test_dir := test
build_dir := build

dsa_sources := $(shell find $(src_dir) \( -name '*.hpp' -o -name '*.cpp' \))
test_sources := $(shell find $(test_dir) -name '*.cpp')
test_objects := $(patsubst $(test_dir)/%.cpp, $(build_dir)/%.o, $(test_sources))

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -I$(src_dir)

GTEST_FLAGS := -lgtest -lgtest_main -pthread

target := $(build_dir)/test

all: $(target)

test: $(target)
	./$(target)

format: $(dsa_sources) $(test_sources)
	@clang-format -i $^
	@dprint fmt

.PHONY: all test

$(target): $(test_objects)
	@$(CXX) $(CXXFLAGS) $^ -o $@ $(GTEST_FLAGS)
	@echo "compiled tests"

$(build_dir)/%.o: $(test_dir)/%.cpp $(dsa_sources)
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(build_dir)

.PHONY: clean
