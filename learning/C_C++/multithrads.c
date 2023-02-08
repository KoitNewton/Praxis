#include <stdio.h>
//#include <unistd.h>
//#include <pthread.h>

void *customThreadFunction(){
    for(int i=0; i<15;i++){
        printf("I am a Custon Thread Function Created By Programmer.\n");
        //sleep(1);
    }

    return NULL;
}
int main(){
    customThreadFunction();
    return 0;


}