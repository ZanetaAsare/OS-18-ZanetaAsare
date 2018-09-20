
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

        char invalid_chars[] = "!@#$%^&*()`~+= <>?/,;':\[]{}|";          //adding an array of possible characters that could cause a file name to be invalid
        int invalid_found = 0;

        int i;
        int len = strlen(invalid_chars);
        for (i = 0; i < len; ++i)     // an iteration through the array of characters
        {
                if (strchr(argv[1], invalid_chars[i]) != NULL){        //checks to see if any of the characters are in the file name given, returns the first occurence of the character
                        invalid_found = 1;
                        break;
                }
        }
        if (invalid_found == 1){
                printf("Invalid file name\n");
        }
        else{
	int k;
	for(k = 1; k < argc; k++){       //an iteration through the array of argument v provided
		FILE * fp;
		fp = fopen(argv[k],"r");        //opens file for reading

		char text;
		while(!feof(fp)){		//while the end of the file has not been reached
			text = fgetc(fp);	//gets the characters from the file which is then printed next
			printf("%c",text);
		}

		fclose(fp);         //file is closed
	}
	}
		return(0);

}
