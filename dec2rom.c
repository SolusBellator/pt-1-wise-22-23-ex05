#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* rom_one(int n) {
    switch(n) 
    {
        case 1:
            return "I";
            break;
        case 2:
            return "X";
            break;
        case 3:
            return "C";
            break;
        case 4:
            return "M";
            break;
        default:
            exit(-2);
    }
}

char* rom_five(int n) {
    switch(n) 
    {
        case 1:
            return "V";
            break;
        case 2:
            return "L";
            break;
        case 3:
            return "D";
            break;
        default:
            exit(-2);
    }
}

int rom(char* dec) 
{
    int num = atoi(dec);
    int digits = log10(num) + 1;
    int tmp = 0;
    int keep = num;

    char str[500] = "";
    

    for(int i = digits; i >= 1; i--) 
    {
        num = keep / pow(10, i-1);
        tmp = num % 10;

        if(tmp == 0) 
        {
            continue;
        } 
        else if(tmp <= 3) 
        {
            for(int j = 1; j <= tmp; j++) 
            {
                strcat(str, rom_one(i));
            }
        } 
        else if(tmp == 4) 
        {
            strcat(str, rom_one(i));
            strcat(str, rom_five(i));
        } 
        else if(tmp == 5) 
        {
            strcat(str, rom_five(i));
        } 
        else if(tmp <= 8 && tmp > 5) 
        {
            strcat(str, rom_five(i));

            for(int k = 6; k <= tmp; k++) 
            {
                strcat(str, rom_one(i));
            }
        } 
        else if(tmp == 9) 
        {
            strcat(str, rom_one(i));
            strcat(str, rom_one(i+1));
        }        
    }

    printf("%s\n", str);

    return 0;
}

int main(int argc, char** args) 
{
    if(argc < 2) 
    {
        printf("Invalid call: Too few arguments specified!\n");
        printf("usage: %s <number to transcript>\n", args[0]);
        exit(-1);
    }
    else if(argc > 2)
    {
        printf("Invalid call: Too many arguments specified!\n");
        printf("usage: %s < encrypt | decrypt > <number to shift>\n", args[0]);
        exit(-1);
    }

    for(int i = 1; i < argc; i++) 
    {
        rom(args[i]);
    }
}