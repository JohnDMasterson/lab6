#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <string.h>
#include <malloc.h>


int main(int argc,char** argv) {
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
	-get ppid
        -Fork
          Parent:
		-Foreverything starting at ppid and lower
			-Change parent pid to last arg
			-Kill program at PID
          Child:
		-change parent process to child process id
           	-repeat fork();
 *********************************/
 int parentPID = getppid();
 int pid = getpid();

 //printf("PID is %d and PPID is %d\n", pid, parentPID);
 //printf("Changing the group PID");
 setpgrp();
 int newpgid = getpgid(0);
 //printf("New Group ID is %d\n", newpgid);
 kill(-1*parentPID, SIGKILL);
 while(1) {
 	int pid = fork();
		int i = parentPID+1;
		int max = i + 200;
		for(i; i<max; i++) {
			int grp = getpgid(i);
			if(grp != newpgid) {
 				kill(i, SIGKILL);
			}
		}
 }
}
