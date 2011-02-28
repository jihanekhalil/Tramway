#include "thread.h"

void *start_thread(void * param){
    Thread * t = static_cast<Thread*>(param);
    t->run();
}
void Thread::start(){
    pthread_create (&t, NULL, *start_thread, static_cast<void*>(this));
}

Thread::Thread()
{
}

