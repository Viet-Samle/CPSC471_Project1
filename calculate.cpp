#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define N 3
#define M 4

class event {
public:
    string e;
    int LC_value;
    event();
};
event::event(void) {
    LC_value = -1;

}
class process {
public:
    event *p_events;
    int all_events;
    int events_done;
    int current_LCvalue;
    bool done;
    process();
};
process::process(void) {
    p_events = new event[M];
    current_LCvalue = 0;
    all_events = 0; // Number of events in the process
    events_done = 0; // Works as a counter for what events are done in each process
    done = false;
}

int main() {
    string input;
    process all_processes[N];
    bool all_done = false;
    int current_p = 0;
    int current_event;
    int send_arg;
    int receive_arg;
    int sendarray[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    char* char_temp;

    cout << "Enter the input for the logical clock" << endl;
    for (int i = 0; i < N; i++) {
      cout << "Enter the events for process " << i << endl;
      for (int j = 0; j < M; j++) {
        cin >> input;
        if (input != "NULL") {
            all_processes[i].p_events[j].e = input;
            all_processes[i].all_events++;
        }
      }
    }

    // Showing the input
    // Showing P0
    cout << endl << "Your input is as follows: " << endl;
    for (int i = 0; i < N; i++) {
      cout << "P" << i << ": ";
      for (int j = 0; j < all_processes[i].all_events; j++) {
        cout << all_processes[i].p_events[j].e << " ";
      }
      cout << endl;
    }
    cout << endl;
    cout << "The solution is: " << endl;

    //
    while (!all_done) {
        // If the process still has events to assign LC values to
        if (all_processes[current_p].done == false) {
          current_event = all_processes[current_p].events_done;
            // If the event is a send event
            if (all_processes[current_p].p_events[current_event].e[0] == 's') {
                char_temp = &all_processes[current_p].p_events[current_event].e[1];
                send_arg = atoi(char_temp);
                all_processes[current_p].p_events[current_event].LC_value = all_processes[current_p].current_LCvalue + 1;
                all_processes[current_p].current_LCvalue = all_processes[current_p].p_events[current_event].LC_value;
                // Assigning send LC values to the send array
                sendarray[send_arg] = all_processes[current_p].p_events[current_event].LC_value;
                // If the process's events are all complete, then it's done
                if (all_processes[current_p].events_done == all_processes[current_p].all_events - 1) {
                    all_processes[current_p].done = true;
                }
                else {
                    all_processes[current_p].events_done++;
                }
            }
            // If the event is a receive event
            else if (all_processes[current_p].p_events[current_event].e[0] == 'r') {
                char_temp = &all_processes[current_p].p_events[current_event].e[1];
                receive_arg = atoi(char_temp);
                // If the send array has an entry for the event
                // So r2 can only poceed if s2 has already been sent and recorded in send array
                if (sendarray[receive_arg] < 100) {
                    all_processes[current_p].p_events[current_event].LC_value = max(all_processes[current_p].current_LCvalue, sendarray[receive_arg]) + 1;
                    all_processes[current_p].current_LCvalue = all_processes[current_p].p_events[current_event].LC_value;
                    if (all_processes[current_p].events_done == all_processes[current_p].all_events) {
                        all_processes[current_p].done = true;
                    }
                    else {
                        all_processes[current_p].events_done++;
                    }
                }
                else {
                    //do not have entry for send array
                    current_p = (current_p + 1) % 3;
                }
            }
            // the event is internal and will be assigned an LC value
            else {
                all_processes[current_p].p_events[current_event].LC_value = all_processes[current_p].current_LCvalue + 1;
                all_processes[current_p].current_LCvalue = all_processes[current_p].p_events[current_event].LC_value;
                if (all_processes[current_p].events_done == all_processes[current_p].all_events - 1) {
                    all_processes[current_p].done = true;
                }
                else {
                    all_processes[current_p].events_done++;
                }
            }
        }
        else {
            current_p = (current_p + 1) % 3;
        }
        if (all_processes[0].done == true && all_processes[1].done == true && all_processes[2].done == true) all_done = true;
    }
    // Printing the LC values for each event
    for (int i = 0; i < N; i++) {
      cout << "P" << i <<  ": ";
      for (int j = 0; j < all_processes[i].all_events; j++) {
        cout << all_processes[i].p_events[j].LC_value << " ";
      }
      cout << endl;
    }
    return 0;
}

