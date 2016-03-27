#ifndef DATAPOINT_H_
#define DATAPOINT_H_
class DataPoint { // Stores one data point
public:
	int DIM; // dimensionality of data
	bool classLabel; // zero or one
	double* features; // list of features, size is DIM
	DataPoint(); // constructor
	DataPoint(bool _classLabel, int _dim, double* vals); // constructor
	void print(); // just for debugging purposes
};

#endif /* DATAPOINT_H_ */
