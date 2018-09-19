
#include <stdio.h>
#include <string.h>


int main()
{
	char searchitem[31];
	printf("Please enter the word you want to search for: ");
	scanf("%s",searchitem);

        char filename[31];
        printf("Please enter the name of the file you want to search in, with the full extension: ");
        scanf("%s",filename);

//	char invalid_chars[] = "!@#$%^&*()`~+= <>?\/,;':[]{}|";
//	int invalid_found = 0;

//	int i;
//	for (i = 0; i < strlen(invalid_chars); ++i)
//	{
//		if (strchr(filename, invalid_chars[i]) != NULL){
//			invalid_found = 1;
//			break;
//		}
//	}
//	if (invalid_found == 1){
//		printf("Invalid file name");
//	}
//	else{

        FILE * fp;

        fp = fopen(("%s",filename),"r");

        char word[100];
	int search;


        while(fgets(word,100,fp)){
		printf("%s\n",word);


		search = strcasestr(word,searchitem);

		if(search==0)
		{
			printf("\033[1;35mWord not found in line above\033[0m\n");
		}
		else
		{
			printf("\033[1;31mWord found in line above!\033[0m\n");
		}
	}


        fclose(fp);
//	}
        return(0);
}



