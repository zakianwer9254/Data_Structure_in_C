#include<stdio.h>


int main(){
	FILE *fp;
	int i=0;
	int a[100];
	fp= fopen("input.txt", "r");
		while(!feof(fp)){
			fscanf(fp, "%d",&a[i++]);
		}
	fclose(fp);
	FILE *fw;
	fw = fopen("texx.txt", "w");
	for(int j=0; j<i-1; j++){
		fprintf(fw, "%d\n",a[j]);
	}
	
}