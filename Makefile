source1 : source1.o 161044069_main.o 
	g++ -o source1 161044069_main.o source1.o
	
source1.o : source1.cpp
	g++ -c -std=c++0x -Wall source1.cpp
	
161044069_main.o : 161044069_main.cpp
	g++ -c -std=c++0x -Wall 161044069_main.cpp

clean:
	rm *.o source1		
