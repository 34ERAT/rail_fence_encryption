#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
int* divider_fn( long file_size ,int* number_of_blocks )
{
    // determine th size of each block by dividing  file_size and the  number_of_blocks
    int result = file_size/(*number_of_blocks);
    int sum = result* (*number_of_blocks);
    int reminder = file_size - sum;
        /// arrau declaration 
     int* block_size_array = NULL;

     if( reminder == 0 )
     {
          if( (block_size_array = malloc( sizeof(int)*(*number_of_blocks ))) == 0 )
          {
              printf(" memory allocation failed \n");
          }
          sum = 0;
     }else
     {
            int new_num_of_blocks = *number_of_blocks+1;
          if( (block_size_array = malloc( sizeof(int)*new_num_of_blocks )) == 0 )
          {
              printf(" memory allocation failed \n");
          }else
          {
              sum = 0;
              block_size_array[ *number_of_blocks ] = reminder;
              *number_of_blocks = new_num_of_blocks;
              sum = reminder;
          }
     }
    
     for(int j= 0 ; j < *number_of_blocks-1 ; j++)
     {
         block_size_array[ j ] = result; 
         sum += result;
         
     }
     printf(" sum :: = %d ", sum );



    return block_size_array;
}


int* get_user_details(FILE* file_to_cypher,int* num_of_blocks)
{
    fseek(file_to_cypher,0,SEEK_END);
    long file_size = ftell(file_to_cypher);
    fseek(file_to_cypher,0,SEEK_SET);

    printf("The File size of you file is [ %ld ],file\n", file_size);
    // declaration of varible and initionlization
    int number_of_blocks;
    int* block_size= NULL;/// = malloc(sizeof(int)*number_of_blocks);
    bool success =false ;

    while(1)
    {

        printf("HOW MANY BLOCK DO YOU WISH TO  HAVE?\n : enter number of block to proceed ");
       if(scanf("%d",&number_of_blocks)==EOF) 
       {
           printf("error ::: reading the  ender value make sure is and interger \n");
           continue;
       }else
       {  

        fgetc(stdin);

        block_size  =  divider_fn (file_size,&number_of_blocks);

      *num_of_blocks = number_of_blocks;     
       success = true;


       // user to enter   the encryption key in form of bloc_size

        /*printf("ENTER THE KEY SEQUENCE  'i.e 20 40 60 39' the number rep the  size of each block :::\n");
        for(int j = 0 ; j<number_of_blocks ; j++)
        {
            int current = 0;
            printf("Enter size of block  [ %d ] ", j);
            if(scanf("%d",&current)== EOF)
            {
               
                    printf("the value entered is not interger type \n");
                    memset(block_size,0,number_of_blocks);
                   
                    break;
            }
            block_size[j]=current;
            success = true;

        }*/

        ///// displaying the encryption key to the user

        if(success == true)
        {
        printf("  THE  key is :::  ");
            for (int j = 0 ; j < number_of_blocks ; j++)
            {
                printf("%d ",block_size[j]);
            }
            printf("\n");
            goto end;

       }
       }
    }
end:
    return block_size; 

}
char* File_name()
{
//start:

    char* file_name = NULL;
       file_name =  malloc(100*sizeof(char));
start:
    if(fgets(file_name , 100, stdin)== NULL)
    {
        printf(" could not get the string ");
        goto start;
    }else
    {
       char *pos = NULL;
       if((pos=strchr(file_name, '\n'))!=NULL)
       {
           *pos='\0';
       }

    }
    return file_name;

}


