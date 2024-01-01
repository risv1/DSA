#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Process {
    int id;
    int priority;
    int arrivalTime; 
    int waitingTime;  

    Process(int processId, int processPriority, int processArrivalTime)
        : id(processId), priority(processPriority), arrivalTime(processArrivalTime), waitingTime(0) {}
};

struct ComparePriority {
    bool operator()(const Process& p1, const Process& p2) {
        if (p1.priority == p2.priority) {
            return p1.arrivalTime > p2.arrivalTime;  // If priorities are the same, choose the one that arrived first
        }
        return p1.priority > p2.priority;  
    }
};

int main() {
    std::priority_queue<Process, std::vector<Process>, ComparePriority> readyQueue;

    int numProcesses;
    std::cout << "Enter the number of processes: ";
    std::cin >> numProcesses;

    std::vector<Process> processes;
    for (int i = 0; i < numProcesses; i++) {
        int id, priority, arrivalTime;
        std::cout << "Enter priority for Process " << i + 1 << ": ";
        std::cin >> priority;
        std::cout << "Enter arrival time for Process " << i + 1 << ": ";
        std::cin >> arrivalTime;
        processes.push_back(Process(i + 1, priority, arrivalTime));
    }

    int currentTime = 0;

    std::cout << "Priority Scheduling Result:" << std::endl;

    while (!readyQueue.empty() || !processes.empty()) {
        for (auto it = processes.begin(); it != processes.end();) {
            if (it->arrivalTime <= currentTime) {
                readyQueue.push(*it);
                it = processes.erase(it);
            } else {
                break;
            }
        }

        if (!readyQueue.empty()) {
            Process currentProcess = readyQueue.top();
            readyQueue.pop();
            currentProcess.waitingTime = currentTime - currentProcess.arrivalTime;
            std::cout << "Process " << currentProcess.id << " (Priority " << currentProcess.priority
                      << ") Waiting Time: " << currentProcess.waitingTime << std::endl;
            currentTime++;
        } else {
            currentTime++;
        }
    }

    return 0;
}
