
#include "data_structure.h"
#include "sort.h"


int bubble_sort(int data[], const int size)
{
	int i = 0;
	int j = 0;

	for (i = size; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			int tmp = 0;
			if (data[j] > data[j + 1])
			{
				tmp = data[j];
				data[j] = data[ j+1 ];
				data[ j+1 ] = tmp;			   
			}

		    
		}	 
	}
   

}
