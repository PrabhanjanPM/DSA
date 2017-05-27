#include <stdio.h>
#include <stdlib.h> 

void merge(int* arr, int left, int middle, int right);
void mergesort(int* arr, int left, int right);
int main(int argc, char** argv){
	if(argc != 2){
		printf("Usage - %s <test_file>\n",argv[0]);
		exit(0);
	}
	FILE* input_file = fopen(argv[1], "r");
	int length, i;
	fscanf(input_file, "%d\n", &length);
	int array[length];
	for(i=0;i<length;i++){
		fscanf(input_file, "%d\n", &array[i]);
	}

	/* to print the array
	for(i=0;i<length;i++){
		printf("%d\n",array[i]);
	}
	*/

	mergesort(array, 0, length);
	
	for(i=0;i<length;i++){
		printf("%d\n",array[i]);
	}

	return 0;
}

void mergesort(int* array, int left, int right){
	int length = right-left;
	if(length>1){
		int middle = (left + right)/2;
		mergesort(array, left, middle);
		mergesort(array, middle, right);
		merge(array, left, middle, right);
	}
}

void merge(int* array, int left, int middle, int right){
	int left_len  = middle - left;
	int right_len = right  - middle;
	int left_array[left_len], right_array[right_len];
	int i,j,k=0;
	for(i=0;i<left_len;i++){
		left_array[i] = array[left+i];
	}
	for(j=0;j<right_len;j++){
		right_array[j] = array[middle+j];
	}
	i = 0;
	j = 0;
	k = left;
	while(i<left_len && j<right_len){
		if(left_array[i]<right_array[j]){
			array[k] = left_array[i];
			i++;
			k++;
		}
		else{
			array[k] = right_array[j];
			j++;
			k++;
		}
	}
	while(i<left_len){
		array[k] = left_array[i];
		i++;
		k++;
	}
	while(j<right_len){
		array[k] = right_array[j];
		j++;
		k++;
	}
}



		
