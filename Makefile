# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g --coverage -O0
INCLUDES = -I/usr/local/include
LDFLAGS = -L/usr/local/lib
LDLIBS = -lgtest -lgtest_main -pthread --coverage

# Directories
BUILD_DIR = .output
COV_DIR = $(BUILD_DIR)/coverage_report
LCOV_INFO = $(BUILD_DIR)/coverage.info

# Source files
SRC = function_need_to_test.cpp test.cpp
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)
EXE = $(BUILD_DIR)/runTests

# Default rule: build, run tests, and show coverage
all: $(EXE) run_tests coverage display

# Ensure output directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile source files
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Link executable
$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# Run the tests
run_tests:
	$(EXE)

# Generate coverage report
coverage:
	lcov --ignore-errors inconsistent,unsupported,format --capture --directory $(BUILD_DIR) --output-file $(LCOV_INFO).tmp
	lcov --ignore-errors inconsistent,unsupported,format,unused --remove $(LCOV_INFO).tmp '/usr/*' '/Applications/*' '*/googletest/*' --output-file $(LCOV_INFO)
	rm -f $(LCOV_INFO).tmp
	genhtml --ignore-errors source,category $(LCOV_INFO) --output-directory $(COV_DIR)

# Display coverage result in terminal
display:
	lcov --ignore-errors inconsistent,unsupported,format,unused --list $(LCOV_INFO)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run_tests coverage display clean