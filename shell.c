#include<stdio.h>
#include<stdlib.h>
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
        args=lsh_split_line(line);
        status=lsh_execute(args);
        free(line);
        free(args);
    }while(status);

}