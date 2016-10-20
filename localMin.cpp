#include "localMin.h"


using namespace std;

LocalMin::LocalMin()
{
	initWideValley();
	findLocalMinimumIndexes();

}

LocalMin::~LocalMin()
{

}

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
	
	//random values : <0;range)
	unsigned int range = 20;

	int randomValue =0;

	srand(time(NULL));
	
	for ( int i =0; i < size ; i++)
	{	
		randomValue = rand() % range;			
		valuesVector.push_back(randomValue);	
	}
}

void LocalMin::findLocalMinimumIndexes()
{
	//znalezienie elementow ktorych sasiedzi maja mniejsze wartosci
	
	int vectorItemSize = sizeof(unsigned int);
	
	//TODO think abot it
	//auto itemBeforeIterator;
	//auto itemAfterIterator;
	
	for( auto it = valuesVector.begin(); it != valuesVector.end(); it++ )
	{
		if(it != valuesVector.begin() &&  it != valuesVector.end() )
		{
			auto iterBeforeIterator = it - 1 ;	
			auto iterAfterIterator  = it + 1;
		
			//jezeli oba elememnty sasiadujace sa mniejsze to wybieramy element	

						
			if( *iterBeforeIterator < *it && *iterAfterIterator < *it )
			{
				localMaximumIndexesVector.push_back(it - valuesVector.begin() );	
			}

		}
		
		//dla elementow skrajnych za nieistniejacy element przyjmujemy 0
		else if( it == valuesVector.begin() )
		{
			auto iterAfterIterator  = it + 1;
	
			if( *it > 0 && *it > *iterAfterIterator  )
			{
				localMaximumIndexesVector.push_back(it - valuesVector.begin() );	
			} 							
		}	
		else
		{
			auto iterBeforeIterator  = it - 1;
	
			if( *it > 0 && *it > *iterBeforeIterator  )
			{
				localMaximumIndexesVector.push_back(it - valuesVector.begin() );	
			}
		}	

	}
} 
//TODO think about smarter solution (generic,template)
//aktualnie wystepuje dupikacja kodu :(

void LocalMin::printVector(string vectorNameArg)
{
	if( vectorNameArg == "valuesVestor" )
	{
		cout<<"\nvalues vector content:\n";
		
		for(auto item :valuesVector)
		{
			cout<<item<<endl;
		}
		cout<<"\nend of values vector\n";
		
	}
	else if( vectorNameArg == "localMaximumIndexesVector" )
	{	
		cout<<"\nlocal maximum indexes vector:\n";
		
		for(auto item : localMaximumIndexesVector )
		{
			cout<<item<<endl;
		}
		cout<<"\nend of values vector\n";
	}	


}
