/*
 CPU SCHEDULING (ROUND ROBIN)
 
 Round Robin is a CPU scheduling algorithm where each process is assigned a fixed time slot in a cyclic way. It is basically the preemptive version of First come First Serve CPU Scheduling algorithm.
 Round Robin CPU Algorithm generally focuses on Time Sharing technique.
 The period of time for which a process or job is allowed to run in a pre-emptive method is called time quantum.
 Each process or job present in the ready queue is assigned the CPU for that time quantum, if the execution of the process is completed during that time then the process will end else the process will go back to the waiting table and wait for its next turn to complete the execution.
 Using Queues Write a C program to calculate the Average Turn Around Time of a set of processes given an Array of Process times and time quantum.
 
 Input Format:
     Line1: No of Processes
     Line2: Comma separated process times
     Line3: Time Quantum
     
 Constraints:
    None

 Output Format:
    Floor value of Average Turn around Time
 
 
 Sample Input:
 4
 1,2,3,4
 4
 
 Sample Output:
 5
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Task;

float calculateAverageTurnaroundTime(Task tasks[], int num_tasks, int time_slice)
{
    int current_time = 0;
    int completed_tasks = 0;
    int total_turnaround_time = 0;
    
    while (completed_tasks < num_tasks)
    {
        for (int i = 0; i < num_tasks; i++)
        {
            if (tasks[i].remaining_time > 0)
            {
                int execution_time = (tasks[i].remaining_time < time_slice) ? tasks[i].remaining_time : time_slice;
                
                current_time += execution_time;
                tasks[i].remaining_time -= execution_time;
                
                if (tasks[i].remaining_time == 0)
                {
                    total_turnaround_time += current_time;
                    completed_tasks++;
                }
            }
        }
    }
    
    return (float)total_turnaround_time / num_tasks;
}

int main()
{
    int num_tasks;
    scanf("%d", &num_tasks);

    Task tasks[num_tasks];
    char input_buffer[100];
    scanf("%s", input_buffer);

    char *token = strtok(input_buffer, ",");
    for (int i = 0; i < num_tasks; i++)
    {
        tasks[i].id = i + 1;
        tasks[i].burst_time = atoi(token);
        tasks[i].remaining_time = tasks[i].burst_time;
        token = strtok(NULL, ",");
    }

    int time_slice;
    scanf("%d", &time_slice);

    float avg_turnaround_time = calculateAverageTurnaroundTime(tasks, num_tasks, time_slice);
    printf("%.0f\n", avg_turnaround_time);

    return 0;
}
