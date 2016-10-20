#include <vector>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <string.h>

class LocalMin{

private:
	
	std::vector<unsigned int > valuesVector;


public:

	void initWideValley();
	
	void initNarrowValley();

	void initRandomValley();

};
