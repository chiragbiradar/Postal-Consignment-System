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


struct post_info
{
    int speed_rating;
    char departure_place[20],destination_place[20];
};


//Generates and prints 'count' random
// numbers in range [lower, upper].
int printRandoms_o(int lower, int upper,int count)
{
	int i;
	for (i = 0; i < count; i++) {
		int num = (rand() %(upper - lower + 1)) + lower;
		return num;
	}

}




int minDistance(int dist[],bool sptSet[])
{
	
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < NOC; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printPath(int parent[], int j)
{
	
	// Base Case : If j is source
	if (parent[j] == - 1)
		return;

	printPath(parent, parent[j]);

	printf("%d-> ", j);
}

int printSolution(int dist[], int n,int parent[],int dest)
{
	int src = 0;
	printf("Vertex\t Distance\tPath");
	//for (int i = 1; i < V; i++)
	//{
		printf("\n%d -> %d \t\t %d\t\t%d-> ",src, dest, dist[dest], src);
		printPath(parent, dest);
	//}
}

void dijkstra(int graph[NOC][NOC], int src,int dest)
{
	int dist[NOC];

	bool sptSet[NOC];

	int parent[NOC];

	for (int i = 0; i < NOC; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	dist[src] = 0;

	for (int count = 0; count < NOC - 1; count++)
	{
		int u = minDistance(dist, sptSet);
		sptSet[u] = true;
		for (int v = 0; v < NOC; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	// print the constructed
	// distance array
	printSolution(dist, NOC, parent,dest);
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

    FILE *fptr = fopen("graph_distance.txt", "r");
    if (fptr == NULL)
    {
        printf("Error Reading File!!!\n");
        return 1;
    }

    for (int k = 0; k < 100; k++)
    {
        for (int j = 0; j < 100; j++)
        {
            fscanf(fptr, "%d", &graph[k][j]);
        }
    }
    fclose(fptr);


srand(time(0));
int no_of_deliveries=printRandoms_0(20, 100, 1);
struct post_info PI[no_of_deliveries];
for(int start=0;start<no_of_deliveries;start++)
{
        PI[start]..
    



dijkstra(graph,)

}

    return 0;
}
