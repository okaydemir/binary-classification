#include <iostream>
#include "DataPoint.h"
#include "DecisionTree.h"
#include <fstream>
#include <stdio.h>
#include <sstream>


using namespace std;

DecisionTree::DecisionTree() {

}


void DecisionTree::importData(char* infileName) {

	 ifstream myfile(infileName);//start file stream
	 string line;
	 getline(myfile, line);
	 stringstream data(line);
data>>this->DIM>>this->NUM_DATA_POINT;//update dim and num_data_point with the first line's info

		this->samples = new DataPoint*[NUM_DATA_POINT]; //initialize samples

		//DataPoint** x= new DataPoint[NUM_DATA_POINT];
		//this->samples*=x;
		double vals[DIM]; // vals will hold all the values for a datapoint
		int classlabel=0; // initialize classlabel as false

		for(int i=0;i<this->NUM_DATA_POINT;i++){//outer for loop iterates through every line
			std::getline(myfile, line);
			std::stringstream data2(line);
			data2>>classlabel;
					for(int j=0;j<this->DIM;j++){//inner for loop will save every value in that single line to vals
						data2>>vals[j];
					}



			samples[i] = new DataPoint(classlabel,this->DIM,vals);//after the inner for loop we have the right vals for a single datapoint



		}



}
void DecisionTree::runDecisionTreeAlgorithm(char* outfileName) {

	double smallestrate=1;//smallest misclassification rate we can get
	int smallestid;//id of the item we got smallest MR

	for(int j=0;j<this->DIM;j++){//outer loop will iterate through rows




	for(int i=0;i<this->NUM_DATA_POINT;i++){//middle loop will iterate through columns
		double howmanytrue=0;//number of predictions we got right
		for(int k=0;k<this->NUM_DATA_POINT;k++){//inner loop will iterate through columns again to compare with each other
			//we'll make an assumption that if our base value>compared value their labels are same, if base<compared their labels are different.
			//it'll calculate the misclassification rate(say MR), we don't test the reverse situation simply because it has the misclassification rate of 1-MR



 if(samples[i]->features[j]> samples[k]->features[j]){//base>compared
	 if(samples[i]->classLabel ==  samples[k]->classLabel){//labels are same
	 howmanytrue++;
	 }
 }else{//base<compared

 if(samples[i]->classLabel !=  samples[k]->classLabel){//labels are different
	howmanytrue++;
 }

 }



		}
double currentrate=howmanytrue/this->NUM_DATA_POINT;//misclassification rate if we were to pick this value as threshold
if (currentrate>0.5){currentrate= 1-currentrate;}//if it's bigger than 0.5 we'll take the reverse situation
		if(smallestrate>currentrate){//if a better threshold has been found, update the current data
smallestrate = currentrate;
smallestid=j;
		}

	}



	}

	ofstream myfile;//start file stream
	  myfile.open (outfileName);
	  myfile  << smallestid << " " << smallestrate;//write to file
	  myfile.close();

}
