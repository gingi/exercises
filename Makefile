CC = g++

programs = permute mergedisjoint arrayclass

all: $(programs)

$(programs): %: %.o

clean:
	rm -f $(programs) *.o
