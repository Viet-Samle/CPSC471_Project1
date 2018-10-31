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
    string label;
    int LC_value;
    event();
};
event::event(void) {
    LC_value = -1;
    label = "i";
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
    int value;
    string tmp;
    bool correct = true;
    int event_count;
    int rcv_count = 0;
    int send_count = 0;
    int rcv_array[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int send_array[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    // Inputting LC-values
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
    cout << "You entered: " << endl;
    // Showing LC value input
    for (int i = 0; i < N; i++) {
      cout << "\tP" << i << ": ";
      for (int j = 0; j < all_processes[i].all_events; j++) {
        cout << all_processes[i].p_events[j].LC_value << " ";
      }
      cout << endl;
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < all_processes[i].all_events; j++) {
        if (all_processes[i].p_events[j].LC_value != all_processes[i].current_LCvalue + 1) {
          all_processes[i].p_events[j].label[0] = 'r';
          value = rcv_count + 1;
          tmp = to_string(value);
          all_processes[i].p_events[j].label += tmp;
          rcv_array[rcv_count++] = all_processes[i].p_events[j].LC_value;
        }
        all_processes[i].current_LCvalue = all_processes[i].p_events[j].LC_value;
      }
    }

    for (int i = 0; i < rcv_count; i++) {
      //cout << "Receive array at index: " << i << "\n \t Value of: " << rcv_array[i] << endl;
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < all_processes[j].all_events; k++) {
          // Only check internal events for send events
          if (all_processes[j].p_events[k].label == "i") {
            if (all_processes[j].p_events[k].LC_value == rcv_array[i] - 1) {
              all_processes[j].p_events[k].label = "s";
              send_array[i] = all_processes[j].p_events[k].LC_value;
              tmp = to_string(i + 1);
              all_processes[j].p_events[k].label += tmp;
              rcv_array[i] = -1;
            }
          }
        }
      }
      // if after looping through all processes, and a value still hasn't been found for send
      // No send exists for the receive; No solution is possible
      if (send_array[i] == -1) {
        cout << "INCORRECT" << endl;
        return 0;
      }
    }

    cout << "Label for given values are" << endl;
    for (int i = 0; i < N; i++) {
      cout << "\tP" << i << ": ";
      for (int j = 0; j < all_processes[i].all_events; j++) {
        cout << all_processes[i].p_events[j].label << " ";
      }
      cout << endl;
    }
    cout << endl;



    return 0;
}


