#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if(argc != 2){
		printf("Usage - %s <test_file>\n",argv[0]);
		exit(0);
	}
	FILE* input_file = fopen(argv[1], "r");
	int n, i;
	fscanf(input_file, "%d\n", &n);
	int array[n];
	for(i=0;i<n;i++){
		fscanf(input_file, "%d\n", &array[i]);
	}
	for(i=0;i<n;i++){
		int j;
		for(j=0;j<n-1;j++){
			if(array[j+1]<array[j]){
				int temp = array[j];
				array[j] = array[j+1];;
				array[j+1] = temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",array[i]);
	}
	fclose(input_file);
	return 0;
}
