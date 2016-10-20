#include <vector>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <string.h>


using namespace std;

class LocalMin { 

private:
	
	vector<unsigned int > valuesVector;
	vector<unsigned int > localMinimumIndexesVector;	

public:
	LocalMin();

	~LocalMin();

	void initWideValley();
	
	void initNarrowValley();

	void initRandomValley();

	void findLocalMinimumIndexes();

	
	

};
