CC = g++
EXECUTABLE = bin/main.out
CFLAGS = -Wall -Werror -c -MD
SOURCES = $(wildcard $(addprefix src/,*.cpp))
OBJECTS = $(patsubst $(addprefix src/, %.cpp),$(addprefix build/, %.o),$(wildcard $(addprefix src/, *.cpp)))
DEPENDENCIES = $(patsubst $(addprefix build/, %.o), $(addprefix build/, %.d), $(wildcard $(addprefix build/, *.o)))
TEST_SOURCES = $(wildcard $(addprefix test/, *.cpp))
TEST_OBJECTS = $(patsubst $(addprefix test/, %.h),$(addprefix build/, %.o),$(wildcard $(addprefix test/, *.h))) $(patsubst $(addprefix test/, %.cpp),$(addprefix build/, %.o),$(wildcard $(addprefix test/, *.cpp)))
TEST_EXECUTABLE = bin/test.out

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $^ -o $@ -std=c++11

build/%.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -std=c++11

.PHONY : clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(DEPENDENCIES) $(TEST_OBJECTS) $(TEST_EXECUTABLE)

.PHONY : test
test : $(TEST_SOURCES) $(TEST_EXECUTABLE)
	$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE) : $(TEST_OBJECTS)
	$(CC) $^ -o $@ -std=c++11

build/%_test.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -std=c++11

build/%.o : test/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -std=c++11

include $(wildcard $(addprefix build/, *.d))