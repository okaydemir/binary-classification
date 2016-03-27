CC = g++
CFLAGS  = -std=c++11 -g -Wall

prog: DataPoint.o DecisionTree.o Main.o
	$(CC) $(CFLAGS) DataPoint.o DecisionTree.o Main.o -o project1

DecisionTree.o: DecisionTree.cpp DecisionTree.h DataPoint.h DataPoint.cpp
	$(CC) $(CFLAGS) -c DecisionTree.cpp

DataPoint.o: DataPoint.h DataPoint.cpp
	$(CC) $(CFLAGS) -c DataPoint.cpp

Main.o: Main.cpp DecisionTree.o
	$(CC) $(CFLAGS) -c Main.cpp

clean:
	rm -f *.o
	rm -f prog

# g++ -c DataPoint.cpp DecisionTree.cpp Main.cpp
# g++ DataPoint.o DecisionTree.o Main.o -o myprog


