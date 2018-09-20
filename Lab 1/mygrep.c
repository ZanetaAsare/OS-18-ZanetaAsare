
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	char invalid_chars[] = "!@#$%^&*()`~+= <>?/,;':\[]{}|";			//an array of charcters that could make a file name invalid
	int invalid_found = 0;

	int i;
	int len = strlen(invalid_chars);
	for (i = 0; i < len; ++i)			//an iteration through the array of characters
	{
		if (strchr(argv[2], invalid_chars[i]) != NULL){       //a check to see if the character is in the filename provided, it returns the first occurence of the character
			invalid_found = 1;				//if return array is not empty, it shows that there is an invalid character present
			break;
		}
	}
	if (invalid_found == 1){
		printf("Invalid file name\n");
	}
	else{

	int k;
	for(k = 2; k < argc; k++){			//an iteration through the array of arguments provided by the user

	        FILE * fp;

        	fp = fopen(argv[k],"r");		//file is opened for reading

        	char word[100];
		int search;


	        while(fgets(word,100,fp)){


			search = strcasestr(word,argv[1]);	//while the lines are being read, strcasestr searches for an occurence of the search item, regardless of case.

			if(search==0)
			{
			}
			else
			{
				printf("%s\n",word);		//prints the line if the search item is found on it
			}
	}


        fclose(fp);			//file is closed

	}
	}
        return(0);
}



