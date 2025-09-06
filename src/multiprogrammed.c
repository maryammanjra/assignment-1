#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"

void scheduler(queue_t *ready_queue) {
    // Implement polling OR interrupts OR multiprogramming here
    // e.g. while (ready_queue not empty) { dequeue(); run process; }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    queue_t ready_queue = {NULL, NULL, 0};
    file_read(argv[1]);

    scheduler(&ready_queue);

    return 0;
}
