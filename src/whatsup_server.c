#include "../rpcgen/whatsup.h"

// int num_calls_add = 0;

// int *add_args_1_svc(record *rec, struct svc_req *rqstp) {

//     static int result;

//     result = rec->first_num + rec->second_num;

//     num_calls_add++;

//     return &result;
// }

// int *sub_args_1_svc(record *rec, struct svc_req *rqstp) {

//     static int result;

//     result = rec->first_num - rec->second_num;

//     return &result;
// }

// int *state_1_svc(void *pvoid, struct svc_req *rqstp) {

//     return &num_calls_add;
// }

// int *send_msg_1_svc(record *rec, struct svc_req *rqstp) {

//     static int result;

//     result = rec->first_num - rec->second_num;

//     return &result;
// }

int *send_msg_1_svc(message *msg, struct svc_req *rqstp)
{
    static int result;

    return &result;
}

int *list_msgs_1_svc(message *msg, struct svc_req *rqstp)
{
    static int result;

    return &result;
}

contacts *list_contacts_1_svc(user * usr, struct svc_req *rqstp)
{
    //Why static
    static contacts result;

    return &result;
}

contacts *list_groups_1_svc(user *usr, struct svc_req *rqstp)
{
    static contacts result;

    return &result;
}
