#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// encrypiton function 
int* positions( int str_len ,int  key )
{

    int *array=malloc(sizeof(int)*str_len);

    // declaration of varibles
    int total_rails=key;
    int current_rail=0;
    int current_position=0;
    int temp=current_position;
    int flag=0;
    // varibles that specifies the characters to be copied
    // and where to be copied
    int k=0;
    int l=0;
    /* equations to detemine the location of the character int the array
     * x determines position of characters on  the first and last row
     * y and z determines the positions of characters inthe midrows i.e between the first and last row
     */
    int x=(total_rails-1)*2;
    int y=(total_rails-current_rail)*2;
    int z=(current_rail-1)*2;
    for(int i = 0; i <total_rails ; i++)
    {
        current_rail=i+1;
        x=(total_rails-1)*2;
        y=(total_rails-current_rail)*2;
        z=(current_rail-1)*2;
        if(current_rail == 1 || current_rail==total_rails)
        {
            if(current_rail==total_rails)
            {
                current_position=current_rail-1;
            }
            while(current_position<str_len)
            {
                array[k]=current_position;
                current_position+=x;
                k++;
                
            }
        }else
        {
            current_position=current_rail-1;
            temp=current_rail;
            while(current_position<str_len)
            {
                if(flag==0)
                {
                    if(temp==current_rail)
                    {
                       array[k]=current_position;
                       temp++;
                    }else
                    {
                        current_position+=y;
                        if(current_position>str_len-1){ break; }
                        array[k]=current_position;
                        flag=1;
                    }

                }else
                {
                    current_position+=z;
                    if(current_position>str_len-1){break;}
                    array[k]=current_position;
                    flag=0;
                }
                k++;
            }
        }

    }

    
  
/*    for(int j = 0  ; j<str_len; j++)
    {
        printf("%d ",array[j]);
    }
    printf("\n");   
 */  
    return array;      // return the pointer to the int array

}
char* decrype(char* character_block, int key )
{
           char* final_character_block = NULL;
           int string_len = strlen(character_block);
          int* indexes =  positions(string_len,key);
          
          final_character_block = malloc(string_len*sizeof(char));
              if(final_character_block != NULL)
              {

              

          for( int j = 0 ; j<string_len ; j++   )
          {
              
              int current_position = indexes[j];  // get respecitive position of  characters

                // arrange the characters to  their respecitive positions (" create oringal text ")
              final_character_block[current_position] = character_block[j];
          }
             }else
              {
                  printf("Failed to get allocate memory");
              }
            
          return final_character_block;
}
