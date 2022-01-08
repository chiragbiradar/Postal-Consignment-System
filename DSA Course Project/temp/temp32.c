#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include<limits.h>
#include<stdbool.h>





#define NOC 100

int graph[NOC][NOC];




struct city_info
{
    //int slno;
    char name[20];
};


int main()
{
    struct city_info ci[1000];
    FILE *fptr = fopen("city_names.txt", "r");

    if (fptr == NULL)
        printf("Error Reading File!!!\n");
    int i = 0;
    while (!feof(fptr))
    {
        fscanf(fptr, "%s\n", ci[i].name);
        i++;
    }
    fclose(fptr);

     for(int i=0;i<100;i++)
    {
        printf("%d  %s\n",i+1,ci[i].name);
    }
    return 0;
}
