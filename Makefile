EXENAME = test
OBJS = .objs/sensor.o .objs/main.o

CXX = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++ -c -g -O0 -Wall -Wextra
LD = clang++
LDFLAGS = -std=c++11

all: $(EXENAME)

.objs:
	@mkdir -p .objs

$(EXENAME): $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@

.objs/main.o: src/pc_test/main.cpp .objs
	$(CXX) $< $(CXXFLAGS) -o $@

.objs/sensor.o: lib/sensor/sensor.cpp .objs
	$(CXX) $< $(CXXFLAGS) -o $@

clean:
	-rm -rf *.o $(EXENAME) .objs
