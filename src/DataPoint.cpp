#include <iostream>
#include "DataPoint.h"
using namespace std;

DataPoint::DataPoint() {
}

DataPoint::DataPoint(bool _classLabel, int _dim, double* _features) {
	classLabel = _classLabel;
	DIM = _dim;
	features = new double[_dim];
	copy(_features, _features+_dim, this->features);
}

void DataPoint::print() {
	cout << "class=" << this->classLabel << "\t";
	for (double* ptr=features; ptr<features+DIM; ptr++) {
		cout << *ptr << "\t";
	}
	cout << endl;
}
