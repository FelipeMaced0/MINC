#include <stdlib.h>
#include <string.h>
#include "functions.h"

extern cmp cmp_function; // Global Variable to store a compare function

static void Merge(void *arr, int begin, int middle, int end, int size){
	int begin1 = begin; // goes from [begin] to [middle]
	int begin2 = middle+1; // goes from [middle+1] to [end]
	int count=0;
	int len = end-begin+1;
	char *arr_char = (char *)arr;
	char *aux_arr = (char *)malloc(len*size);

	while((begin1 <= middle) && (begin2 <= end)){
		//cmp_function comes into play
		if(cmp_function(arr_char+(begin1*size), arr_char+(begin2*size)) < 0){
			memcpy(aux_arr+(count*size), arr_char+(begin1*size), size);
			begin1++;	
		}else{
		
			memcpy(aux_arr+(count*size), arr_char+(begin2*size), size);
			begin2++;
		}
		count++;
	}


	while(begin1 <= middle){
		memcpy(aux_arr+(count*size), arr_char+(begin1*size), size);
		count++;
		begin1++;
	}

	while(begin2 <= end){
		memcpy(aux_arr+(count*size), arr_char+(begin2*size), size);
		count++;
		begin2++;
	}

	memcpy(arr_char+(begin*size), aux_arr, size*len);
	free(aux_arr);
}

static void MergeSort(void *arr, int begin, int end, int size){
	if(begin < end){
		int middle = (begin+end)/2;

		MergeSort(arr, begin, middle, size);  //Divide until it has begin==middle
		MergeSort(arr, middle+1, end, size);  // Divide until it has begin==end
		Merge(arr, begin, middle, end, size); // Merge two intervals together
	}
}

void merge_sort(void *arr, int len, int size){
	MergeSort(arr, 0, len-1, size);
}
/*
 * When sorting strings 
 * make sure to pass how
 * big each string is.
 *
 * */
int main(){
	int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	char b[4][10] = {"d","b","c","a"};

	set_cmp_function(&func_string);
	
	merge_sort(b, 4, 10);

	for(int i=0; i < 4; i++){
		printf(" %s", b[i]);
	}
}
