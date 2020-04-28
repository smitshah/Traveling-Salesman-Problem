#include<stdio.h>
#include<stdlib.h>

// Initializing the distances between cities
int A[4][4]={{0,2,5,7}, {2,0,1,4}, {5,1,0,3}, {7,4,3,0}}, completed[4], dist=0;

void takeInput()
{
    int i,j;
	printf("\n Total number of cities: 4"); //Number of cities
	for(i=0; i<4; i++)
	{
		completed[i]=0;
	}

// Making a matrix of distances using for loop
    printf("\n\n The distance matrix is:");
    
    for(i=0; i<4; i++)
    {
        printf("\n");
        for(j=0; j<4; j++)
            printf("\t %d",A[i][j]);
    }
}

// Calculating minimum path to be followed by the salesman
void minpath(int city)
{
    int i,ncity;
    completed[city]=1;
    printf("%d--->",city+1);
    ncity=mindist(city);
    if(ncity==999)
    {
        ncity=0;
        printf("%d",ncity+1);
        dist+=A[city][ncity];
        return;
    }
    minpath(ncity);
}

// Calculating minimum distance to be covered by the salesman
int mindist(int c)
{
    int i,nc=999;
    int min=999,kmin; 
    for(i=0; i<4 ;i++)
    {
        if((A[c][i]!=0)&&(completed[i]==0))
        {
            if(A[c][i]+A[i][c] < min)
            {
                min=A[i][0]+A[c][i];
                kmin=A[c][i];
                nc=i;
            }
        }
    }
    if(min!=999)
        dist+=kmin;
    return nc;
}


int main()
{
printf("\n \t ............Traveling Salesman Problem............");
    takeInput();
    printf("\n\n The Minimun Path is:\n");
    minpath(0); //passing 0 because starting vertex
    printf("\n\n Minimum distance is %d\n ",dist);
    return 0;
}
