#include <sys/time.h>
#include <sys/resource.h>

int main() {
  setpriority(PRIO_PROCESS, 0, -20);
}
