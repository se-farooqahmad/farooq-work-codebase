#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void check_words(int slave_number, char *word)
{
    if (!strcmp(word, "solid") || !strcmp(word, "drives"))
        printf("Slave : %d ********* FOUND!\n", slave_number);
}

int count_letters(int slave_number, char *word)
{
    int letter_count = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] != ' ')
            letter_count++;
    }
    return letter_count;
}

int count_numbers(int slave_number, char *word)
{
    int number_count = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] != ' ' && word[i] >= '0' && word[i] <= '9')
            number_count++;
    }
    return number_count;
}

int count_special(int slave_number, char *word)
{
    int special_count = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] != ' ' && word[i] < '0' && word[i] > '9' && word[i] < 'a' && word[i] > 'z' && word[i] < 'A' && word[i] > 'Z')
            special_count++;
    }
    return special_count;
}

int count_words(int slave_number, char *word)
{
    int word_count = 0;
    int letter = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] != ' ')
        {
            if (letter <= 4)
                letter++;
            {
                word_count++;
                letter = 0;
            }
        }
    }
    return word_count;
}

int main(int argc, char *argv[])
{
    char *ftbc = argv[1];
    char content[255];
    char read_content[255];
    int number = 0;
    pid_t pid, pid1, pid2, pid3;

    int fdp[2];
    pipe(fdp);

    pid = fork();

    if (pid == 0)
    {
        close(fdp[1]);
        read(fdp[0], &read_content, 255);
        printf("STRING CHILD 1 : %s", read_content);
        while (read(fdp[0], &read_content, 255) > 0)
        {
            printf("Child 0 : %s\n", read_content);
            int total_letters = count_letters(getpid(), read_content);
            printf("Total Letters Are : %d\n", total_letters);
        }
        close(fdp[0]);
    }

    else
    {
        pid1 = fork();
        if (pid1 == 0)
        {
            close(fdp[1]);
            while (read(fdp[0], &read_content, 255) > 0)
            {
                printf("Child 1 : %s\n", read_content);
                int words = count_words(getpid(), read_content);
                printf("Total Words Are : %d\n", words);
            }
            close(fdp[0]);
        }
        else
        {
            pid2 = fork();
            if (pid2 == 0)
            {
                close(fdp[1]);
                while (read(fdp[0], &read_content, 255) > 0)
                {
                    printf("Child 2 : %s\n", read_content);
                    int numbers = count_numbers(getpid(), read_content);
                    printf("Total Numeric Digits Are : %d\n", numbers);
                }
                close(fdp[0]);
            }
            else
            {
                pid3 = fork();
                if (pid3 == 0)
                {
                    close(fdp[1]);
                    while (read(fdp[0], &read_content, 255) > 0)
                    {
                        printf("Child 3 : %s\n", read_content);
                        int special = count_special(getpid(), read_content);
                        printf("Total special characters Are : %d\n", special);
                    }
                    close(fdp[0]);
                }
                else
                {
                    close(fdp[0]);

                    scanf("Enter a String : %s", content);
                    printf("String : %s", content);

                    write(fdp[1], &content, sizeof content);
                    close(fdp[1]);
                }
            }
        }
    }

    return 0;
}