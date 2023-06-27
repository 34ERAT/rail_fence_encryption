#include"input.c"
#include"get_user_key.c"
#include"decryptio.c"
int main()
{
        // file pointers 
        FILE* file_to_encrypt = NULL, *file_to_write = NULL;




    printf("Sepcifi you input method \n  ");
    char method[22] = "user\n";

    // variable of the  pointers;
    char* hello= NULL; 
    int* key_block = NULL;
    int num_of_blocks = 0;
    int flag = 0;

    // getting the mode of input from the user;

    while(1)
    {
        printf( "Wating for you command ::: " );
        if(fgets(method,22,stdin)!=NULL)
        {
            
            if(strcmp(method,"user\n")==0)
            {
                    hello = specified_string();
                    break;
            }else
            {
                if(strcmp(method,"file_encrypt\n")== 0)
                {
                    // opening the files
                         printf("enter the file to encrypt::: ");
                         char* file_name = File_name();
                            file_to_encrypt = fopen(file_name,"rb");
                            printf("enter the name of you out put file::: ");
                            file_name = File_name();
                            file_to_write = fopen(file_name,"wb");
                            if( file_to_encrypt != NULL &&  file_to_write != NULL )
                            {
                      key_block =  get_user_details(file_to_encrypt,&num_of_blocks);
                       
                     file_encrypt(file_to_encrypt,file_to_write,key_block,num_of_blocks);
                            fclose(file_to_encrypt);
                            fclose(file_to_write);
                            file_to_encrypt= NULL;
                            file_to_write = NULL;
                           
                            } else
                            {

                            file_to_encrypt = NULL;
                            file_to_encrypt = NULL;
                                printf("file path is to read form or write seem to be null \n try again ? ");
                            }
                            

                }else
                {
                       if( strcmp(method,"file_decrypt\n")==0 )
                       {
                           flag = 1;
                            // opening the files
                         printf("enter the file to decrypt::: ");
                         char* file_name = File_name();
                            file_to_encrypt = fopen(file_name,"rb");
                            printf("enter the name of you out put file::: ");
                            file_name = File_name();
                            file_to_write = fopen(file_name,"wb");
                            if( file_to_encrypt != NULL && file_to_write != NULL )
                            {
                       key_block =  get_user_details(file_to_encrypt,&num_of_blocks);
                     
                        file_decrypt(file_to_encrypt,file_to_write,key_block,num_of_blocks);
                            fclose(file_to_encrypt);
                            fclose(file_to_write);
                            file_to_encrypt = NULL;
                            file_to_encrypt = NULL;
                            }else
                            {

                            file_to_encrypt = NULL;
                            file_to_encrypt = NULL;
                                printf("file path is to read form or write seem to be null \n try again ? ");
                            }
                       } else
                       {
                           if( strcmp(method,"exit\n")==0 )
                           {
                                    printf("exiting \n ");
                                    break;
                           }
                       }



                }
            }

        }
    }

    if( hello != NULL )
    {
// getting the string length 
    int len = strlen(hello);
    // printing the length of the string 
    printf("%d\n",len);

    int key = keygen( len);// encrypiton key
    char* cipher_text=NULL;     
    cipher_text = encrypt(hello,key,len); // function return a pointer to array string ;


    printf("%s\n",cipher_text);// printing the  content of the string 
    char* decipher_text= NULL;
    decipher_text = decrypt(cipher_text,key,len);
    printf("the decrypted text\n%s\n",decipher_text);
    free(decipher_text); // free memory

    free(cipher_text);// free the memory 

    cipher_text=NULL;
    decipher_text=NULL;
    }
    return 0;

} 
