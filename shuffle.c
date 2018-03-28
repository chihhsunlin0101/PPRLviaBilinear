#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define recordnum 100
#define attribute 6
//======================================================================//
struct fA2{ 
    char dim[1024]; //1024
};
struct nA2{
    int dim[attribute];
};
struct sA2{
    float dim[attribute];
};
//======================================================================//

//======================================================================//
int main(){

	clock_t t1, t2;
	t1 = clock();
	//char filename[11][10] = {"datasetA", "datasetA1", "datasetA2", "datasetA3", "datasetA4", "datasetA5", "datasetA6", "datasetA7", "datasetA8", "datasetA9", "datasetAA"};
	//char filename[11][10] = {"datasetB", "datasetB1", "datasetB2", "datasetB3", "datasetB4", "datasetB5", "datasetB6", "datasetB7", "datasetB8", "datasetB9", "datasetBA"};

	//char filename[2][11] = {"datasetB", "datasetB01"};

	//for(int fround = 0; fround < 12; fround += 11){
	FILE *fileA;			
	fileA = fopen("datasetB","r");

	char bufferA[1024*attribute]="";
	const char *sep = " \n";
	char *token;
	int start = -1;
	fA2** A = new fA2*[recordnum];
	for(int i = 0; i < recordnum; i++){
		A[i] = new fA2[attribute];
	}
	nA2 lengthA[recordnum];

	while(fgets(bufferA, sizeof(bufferA), fileA) != NULL){
		start++;
		int att = -1;
		token = strtok(bufferA, sep);
		while(token){
			att ++;
			int len = strlen(token);
			lengthA[start].dim[att] = len;
			strncpy(A[start][att].dim, token, len);
			//printf("[%d, %d] = %d     %s\n", start, att, len, A[start][att].dim);
			token = strtok(NULL, sep);
		}	
	}//  end_read

	int shufflebox[recordnum];
	for(int i = 0; i < recordnum; i++){
		shufflebox[i] = i;
	}

	srand(time(0));
	int m, n, t;
	for(int i = 0; i < 50; i++){
		m = rand()%recordnum;
		n = rand()%recordnum;
		t = shufflebox[m];
		shufflebox[m] = shufflebox[n];
		shufflebox[n] = t;
	}

	fclose(fileA);
	fileA = fopen("datasetB","w");

	int flag = attribute - 1;
	int flag2;
	for(int i = 0; i < recordnum; i++){
		flag2 = shufflebox[i];
		for( int j = 0; j < flag; j++){
			fprintf(fileA, "%s ", A[flag2][j].dim);
		}
		fprintf(fileA, "%s\n", A[flag2][flag].dim);   
	}//  end_write



	fclose(fileA);


	//}

	t2 = clock();
	printf("\nExecution time: %lf\n", (t2-t1)/(double)(CLOCKS_PER_SEC));

	return 0;
}
