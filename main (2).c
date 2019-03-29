// to complie this simply type
// gcc -o main main.c 
//to run this
// main<a.dat
//worst case time is m*n


#include <stdio.h>
#include <stdlib.h>
int sum;
void readInput(int* n,int *m,int** S)
{
// Loads all input and allocates space
int i;
sum=0;

scanf("%d",n);
//scanf("%d",m);

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
//printing the i and s(I)
//for (i=1;i<=*n;i++){
//  printf(" %d ",(*S)[i]);
//}
for (i=1;i<=*n;i++){
  sum = sum + (*S)[i];
}
*m = sum / 3;
//printf("\n\nm:%d\n\n",*m);

printf("\n");
//
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

void writeOutput(int n,int m,int* S,int C[m+1][m+1])
{
int i,k;
//for printing the serial number i
for(i=0;i<=m;i++){
printf(" %d      ", i);
}
printf("\n\n");
//for printing the serial number j

for(k=0;k<=m;k++){
    printf("%d",k);
    for(i=0;i<=m;i++){
    printf(" %d      ", C[k][i]);
    }
    printf("\n");
}
// Output the input set
/*printf("  i   S\n");
printf("-------\n");
for (i=0;i<=n;i++)
  printf("%3d %3d\n",i,S[i]);

// Output the DP table
if (m<=50)
{
  printf("  i   C\n");
  printf("-------\n");
  for (i=0;i<=m;i++)
    printf("%3d %3d\n",i,C[i]);
}

// Output the backtrace
if (C[m]==n+1)
  printf("No solution\n");
else
{
  printf("Solution\n");
  printf("  i   S\n");
  printf("-------\n");
  for (i=m;i>0;i-=S[C[i]])
    printf("%3d %3d\n",C[i],S[C[i]]);
}
*/
}
void backtracking(int n,int m,int* S,int C[m+1][m+1]){
int i,j,k,counter1,counter2,jn,in, counter;
counter=0;
counter1=1;
counter2=1;
i = m;
j = m;
int arr1[m];
int arr2[m];
int arr3[m];
while(1){
 counter++;
 jn = j - S[C[i][j]];
 in = i - S[C[i][j]];
   
   if(jn<0 && in>=0){
   // we will be using i ie upd arr2
   arr2[counter2]=S[C[i][j]];
   counter2++;
   i = in;
   }
   else if(C[i][jn]>n){
   // we choose to update array 2
   arr2[counter2]=S[C[i][j]];
   counter2++;
   i = in;
   }
   else if(C[i][jn]==C[in][j]){
   // we choose to always update our arr1
   arr1[counter1]=S[C[i][j]];
   counter1++;
   j = jn;
   }
   else if (C[i][jn]>C[in][j]){
   arr1[counter1]=S[C[i][j]];
   counter1++;
   j = jn;
   }
   else if (C[i][jn]<C[in][j]){
   //we will be updating arr2
   arr2[counter2]=S[C[i][j]];
   counter2++;
   i = in;
   } 
 if(counter==20){
   break;
 }
}//for main while loop 

	printf("\n array 1 ");
	for(i=1;i<=counter1-1;i++){
 		printf(" %d",arr1[i]);
	}

	printf("\n array 2 ");
	for(i=1;i<=counter2-1;i++){
		printf(" %d",arr2[i]);
	}
	printf("\n");

}// for the backtracking function


int main()
{
int n;    // Size of input set
int m;    // Target value
int *S;   // Input set
   // Cost table

readInput(&n,&m,&S);
int C[m+1][m+1];
subsetSum(n,m,S,C);

if(m<=10){
writeOutput(n,m,S,C);
}
printf("\nsum is:%d\n",sum);
printf("m is:%d\n",m);

if(sum%3==0){
backtracking(n,m,S,C);
}else{
printf("\nno solutionsssss\n");
}


//testing prints
//printf("\nc[784][19]:%d\n",C[784][19]);
//printf("\nc[588][215]:%d\n",C[588][215]);

free(S);
//free(C);
}
