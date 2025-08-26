#include "data_structures.h"
#include <stdio.h>
#include <assert.h>

/* Modify this function to store your input as you prefer, 
DO NOT RETURN A CHAR ARRAY unless
malloc'd and subsequently freed */ 
void file_read(char *file_name){
    FILE *file_ptr = fopen(file_name, "r");
    assert(file_ptr != NULL);

    int read_length = 30;
    char curr_line[read_length];

    while(fgets(curr_line, read_length, file_ptr)){
        fprintf("%s", curr_line);
    }

    fclose(file_ptr);
}

void file_write(char *file_name, char *write_string){
    FILE *file_ptr = fopen(file_name, "a");
    assert(file_ptr != NULL);

    fprintf(file_ptr, write_string);

    fclose(file_ptr);
}




