#include <iostream>
#include "DataPoint.h"
#include "DecisionTree.h"
using namespace std;


void print(DecisionTree* dt) {
	cout << "A decision tree in " << dt->DIM << " dimensions with " << dt->NUM_DATA_POINT << " samples:" << endl;
	for (int i=0; i<dt->NUM_DATA_POINT; i++) {
		dt->samples[i]->print();
	}
}


int main(int argc, char *argv[]){
	if(argc!=3){
		printf("Usage: ./project1 infile outfile\n");
		return 0;
	}
	DecisionTree* dt = new DecisionTree();
	dt->importData(argv[1]);
	dt->runDecisionTreeAlgorithm(argv[2]);

	return 0;
}
