CXX=c++
CXXFLAGS+=-std=c++1z -g -Wall -pedantic
LDFLAGS+=-lSDL2
TARGET=play
OBJS=$(patsubst %.cc, %.o, $(wildcard *.cc))

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm $(TARGET) $(OBJS)
