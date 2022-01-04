#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct Point{
    int x,z;
    char y[20];
}Point;


int main()
{
    FILE* file = fopen("input.txt","r");
    if(file==NULL)
    return 1;

    char buffer[200];
    fgets(buffer,200,file);

    while(!feof(file)){
        Point p;
        
        // fscanf(file,"%d %s %d",&p.x,p.y,&p.z );
        sscanf(buffer,"%d %s %d",&p.x,p.y,&p.z );
        printf("Read point: %d  %s  %d\n",p.x,p.y,p.z );
        fgets(buffer,200,file);
    }
    fclose(file);

return 0;
}   