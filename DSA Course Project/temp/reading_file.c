#include <stdlib.h>
#include<string.h>
#include<stdio.h>

struct city_info
{
    //int slno;
    char name[20];
};

int main()
{
    struct city_info ci[5];
    FILE* fptr = fopen("input.txt","r");

    if(fptr==NULL)
    printf("Error Reading File!!!\n");
    int i = 0;
    while(!feof(fptr)){
        fscanf(fptr,"%s",ci[i].name);
        i++;
    }
    fclose(fptr);

    for(int i=0;i<5;i++)
    {
        printf("%d  %s\n",i,ci[i].name);
    }

    return 0;
}