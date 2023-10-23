CXXFLAGS = -Wall -g -O2 -std=gnu++20
LDLIBS = -lm
EXE = millionairemadness

all: $(EXE)

%: %.o
%.o: %.cpp

clean:
	rm -f millionairemadness

	rm -f *.o
