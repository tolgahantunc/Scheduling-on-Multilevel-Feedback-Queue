# Scheduling-on-Multilevel-Feedback-Queue (Homework)

Implement a C program that is explained below using WinAPI operating system.  

 
In  this  homework  we  want  you  to  implement  a  scheduling  on  multilevel  feedback  queue. However, you are not expected to exactly implement a multilevel feedback queue, but implement its simulation.  

 
You should assume that you have 3 queues. Each queue will have its own single scheduling algorithm. The  first  2  queues  will  have  RR  (Round Robin)  algorithm  and  the last queue  will  have FCFS (First Come First Serve) algorithm.  The first two queues must have different quantum times. The first queue’s quantum time should be set to 8 and the second should be set to 16.  

 
When a process enters the first queue it can run at most as the quantum time (8ms) defined for this queue. If it still needs time to finish its work (burst time > quantum time) it should be dropped to the second queue. When the process is dropped to the second queue it can run at most as the quantum time (16ms), but if it still needs time to finish its work, it is dropped to the third (last) queue.  


Your  program  should  have  20  processes.  Each  process’  burst  time  should  be  assigned randomly in between 4ms – 50ms. Please make sure that you have at least one process in each interval time given below.  

  4ms <= burst time <= 8ms  
  8ms < burst time <=24 ms  
  24ms < burst time  


HINT:  While  defining  your  processes,  you  can  use  a  structure  that  keeps  the  information  of  the processes. 
