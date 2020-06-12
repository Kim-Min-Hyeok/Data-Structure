#On my honor, I pledge that I have neither received nor provided 
#improper assistance in the completion of this programming assignment.
#Signed: 김민혁
CC = g++
LDFLAGS = -L../../lib -lsort -lnowic -lm
INCDIR - ../../include
SRCS = buble.cpp insertion.cpp quicksort.cpp selection.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = libsort
TARGET: $(OBJS)
	$(CC) -I$(INCDIR) -o $@ $^ $(LDFLAGS)

	.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

//make.1
	libsort: bubble.o insertion.o quicksort.o selection.o
		g++ bubble.o insertion.o quicksort.o selection.o -o libsort

	bubble.o: bubble.cpp
		g++ -c bubble.cpp
	insertion.o: insertion.cpp
		g++ -c insertion.cpp
	quicksort.o: quicksort.cpp
		g++ -c quicksort.cpp
	selection.o: selection.cpp
		g++ -c selection.cpp
	clean:
		rm -f *.o libsort.exe libsort

//make.2
CC=g++
LDFLAGS = -L../../lib
INCDIR = ../../include

SRCS = buble.cpp insertion.cpp quicksort.cpp selection.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
TARGET = libsort
* make target (executable)
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	(CC) -c $(CCFLAGS) -I$(INCDIR) $< -o $@
	(cc) -I$(INCDIR) -MM -MF $*.d $<
-include $(DEPS)

.PHONY: all debug clean cleanx
all: $(TARGET)
debug: CCFLAGS += -DDEBUG -g
debug: all
clean:
	rm -f $(OBJS) $(DEPS)
cleanx:
	rm -f $(OBJS) $(DEPS) $(TARGET).exe $(TARGET)
