CC = g++
JAVAC = javac

programs = permute mergedisjoint arrayclass funcptr recurseptr bft

all: $(programs) compile-java

compile-java: *.java
	$(JAVAC) *.java

$(programs): %: %.o

clean:
	rm -f $(programs) *.o *.class
