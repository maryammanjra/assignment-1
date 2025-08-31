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
        printf("%s", curr_line);
    }

    fclose(file_ptr);
}

void file_write(char *file_name, char *write_string){
    FILE *file_ptr = fopen(file_name, "a");
    assert(file_ptr != NULL);

    fprintf(file_ptr, write_string);

    fclose(file_ptr);
}

void enqueue(queue_t *queue, PCB *add){
    if(queue->head == NULL){
        queue->head = add;
        queue->tail = add;
    } else {
        queue->tail->next = add;
        queue->tail = add;
    }
    queue->length += 1;
}

PCB* dequeue(queue_t *queue) {
    if (queue->head == NULL) {
        return NULL;
    }

    PCB *removed = queue->head;
    queue->head = queue->head->next;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    removed->next = NULL; 
    queue->length--;

    return removed;
}

void print_queue(queue_t *queue) {
    PCB *current = queue->head;
    printf("Queue (length = %d): ", queue->length);
    while (current != NULL) {
        printf("[PID: %d, read_time: %d] -> ", current->PID, current->read_time);
        current = current->next;
    }
    printf("NULL\n");
}







