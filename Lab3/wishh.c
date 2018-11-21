#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void errorstat()
{
    char error_message[30] = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message));
    return;
}

int main(int argc, char *argv[])
{

    if (argc > 2)
    {
        errorstat();
        exit(0);
    }

    char com[30];
    const char s[2] = " ";
    char *token;
    char *arr[10];
    char *parr[10];
    char *bin_path = "/bin/";
    char *user_path = "/user/bin/";

    if (argc == 2)
    {
        FILE *fp;
        fp = fopen(argv[1], "r");

        if (fp == NULL)
        {
            errorstat();
            exit(1);
        }

        while (!feof(fp))
        {

            fscanf(fp, "%[^\n]", com);
            token = strtok(com, s);

            int i = 0;

            while (token != NULL)
            {
                arr[i] = token;
                i++;
                token = strtok(NULL, s);
            }

            char *path1 = malloc(strlen(bin_path) + strlen(arr[0]) + 1);
            strcat(path1, bin_path);
            strcat(path1, arr[0]);
            char *path2 = malloc(strlen(user_path) + strlen(arr[0]) + 1);
            strcat(path2, user_path);
            strcat(path2, arr[0]);

            for (int x = 1; x < i; x++)
            {
                parr[x] = arr[x];
            }

            if (strcmp(arr[0], "ls") == 0)
            {
                __pid_t pid = fork();

                if (pid < 0)
                {
                    errorstat();
                    printf("Child process cannot run\n");
                    wait(NULL);
                }
                else
                {
                    if (access(path1, (X_OK)) == 0)
                    {
                        parr[0] = path1;
                        execv(path1, parr);
                    }
                    else if (access(path2, (X_OK)) == 0)
                    {
                        parr[0] = path2;
                        execv(path2, parr);
                    }
                    else
                    {
                        errorstat();
                        printf("Path inaccessible\n");
                    }
                }
            }

            if (strcmp(arr[0], "cd") == 0)
            {
                printf("In the cd domain\n");
                if (chdir(arr[1]) == 0)
                {
                    printf("Folder Accessed\n");
                }

                else
                {
                    errorstat();
                    printf("Folder not available\n");
                }
            }

            if (strcmp(arr[0], "path") == 0)
            {
                printf("In the path domain\n");
            }

            if (strcmp(arr[0], "exit") == 0)
            {
                exit(0);
            }
        }

        fclose(fp);
        exit(0);
    }

    char command[100];
    int cmp = 1;

    while (cmp != 0)
    {
        printf("wish> ");
        scanf("%s", command);

        token = strtok(command, s);
        int i = 0;

        while (token != NULL)
        {
            arr[i] = token;
            i++;
            token = strtok(NULL, s);
        }

        char *path1 = malloc(strlen(bin_path) + strlen(arr[0]) + 1);
        strcat(path1, bin_path);
        strcat(path1, arr[0]);
        char *path2 = malloc(strlen(user_path) + strlen(arr[0]) + 1);
        strcat(path2, user_path);
        strcat(path2, arr[0]);

        for (int x = 1; x < i; x++)
        {
            parr[x] = arr[x];
        }

        if (strcmp(arr[0], "ls") == 0)
        {
            __pid_t pid = fork();

            if (pid < 0)
            {
                errorstat();
                printf("Child process cannot run\n");
                wait(NULL);
            }
            else
            {
                if (access(path1, (X_OK)) == 0)
                {
                    parr[0] = path1;
                    execv(path1, parr);
                }
                else if (access(path2, (X_OK)) == 0)
                {
                    parr[0] = path2;
                    execv(path2, parr);
                }
                else
                {
                    errorstat();
                    printf("Path inaccessible\n");
                }
            }
        }

        else if (strcmp(arr[0], "cd") == 0)
        {

            if (chdir(arr[1]) == 0)
            {
                printf("Folder Accessed\n");
            }

            else
            {
                errorstat();
                printf("Folder not available\n");
            }
        }

        else if (strcmp(arr[0], "path") == 0)
        {
            printf("In the path domain\n");
        }

        else if (strcmp(arr[0], "exit") == 0)
        {
            exit(0);
        }

        else
        {
            errorstat();
            printf("Command not recognisable, please try again\n");
        }
    }

    return (0);
}
