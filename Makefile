CC = g++
EXECUTABLE = bin/main.out
CFLAGS = -Wall -Werror -c -MD
SOURCES = $(wildcard $(addprefix src/,*.cpp))
OBJECTS = $(patsubst $(addprefix src/, %.cpp),$(addprefix build/, %.o),$(wildcard $(addprefix src/, *.cpp)))
DEPENDENCIES = $(patsubst $(addprefix build/, %.o), $(addprefix build/, %.d), $(wildcard $(addprefix build/, *.o)))

all : $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $^ -o $@

build/%.o : src/%.cpp
	$(CC) $(CFLAGS) $< -o $@

.PHONY:clean
clean:
	rm $(OBJECTS) $(EXECUTABLE) $(DEPENDENCIES)

include $(wildcard $(addprefix build/, *.d))