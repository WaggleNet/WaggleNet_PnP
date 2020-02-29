EXENAME = test
OBJS = .objs/sensor.o .objs/main.o

CXX = g++
CXXFLAGS = -std=c++11 -c -g -O0 -Wall -Wextra
LD = g++
LDFLAGS = -std=c++11

all: $(EXENAME)

.objs:
	@mkdir -p .objs

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

.objs/main.o: examples/pc_test/main.cpp .objs
	$(CXX) $< $(CXXFLAGS) -o $@

.objs/sensor.o: src/sensor.cpp .objs
	$(CXX) $< $(CXXFLAGS) -o $@

clean:
	-rm -rf *.o $(EXENAME) .objs
