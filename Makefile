CC = g++

programs = permute mergedisjoint arrayclass funcptr

all: $(programs)

$(programs): %: %.o

clean:
	rm -f $(programs) *.o
