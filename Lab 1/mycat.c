
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
                if (strchr(argv[1], invalid_chars[i]) != NULL){
                        invalid_found = 1;
                        break;
                }
        }
        if (invalid_found == 1){
                printf("Invalid file name\n");
        }
        else{

		FILE * fp;
		fp = fopen(argv[1],"r");

		char text;
		while(!feof(fp)){
			text = fgetc(fp);
			printf("%c",text);
		}

		fclose(fp);
	}
		return(0);

}
