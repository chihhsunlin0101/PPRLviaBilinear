// Boneh-Lynn-Shacham short signatures demo.
//
// See the PBC_sig library for a practical implementation.
//
// Ben Lynn
#include <pbc.h>
#include <pbc_test.h>
#include <time.h>
#include <string.h>

void get_hash_code(char*temp,char*s,int start);
int main(int argc, char **argv) {

	pairing_t pairing;
	element_t g, hA,hB;
	element_t public_keyA, sigA, public_keyB, sigB;
	element_t secret_keyA, secret_keyB;
	element_t temp1, temp2;

	char bufferA[1200]="",bufferB[1200]="";		//file read buffer
    float weight[5]={0.2,0.2,0.2,0.2,0.2};   

	clock_t start, end;				//calculate the program running time

	pbc_demo_pairing_init(pairing, argc, argv);

	element_init_G2(g, pairing);
	element_init_G2(public_keyA, pairing);
	element_init_G2(public_keyB, pairing);
	element_init_G1(hA, pairing);
	element_init_G1(hB, pairing);
	element_init_G1(sigA, pairing);
	element_init_G1(sigB, pairing);
	element_init_GT(temp1, pairing);
	element_init_GT(temp2, pairing);
	element_init_Zr(secret_keyA, pairing);
	element_init_Zr(secret_keyB, pairing);


	//generate system parameters
	element_random(g);
	//generate private key
	element_random(secret_keyA);
	element_random(secret_keyB);

	//compute corresponding public key
	element_pow_zn(public_keyA, g, secret_keyA);
	element_pow_zn(public_keyB, g, secret_keyB);


	FILE *filePair;
	filePair=fopen("pair","w");
	int comparetimes = 0;
	int hitnumber = 0;

	//char filename1[15][10] = {"outputa01", "outputb01", "pair01.txt", "outputa02", "outputb02", "pair02.txt","outputa03", "outputb03", "pair03.txt","outputa04", "outputb04", "pair04.txt","outputa05", "outputb05", "pair05.txt"};
	char filename1[20][11] = {"outputa01", "outputb01", "outputa02", "outputb02","outputa03", "outputb03", "outputa04", "outputb04", "outputa05", "outputb05", "outputa06", "outputb06", "outputa07", "outputb07", "outputa08", "outputb08", "outputa09", "outputb09", "outputa10", "outputb10"};


	int PPRLround = 0;
	for(int fround = 0; fround < 20; fround += 2){
		PPRLround++;
		FILE *fileA,*fileB;
		fileA=fopen(filename1[0 + fround],"r");			//open files
		fileB=fopen(filename1[1 + fround],"rb+");


		int ia =1,ib=1,totalPair=0; //ia:the line number of A
		float score=0;

		char tempA[115]="",tempB[115]=""; //store the slice of A and B
		start=clock();			//start timer

		while(fgets(bufferA,sizeof(bufferA),fileA) != NULL) //read a line from A
		{
			while(fgets(bufferB,sizeof(bufferB),fileB) != NULL) //read a line from B
			{
				for(int i=1;i<=5;i++)			//test the 10 elements of A and B
				{
					strcpy(tempA,"");	//init
					strcpy(tempB,"");
					get_hash_code(tempA,bufferA,i-1); //get the slice of string
					get_hash_code(tempB,bufferB,i-1);
					//generate element from a hash
					element_from_hash(hA, tempA, sizeof(tempA));
					element_from_hash(hB, tempB, sizeof(tempB));
					//making signature
					element_pow_zn(sigA, hA, secret_keyA);
					element_pow_zn(sigB, hB, secret_keyB);
					//apply
					pairing_apply(temp1,sigA,public_keyB,pairing);
					pairing_apply(temp2,sigB,public_keyA,pairing);
					//compare
					comparetimes++;
					if (!element_cmp(temp1, temp2)) {
						score=score+weight[i-1];
						//printf("score: %f\n", score);
					} 

				}
				if (score>0.8) {
					//claim that 2 records are equivalent
					printf("[%d,%d,%f]\n",ia,ib,score);
					fprintf(filePair,"[%s , %d , %d] = %f\n",filename1[0 + fround],ia,ib,score);
					totalPair++;
					hitnumber++;
				}
				score=0;
				ib++;
				
			}
			ia++;			//clear all variables
			ib=1;
			score=0;
			strcpy(bufferA,"");	
			strcpy(bufferB,"");
			rewind(fileB);
		}
		end=clock();			//end timer

		printf("PPRL finished.It takes %lf s.\n",(end-start)/(double)(CLOCKS_PER_SEC));
		printf("Number of total pairs is:%d\n",totalPair);
		printf("END for %d round\n",PPRLround);
		fprintf(filePair,"PPRL finished.It takes %lf s.\n",(end-start)/(double)(CLOCKS_PER_SEC));
		fprintf(filePair,"Number of total pairs is:%d\n",totalPair);
		
		fclose(fileA);
		fclose(fileB);
	}
	fclose(filePair);
	printf("total compare times: %d\n", comparetimes);
	printf("total hit times: %d\n", hitnumber);
/*
	char filename2[15][10] = {"outputa6", "outputa6", "pair6.txt", "outputa7", "outputb7", "pair7.txt","outputa8", "outputb8", "pair8.txt","outputa9", "outputb9", "pair9.txt","outputaA", "outputbA", "pairA.txt"};


	for(int fround = 0; fround < 15; fround += 3){

		FILE *fileA,*fileB,*filePair;
		fileA=fopen(filename2[0 + fround],"r");			//open files
		fileB=fopen(filename2[1 + fround],"rb+");
		filePair=fopen(filename2[2 + fround],"w");

		int ia =1,ib=1,totalPair=0; //ia:the line number of A
		float score=0;

		char tempA[115]="",tempB[115]=""; //store the slice of A and B
		start=clock();			//start timer

		while(fgets(bufferA,sizeof(bufferA),fileA) != NULL) //read a line from A
		{
			while(fgets(bufferB,sizeof(bufferB),fileB) != NULL) //read a line from B
			{
				for(int i=1;i<=10;i++)			//test the 10 elements of A and B
				{
					strcpy(tempA,"");	//init
					strcpy(tempB,"");
					get_hash_code(tempA,bufferA,i-1); //get the slice of string
					get_hash_code(tempB,bufferB,i-1);
					//generate element from a hash
					element_from_hash(hA, tempA, sizeof(tempA));
					element_from_hash(hB, tempB, sizeof(tempB));
					//making signature
					element_pow_zn(sigA, hA, secret_keyA);
					element_pow_zn(sigB, hB, secret_keyB);
					//apply
					pairing_apply(temp1,sigA,public_keyB,pairing);
					pairing_apply(temp2,sigB,public_keyA,pairing);
					//compare
					if (!element_cmp(temp1, temp2)) {
						score=score+weight[i-1];
					} 

				}
				if (score>0.8) {
					//claim that 2 records are equivalent
					printf("[%d,%d,%f]\n",ia,ib,score);
					fprintf(filePair,"[%d,%d,%f]\n",ia,ib,score);
					totalPair++;
				}
				score=0;
				ib++;
				
			}
			ia++;			//clear all variables
			ib=1;
			score=0;
			strcpy(bufferA,"");	
			strcpy(bufferB,"");
			rewind(fileB);
		}
		end=clock();			//end timer

		printf("PPRL finished.It takes %lf s.\n",(end-start)/(double)(CLOCKS_PER_SEC));
		printf("Number of total pairs is:%d\n",totalPair);
		fprintf(filePair,"PPRL finished.It takes %lf s.\n",(end-start)/(double)(CLOCKS_PER_SEC));
		fprintf(filePair,"Number of total pairs is:%d\n",totalPair);
		
		fclose(fileA);
		fclose(fileB);
		fclose(filePair);
	}
*/

	element_clear(sigA);
	element_clear(public_keyA);
	element_clear(secret_keyA);
	element_clear(sigB);
	element_clear(public_keyB);
	element_clear(secret_keyB);
	element_clear(g);
	element_clear(hA);
	element_clear(hB);
	element_clear(temp1);
	element_clear(temp2);
	pairing_clear(pairing);
	
	return 0;
}



void get_hash_code(char*temp,char*s,int start)
{
	int i=0;
	while(i<114)
	{	//get the hash code
		temp[i]=s[start*115+i];
		i++;
	}
}
