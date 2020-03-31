CXXARGS  = -g -Wall
CXXFLAGS = -I. $(CXXARGS)

all: tp1.exe

tp1.exe: main.o vector.o cmdline.o complejo.o FourierTransform.o
		$(CXX) $(CXXFLAGS) -o tp1.exe main.o vector.o cmdline.o complejo.o FourierTransform.o

main.o: main.cpp cmdline.h vector.h
		$(CXX) $(CXXFLAGS) -o main.o -c main.cpp

vector.o: vector.cc vector.h complejo.h
		$(CXX) $(CXXFLAGS) -o vector.o -c vector.cc

cmdline.o: cmdline.cc cmdline.h complejo.h
		$(CXX) $(CXXFLAGS) -o cmdline.o -c cmdline.cc

complejo.o: complejo.cc complejo.h
		$(CXX) $(CXXFLAGS) -o complejo.o -c complejo.cc

FourierTransform.o: FourierTransform.cc FourierTransform.h
		$(CXX) $(CXXFLAGS) -o FourierTransform.o -c FourierTransform.cc


clean:
		$(RM) -vf *.o *.~ *.t *.out *.err
