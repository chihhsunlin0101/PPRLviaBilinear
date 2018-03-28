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
	
	//char filename[11][11] = {"datasetA", "datasetA01", "datasetA02", "datasetA03", "datasetA04", "datasetA05", "datasetA06", "datasetA07", "datasetA08", "datasetA09", "datasetA10"};
	char filename[11][11] = {"datasetB", "datasetB01", "datasetB02", "datasetB03", "datasetB04", "datasetB05", "datasetB06", "datasetB07", "datasetB08", "datasetB09", "datasetB10"};

	//for(int fround = 0; fround < 12; fround += 11){
	FILE *fileA;			
	fileA = fopen(filename[0],"r");
	FILE *fileB;
	fileB = fopen(filename[1],"w");
	FILE *fileC;
	fileC = fopen(filename[2],"w");
	FILE *fileD;
	fileD = fopen(filename[3],"w");
	FILE *fileE;
	fileE = fopen(filename[4],"w");
	FILE *fileF;
	fileF = fopen(filename[5],"w");
	FILE *fileG;
	fileG = fopen(filename[6],"w");
	FILE *fileH;
	fileH = fopen(filename[7],"w");
	FILE *fileI;
	fileI = fopen(filename[8],"w");
	FILE *fileJ;
	fileJ = fopen(filename[9],"w");
	FILE *fileK;
	fileK = fopen(filename[10],"w");


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

    float diff = (maxS-minS)/10;
	float range1 = diff +  minS;
	float range2 = range1 + diff;
	float range3 = range2 + diff;
	float range4 = range3 + diff;
	float range5 = range4 + diff;
	float range6 = range5 + diff;
	float range7 = range6 + diff;
	float range8 = range7 + diff;
	float range9 = range8 + diff;
	
	int flag = attribute - 1;

	for( int i =0; i < recordnum; i++){
		float tmp = totalscoreA[i];
		if(tmp < range1){
			for( int j = 0; j < flag; j++){
				fprintf(fileB, "%s ", A[i][j].dim);
			}
			fprintf(fileB, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range2){
			for( int j = 0; j < flag; j++){
				fprintf(fileC, "%s ", A[i][j].dim);
			}
			fprintf(fileC, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range3){
			for( int j = 0; j < flag; j++){
				fprintf(fileD, "%s ", A[i][j].dim);
			}
			fprintf(fileD, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range4){
			for( int j = 0; j < flag; j++){
				fprintf(fileE, "%s ", A[i][j].dim);
			}
			fprintf(fileE, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range5){
			for( int j = 0; j < flag; j++){
				fprintf(fileF, "%s ", A[i][j].dim);
			}
			fprintf(fileF, "%s\n", A[i][flag].dim);   
		}  
		else if(tmp < range6){
			for( int j = 0; j < flag; j++){
				fprintf(fileG, "%s ", A[i][j].dim);
			}
			fprintf(fileG, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range7){
			for( int j = 0; j < flag; j++){
				fprintf(fileH, "%s ", A[i][j].dim);
			}
			fprintf(fileH, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range8){
			for( int j = 0; j < flag; j++){
				fprintf(fileI, "%s ", A[i][j].dim);
			}
			fprintf(fileI, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range9){
			for( int j = 0; j < flag; j++){
				fprintf(fileJ, "%s ", A[i][j].dim);
			}
			fprintf(fileJ, "%s\n", A[i][flag].dim);   
		}
		else{
			for( int j = 0; j < flag; j++){
				fprintf(fileK, "%s ", A[i][j].dim);
			}
			fprintf(fileK, "%s\n", A[i][flag].dim);   
		}  
	}//  end_write


	fclose(fileA);
	fclose(fileB);
	fclose(fileC);
	fclose(fileD);
	fclose(fileE);
	fclose(fileF);
	fclose(fileG);
	fclose(fileH);
	fclose(fileI);
	fclose(fileJ);
	fclose(fileK);
	//}

	t2 = clock();
	printf("\nExecution time: %lf\n", (t2-t1)/(double)(CLOCKS_PER_SEC));

	return 0;
}
