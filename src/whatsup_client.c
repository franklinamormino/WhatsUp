#include <stdio.h>
#include <rpc/rpc.h>
#include "../rpcgen/whatsup.h"

#define DEBUG 1

main(int argc, char *argv[]) {

    CLIENT *cl;
    // int *answer;
    // void *pvoid;

    int exit = 0;
    char * buffer = malloc(80);
    char * command;
    char * arg1;
    char * arg2;

    FILE *fp;
    fp = fopen("contact_list.txt", "w");

    record *rec = (record *) malloc(sizeof(record));

    if (argc != 4) {
        printf("Usage: %s server arg1 arg2\n", argv[0]);
        return (1);
    }

    if (!(cl = clnt_create(argv[1], WHATSUPPROG,WHATSUPVERS,"tcp"))) {
        clnt_pcreateerror(argv[1]);
        return(1);
    }

    rec->first_num = atoi(argv[2]);
    rec->second_num= atoi(argv[3]);


    do {
        printf("> ");
        fflush(stdout); //Limpa stdout
        //scanf("%79s",buffer); //Aceita até 79 caracteres
        fgets (buffer, 80, stdin);
        //Remove trailing newline, if there.
        if ((strlen(buffer)>0) && (buffer[strlen (buffer) - 1] == '\n'))
            buffer[strlen (buffer) - 1] = '\0';

        command  = strtok(buffer, " "); //strtok monta uma sequência de chamadas de funções para splitar uma string.
        arg1 = strtok(NULL, " ");
        arg2 = strtok(NULL, " ");

        #ifdef DEBUG
        printf("[DEBUG] buffer = %s\n",buffer);
        printf("[DEBUG] command = %s\n",command);
        printf("[DEBUG] arg1 = %s\n",arg1);
        printf("[DEBUG] arg2 = %s\n",arg2);
        #endif

        if (strcmp("exit",command) == 0) {
            #ifdef DEBUG
            printf("[DEBUG] Recebeu comando exit\n");
            #endif

            exit = 1;
        }
        else if ((strcmp("i",command) == 0) && (strlen(arg1) > 0) && (strlen(arg2) > 0)) {
            #ifdef DEBUG
            printf("[DEBUG] Recebeu comando i\n");
            #endif

            //insert_contact_in_list(contact_name);
        }
        else if ((strcmp ("g",command) == 0) && (strlen(arg1) > 0) && (strlen(arg2) > 0)) {
            #ifdef DEBUG
            printf("[DEBUG] Recebeu comando g\n");
            #endif

            //insert_contact_in_group(contact_name, group_name);
        }
        else if ((strcmp ("l",command) == 0) && (strlen(arg1) > 0)) {
            #ifdef DEBUG
            printf("[DEBUG] Recebeu comando l\n");
            #endif

            //list_messages(conta);
        }
        else if ((strcmp ("s",command) == 0) && (strlen(arg1) > 0) && (strlen(arg2) > 0)) {
            #ifdef DEBUG
            printf("[DEBUG] Recebeu comando s\n");
            #endif

            //send_message(name, message);
        }
        else if (strcmp ("c",command) == 0) {
            #ifdef DEBUG
            printf("[DEBUG] Recebeu comando s\n");

            #endif

            //list_all(name, message);
        }
        else {
            #ifdef DEBUG
            printf("[DEBUG] Comando não reconhecido\n");
            #endif
        }

    } while (exit == 0);

    #ifdef DEBUG
    printf("[DEBUG] saiu\n");
    #endif

    /** Sum **/

//     answer = add_args_1(rec,cl);

//     if (answer == (int *) NULL) {
//         fprintf(stderr,"Error: could not produce meaningful results");
//         return(1);
//     }

//     printf("%s + %s = %d\n", argv[2], argv[3], *answer);

//    /** Sub **/

//     answer = sub_args_1(rec,cl);

//     if (answer == (int *) NULL) {
//         printf("error: could not produce meaningful results");
//         return(1);
//     }

//     printf("%s - %s = %d\n", argv[2], argv[3], *answer);

//    /** State **/

//     answer = state_1(pvoid,cl);

//     if (answer == (int *) NULL) {
//         printf("Error: state could not produce meaningful results");
//         return(1);
//     }

//     printf("State = %d\n", *answer);

    free(buffer);
    free(command);
    free(arg1);
    free(arg2);

    return (0);
}
