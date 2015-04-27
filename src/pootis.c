#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

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
  //perror("SETPRIORITY"); 
 else
  printf("Arena priority set to 19\n");
 printf("Arena Conditions set\n\n\n");
#endif



}
