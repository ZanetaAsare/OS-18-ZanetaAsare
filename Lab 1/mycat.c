#include <stdio.h>

int main()
{
	char filename[31];
	printf("Please enter the name of the file with the full extension: ");
	scanf("%s",filename);

	FILE * fp;

	fp = fopen(("%s",filename),"r");

	char text;
	while(!feof(fp)){
		text = fgetc(fp);
		printf("%c",text);
	}

	fclose(fp);
	return(0);
}

