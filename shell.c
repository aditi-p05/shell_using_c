#include<stdio.h>
#include<stdlib.h>
#define LSH_BUFFERSIZE 1024
void lsh_loop();
char * lsh_readline();
char ** lsh_split_line(char *);
int lsh_execute(char**);
int main(){
    lsh_loop();
    return EXIT_SUCCESS;

}
void lsh_loop(){
    char * line;
    char **args;
    int status;
    do{
        printf(">");
        line=lsh_readline();
        //args=lsh_split_line(line);
        //status=lsh_execute(args);
        free(line);
        free(args);
        printf("y");
    }while(status);

}
char * lsh_readline(){
    int buffersize= LSH_BUFFERSIZE;
    char* buffer =malloc(sizeof(char)*buffersize);
    int c;
    int pos=0;
    if(buffer==NULL){
        printf("Memory allocation error!");
        exit(EXIT_FAILURE); 
    }
    while(1){
        c=getchar();
        if(c==EOF || c=='\n'){
            buffer[pos]='\0';
            return buffer;
        }
        buffer[pos]=c;
        pos++;
        if(pos==buffersize){
            buffersize+=LSH_BUFFERSIZE;
            buffer=realloc(buffer,buffersize);
            if(!buffer){
                printf("Memory allocation error");
                exit(EXIT_FAILURE);
            }
         
        }

    }
}