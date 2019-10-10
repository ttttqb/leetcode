#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void GetMemory(char* p)
{
    p=(char*)malloc(100);
}

int main()
{
    char *str=NULL;
    GetMemory(str);
    strcpy(str,"hello world");
    printf("%s",str);
    return 0;
}