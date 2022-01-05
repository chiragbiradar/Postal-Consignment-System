#include<stdio.h>
#include<stdlib.h>


void sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int first_fit(int weight[],int n,int c)
{
    int res=0;
    int bin_rem[n];
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<res;j++)
        {
            if(bin_rem[j]>=weight[i])
            {
                bin_rem[j]=bin_rem[j]-weight[i];
                break;
            }
        }
        if(j==res)
        {
            bin_rem[res]=c-weight[i];
            res++;
        }
    }
    return res;
}



int first_fit_decreasing(int weight[],int n,int c)
{
    sort(weight,n);
    return first_fit(weight,n,c);
}




int main()
{
    int no_of_weights;
   // printf("Enter the size of the bin = \n");
    //scanf("%d",&size_of_bin);
    printf("Enter the no_of_weights to be placed = \n");
    scanf("%d",&no_of_weights);

    int weight[10],sum=0,no_of_bins=10;


    for(int i=1;i<=no_of_weights;i++)
    {
        scanf("%d",&weight[i]);
        sum+=weight[i];
    }
    int n=sizeof(weight)/sizeof(weight[0]);
    printf("number of bins required = %d\n",first_fit_decreasing(weight,n,no_of_weights));
    return 0;


}
