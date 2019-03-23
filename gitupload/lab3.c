 Subset sums by dynamic programming
// CSE 2320 Notes 7

#include <stdio.h>
#include <stdlib.h>

void readInput(int* n,int* m,int** S)
{
// Loads all input and allocates space
int i;

scanf("%d",n);
scanf("%d",m);

*S=(int*) malloc((*n+1)*sizeof(int));
//*C=(int*) malloc((*m+1)*(*m+1)*sizeof(int));
//if (!(*S) || !(*C))
//{
 // printf("malloc failed %d\n",__LINE__);
  //exit(0);
//}

(*S)[0]=0;                // Sentinel zero
for (i=1;i<=*n;i++){
  scanf("%d",*S+i);
}
}

void subsetSum(int n,int m,int* S,int C[m+1][m+1])
{
int i,j,q,k,potentialSum,leftover;

// Initialize table for DP

C[0][0]=0;



  // DP base case
// For each potential sum, determine the smallest index such
// that its input value is in a subset to achieve that sum.
    for(k=0;k<(m+1);k++){
        for (potentialSum=1; potentialSum<=m; potentialSum ++)
        {
            for (j=1;j<=n;j++)
            {
                leftover=potentialSum-S[j];      // To be achieved with other values
                if (leftover>=0 &&               // Possible to have a solution
                C[k][leftover]<j){                 // Indices are included in


                break;
                }
                leftover=k-S[j];      // To be achieved with other values
                if (leftover>=0 &&               // Possible to have a solution
                C[leftover][potentialSum]<j)                 // Indices are included in
                {
                break;
                }

                                        // ascending order.
            }
        C[k][potentialSum]=j;
        C[potentialSum][k]=j;
        }

    }
}


