#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

/*
Modify this struct to accomodate your solutions
*/

typedef struct {
    int PID;
    int read_time; 
    struct PCB *next;
} PCB; 

typedef struct {
    int currProcess;
} CPU;

typedef struct {
    PCB *head;
    PCB *tail;
    int length;
} queue_t; 

void enqueue(queue_t *add_to, PCB *add);

PCB *dequeue(queue_t *delete_from);

PCB front(queue_t *get_front);

void file_write(char *file_name, char *write_string);

void file_read(char *file_name);
#endif // DATA_STRUCTURES_H