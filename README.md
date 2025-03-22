# Google Test Simple

## 1. Intall lastest google test with command lines:
```
git clone https://github.com/google/googletest
cd googletest
mkdir build
cd build
cmake ..
make
make install
```

## 2. Build and run this project with CMake

```sh
cd Google-Test-Simple
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
./runTests
```

## 3. Build and run this project with Makefile

```sh
# Clean any previous builds
make clean

# Build the project, run tests, and generate coverage report
make all

# Or you can run individual steps:
make            # Just build the project
make run_tests  # Run the tests
make coverage   # Generate coverage report
make display    # Show coverage statistics

# To show html report
open .output/coverage_report/index.html  # On macOS
xdg-open .output/coverage_report/index.html  # On Linux
```

### Coverage Result

![Coverage Result](resources/html_report.png)



The coverage report will be generated in `.output/coverage_report/index.html`. Open this file in a web browser to view the detailed coverage report.

### Prerequisites for Makefile build:
- g++ compiler
- Google Test library
- lcov (for coverage reporting)

To install prerequisites on macOS:
```sh
brew install lcov
```


