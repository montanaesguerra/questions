# compiler options
CXXFLAGS = -g -Wall -Wextra
CXXFLAGS += -std=c++17 -pedantic -pedantic-errors
CXXFLAGS += -Wfloat-equal -Wredundant-decls -Wshadow -Wconversion

# list .h files here
HEADERS = MultipleChoice.h Question.h ShortAnswer.h NumericAnswer.h

# list .cpp files here
TEST_FILES = tests.cpp MultipleChoice.cpp Question.cpp ShortAnswer.cpp NumericAnswer.cpp
SHARED_FILES = 

.PHONY: all
all: tests.exe

.PHONY: tests.exe # Always force rebuild of tests
tests.exe: $(TEST_FILES) $(SHARED_FILES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_FILES) $(SHARED_FILES) -o $@

.PHONY: clean
clean:
	rm -f tests.exe
