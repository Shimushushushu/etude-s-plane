CXX = g++
CXXFLAGS = -std=c++11 -Iinclude

vpath %.h  include
vpath %.cc src .

color.o: color.cc color.h
	$(CXX) $(CXXFLAGS) -c src/color.cc

color-test: color-test.cc color.o color.h
	$(CXX) $(CXXFLAGS) color-test.cc color.o -o color-test

complex2hsl.o: complex2hsl.cc complex2hsl.h
	$(CXX) $(CXXFLAGS) -c src/complex2hsl.cc

complex2hsl-test: complex2hsl-test.cc complex2hsl.o complex2hsl.h color.o color.h
	$(CXX) $(CXXFLAGS) complex2hsl-test.cc complex2hsl.o color.o -o complex2hsl-test

main: main.cc complex2hsl.o complex2hsl.h color.o color.h
	$(CXX) $(CXXFLAGS) main.cc color.o complex2hsl.o -o main

out.ppm: main
	./main

out.png: out.ppm
	-rm out.png
	ffmpeg -i out.ppm out.png

.PHONY: clean
clean:
	-rm *.o
	-rm *-test main
	-rm out.ppm out.png