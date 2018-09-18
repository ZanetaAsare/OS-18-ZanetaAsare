#include <stdio.h>

int main()
{
	char filename[31];
	printf("Please enter the name of the file with the full extension: ");
	scanf("%s",filename);

	FILE * fp;

	fp = fopen(("%s",filename),"r");
	char c[100];

	while(!feof(fp)){
		fgets(c,100,fp);
		puts(c);
	}

	fclose(fp);
	return(0);
}

