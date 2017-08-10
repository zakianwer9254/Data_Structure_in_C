#include<stdio.h>
#include<stdlib.h>

int main(){
	char str[5];
	int c;
	int i=0;
	char arr[10];
	int j=0;
	while((c=getchar())!='\n'){
		if(c==' '){
			arr[j++]=atoi(str);
			i=0;
			continue;
		}
		str[i++]=c;
		
	}
	if(c=='\n'){
		arr[j++]=atoi(str);
	}

	for(int i=0; i<10; i++)
		printf("%d ",arr[i]);
}