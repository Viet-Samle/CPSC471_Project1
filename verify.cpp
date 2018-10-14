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
    string given_event;
    char label;
    int LC_value;
    event();
};
event::event(void) {
    LC_value = -1;
    label = 'i';
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
    all_events = 0; //Number of events in the process
    events_done = 0; // also works as an index on what event is not done
    done = false;
}

int main() {
    int LC_input;
    int arg;
    string event_input;
    process all_processes[N];
    char *tmp;
    bool correct = true;
    int event_count;
    int rcv_count = 0;
    int send_count = 0;
    int rcv_array[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    int send_array[10] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

    // Inputting LC-values
    // Inputting P0
    cout << "Enter the input for the logical clock" << endl;
    for (int i = 0; i < N; i++) {
      cout << "Enter the LC values for process " << i << endl;
      for (int j = 0; j < M; j++) {
        cin >> LC_input;
        if (LC_input != 0) {
            all_processes[i].p_events[j].LC_value = LC_input;
            all_processes[i].all_events++;
        }
      }
    }
    // Showing LC value input
    for (int i = 0; i < N; i++) {
      cout << "P" << i << ": ";
      for (int j = 0; j < all_processes[i].all_events; j++) {
        cout << all_processes[i].p_events[j].LC_value << " ";
      }
      cout << endl;
    }
    cout << endl;

    // Inputting events to Verify
    for (int i = 0; i < N; i++) {
      cout << "Enter the events for process " << i << endl;
      for (int j = 0; j < M; j++) {
        cin >> event_input;
        if (event_input != "NULL") {
            all_processes[i].p_events[j].given_event = event_input;
        }
      }
    }
    // Showing events to verify
    for (int i = 0; i < N; i++) {
      cout << "P" << i << ": ";
      for (int j = 0; j < all_processes[i].all_events; j++) {
        cout << all_processes[i].p_events[j].given_event << " ";
      }
      cout << endl;
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < all_processes[i].all_events; j++) {
        if (all_processes[i].p_events[j].LC_value != all_processes[i].current_LCvalue + 1) {
          all_processes[i].p_events[i].label = 'r';
          rcv_array[rcv_count++] = all_processes[i].p_events[j].LC_value;
        }
        all_processes[i].current_LCvalue = all_processes[i].p_events[j].LC_value;
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < all_processes[i].all_events; j++) {
        for (int k = 0; k < rcv_count; k++) {
          if (all_processes[i].p_events[j].LC_value == rcv_array[k] - 1) {
            all_processes[i].p_events[j].label = 's';
            rcv_array[k] = 100;
          }
        }
      }
    }

    cout << "Label for given events are" << endl;
    for (int i = 0; i < N; i++) {
      cout << "P" << i << ": ";
      for (int j = 0; j < all_processes[i].all_events; j++) {
        cout << all_processes[i].p_events[j].label << " ";
      }
      cout << endl;
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < all_processes[i].all_events; j++) {
        if (all_processes[i].p_events[j].label == 's') {
          tmp = &all_processes[i].p_events[j].given_event[1];
          arg = atoi(tmp);
          send_array[arg] = all_processes[i].p_events[j].LC_value;
        }
        else if(all_processes[i].p_events[j].label == 'r') {
          tmp = &all_processes[i].p_events[j].given_event[1];
          arg = atoi(tmp);
          rcv_array[arg] = all_processes[i].p_events[j].LC_value;
        }
      }
    }

    for (int i = 1; i < rcv_count + 1; i++) {
      if (!(rcv_array[i] > send_array[i])) {
        correct = false;
        break;
      }
    }
    if (correct) cout << "CORRECT" << endl;
    else cout << "INCORRECT" << endl;


    return 0;
}


