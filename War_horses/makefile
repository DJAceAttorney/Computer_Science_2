CXX = g++
CXXFLAGS = -Wall

proj4: Heavy.o Medium.o Light.o Horse.o Untrained.o Warhorse.o War.o driver.cpp
	$(CXX) $(CXXFLAGS)  Heavy.o Medium.o Light.o Horse.o Untrained.o Warhorse.o War.o driver.cpp -o proj4

Horse.o: Horse.cpp
	$(CXX) $(CXXFLAGS) -c Horse.cpp

Untrained.o: Horse.o Untrained.cpp
	$(CXX) $(CXXFLAGS) -c Untrained.cpp

Warhorse.o: Horse.o Warhorse.cpp
	$(CXX) $(CXXFLAGS) -c Warhorse.cpp

Light.o: Warhorse.o Horse.o Light.cpp
	$(CXX) $(CXXFLAGS) -c Light.cpp

Medium.: Warhorse.o Horse.o Medium.cpp
	$(CXX) $(CXXFLAGS) -c Medium.cpp

Heavy.o: Warhorse.o Horse.o Heavy.cpp
	$(CXX) $(CXXFLAGS) -c Heavy.cpp

War.o: War.cpp
	$(CXX) $(CXXFLAGS) -c War.cpp

clean:
	rm *.o*
	rm *~

run:
	./proj4
