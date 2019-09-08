# include<stdio.h>
# include<signal.h>
# include<unistd.h>
# include<stdlib.h>
#include<string.h>


int check_character(char *arg, char cmp_string){
    int arg_length = strlen(arg);
    printf("%d\n", arg_length);
    int count = 0;
    for (int i = 0; i < arg_length; i++)
    {
        if(arg[i] == cmp_string){
            count++;
        } 
    }
    
    return count;
}

int main(){

    char name[200];
    while(1){
        char arg[200];
        gets(arg);

        if (strlen(arg) == 1 & arg[0] == 'q'){
            break;
        }
        else {
            puts(arg);
        }
    }
    // gets(name);
    // puts(name);
    // printf("\n%d",check_character(name,'n'));
    // //printf("%s", name);
    return 0;
}
