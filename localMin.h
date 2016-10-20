#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <string.h>


using namespace std;

class LocalMin { 

private:

	void printVector(string vectorName);
	
	unsigned int getPositionOfItem(int valueArg); 
	
	vector<unsigned int > valuesVector;
	
	vector<unsigned int > localMaximumIndexesVector;	

public:
	LocalMin();

	~LocalMin();

	void initWideValley();
	
	void initNarrowValley();

	void initRandomValley();

	void findLocalMaxIndexes( bool firstCall = true );

};
