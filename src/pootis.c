#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <asm/semaphore.h>

void handler ( int signum) {
  printf("Signal Handled");
}

int main() {
 /******************************************
 |       This area is to set up arena conditions       |
 |        It:                                                                                     |
 |             - Sets process priority to 19                        |
 ******************************************/
 #ifdef ARENATEST
printf("Setting up arena conditions\nChanging Priority to 19\n");
 int prioarena = getpriority(PRIO_PROCESS, 0);
printf("Current priority is %d\nSetting arena priority to 19\n", prioarena);
 if (setpriority(PRIO_PROCESS, 0, 19) < 0)
  printf("Set Prioity failed\n");
 else
  printf("Arena priority set to 19\n");

 // block all signals to the extent allowed by the kernel, inherited by all children
 printf("Blocking signals\n");
 sigset_t   mask;
 sigfillset(&mask);
 sigprocmask(SIG_SETMASK, &mask, NULL);


 printf("Arena Conditions set\n\n\n");
#endif


 /*********************************
      Start of my program
      Stragety:
        -Fork
          Parent:
            -fall into uninterruptible sleep?
          Child:
            -kill everything but itself
        -Get Parent PID
        -For Every PID > parents
        -Kill that PID
 *********************************/
 int parentPID = getppid();

 //pthread_mutex_t mutex;
 //pthread_mutex_init(&mutex, NULL, NULL);
 //pthread_mutex_lock(&mutex);

}
