#include <iostream>
#include <string>

using namespace std;

#define N 3
#define M 4


class process {
  public:
    string *events;
    int all_events;
    int events_done;
    bool done;
    process();
};
process::process(void) {
  events = new string[M];
  all_events = 0;
  events_done = 0;
  done = false;
}

void process_print(process *p) {
  for (int i = 0; i < p->all_events; i++) {
    cout << p->events[i] << " ";
  }
  cout << endl;
}

int main() {
  int last_sent = 1;
  string input;
  process all_processes[N];
  bool all_done = false;
  process *p0;
  process *p1;
  process *p2;

  cout << "Enter the input for the logical clock" << endl;
  cout << "Enter the events for the first process" << endl;
  for (int i = 0; i < M; i++) {
    cin >> input;
    cout << "seg fault 1" << endl;
    if (input != "NULL") {
      cout << input << endl;
      p0->events[i] = input;
      cout << "seg fault 3" << endl;
      p0->all_events++;
    }
  }
  cout << "Enter the events for the second process" << endl;
  for (int i = 0; i < M; i++) {
    cin >> input;
    if (input != "NULL") {
      p1->events[i] = input;
      p1->all_events++;
    }
  }
  cout << "Enter the events for the third process" << endl;
  for (int i = 0; i < M; i++) {
    cin >> input;
    if (input != "NULL") {
      p2->events[i] = input;
      p2->all_events++;
    }
  }

  /*
  while (!all_done) {

  }
  */



  return 0;
}
