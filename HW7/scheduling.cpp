#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};



void print_gantt_chart(const vector<Process>& processes) {
    cout << "Gantt Chart: ";

    int current_time = 0;
    cout << current_time;

    for (const Process& p : processes) {
        if (current_time < p.arrival_time) {
            cout << " | Idle | " << p.arrival_time;
            current_time = p.arrival_time;
        }

        cout << " | P" << p.pid << " | ";
        current_time += p.burst_time;
        cout << current_time;
    }

    cout << '\n';
}


void print_averages(const vector<Process>& processes) {
    double total_waiting = 0;
    double total_turnaround = 0;
    double total_response = 0;

    for (const Process& p : processes) {
        total_waiting += p.waiting_time;
        total_turnaround += p.turnaround_time;
        total_response += p.response_time;
    }

    int n = processes.size();

    cout << fixed;
    cout.precision(2);

    cout << "\nAverage Waiting Time: "
         << total_waiting / n << '\n';
    cout << "Average Turnaround Time: "
         << total_turnaround / n << '\n';
    cout << "Average Response Time: "
         << total_response / n << '\n';
}





void fcfs(vector<Process> processes) {
    sort(processes.begin(), processes.end(),
         [](const Process& a, const Process& b) {
             if (a.arrival_time == b.arrival_time) {
                 return a.pid < b.pid;
             }
             return a.arrival_time < b.arrival_time;
         });

    int current_time = 0;

    for (Process& p : processes) {
        if (current_time < p.arrival_time) {
            current_time = p.arrival_time;
        }

        p.waiting_time = current_time - p.arrival_time;
        p.response_time = p.waiting_time;

        current_time += p.burst_time;

        p.turnaround_time = current_time - p.arrival_time;
    }

    cout << "\n=== First Come First Served (FCFS) ===\n";
    print_gantt_chart(processes);

    cout << "PID\tAT\tBT\tWT\tTAT\tRT\n";

    for (const Process& p : processes) {
        cout << p.pid << '\t'
             << p.arrival_time << '\t'
             << p.burst_time << '\t'
             << p.waiting_time << '\t'
             << p.turnaround_time << '\t'
             << p.response_time << '\n';
    }

    print_averages(processes);
}


void sjf(vector<Process> processes) {
    vector<Process> scheduled;
    vector<bool> completed(processes.size(), false);

    int current_time = 0;
    size_t completed_count = 0;

    while (completed_count < processes.size()) {
        int shortest = -1;

        for (size_t i = 0; i < processes.size(); i++) {
            if (!completed[i] &&
                processes[i].arrival_time <= current_time) {

                if (shortest == -1 ||
                    processes[i].burst_time <
                        processes[shortest].burst_time ||
                    (processes[i].burst_time ==
                         processes[shortest].burst_time &&
                     processes[i].arrival_time <
                         processes[shortest].arrival_time) ||
                    (processes[i].burst_time ==
                         processes[shortest].burst_time &&
                     processes[i].arrival_time ==
                         processes[shortest].arrival_time &&
                     processes[i].pid < processes[shortest].pid)) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            int next_arrival = -1;

            for (size_t i = 0; i < processes.size(); i++) {
                if (!completed[i] &&
                    (next_arrival == -1 ||
                     processes[i].arrival_time <
                         processes[next_arrival].arrival_time)) {
                    next_arrival = i;
                }
            }

            current_time = processes[next_arrival].arrival_time;
            continue;
        }

        Process p = processes[shortest];

        p.waiting_time = current_time - p.arrival_time;
        p.response_time = p.waiting_time;

        current_time += p.burst_time;

        p.turnaround_time = current_time - p.arrival_time;

        scheduled.push_back(p);
        completed[shortest] = true;
        completed_count++;
    }

    cout << "\n=== Shortest Job First (SJF) ===\n";
    print_gantt_chart(scheduled);

    cout << "PID\tAT\tBT\tWT\tTAT\tRT\n";

    for (const Process& p : scheduled) {
        cout << p.pid << '\t'
             << p.arrival_time << '\t'
             << p.burst_time << '\t'
             << p.waiting_time << '\t'
             << p.turnaround_time << '\t'
             << p.response_time << '\n';
    }
    print_averages(scheduled);
}


int main() {
    int n;

    cout << "Enter the number of processes: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid number of processes.\n";
        return 1;
    }

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;

        cout << "Enter the arrival time and burst time for process "
             << i + 1 << ": ";

        if (!(cin >> processes[i].arrival_time
                  >> processes[i].burst_time) ||
            processes[i].arrival_time < 0 ||
            processes[i].burst_time <= 0) {
            cout << "Invalid input. Arrival time must be non-negative "
                    "and burst time must be positive.\n";
            return 1;
        }

        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].response_time = 0;
    }

    fcfs(processes);
    sjf(processes);

    return 0;
}
