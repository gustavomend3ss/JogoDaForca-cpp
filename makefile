CXX = g++
CXXFLAGS = -std=c++11 -fexec-charset=UTF-8

forca: forca.cpp
	$(CXX) $(CXXFLAGS) forca.cpp -o forca
