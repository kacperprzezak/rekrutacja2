#include "localMin.h"


using namespace std;

LocalMin::LocalMin()
{
	initWideValley();
	findLocalMaxIndexes();
	printVector("localMaximumIndexesVector");

}

LocalMin::~LocalMin()
{

}

void LocalMin::initWideValley()
{
	valuesVector = { 1,0,3,5,4,0,1,2,1,3,0,1,2,0,1 };
	printVector("valuesVector");

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

//deafult value of function arg is true, I setted this in header file
//funkcja bedzie wywoływana rekurencyjnie

void LocalMin::findLocalMaxIndexes( bool firstCall )
{
	//znalezienie elementow ktorych sasiedzi maja mniejsze wartosci
	if( firstCall == true )
	{	
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
		printVector("localMaximumIndexesVector");
		findLocalMaxIndexes(false);

	}
	//ta czesc funkcji bedzie wywoływana rekurencyjnie	
	else
	{
		unsigned int sizeBeforeCall = localMaximumIndexesVector.size();
		
		vector<unsigned int> newValueOfIndexVector; 
		
		for( auto it = localMaximumIndexesVector.begin(); it !=  localMaximumIndexesVector.end();++it)
		{
						
			/*if( newValueOfIndexVector.size() ==  localMaximumIndexesVector.size() - 2  )
			{
				break;
			}*/
	
			//jeżli obaj sąsiedzi są wyźsi to wyrzucamy indeks
			//konczymy dzialanie gdy nic nie usunaeliśmy

			//pierwszy element
			if ( *it == 0  &&  sizeBeforeCall >  1 ) 
			{
				auto nextIndex = *(it+1);
 
				if (  valuesVector[*it] >  valuesVector[nextIndex]  &&  valuesVector[*it] > 0 )
				{
					 newValueOfIndexVector.push_back(*it);
				}
			}
			//ostatni element	
			else if ( *it == localMaximumIndexesVector.size() - 1 && localMaximumIndexesVector.size() > 1 )
			{
				if ( valuesVector[*it] >  valuesVector[*(it-1)] &&  valuesVector[*it] > 0 ) 
				{
					 newValueOfIndexVector.push_back(*it);
				}			
			}

			//elementy nie bedace skrajnymi
			else
			{
				if( valuesVector[*it] > valuesVector[ *(it-1) ]  &&  valuesVector[*it] >  valuesVector[ *(it+1) ] )
				{
					newValueOfIndexVector.push_back(*it);
				}	
			}	
		}

		localMaximumIndexesVector.clear();
		
		localMaximumIndexesVector =  newValueOfIndexVector;		
		
		unsigned int currentSize =  localMaximumIndexesVector.size();

		if  ( sizeBeforeCall != currentSize )
		{
			findLocalMaxIndexes(false);
			//call itself
		}
		//koniec wywoływania rekurencji
		
	}


} 
//TODO think about smarter solution (generic,template)
//aktualnie wystepuje dupikacja kodu :(

void LocalMin::printVector(string vectorNameArg)
{
	if( vectorNameArg == "valuesVector" )
	{
		cout<<"\nvalues vector content:\n";
		
		for(auto &item :valuesVector)
		{
			cout<<item<<endl;
		}
		cout<<"end of values vector\n";
		
	}
	else if( vectorNameArg == "localMaximumIndexesVector" )
	{	
		cout<<"\nlocal maximum indexes vector:\n";
		
		for(auto item : localMaximumIndexesVector )
		{
			cout<<item<<endl;
		}
		cout<<"end of values vector\n";
	}	

}
