#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include"encryption_function.c"
//#include"decryptio.c"
#include"decryption_function.c"

char* specified_string()
{
    char * user_specified_string= NULL;
    
    user_specified_string = malloc(100*sizeof(char)); // allocation memory 

    printf("Enter the String you wish to encyrpyt using rali fence \n");

    if(  fgets(user_specified_string,100,stdin) != NULL)
    { 
    
  //  fgetc(stdin); // clear the input buffer 

    // search for \n line char and replace it with \o if it exist;
    char *pos;
    if((pos =strchr(user_specified_string,'\n')) != NULL )
    {
        *pos = '\0';

            // return user_specified_string;
    }

    }else
    {
        printf("the input was longer that expecte \n");
    }
     
    return user_specified_string;
    
}
// generating a relative key relative to the size of  the block
//
int keygen(int size)
{
    int key = 0;

    if(size > 20 )
    {
        double size_f = (double)size;
            key  =(int) sqrt(size_f);
    }else
    {
        if(size>=10)
        {
             key = 4;
        }else
        {
            key = 3;
        }
    }
    return key;
}



void file_encrypt( FILE* file , FILE* new_file ,int *sequence, int number_of_blocks )
{
    // find the  size of the file :w


    fseek(file,0,SEEK_END);
    long file_size = ftell(file);
    fseek(file,0,SEEK_SET);

    //variable to store char form the file

    char *  current_block = NULL;
    char * generated_string = NULL;
    
    // geting the size of array;
    int size = number_of_blocks; //size_total_bytes/size_of_element;
    int flag = 0;


    for(int j = 0 ;  j < size; j++)
    {
        current_block =malloc(sequence[j]*sizeof(char));
        int current_size = sequence[j];

            if(fread(current_block,current_size,sizeof(char),file)== sizeof(char))
            {
                    int key = keygen(current_size );  // generating the encrypt key for the rail not to be confuced with the key use inputed 
                                                                    // geerall key;
                      
                      // getting the generated cypher

                    generated_string = encrypt(current_block, key,current_size);

                    // writing the string to the file
                    if(fwrite(generated_string,current_size,sizeof(char),new_file)==sizeof(char))
                    {
                       //printf("block [ %d ]whas was encyrpted succefuly size of  block ::: [ %d ]\n",j,current_size);
                        free(current_block);
                        free(generated_string);
                        generated_string = NULL;
                        current_block = NULL;
                        continue;
                    }else
                    {
                        printf("the was and error writing to the file_\n");
                        flag = 1;
                        break;
                    }

                    

            }else
            {
                printf("Failed to read the file : : pleace check your file pointer ");
                flag = 1;
                break;
            }

    }
    if( flag == 0 )
    {

     printf("the  file whas was encyrpted succefully  no error was found \n");
    }
 // freeing the the memory  
   free(generated_string);
   free(current_block);
   current_block = NULL;
   generated_string =NULL;
    

}

// decryption
 void file_decrypt( FILE* file , FILE* new_file ,int *sequence, int number_of_blocks )
{
    // find the  size of the file :w


    fseek(file,0,SEEK_END);
    long file_size = ftell(file);
    fseek(file,0,SEEK_SET);

    //variable to store char form the file

    char *  current_block = NULL;
    char * generated_string = NULL;
    
    // geting the size of array;
    int size = number_of_blocks; //size_total_bytes/size_of_element;
    int flag = 0;


    for(int j = 0 ;  j < size; j++)
    {
        current_block =malloc(sequence[j]*sizeof(char));
        int current_size = sequence[j];

            if(fread(current_block,current_size,sizeof(char),file)== sizeof(char))
            {
                    int key = keygen(current_size );  // generating the encrypt key for the rail not to be confuced with the key use inputed 
                                                                    // geerall key;
                      // getting the generated cypher

                    generated_string =decrypt(current_block, key, current_size);

                    // writing the string to the file
                    if(fwrite(generated_string,current_size,sizeof(char),new_file)== sizeof(char))
                    {
                       // printf("block [ %d ]whas was decrypted  succefuly size of  block ::: [ %d ]\n",j,current_size);
                        free(current_block);
                        free(generated_string);
                        generated_string = NULL;
                        current_block = NULL;
                        continue;
                    }else
                    {
                        printf("the was and error writing to the file_\n");
                        flag = 1;
                        break;
                    }

                    

            }else
            {
                printf("Failed to read the file : : pleace check your file pointer ");
                flag = 1;
                break;
            }

    }

    if( flag == 0 )
    {

     printf("the  file whas was dencyrpted succefully  no error was found \n");
    }
    // freeing the the memory  
   free(generated_string);
   free(current_block);
   current_block = NULL;
   generated_string =NULL;
   

}

