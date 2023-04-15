CC=g++
INCDIRS=-I.
# OPT=-O0
CFLAGS=$(INCDIRS) 

CFILES=BuildMap.cpp kanaExam.cpp kanas.cpp Score.cpp
OBJECTS=BuildMap.o kanaExam.o kanas.o Score.o

BINARY=kana 

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o:%.c 
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf $(BINARY) $(OBJECTS)
