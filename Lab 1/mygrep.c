
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char invalid_chars[] = "!@#$%^&*()`~+= <>?/,;':\[]{}|";
	int invalid_found = 0;

	int i;
	int len = strlen(invalid_chars);
	for (i = 0; i < len; ++i)
	{
		if (strchr(argv[2], invalid_chars[i]) != NULL){
			invalid_found = 1;
			break;
		}
	}
	if (invalid_found == 1){
		printf("Invalid file name\n");
	}
	else{

	int k;
	for(k = 2; k < argc; k++){

	        FILE * fp;

        	fp = fopen(argv[k],"r");

        	char word[100];
		int search;


	        while(fgets(word,100,fp)){


			search = strcasestr(word,argv[1]);

			if(search==0)
			{
			}
			else
			{
				printf("%s\n",word);
			}
	}


        fclose(fp);

	}
	}
        return(0);
}



