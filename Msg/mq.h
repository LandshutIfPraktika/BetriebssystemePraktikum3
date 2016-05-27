//
// Created by s-gheldd on 4/27/16.
//

#ifndef MSG_MQ_H
#define MSG_MQ_H

/* Schlüssel der Message-Queue für Server und Clients */
#define MQ_KEY 0xabcdef12

/* Wählen Sie eine etwas „kryptische“ Zahl */
/* Maximale Länge der Nachricht */
#define MSG_SIZE 20
/* Struktur einer Message */

struct msg_message{
    long mtyp;
    char text[MSG_SIZE];
};

#endif //MSG_MQ_H
