#include "localMin.h"


using namespace std;

LocalMin::LocalMin()
{
	initWideValley();
	findLocalMaxIndexes();
	
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
	
	vector<unsigned int > valuesVectorKopia = valuesVector;

	int vectorItemSize = sizeof(unsigned int);
	
	int sizeBefore = valuesVector.size();

	
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

		vector <unsigned int> newValuesVector;
		
		for(auto & index: localMaximumIndexesVector )
		{
			newValuesVector.push_back(valuesVector[index]);
		}	

		valuesVector = newValuesVector;
		
		printVector("valuesVector");

	        sizeBefore = valuesVector.size();
		unsigned int sizeAfter = 0;

		newValuesVector.clear();
		
		do{
			
		        sizeBefore = valuesVector.size();
	
			for(auto iter = valuesVector.begin(); iter != valuesVector.end(); ++iter )
			{
				if ( iter == valuesVector.begin() )
				{
					auto nextIter = iter + sizeof(unsigned int); 

					if( *iter > 0 && *iter > *nextIter )
					{
						newValuesVector.push_back(*iter);
					}
				}

				else if ( iter == valuesVector.end() )
				{
					auto previousIter = iter - sizeof(unsigned int); 

					if( *iter > 0 && *iter > *previousIter )
					{
						newValuesVector.push_back(*iter);
					}
				}		

				else
				{
					auto nextIter = iter + sizeof(unsigned int); 
					auto previousIter = iter - sizeof(unsigned int); 

					if( *iter > *nextIter && *iter > *previousIter )
					{
						newValuesVector.push_back(*iter);
					}
				}
	
			}	 

			  
			sizeAfter = valuesVector.size();

			valuesVector.clear();

			valuesVector= newValuesVector;

		}while( sizeBefore != sizeAfter );
		printVector("valuesVector");
		
		auto  maxElement = max_element(begin(valuesVector),end(valuesVector));		
			
	

		unsigned int maxDolina = 0;
		unsigned int aktualnaDolina = 0;

		for(int i = 0; i <  valuesVectorKopia.size(); i++ )
		{
			 unsigned int item = valuesVectorKopia[i];
		  
		  
			bool itemIsMaximum = binary_search(valuesVector.begin(),valuesVector.end(),item );
		
			if(itemIsMaximum)  
			{
			
				//lewa dolina, mozna by zrobic te funkcjonalnosc lambda
				//dodajemy kolejno rożnice danego maksimu i aktualnego elementu aż natrafimy na element wiekszy badz rowny naszemu aktulnemu
				//maksimum lub doldziemy do konca przedzialu
				//jesli po wykonaniu petli vartosc zmiennej aktualna dolina bedzie wieksza od maksymalna dolina to ustwiamy maxDolina na te wartosc   						
				for(int j=i;j>=0;j--)
				{
					int roznica = item - valuesVectorKopia[i];
					

					if(roznica > 0)
					{
						aktualnaDolina += roznica;
					}
					else
					{
						break;
					}
				}
			 	//porowna aktualna dolina z max jesli wieksza ustaw max i wyzeruj aktualnaDolina

				//prawa dolina
				for(int j=i;j<valuesVectorKopia.size();j++)
				{
				
				}
				//porowna aktualna dolina z max jesli wieksza ustaw max i wyzeruj aktualnaDolina

			 
			} 
		}		
		
						

}
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
