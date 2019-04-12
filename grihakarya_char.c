//Copyright 4/12/2019 Bishesh Shrestha
//101556177
//
#include <stdio.h>
#include <stdlib.h>
int count = 0;
int illegal_checker=1;
int stack_len=0;
struct node
{
 char color;
 int black_height;
};


void pop(struct node stacks[]){
 stack_len = stack_len -2;
}
void push(struct node stacks[],struct node n ){
stacks[stack_len] = n;
stack_len++;
//stacks[count].black_height = stacks[count-1].black_height;
}


int main()
{
   int i,len;
   char str[200];
   gets(str);
   for(len = 0; str[len] != '\0'; ++len);
   struct node *nodes= (struct node*)malloc(len*sizeof(struct node));
   // make an array of struct node
   for(i=0;i<len;i++){
     if(str[i]=='.'){
       nodes[i].black_height = 1;
       nodes[i].color = '.';
     }
     if(str[i]=='B'){
       nodes[i].black_height = 1;
       nodes[i].color = 'B';
     }
     if(str[i]=='R'){
       nodes[i].black_height = 0;
       nodes[i].color = 'R';
     }
   }
   // now make a stack
  struct node *stacks= (struct node*)malloc(len*sizeof(struct node));
    //pushing in stacks
for(i=0;i<len;i++){


      //sentinial case
      if(nodes[i].color == '.'){
            push(stacks,nodes[i]);
        }



      // non sentinial case B
        if(nodes[i].color == 'B'){
            // stack ma sentinal cha
            if(stacks[stack_len-1].color == '.' && stacks[stack_len-2].color == '.'){
              if(stacks[stack_len-1].black_height == stacks[stack_len-2].black_height){
              nodes[i].black_height = nodes[i].black_height + stacks[stack_len-1].black_height; // updating the black height
              pop(stacks);
              push(stacks,nodes[i]);
              }else{
               printf("Illegal");
               illegal_checker = 0;
               break;
              }
            }

            // stack ma values haru cha that are not sentinial
            else if(stacks[stack_len-1].color != '.' && stacks[stack_len-2].color != '.' ){

                if(stacks[stack_len-1].black_height == stacks[stack_len-2].black_height){
                        nodes[i].black_height = nodes[i].black_height + stacks[stack_len-1].black_height; // updating the black height
                            pop(stacks);
                                push(stacks,nodes[i]);
                                }else{
                                printf("\nIllegal height\n");
                                illegal_checker = 0;
                                }
            }
            else {
                printf("\nIllegal not a tree\n");
                illegal_checker = 0;
                break;

            }
        }

       // non sentinial case R
        if(nodes[i].color == 'R'){
            //check node for redchild
            if(stacks[stack_len-1].color == 'R' || stacks[stack_len-2].color == 'R'){
                printf("\nConsecutive Red node\n");
                illegal_checker = 0;
                break;
            }
            // sentinial case
            if(stacks[stack_len-1].color == '.' && stacks[stack_len-2].color == '.'){
              if(stacks[stack_len-1].black_height == stacks[stack_len-2].black_height){
              nodes[i].black_height = nodes[i].black_height + stacks[stack_len-1].black_height; // updating the black height
              pop(stacks);
              push(stacks,nodes[i]);
              }else{
               printf("Illegal");
               illegal_checker = 0;
               break;
              }
            }
            if(stacks[stack_len-1].color == 'B' && stacks[stack_len-2].color == 'B'){
               if(stacks[stack_len-1].black_height == stacks[stack_len-2].black_height){
              nodes[i].black_height = nodes[i].black_height + stacks[stack_len-1].black_height; // updating the black height
              pop(stacks);
              push(stacks,nodes[i]);
              }else{
               printf("Black Height Error");
               illegal_checker = 0;
               break;
              }
            }
            if(stacks[stack_len-1].color == 'B' && stacks[stack_len-2].color == '.'){
               printf("Black height error");
               illegal_checker = 0;
               break;
              }
            if(stacks[stack_len-1].color == '.' && stacks[stack_len-2].color == 'B'){
               printf("Black Height Error");
               illegal_checker = 0;
               break;
              }





        }

}//for
if(illegal_checker==1){
   /*for(i=0;i<stack_len;i++){
        printf("stack %c\n",stacks[i].color);
        printf("stack %d\n",stacks[i].black_height);
    }*/
    printf("\nthe given is a Legal tree\n");
}

return 0;
}
