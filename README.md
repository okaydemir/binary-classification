# binary-classification
C++ simple machine learning
https://en.wikipedia.org/wiki/Binary_classification
https://en.wikipedia.org/wiki/Decision_tree_learning


Given features and class of multiple binary classifiable members, this program picks a feature to use to classify them with minimum error. It then prints feature index and misclassification rate. It picks only one feature for the sake of simplicity.

# Input
Input file has the following format:
5 100
0 66.84 80.96 -11.50 47.65 86.76
1 62.71 69.36 7.90 48.18 98.71
1 52.21 77.80 7.55 37.37 59.08
1 61.12 73.26 20.10 40.06 68.35
...
The first line contains two integers that are separated by white space: dimensionality of data(N ),
i.e, number of features, and number of data points in dataset(K). Following lines are all data points.
Take the second line for example: The first integer is class label and next doubles are features, all separated
by white space.

# Output
This file contains one integer and one double: id of the feature used for classification and misclassification
rate when classification is done with this feature and best possible threshold.Example output file:
2 0.32

# Usage
./classify inputFile outputFile
