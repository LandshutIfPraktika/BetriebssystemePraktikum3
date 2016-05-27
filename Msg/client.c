//
// Created by s-gheldd on 4/27/16.
//

#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include "mq.h"

int main() {
    int msq_id = msgget(MQ_KEY, 0);
    struct msqid_ds msqid_ds;
    struct msg_message send_message, rec_message;
    pid_t pid, fork_pid;
    int i;
    fork_pid = 0;
    for (i = 0; (i < 5) && !fork_pid; i++) {
        fork_pid = fork();
    }

    pid = getpid();

    if (msq_id == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 5; i++) {
        send_message.mtyp = 1;
        sprintf(send_message.text, "%d\n", pid);
        msgsnd(msq_id, &send_message, MSG_SIZE, 0);
        rec_message.mtyp = pid;
        msgrcv(msq_id, &rec_message, MSG_SIZE, pid, 0);
        printf("Server answered: %s\n", rec_message.text);
    }

    send_message.mtyp = 1;
    sprintf(send_message.text, "%d\n", -1);
    msgsnd(msq_id, &send_message, MSG_SIZE, 0);

    return 0;

}