EXENAME = test
OBJS = sensor.o main.o

CXX = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++ -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++11

all: $(EXENAME)

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

main.o: src/pc_test/main.cpp
	$(CXX) $< $(CXXFLAGS)

sensor.o: src/sensor/sensor.cpp
	$(CXX) $< $(CXXFLAGS)

clean:
	-rm -f *.o $(EXENAME)
