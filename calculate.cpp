#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define N 3
#define M 4

class event {
  public:
    string e;
    event();
};

class process {
  public:
    event *p_events;
    int all_events;
    int events_done;
    int LC_value;
    bool done;
    process();
};
process::process(void) {
  p_events = new event[M];
  LC_value = 0;
  all_events = 0;
  events_done = 0; // also works as an index on what event is not done
  done = false;
}

int main() {
  int last_sent = 0;
  string input;
  process all_processes[N];
  bool all_done = false;
  int current_p = 0;
  int send_arg;
  int receive_arg;

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

      
      if (all_processes[current_p].p_events[all_processes[current_p].events_done].e[0] == 's') {
        send_arg = atoi((char *)all_processes[current_p].p_events[all_processes[current_p].events_done].e[1]);
        if (send_arg == last_sent + 1) {
           // TODO : Assign the LC value
        }
      }
      else if (all_processes[current_p].p_events[all_processes[current_p].events_done].e[0] == 'r') {
        receive_arg = atoi((char *)all_processes[current_p].p_events[all_processes[current_p].events_done].e[1]);
        if (receive_arg == last_sent) {
          // TODO: Assign the LC value
        }
        else {

        }
      }
      // the event is internal and will be assigned an LC value
      else {
        // TODO: Assign the LC Value
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
