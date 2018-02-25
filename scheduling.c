#include<stdio.h>
#include<stdlib.h>

#define totalProcess 20	//number of total process

/*
-structure that keeps the information of the processes
-burstTime: keeps the burst time of process
-remainingTime: keeps the remaining time of the process to be completed
*/
struct process
{
	int burstTime;
	int remainingTime;
}*str;

/*
-time: keeps the total spent time of all processes
-timeQuantum1: keeps the time quantum of first round robin algorithm
-timeQuantum2: keeps the time quantum of second round robin algorithm
*/
int time, timeQuantum1, timeQuantum2, count = 0;

void FCFS(){

	/*
	-apply fcfs algorithm to all remaining processes
	-in the first if statement, fcfs applies to all remaining processes and calculates the total 			time to show waiting and turn around time at the end
	*/
	for (count = 0; count < totalProcess; count++)
	{
		if ((str + count)->remainingTime > 0)
		{
			time = time + (str + count)->remainingTime;
			(str + count)->remainingTime = 0;
			printf("----------\n");
			printf("Process %d finished in FCFS algorithm. It's\nTurn around time is %dms and Waiting time is %dms.\n", count, time, time - (str + count)->burstTime);
		}
	}
}

void roundRobinSecond(){
	timeQuantum2 = 16; //set time quantum for second round robint algorithm


	/*
	-apply second round robin algorithm to all remaining processes
	-first if statement checks, if remaining time is smaller than second time quantum, then 		assign that process as done
	-else if statement applies the second round robin algorithm to the all other processes
	-at last, there is a calculating operation to calculate the total time to show waiting and 			turn around time at the end

	*/
	for (count = 0; count < totalProcess; count++)
	{
		if ((str + count)->remainingTime <= timeQuantum2 && (str + count)->remainingTime > 0)
		{
			time = time + (str + count)->remainingTime;
			(str + count)->remainingTime = 0;
			printf("----------\n");
			printf("Process %d finished in 2nd RR algorithm. It's\nTurn around time is %dms and Waiting time is %dms.\n", count, time, time - (str + count)->burstTime);
		}
		else if ((str + count)->remainingTime > 0)
		{
			(str + count)->remainingTime = (str + count)->remainingTime - timeQuantum2;
			time = time + timeQuantum2;
		}
	}

	FCFS(); //call FCFS algorithm after applying second round robin to all processes

}

void roundRobinFirst(){
	timeQuantum1 = 8; //set time quantum for first round robint algorithm

	/*
	-apply first round robin algorithm to all remaining processes
	-first if statement checks, if remaining time is smaller than first time quantum, then 			assign that process as done
	-else if statement applies the first round robin algorithm to the all other processes
	-at last, there is a calculating operation to calculate the total time to show waiting and 			turn around time at the end

	*/
	for (count = 0; count < totalProcess; count++)
	{
		if ((str + count)->remainingTime <= timeQuantum1 && (str + count)->remainingTime > 0)
		{
			time = time + (str + count)->remainingTime;
			(str + count)->remainingTime = 0;
			printf("----------\n");
			printf("Process %d finished in 1st RR algorithm. It's\nTurn around time is %dms and Waiting time is %dms.\n", count, time, time - (str + count)->burstTime);
		}
		else if ((str + count)->remainingTime > 0)
		{
			(str + count)->remainingTime = (str + count)->remainingTime - timeQuantum1;
			time = time + timeQuantum1;
		}
	}

	roundRobinSecond(); //call second round robin algorithm after applying first round robin to all processes

}

int main(){

	str = (struct process*) malloc(totalProcess * sizeof(struct process)); //this code allocates the memory for each process with pointer str pointing to base address

	//assign burst times to all process randomly
	(str + count)->burstTime = (rand() % (8 + 1 - 4)) + 4; //generate a process which has a burst time in 4ms <= burst time <= 8ms
	(str + count)->remainingTime = (str + count)->burstTime; //set remaining time as burst time

	count = count + 1;
	(str + count)->burstTime = (rand() % (24 + 1 - 9)) + 9; //generate a process which has a burst time in 8ms < burst time <= 24ms
	(str + count)->remainingTime = (str + count)->burstTime;

	count = count + 1;
	(str + count)->burstTime = (rand() % (50 + 1 - 25)) + 25; //generate a process which has a burst time in 24ms < burst time <= 50ms
	(str + count)->remainingTime = (str + count)->burstTime;

	for (count = 3; count < totalProcess; count++){
		(str + count)->burstTime = (rand() % (50 + 1 - 4)) + 4; //generate a process which has a burst time in 4ms <= burst time <= 50ms
		(str + count)->remainingTime = (str + count)->burstTime;
	}

	//below code generates and prints the burst times for all processes
	printf("Process Number\t\tBurst Time\n");
	for (count = 0; count < totalProcess; count++)
		printf("%d\t\t\t%d\n", count, (str + count)->burstTime);

	printf("\n");

	roundRobinFirst(); //call first round robin algorithm
	
	system("pause");
	return 0;
}