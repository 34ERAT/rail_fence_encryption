#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// encrypiton function 
char* encrypt( char *plain_text ,int  key,  int length_of_array )
{

    int str_len= length_of_array;
    char* array_char= malloc(sizeof(char)*str_len);
    if(array_char==NULL){printf("The memory allocation was not succefull\n");}
    memset(array_char,'\0',str_len);
    //creating array to hold positions   not this array is helpfull for debuging and  understanding of the decrypion process " show how character are distributed in the array_char "
    //
    int *array=malloc(sizeof(int)*str_len);
    if(array==NULL){ printf("memory alllocation was  not succefull "); }
        memset(array,'0',str_len);
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
                array_char[k]=plain_text[current_position];
                array[k]=current_position;
                current_position+=x;
                k++;
                
            }
        }else
        {
            current_position=current_rail-1;
            temp=current_rail;
            flag = 0;
            while(current_position<str_len)
            {
                if(flag==0)
                {
                    if(temp==current_rail)
                    {
                       array_char[k]=plain_text[current_position];
                       array[k]=current_position;
                       temp++;
                    }else
                    {
                        current_position+=y;
                        if(current_position>str_len-1){ break; }
                        array_char[k]=plain_text[current_position];
                        array[k]=current_position;
                        flag=1;
                    }

                }else
                {
                    current_position+=z;
                    if(current_position>str_len-1){break;}
                    array_char[k]=plain_text[current_position];
                    array[k]=current_position;
                    flag=0;
                }
                k++;
            }
        }

    }


    // the code below in comment  displays  the  positions of each characters in the array 
  
   /* for(int j = 0  ; j<str_len; j++)
    {
        printf("%d ",array[j]);
    }
    printf("\n");   
  */ 
    return array_char;      // return the pointer to the stirng arrray

}
