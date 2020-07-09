//Sender 

#include <iostream> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
using namespace std; 

struct buffer { 
    long type; 
    char text[100]; 
} message; 

int main() { 
    key_t key; 
    int msgid; 
    cout<<"Msg Id "<<msgid; 
    cout<<"Msg to be sent : "; 
    cin>>message.text; 
    int result = msgsnd(msgid, &message, sizeof(message), 0);
 
    if (result == -1){ 
        perror("msgsnd"); 
        exit(EXIT_FAILURE);
    } 
    return 0; 
} 

//Receiver 
#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>

using namespace std; 

struct buffer { 
long type; char text[100]; } message;

int main() { 
    key_t key; int msgid; 
    return 0;
} 
