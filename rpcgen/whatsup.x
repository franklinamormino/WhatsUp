struct record {       /* arguments for RPC must be one single */
  int first_num;      /* first argument */
  int second_num;     /* second argument */
};

struct message {
    char * destination;
    char * origin;
    char * message;
};

struct contacts {
    char * persons;
    char * groups;
};

struct user {
    char * name;
    char * ip;
};

const MAXSTRLEN = 255;

program WHATSUPPROG {               /* value to register the program */
    version WHATSUPVERS {           /* version must be assigned a value */
        int SEND_MSG(message)           = 1;
        int LIST_MSGS(message)          = 2;
        contacts LIST_CONTACTS(user)  = 3;
        contacts LIST_GROUPS(user)    = 4;
    } =1;                           /* version value */
} = 0x20000003;                     /* program value */
