#include <stdio.h>
#include <string.h>
#include <time.h>
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
int char2int(char N){
	int tmp = N - '0';
    return tmp;
}


int computeS(char* A, int len){
	int score = 0;
	for(int i = 0; i < len; i++){
		score = score + char2int(A[i]);
	}
	score = score/len;
	return score;	
}
//======================================================================//
int main(){

	float weight[5]={0.2,0.2,0.2,0.2,0.2};

	clock_t t1, t2;
	t1 = clock();
	//char filename[11][10] = {"datasetA", "datasetA1", "datasetA2", "datasetA3", "datasetA4", "datasetA5", "datasetA6", "datasetA7", "datasetA8", "datasetA9", "datasetAA"};
	//char filename[11][10] = {"datasetB", "datasetB1", "datasetB2", "datasetB3", "datasetB4", "datasetB5", "datasetB6", "datasetB7", "datasetB8", "datasetB9", "datasetBA"};
	
	//char filename[2][11] = {"datasetA", "datasetA01"};
	char filename[2][11] = {"datasetB", "datasetB01"};

	//for(int fround = 0; fround < 12; fround += 11){
	FILE *fileA;			
	fileA = fopen(filename[0],"r");
	FILE *fileB;
	fileB = fopen(filename[1],"w");

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


	sA2 scoreA[recordnum];
	float totalscoreA[recordnum];
	for(int i = 0; i < recordnum; i++){
		for(int j = 1; j < attribute; j++){
			totalscoreA[i] = totalscoreA[i] + computeS(A[i][j].dim, lengthA[i].dim[j])*weight[j-1];
			start++;
		}
		start++;
	}
/*

	float minS = 99.0;
	float maxS = 0.0;
	for(int i = 0; i < recordnum; i++){
		//printf("record[%d] = %f\n", i, totalscoreA[i]);
		if(minS > totalscoreA[i])
			minS = totalscoreA[i];
		else if(maxS < totalscoreA[i])
			maxS = totalscoreA[i];
	}
	printf("recordMIN = %f\n", minS);
	printf("recordMAX = %f\n", maxS);
*/

	float minS = 25.0;
	float maxS = 55.0;

	int flag = attribute - 1;

	for( int i =0; i < recordnum; i++){
		for( int j = 0; j < flag; j++){
			fprintf(fileB, "%s ", A[i][j].dim);
		}
		fprintf(fileB, "%s\n", A[i][flag].dim);   
	}//  end_write


	fclose(fileA);
	fclose(fileB);


	//}

	t2 = clock();
	printf("\nExecution time: %lf\n", (t2-t1)/(double)(CLOCKS_PER_SEC));

	return 0;
}
