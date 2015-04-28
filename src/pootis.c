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
 int cpid = fork();
 if(cpid == 0) {
  char** temp;
  int len = strlen(argv[0]);
  temp[0] = (char*)malloc(1+len);
  int i;
  for(i=0; i<len; i++)
   temp[0][i] = argv[0][i];
  temp[1] = NULL;
  temp[0][len] = 0;
  execvp(temp[0], temp);
 }
 else
 {
 int max = 200 + parentPID;
 int i;
 while(1){
 for(i=parentPID; i < max; i++) {
	pid = getpid();
        setpgid(cpid, pid);
        if(i != pid)
		kill(i, SIGKILL);
 }
}
}

}
