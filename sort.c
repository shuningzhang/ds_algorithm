
#include <stdlib.h>
#include "data_structure.h"
#include "sort.h"


void bubble_sort(int data[], int size)
{
	int i = 0;
	int j = 0;

	for (i = size - 1; i > 0; i--)
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

     return ;	

}




void  quick_sort(int data[], int left, int right)
{
	int watch = data[left];
        int tmp = 0;

	int l = left;
	int r = right;

	while (l < r)
	{
		while ( r > l && data[r] >= watch )
		{
			r--;
			continue;
		}

		while ( r > l && data[l] <= watch )
		{
			l++;
			continue;		
		}

		if (r >= l)
		{
			tmp = data[r];
			data[r] = data[l];
			data[l] = tmp;		
		}
	
	}

	tmp = data[l];
	data[l] = watch;
	data[left] = tmp;
        
	if ( left < (l - 1) )
	{
		quick_sort(data, left, l - 1);
	}

        if ( right > (l + 1))
	{
		quick_sort(data, l + 1, right);
	}

	return ;

}


void select_sort(int data[], int size)
{
	int i = 0;
	int j = 0;
	int min = 0;


	for (i = 0; i < size; i++)
	{
		min = i;
		int tmp = 0;

		for (j = i; j < size; j++)
		{
			if (data[min] > data[j])
			{
				min = j;			
			}
		}

		if (min != i)
		{
			tmp = data[min];
			data[min] = data[i];
			data[i] = tmp;		   
		}
	
	}

}

void insert_sort(int data[], int size)
{
	int i = 0;
	int j = 0;

	for (i = 1; i < size; i++)
	{
		int tmp;

		for (j = i; j > 0; j--)
		{
		    if (data[j] < data[j-1] )
		    {
			    tmp = data[j];
			    data[j] = data[j-1];
			    data[j-1] = tmp;
		    }
		}
	}

}

void swap_data(int* a, int* b)
{
	int tmp = 0;

	tmp = *a;
	*a = *b;
	*b = tmp;

}


void adjust_heap(int data[], int start, int size)
{
	int i = start;
	if (i*2+1 <size && data[i] < data[ i*2+1 ])
	{
		swap_data(&data[i], &data[ i*2+1 ]);
		adjust_heap(data, i*2+1, size);
	}

	if (i*2+2 < size && data[i] < data[ i*2+2 ])
	{
		swap_data(&data[i], &data[ i*2+2 ]);
		adjust_heap(data, i*2+2, size);

	}

}

void build_heap(int data[], int size)
{
       int start_pos = size / 2;


       int i = 0;
       for (i = start_pos; i >= 0; i--)
       {
	       if (2*i+1 < size && data[i] < data[ 2*i+1 ])
	       {
		       swap_data(&data[i], &data[ 2*i+1 ]);
	       }
	       if (2*i+2 < size && data[i] < data[ 2*i+2 ])
	       {
		       swap_data(&data[i], &data[ 2*i+2]);	       
	       }

	       adjust_heap(data, 2*i+1, size);
	       adjust_heap(data, 2*i+2, size);
       }
}




void heap_sort(int data[], int size)
{
	int i = 0;
	
	build_heap(data, size);
	for (i = size-1; i>0; i--)
	{
		swap_data(&data[0], &data[i]);
		adjust_heap(data, 0, i-1);
	}
	 
}


void merge_data(int data[], int start, int mid, int end)
{
	int* tmp_space = malloc((end - start + 1)* sizeof(int));
	if (NULL == tmp_space)
	{
		return;	
	}

	int i = 0;
	int inc = 1;
	int tmp_start = start;
	int tmp_mid = mid+1;

	while (0 != inc && i < (end-start) )
	{
		inc = 0;
		while (tmp_start <= mid && data[tmp_start] <= data[ tmp_mid ])
		{
			tmp_space[i++] = data[tmp_start++];
			inc ++;
		}
		
		while (tmp_mid <=end && data[tmp_mid] <= data[tmp_start])
		{
			tmp_space[i++] = data[tmp_mid++];		
			inc ++;
		}
	
	}

	while (tmp_start <= mid)
	{
		tmp_space[i++] = data[tmp_start++];
	}

	while (tmp_mid <= end)
	{
		tmp_space[i++] = data[tmp_mid++];
	}

	for (i=0; i < (end-start+1); i++)
	{
		data[ start+i ] = tmp_space[i];
	}

	free(tmp_space);


}


void _merge_sort(int data[], int start, int end)
{
	if (end - start > 1)
	{
		int mid = (end - start) / 2 + start;
		_merge_sort(data, start, mid);
		_merge_sort(data, mid+1, end);
		merge_data(data, start, mid, end);
			
	}
	else
	{
		if (data[start] > data[end])
		{
			swap_data(&data[start], &data[end]);
		}
	}

}

void merge_sort(int data[], int size)
{
	_merge_sort(data, 0, size-1);
}


void radix_sort(int data[], int size)
{

}


void bucket_sort(int data[], int size)
{

}





