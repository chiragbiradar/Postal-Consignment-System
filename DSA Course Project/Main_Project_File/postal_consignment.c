#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

#define INFINITY 9999
#define size_of_bin 100

#define NOC 100

int graph[NOC][NOC];
int no_of_deliveries;

void sort(int arr[], int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int first_fit(int weight[], int n)
{
	int res = 0;
	int *bin_rem;
	bin_rem = (int *)malloc(no_of_deliveries * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int j;
		for (j = 0; j < res; j++)
		{
			if (bin_rem[j] >= weight[i])
			{
				bin_rem[j] = bin_rem[j] - weight[i];
				break;
			}
		}
		if (j == res)
		{
			bin_rem[res] = size_of_bin - weight[i];
			res++;
		}
	}
	return res;
}

int first_fit_decreasing(int weight[], int n)
{
	sort(weight, n);
	int soln = first_fit(weight, n);
	return soln;
}

struct bin_info
{
	int destination, departure;
};

struct city_info
{
	char name[20];
};

struct city_info ci[1000];
struct bin_info bin[1000];

struct post_info
{
	int speed_rating, post_weight, destination_place, departure_place;
	//* char [20],[20];
};

// Generates and prints 'count' random
//  numbers in range [lower, upper].
int printRandoms_0(int lower, int upper, int count)
{
	int i, num;
	for (i = 0; i < count; i++)
	{
		num = (rand() % (upper - lower + 1)) + lower;
	}
	return num;
}

void green()
{
	printf("\033[0;32m");
}

void yellow()
{
	printf("\033[1;33m");
}

void cyan()
{
	printf("\033[0;36m");
}

void red () {
  printf("\033[1;31m");
}

void white () {
  printf("\033[0;37m");
}

void reset()
{
	printf("\033[0m");
}

void dijkstra(int graph[NOC][NOC], int n, int startnode, int endnode)
{

	int cost[NOC][NOC], distance[NOC], pred[NOC];
	int visited[NOC], count, mindistance, nextnode, i, j;
	// pred[] stores the predecessor of each node
	// count gives the number of nodes seen so far
	// create the cost matrix
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (graph[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = graph[i][j];
	// initialize pred[],distance[] and visited[]
	for (i = 0; i < n; i++)
	{
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	while (count < n - 1)
	{
		mindistance = INFINITY;
		// nextnode gives the node at minimum distance
		for (i = 0; i < n; i++)
			if (distance[i] < mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}
		// check if a better path exists through nextnode
		visited[nextnode] = 1;
		for (i = 0; i < n; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i] < distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}

	if (endnode != startnode)
	{
		yellow();
		printf("\nShortest Distance from %s to %s = %d kms", ci[startnode].name, ci[endnode].name, distance[endnode]);
		reset();
		printf("\nPath =");
		red();
		printf(" %s", ci[endnode].name);
		reset();
		j = endnode;
		do
		{
			j = pred[j];
			cyan();
			printf(" <- ");
			reset();
			red();
			printf("%s", ci[j].name);
			reset();
		} while (j != startnode);
	}
}

int main()
{
	FILE *fptr = fopen("city_names.txt", "r");

	if (fptr == NULL)
		printf("Error Reading File 1!!!\n");
	int i = 0;
	while (!feof(fptr))
	{
		fscanf(fptr, "%s", ci[i].name);
		i++;
	}
	FILE *fptr2 = fopen("graph_distance.txt", "r");
	if (fptr2 == NULL)
	{
		printf("Error Reading File 2!!!\n");
		return 1;
	}

	for (int k = 0; k < 100; k++)
	{
		for (int j = 0; j < 100; j++)
		{
			fscanf(fptr2, "%d", &graph[k][j]);
		}
	}
	fclose(fptr2);

	srand(time(0));

	no_of_deliveries = printRandoms_0(20, 100, 1);

	struct post_info PI[100];
    int rept[no_of_deliveries][no_of_deliveries];
	printf("No of posts = %d\n", no_of_deliveries);

	int *weight;
	weight = (int *)malloc(no_of_deliveries * sizeof(int));

	if (weight == NULL)
	{
		printf("Memory not allocated.\n");
		exit(0);
	}

	else
	{

		for (int start = 0; start < no_of_deliveries; start++)
		{
			PI[start].departure_place = printRandoms_0(0, 100, 1);
			PI[start].destination_place = printRandoms_0(0, 100, 1);
			PI[start].post_weight = printRandoms_0(1, 1000, 1);
			PI[start].speed_rating = printRandoms_0(0, 10, 1);
			weight[start] = PI[start].post_weight;

			// dijkstra(graph, 100, PI[start].departure_place, PI[start].destination_place);
			// printf("\n");
		}
	}


	white();
	printf("\n========================================================================================\n");
	printf("||");
	reset();
	green();
	printf("Minimum number of post man/delivery services required = %d postmans/vehicles/services", first_fit_decreasing(weight, no_of_deliveries));
	reset();
	white();
	printf("||\n");
	printf("========================================================================================\n");
	reset();
	
	return 0;
}
