#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>

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
    int current_event;
    int current_LCvalue;
    bool done;
    process();
};
process::process(void) {
    p_events = new event[M];
    current_LCvalue = 0;
    current_event = 0;
    all_events = 0; //Number of events in the process
    events_done = 0; // also works as an index on what event is not done
    done = false;
}

int main() {
    string input;
    process all_processes[N];
    bool all_done = false;
    int current_p = 0;
    int send_arg;
    int receive_arg;
    int sendarray[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    
    cout << "Enter the input for the logical clock" << endl;
    cout << "Enter the events for the first process" << endl;
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (input != "NULL") {
            all_processes[0].p_events[i].e = input;
            //cout << all_processes[0].events[i][0] << endl;
            all_processes[0].all_events++;
        }
        
    }
    
    cout << "Enter the events for the second process" << endl;
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (input != "NULL") {
            all_processes[1].p_events[i].e = input;
            all_processes[1].all_events++;
        }
        
    }
    cout << "Enter the events for the third process" << endl;
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (input != "NULL") {
            all_processes[2].p_events[i].e = input;
            all_processes[2].all_events++;
        }
        
    }
    
    
    while (!all_done) {
        if (all_processes[current_p].done == false) {
            
            // TODO: while (all_processes[current_p].p_events) increment this
                if (all_processes[current_p].p_events[all_processes[current_p].events_done].e[0] == 's') {
                    
                    istringstream convert(all_processes[current_p].p_events[all_processes[current_p].events_done].e[1]);
                    
                    if (!(convert >> send_arg)) send_arg = 0;
                    cout << "hi arg" << send_arg << endl;
                    
                    sendarray[send_arg] = all_processes[current_p].p_events[all_processes[current_p].current_event].LC_value = all_processes[current_p].current_LCvalue + 1;
                    
                    all_processes[current_p].p_events[all_processes[current_p].current_event].LC_value = all_processes[current_p].current_LCvalue + 1;
                    
                    all_processes[current_p].current_LCvalue = all_processes[current_p].p_events[all_processes[current_p].current_event].LC_value;
                    all_processes[current_p].events_done++;
                }
                else if (all_processes[current_p].p_events[all_processes[current_p].events_done].e[0] == 'r') {
                    
                    istringstream convert(all_processes[current_p].p_events[all_processes[current_p].events_done].e[1]);
                    
                    if (!(convert >> receive_arg)) receive_arg = 0;
                    cout << "hi arg" << receive_arg << endl;
                    
                    if (sendarray[receive_arg] < 100)
                    {
                        
                    all_processes[current_p].p_events[all_processes[current_p].current_event].LC_value = all_processes[current_p].current_LCvalue + 1;
                        
                        all_processes[current_p].current_LCvalue = all_processes[current_p].p_events[all_processes[current_p].current_event].LC_value;
                        all_processes[current_p].events_done++;
                    }
                    
                    else {
                        //do not have entry for send array
                        
                    }
                }
                // the event is internal and will be assigned an LC value
                else {
                    // TODO: Assign the LC Value
                    all_processes[current_p].p_events[all_processes[current_p].current_event].LC_value = all_processes[current_p].current_LCvalue + 1;
                    
                    all_processes[current_p].current_LCvalue = all_processes[current_p].p_events[all_processes[current_p].current_event].LC_value;
                    all_processes[current_p].events_done++;
                }
                
                
                if (all_processes[current_p].events_done == M) all_processes[current_p].done = true;
                current_p = current_p++ % 3;
            }
            else {
                current_p = current_p++ % 3;
            }
            
            if (all_processes[0].done == true && all_processes[1].done == true && all_processes[2].done == true) all_done = true;
            
        }
    
    
    
    
    return 0;
}
