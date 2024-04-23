#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char caesar_encrypt(char text, int num) 
{
    int c = (int) text;
    int tmp = 0;

    if(c >= 65 && c <= 90) 
    {
        c += num;
        if(c > 90) {
            tmp = c - 90;
            c = 64 + tmp;
        }
    } 
    else if(c >= 97 && c <= 122) 
    {
        c += num;

        if(c > 122) 
        {
            tmp = c - 122;
            c = 96 + tmp;
        }
    }

    char encrypted = c;
    return encrypted;
}

char caesar_decrypt(char text, int num) 
{
    int c = (int) text;
    int tmp = 0;

    if(c >= 65 && c <= 90) 
    {
        c -= num;

        if(c < 65) 
        {
            tmp = 65 - c;
            c = 91 - tmp;
        }
    } 
    else if(c >= 97 && c <= 122) 
    {
        c -= num;

        if(c < 97) 
        {
            tmp = 97 - c;
            c = 123 - tmp;
        }
    }

    char decrypted = c;
    return decrypted;
}

int main(int argc, char** args) 
{

    if(argc < 3)
    {
        printf("Invalid call: Too few arguments specified!\n");
        printf("usage: %s < encrypt | decrypt > <number to shift>\n", args[0]);
        exit(-1);
    }
    else if(argc > 3)
    {
        printf("Invalid call: Too many arguments specified!\n");
        printf("usage: %s < encrypt | decrypt > <number to shift>\n", args[0]);
        exit(-1);
    }

    char read;
    
    while((read = getchar()) != EOF) 
    {
        char text = read;
        int num = atoi(args[2]);

        

        if(strcmp(args[1], "encrypt") == 0) 
        {
            printf("%c", caesar_encrypt(text, num));
        }
        else if(strcmp(args[1], "decrypt") == 0) 
        {
            printf("%c", caesar_decrypt(text, num));
        }
    }
}