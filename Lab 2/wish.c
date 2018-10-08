#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){


        if (argc > 2){
                printf("Error! Function takes only one or no arguments\n");
                exit(0);
        }

        char com[30];
        const char s[2] = " ";
        char *token;

        if (argc == 2){
                FILE *fp;
                fp = fopen(argv[1],"r");

                if (fp == NULL){
                        printf("Error! No filename provided\n");
                        exit(1);
                }

                while(!feof(fp)){

                        fscanf(fp,"%[^\n]",com);
                        token = strtok(com, s);


                        if (strcmp(token,"ls") == 0){}

                        if (strcmp(token,"cd") == 0){}

                        if (strcmp(token,"path") == 0){}

                        if (strcmp(token,"exit") == 0){}

                }

                fclose(fp);
                exit(0);

	}

        char command[100];
        int cmp = 1;

        while(cmp != 0){
                printf("wish> ");
                scanf("%s",command);
                cmp = strcmp(command,"exit");

                token = strtok(command,s);

                if (strcmp(token,"ls") == 0){
                        printf("In the ls domain\n");
                }

                else if (strcmp(token,"cd") == 0){
                        printf("In the cd domain\n")
			par = strtok(
			chdir(par)
                }

                else if (strcmp(token,"path") == 0){
                        printf("In the path domain\n");
                }

                else{
                        printf("Command not recognisable, please try again\n");
                }
        }

        exit(0);
        return(0);

}

