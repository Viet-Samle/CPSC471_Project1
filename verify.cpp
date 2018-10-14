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
    cout << "Enter the LC values for the first process" << endl;
    for (int i = 0; i < M; i++) {
        cin >> LC_input;
        if (LC_input != 0) {
            all_processes[0].p_events[i].LC_value = LC_input;
            all_processes[0].all_events++;
        }
    }
    // Inputting P1
    cout << "Enter the LC values for the second process" << endl;
    for (int i = 0; i < M; i++) {
        cin >> LC_input;
        if (LC_input != 0) {
            all_processes[1].p_events[i].LC_value = LC_input;
            all_processes[1].all_events++;
        }
    }
    // Inputting P2
    cout << "Enter the LC for the third process" << endl;
    for (int i = 0; i < M; i++) {
        cin >> LC_input;
        if (LC_input != 0) {
            all_processes[2].p_events[i].LC_value = LC_input;
            all_processes[2].all_events++;
        }
    }

    // Showing LC value input
    cout << endl << "Your input is as follows: " << endl;
    cout << "P0: ";
    for (int i = 0; i < all_processes[0].all_events; i++) {
        cout << all_processes[0].p_events[i].LC_value << " ";
    }
    cout << endl << "P1: ";
    for (int i = 0; i < all_processes[1].all_events; i++) {
        cout << all_processes[1].p_events[i].LC_value << " ";
    }
    cout << endl << "P2: ";
    for (int i = 0; i < all_processes[2].all_events; i++) {
        cout << all_processes[2].p_events[i].LC_value << " ";
    }
    cout << endl << endl;


    // Inputting events to Verify
    // Inputting events for P0
    cout << "Enter the events for the first process" << endl;
    for (int i = 0; i < M; i++) {
        cin >> event_input;
        if (event_input != "NULL") {
            all_processes[0].p_events[i].given_event = event_input;
        }
    }
    // Inputting events for P1
    cout << "Enter the events for the second process" << endl;
    for (int i = 0; i < M; i++) {
        cin >> event_input;
        if (event_input != "NULL") {
            all_processes[1].p_events[i].given_event = event_input;
        }
    }
    // Inputting events for P2
    cout << "Enter the events for the third process" << endl;
    for (int i = 0; i < M; i++) {
        cin >> event_input;
        if (event_input != "NULL") {
            all_processes[2].p_events[i].given_event = event_input;
        }
    }

    // Showing event input
    cout << endl << "Your input is as follows: " << endl;
    cout << "P0: ";
    for (int i = 0; i < all_processes[0].all_events; i++) {
        cout << all_processes[0].p_events[i].given_event << " ";
    }
    cout << endl << "P1: ";
    for (int i = 0; i < all_processes[1].all_events; i++) {
        cout << all_processes[1].p_events[i].given_event << " ";
    }
    cout << endl << "P2: ";
    for (int i = 0; i < all_processes[2].all_events; i++) {
        cout << all_processes[2].p_events[i].given_event << " ";
    }
    cout << endl << endl;

    // Assigning labels (internal/send/receive) for each LC_value
    for (int i = 0; i < all_processes[0].all_events; i++) {
      if (all_processes[0].p_events[i].LC_value != all_processes[0].current_LCvalue + 1) {
        all_processes[0].p_events[i].label = 'r';
        rcv_array[rcv_count++] = all_processes[0].p_events[i].LC_value;
      }
      all_processes[0].current_LCvalue = all_processes[0].p_events[i].LC_value;
    }
    for (int i = 0; i < all_processes[1].all_events; i++) {
      if (all_processes[1].p_events[i].LC_value != all_processes[1].current_LCvalue + 1) {
        all_processes[1].p_events[i].label = 'r';
        rcv_array[rcv_count++] = all_processes[1].p_events[i].LC_value;
      }
      all_processes[1].current_LCvalue = all_processes[1].p_events[i].LC_value;
    }
    for (int i = 0; i < all_processes[2].all_events; i++) {
      if (all_processes[2].p_events[i].LC_value != all_processes[2].current_LCvalue + 1) {
        all_processes[2].p_events[i].label = 'r';
        rcv_array[rcv_count++] = all_processes[2].p_events[i].LC_value;
      }
      all_processes[2].current_LCvalue = all_processes[2].p_events[i].LC_value;
    }
    for (int i = 0; i < 10; i++) {
      cout << rcv_array[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < all_processes[0].all_events; i++) {
      for (int j = 0; j < rcv_count; j++) {
        if (all_processes[0].p_events[i].LC_value == rcv_array[j] - 1) {
          all_processes[0].p_events[i].label = 's';
          rcv_array[j] = 100;
        }
      }
    }

    for (int i = 0; i < all_processes[1].all_events; i++) {
      for (int j = 0; j < rcv_count; j++) {
        if (all_processes[1].p_events[i].LC_value == rcv_array[j] - 1) {
          all_processes[1].p_events[i].label = 's';
          rcv_array[j] = 100;
        }
      }
    }

    for (int i = 0; i < all_processes[0].all_events; i++) {
      for (int j = 0; j < rcv_count; j++) {
        if (all_processes[2].p_events[i].LC_value == rcv_array[j] - 1) {
          all_processes[2].p_events[i].label = 's';
          rcv_array[j] = 100;
        }
      }
    }

    for (int i = 0; i < all_processes[0].all_events; i++) {
      cout << all_processes[0].p_events[i].label << " ";
    }
    cout << endl;
    for (int i = 0; i < all_processes[1].all_events; i++) {
      cout << all_processes[1].p_events[i].label << " ";
    }
    cout << endl;
    for (int i = 0; i < all_processes[2].all_events; i++) {
      cout << all_processes[2].p_events[i].label << " ";
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
          cout << arg << " | "<< all_processes[i].p_events[j].LC_value << endl;
          rcv_array[arg] = all_processes[i].p_events[j].LC_value;
        }
      }
    }
    cout << "Receive Array: ";
    for (int i = 0; i < 10; i++) {
      cout << rcv_array[i] << " ";
    }
    cout << endl;
    cout << "Send Array: ";
    for (int i = 0; i < 10; i++) {
      cout << send_array[i] << " ";
    }
    cout << endl;


    for (int i = 1; i < rcv_count + 1; i++) {
      cout << rcv_array[i] << " | " << send_array[i] << endl;
      cout << correct << endl;
      if (!(rcv_array[i] > send_array[i])) {
        correct = false;
        break;
      }
    }
    if (correct) cout << "CORRECT" << endl;
    else cout << "INCORRECT" << endl;


    return 0;
}

