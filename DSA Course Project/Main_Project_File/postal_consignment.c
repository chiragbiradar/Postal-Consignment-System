#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>




#define NOC 100

int graph[NOC][NOC];




struct city_info
{
    //int slno;
    char name[20];
};


struct post_info
{
    int speed_rating;
};


//Generates and prints 'count' random
// numbers in range [lower, upper].
int printRandoms_o(int lower, int upper,int count)
{
	int i;
	for (i = 0; i < count; i++) {
		int num = (rand() %
		(upper - lower + 1)) + lower;
		return num;
	}

}




int main()
{
    struct city_info ci[100];
    FILE *fptr = fopen("city_names.txt", "r");

    if (fptr == NULL)
        printf("Error Reading File!!!\n");
    int i = 0;
    while (!feof(fptr))
    {
        fscanf(fptr, "%s", ci[i].name);
        i++;
    }
    fclose(fptr);

    /* for(int i=0;i<100;i++)
    {
        printf("%d  %s\n",i,ci[i].name);
    }*/

    FILE *fptr = fopen("distance_graph.txt", "r");
    if (fptr == NULL)
    {
        printf("Error Reading File!!!\n");
        return 1;
    }

    for (int k = 0; k < 100; k++)
    {
        for (int j = 0; j < 100; j++)
        {
            fscanf(fptr, "%d", graph[k][j]);
        }
    }
    fclose(fptr);


srand(time(0));
int no_of_deliveries=printRandoms_0(20, 100, 1);




    return 0;
}
