#include <stdio.h>

#include "sort.h"

void print_data(int data[], int size)
{
    int i;
    
    printf("data[%d]: {", size);
    for (i = 0; i < size; i++)
    {
	    printf("%d, ", data[i]);    
    }
    printf("}\n");
}

int main()
{
    int data[] = {15, 22, 9, 6, 18, 2, 25,18, 65, 28, 100};
    //int data[] = {1, 3, 5, 7, 9, 2, 4,6, 8, 10, 100};

    int len = sizeof(data)/sizeof(int);
    print_data(data, len); 
    //bubble_sort(data, len);
    //quick_sort(data, 0, len - 1);
    //select_sort(data, len);
    //insert_sort(data, len);
    //heap_sort(data, len);
    //merge_data(data, 0, 4, 10);
    merge_sort(data, len);
    print_data(data, len); 

    return 0;
    
}
