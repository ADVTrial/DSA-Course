/*
A computing system executes multiple tasks simultaneously. Your task is to implement a priority queue that prioritizes these tasks based on their importance or urgency.

The priority queue should prioritize tasks based on the following criteria:

Tasks with higher priority should be executed first.
In the case of tasks with equal priority, tasks with earlier deadlines should be executed first.


Note: A higher integer specifies high priority.

 Input Format
The first line consists of an integer n, the number of tasks to be executed by the computing system.

For each of the n lines, the input consists of the following values separated by a space:

An integer representing the priority of the task
An integer representing the deadline of the task
A string representing the name of the task.
 Output Format
The output prints the list of tasks executed by the computing system, in the order they were executed.

 Constraints
1 <= n <= 105

1 <= length of taskname <= 100

 Sample Input
4
5 1 Task1
1 2 Task2
4 2 Task3
6 1 Task4
 Sample Output
Executed Tasks:
Task4
Task1
Task3
Task2

 Sample Input
4
100 1 Task1
100 1 Task2
100 1 Task3
100 1 Task4
Sample Output
Executed Tasks:
Task1
Task2
Task3
Task4

 Sample Input
4
100 5 Task1
100 2 Task2
100 1 Task3
100 7 Task4
Sample Output
Executed Tasks:
Task3
Task2
Task1
Task4

*/

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct Task
{
    int priority;
    int deadline;
    string name;
};

int main(){
    int n;
    cin>>n;
    Task task[n];
    for(int i=0;i<n;i++){
        cin>>task[i].priority>>task[i].deadline>>task[i].name;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(task[i].priority < task[j].priority)
            {
                swap(task[i],task[j]);
            }
            else if(task[i].priority == task[j].priority)
            {
                if(task[i].deadline > task[j].deadline)
                {
                    swap(task[i],task[j]);
                }
            }
        }
    }
    cout<<"Executed Tasks:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<task[i].name<<endl;
    }
    return 0;
}

