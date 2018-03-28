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
	
	char filename[51][51] = {"datasetA", "datasetA01", "datasetA02", "datasetA03", "datasetA04", "datasetA05", "datasetA06", "datasetA07", "datasetA08", "datasetA09", "datasetA10", "datasetA11", "datasetA12", "datasetA13", "datasetA14", "datasetA15", "datasetA16", "datasetA17", "datasetA18", "datasetA19", "datasetA20", "datasetA21", "datasetA22", "datasetA23", "datasetA24", "datasetA25", "datasetA26", "datasetA27", "datasetA28", "datasetA29", "datasetA30", "datasetA31", "datasetA32", "datasetA33", "datasetA34", "datasetA35", "datasetA36", "datasetA37", "datasetA38", "datasetA39", "datasetA40", "datasetA41", "datasetA42", "datasetA43", "datasetA44", "datasetA45", "datasetA46", "datasetA47", "datasetA48", "datasetA49", "datasetA50"};
	//char filename[51][11] = {"datasetB", "datasetB01", "datasetB02", "datasetB03", "datasetB04", "datasetB05", "datasetB06", "datasetB07", "datasetB08", "datasetB09", "datasetB10", "datasetB11", "datasetB12", "datasetB13", "datasetB14", "datasetB15", "datasetB16", "datasetB17", "datasetB18", "datasetB19", "datasetB20", "datasetB21", "datasetB22", "datasetB23", "datasetB24", "datasetB25", "datasetB26", "datasetB27", "datasetB28", "datasetB29", "datasetB30", "datasetB31", "datasetB32", "datasetB33", "datasetB34", "datasetB35", "datasetB36", "datasetB37", "datasetB38", "datasetB39", "datasetB40", "datasetB41", "datasetB42", "datasetB43", "datasetB44", "datasetB45", "datasetB46", "datasetB47", "datasetB48", "datasetB49", "datasetB50"};

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

	FILE *fileB2;
	fileB2 = fopen(filename[11],"w");
	FILE *fileC2;
	fileC2 = fopen(filename[12],"w");
	FILE *fileD2;
	fileD2 = fopen(filename[13],"w");
	FILE *fileE2;
	fileE2 = fopen(filename[14],"w");
	FILE *fileF2;
	fileF2 = fopen(filename[15],"w");
	FILE *fileG2;
	fileG2 = fopen(filename[16],"w");
	FILE *fileH2;
	fileH2 = fopen(filename[17],"w");
	FILE *fileI2;
	fileI2 = fopen(filename[18],"w");
	FILE *fileJ2;
	fileJ2 = fopen(filename[19],"w");
	FILE *fileK2;
	fileK2 = fopen(filename[20],"w");

	FILE *fileB3;
	fileB3 = fopen(filename[21],"w");
	FILE *fileC3;
	fileC3 = fopen(filename[22],"w");
	FILE *fileD3;
	fileD3 = fopen(filename[23],"w");
	FILE *fileE3;
	fileE3 = fopen(filename[24],"w");
	FILE *fileF3;
	fileF3 = fopen(filename[25],"w");
	FILE *fileG3;
	fileG3 = fopen(filename[26],"w");
	FILE *fileH3;
	fileH3 = fopen(filename[27],"w");
	FILE *fileI3;
	fileI3 = fopen(filename[28],"w");
	FILE *fileJ3;
	fileJ3 = fopen(filename[29],"w");
	FILE *fileK3;
	fileK3 = fopen(filename[30],"w");

	FILE *fileB4;
	fileB4 = fopen(filename[31],"w");
	FILE *fileC4;
	fileC4 = fopen(filename[32],"w");
	FILE *fileD4;
	fileD4 = fopen(filename[33],"w");
	FILE *fileE4;
	fileE4 = fopen(filename[34],"w");
	FILE *fileF4;
	fileF4 = fopen(filename[35],"w");
	FILE *fileG4;
	fileG4 = fopen(filename[36],"w");
	FILE *fileH4;
	fileH4 = fopen(filename[37],"w");
	FILE *fileI4;
	fileI4 = fopen(filename[38],"w");
	FILE *fileJ4;
	fileJ4 = fopen(filename[39],"w");
	FILE *fileK4;
	fileK4 = fopen(filename[40],"w");

	FILE *fileB5;
	fileB5 = fopen(filename[41],"w");
	FILE *fileC5;
	fileC5 = fopen(filename[42],"w");
	FILE *fileD5;
	fileD5 = fopen(filename[43],"w");
	FILE *fileE5;
	fileE5 = fopen(filename[44],"w");
	FILE *fileF5;
	fileF5 = fopen(filename[45],"w");
	FILE *fileG5;
	fileG5 = fopen(filename[46],"w");
	FILE *fileH5;
	fileH5 = fopen(filename[47],"w");
	FILE *fileI5;
	fileI5 = fopen(filename[48],"w");
	FILE *fileJ5;
	fileJ5 = fopen(filename[49],"w");
	FILE *fileK5;
	fileK5 = fopen(filename[50],"w");


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

    float diff = (maxS-minS)/50;
	float range1 = diff +  minS;
	float range2 = range1 + diff;
	float range3 = range2 + diff;
	float range4 = range3 + diff;
	float range5 = range4 + diff;
	float range6 = range5 + diff;
	float range7 = range6 + diff;
	float range8 = range7 + diff;
	float range9 = range8 + diff;
	float range10 = range9 + diff;
	float range11 = range10 + diff;
	float range12 = range11 + diff;
	float range13 = range12 + diff;
	float range14 = range13 + diff;
	float range15 = range14 + diff;
	float range16 = range15 + diff;
	float range17 = range16 + diff;
	float range18 = range17 + diff;
	float range19 = range18 + diff;
	float range20 = range19 + diff;
	float range21 = range20 + diff;
	float range22 = range21 + diff;
	float range23 = range22 + diff;
	float range24 = range23 + diff;
	float range25 = range24 + diff;
	float range26 = range25 + diff;
	float range27 = range26 + diff;
	float range28 = range27 + diff;
	float range29 = range28 + diff;
	float range30 = range29 + diff;
	float range31 = range30 + diff;
	float range32 = range31 + diff;
	float range33 = range32 + diff;
	float range34 = range33 + diff;
	float range35 = range34 + diff;
	float range36 = range35 + diff;
	float range37 = range36 + diff;
	float range38 = range37 + diff;
	float range39 = range38 + diff;
	float range40 = range39 + diff;
	float range41 = range40 + diff;
	float range42 = range41 + diff;
	float range43 = range42 + diff;
	float range44 = range43 + diff;
	float range45 = range44 + diff;
	float range46 = range45 + diff;
	float range47 = range46 + diff;
	float range48 = range47 + diff;
	float range49 = range48 + diff;
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
		else if(tmp < range10){
			for( int j = 0; j < flag; j++){
				fprintf(fileK, "%s ", A[i][j].dim);
			}
			fprintf(fileK, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range11){
			for( int j = 0; j < flag; j++){
				fprintf(fileB2, "%s ", A[i][j].dim);
			}
			fprintf(fileB2, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range12){
			for( int j = 0; j < flag; j++){
				fprintf(fileC2, "%s ", A[i][j].dim);
			}
			fprintf(fileC2, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range13){
			for( int j = 0; j < flag; j++){
				fprintf(fileD2, "%s ", A[i][j].dim);
			}
			fprintf(fileD2, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range14){
			for( int j = 0; j < flag; j++){
				fprintf(fileE2, "%s ", A[i][j].dim);
			}
			fprintf(fileE2, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range15){
			for( int j = 0; j < flag; j++){
				fprintf(fileF2, "%s ", A[i][j].dim);
			}
			fprintf(fileF2, "%s\n", A[i][flag].dim);   
		}  
		else if(tmp < range16){
			for( int j = 0; j < flag; j++){
				fprintf(fileG2, "%s ", A[i][j].dim);
			}
			fprintf(fileG2, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range17){
			for( int j = 0; j < flag; j++){
				fprintf(fileH2, "%s ", A[i][j].dim);
			}
			fprintf(fileH2, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range18){
			for( int j = 0; j < flag; j++){
				fprintf(fileI2, "%s ", A[i][j].dim);
			}
			fprintf(fileI2, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range19){
			for( int j = 0; j < flag; j++){
				fprintf(fileJ2, "%s ", A[i][j].dim);
			}
			fprintf(fileJ2, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range20){
			for( int j = 0; j < flag; j++){
				fprintf(fileK2, "%s ", A[i][j].dim);
			}
			fprintf(fileK2, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range21){
			for( int j = 0; j < flag; j++){
				fprintf(fileB3, "%s ", A[i][j].dim);
			}
			fprintf(fileB3, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range22){
			for( int j = 0; j < flag; j++){
				fprintf(fileC3, "%s ", A[i][j].dim);
			}
			fprintf(fileC3, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range23){
			for( int j = 0; j < flag; j++){
				fprintf(fileD3, "%s ", A[i][j].dim);
			}
			fprintf(fileD3, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range24){
			for( int j = 0; j < flag; j++){
				fprintf(fileE3, "%s ", A[i][j].dim);
			}
			fprintf(fileE3, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range25){
			for( int j = 0; j < flag; j++){
				fprintf(fileF3, "%s ", A[i][j].dim);
			}
			fprintf(fileF3, "%s\n", A[i][flag].dim);   
		}  
		else if(tmp < range26){
			for( int j = 0; j < flag; j++){
				fprintf(fileG3, "%s ", A[i][j].dim);
			}
			fprintf(fileG3, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range27){
			for( int j = 0; j < flag; j++){
				fprintf(fileH3, "%s ", A[i][j].dim);
			}
			fprintf(fileH3, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range28){
			for( int j = 0; j < flag; j++){
				fprintf(fileI3, "%s ", A[i][j].dim);
			}
			fprintf(fileI3, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range29){
			for( int j = 0; j < flag; j++){
				fprintf(fileJ3, "%s ", A[i][j].dim);
			}
			fprintf(fileJ3, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range30){
			for( int j = 0; j < flag; j++){
				fprintf(fileK3, "%s ", A[i][j].dim);
			}
			fprintf(fileK3, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range31){
			for( int j = 0; j < flag; j++){
				fprintf(fileB4, "%s ", A[i][j].dim);
			}
			fprintf(fileB4, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range32){
			for( int j = 0; j < flag; j++){
				fprintf(fileC4, "%s ", A[i][j].dim);
			}
			fprintf(fileC4, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range33){
			for( int j = 0; j < flag; j++){
				fprintf(fileD4, "%s ", A[i][j].dim);
			}
			fprintf(fileD4, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range34){
			for( int j = 0; j < flag; j++){
				fprintf(fileE4, "%s ", A[i][j].dim);
			}
			fprintf(fileE4, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range35){
			for( int j = 0; j < flag; j++){
				fprintf(fileF4, "%s ", A[i][j].dim);
			}
			fprintf(fileF4, "%s\n", A[i][flag].dim);   
		}  
		else if(tmp < range36){
			for( int j = 0; j < flag; j++){
				fprintf(fileG4, "%s ", A[i][j].dim);
			}
			fprintf(fileG4, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range37){
			for( int j = 0; j < flag; j++){
				fprintf(fileH4, "%s ", A[i][j].dim);
			}
			fprintf(fileH4, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range38){
			for( int j = 0; j < flag; j++){
				fprintf(fileI4, "%s ", A[i][j].dim);
			}
			fprintf(fileI4, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range39){
			for( int j = 0; j < flag; j++){
				fprintf(fileJ4, "%s ", A[i][j].dim);
			}
			fprintf(fileJ4, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range40){
			for( int j = 0; j < flag; j++){
				fprintf(fileK4, "%s ", A[i][j].dim);
			}
			fprintf(fileK4, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range41){
			for( int j = 0; j < flag; j++){
				fprintf(fileB5, "%s ", A[i][j].dim);
			}
			fprintf(fileB5, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range42){
			for( int j = 0; j < flag; j++){
				fprintf(fileC5, "%s ", A[i][j].dim);
			}
			fprintf(fileC5, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range43){
			for( int j = 0; j < flag; j++){
				fprintf(fileD5, "%s ", A[i][j].dim);
			}
			fprintf(fileD5, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range44){
			for( int j = 0; j < flag; j++){
				fprintf(fileE5, "%s ", A[i][j].dim);
			}
			fprintf(fileE5, "%s\n", A[i][flag].dim);
		}
		else if(tmp < range45){
			for( int j = 0; j < flag; j++){
				fprintf(fileF5, "%s ", A[i][j].dim);
			}
			fprintf(fileF5, "%s\n", A[i][flag].dim);   
		}  
		else if(tmp < range46){
			for( int j = 0; j < flag; j++){
				fprintf(fileG5, "%s ", A[i][j].dim);
			}
			fprintf(fileG5, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range47){
			for( int j = 0; j < flag; j++){
				fprintf(fileH5, "%s ", A[i][j].dim);
			}
			fprintf(fileH5, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range48){
			for( int j = 0; j < flag; j++){
				fprintf(fileI5, "%s ", A[i][j].dim);
			}
			fprintf(fileI5, "%s\n", A[i][flag].dim);   
		}
		else if(tmp < range49){
			for( int j = 0; j < flag; j++){
				fprintf(fileJ5, "%s ", A[i][j].dim);
			}
			fprintf(fileJ5, "%s\n", A[i][flag].dim);
		}
		else {
			for( int j = 0; j < flag; j++){
				fprintf(fileK5, "%s ", A[i][j].dim);
			}
			fprintf(fileK5, "%s\n", A[i][flag].dim);   
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
	fclose(fileB2);
	fclose(fileC2);
	fclose(fileD2);
	fclose(fileE2);
	fclose(fileF2);
	fclose(fileG2);
	fclose(fileH2);
	fclose(fileI2);
	fclose(fileJ2);
	fclose(fileK2);
	fclose(fileB3);
	fclose(fileC3);
	fclose(fileD3);
	fclose(fileE3);
	fclose(fileF3);
	fclose(fileG3);
	fclose(fileH3);
	fclose(fileI3);
	fclose(fileJ3);
	fclose(fileK3);
	fclose(fileB4);
	fclose(fileC4);
	fclose(fileD4);
	fclose(fileE4);
	fclose(fileF4);
	fclose(fileG4);
	fclose(fileH4);
	fclose(fileI4);
	fclose(fileJ4);
	fclose(fileK4);
	fclose(fileB5);
	fclose(fileC5);
	fclose(fileD5);
	fclose(fileE5);
	fclose(fileF5);
	fclose(fileG5);
	fclose(fileH5);
	fclose(fileI5);
	fclose(fileJ5);
	fclose(fileK5);
	//}

	t2 = clock();
	printf("\nExecution time: %lf\n", (t2-t1)/(double)(CLOCKS_PER_SEC));

	return 0;
}
