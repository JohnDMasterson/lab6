# lab6
John Masterson
masters6

My strategy is very simple,
  - I start by changing my Process Group ID to separate it from the arena
  - Then I kill the arena and try to kill the processes that the arena is grouped with. When the arena is killed, no new combatants can start, and it's a battle of the first run processes. 
  - Then I will do forever:
    - Try to fork the process
    - With both processes, I try to kill all the processes with higher PID's than the original arena PID
    - I check the current running process group PID first to make sure I'm not killing my own process


  I suspect that the arena game is going to be heavily influenced and won by the first process started and how the CPU schedules the processes. This would be much more interesting if we were running this on a multi-core machine.
