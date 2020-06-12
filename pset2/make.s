#On my honor, I pledge that I have neither received nor provided 
#improper assistance in the completion of this programming assignment.
#Signed: 김민혁
CC = g++
SRCS = bubble.cpp insertion.cpp quicksort.cpp selection.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = libsort.a

$(TARGET): $(OBJS)
	ar cru $@ $^
	ranlib $@

$(OBJS): %.o: %.cpp
	$(CC) -c $< -o $@
	$(CC) -MM -MF $*.d $<
-include $(SRCS:.cpp=.d)
