// a c program to divide  and store number in an array
#include<stdio.h>
#include<stdlib.h>

void divider(int size , int divident)
{
    int result = size/divident;
    int sum = 0; 
    printf("the result  is %d ", result);
    int* array = malloc(sizeof(int)* divident);
   for(int j = 0 ; j< divident ; j++)
   {
       array[j] = result;
       sum += result;
   }
   if( sum != size )
   {
       int new_result = divident + 1;
       int* new_array = realloc(array,sizeof(int)* new_result);
       int rem = size - sum;
      new_array[new_result-1] = rem;
       sum = 0;
       for( int j = 0 ; j <= divident; j++)
       {

       printf("size of block [ %d ] is  [ %d ]\n ", j , array[j]);
       sum += array[j];
       }

   }else
   {

   // printin the result 
   for( int j  = 0 ; j < divident ; j++ )
   {
       printf("size of block [ %d ] is  [ %d ]\n ", j , array[j]);
   }
   }
   printf("the sum of the element of the array is [ %d ]", sum);

}

int main()
{
    // varible declaration 
    int  size = 0 ;
    int blocks  = 0;

    printf("Enter the  size of  input ::: ");
    scanf("%d", &size);
    fgetc(stdin);
    printf("Enter the number of blocks :::");
    scanf("%d", &blocks);
    divider(size,blocks);
}
