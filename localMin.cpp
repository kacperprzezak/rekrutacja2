#include "localMin.h"


void LocalMin::initWideValley()
{
	valuesVector = { 1,0,3,5,4,0,1,2,1,3,0,1,2,0,1 };
}

void LocalMin::initNarrowValley()
{
	valuesVector = { 10,9,5,0,4,9,15,12,111,13,60,21,12,340,133 };
}

void LocalMin::initRandomValley()
{
	int size = 15;
	
	//<0;range-1>
	unsigned int range = 20;

	int randomValue =0;

	srand(time(NULL));
	
	for ( int i =0; i < size ; i++)
	{	
		randomValue = rand() % range;			
		
		valuesVector.push_back(randomValue);	
	}
}
