.default: all

PROGRAMS=time

all: $(PROGRAMS)

clean:
	rm -rf $(PROGRAMS) *.o *.dSYM

time: main.o Time.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
