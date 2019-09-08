# include<stdio.h>
# include<signal.h>
# include<unistd.h>
# include<stdlib.h>
#include<string.h>


int check_character(char *arg, int *count, int *position, char *position_type){
    int arg_length = strlen(arg);
    printf("%d\n", arg_length);

    
    //pos = position;
    //int count = 0;
    for (int i = 0; i < arg_length; i++)
    {
        if(arg[i] == '|'){
            *count = *count + 1;
            realloc(position, *count*sizeof(int));
            realloc(position_type, *count*sizeof(char));
            position[*count -1] = i;
            //printf("/ninside function position %d",position)
            position_type[*count] = '|';
        }
        else if(arg[i] == 'S'){
            *count = *count + 1;
            realloc(position, *count*sizeof(int));
            realloc(position_type, *count*sizeof(char));
            position[*count] = i;
            position_type[*count] = 'S';
        }
        else if(arg[i] == '$'){
            *count = *count + 1;
            realloc(position, *count*sizeof(int));
            realloc(position_type, *count*sizeof(char));
            position[*count] = i;
            position_type[*count] = '$';
        }
         
    }
    
    return 0;
}

int main(){

    while(1){
        int *position = (int*)malloc(1*sizeof(int));
        char *position_type = (char*)malloc(1*sizeof(char));
        
        char arg[200];
        
        gets(arg);
        int count = 0;

        if (strlen(arg) == 1 & arg[0] == 'q'){
            break;
        }
        else {
            //puts(arg);
            check_character(arg, &count, position, position_type);
        }

        if (count > 0){
            printf("not normal");
            for (int i = 0; i < count; i++)
            {
                printf("\n position %d : %d", i,position[i]);
            }
            
        }
        else{
            printf("normal\n");
        }


    }
    // gets(name);
    // puts(name);
    // printf("\n%d",check_character(name,'n'));
    // //printf("%s", name);
    return 0;
}
