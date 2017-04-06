#include "bits/stdc++.h"
using namespace std;
/*
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
*/


int main(int argc, char const *argv[]) {
  int t;
  int c = 1;
  while (scanf("%d", &t) != EOF) {
    if (t == 0) break;
    vector<queue<int> > q(t);
    vector< set<int> > members(t);
    queue<int> master;
    queue<int> toPrint;
    for (int i = 0; i < t; ++i) {
      int n;
      scanf("%d",&n);
      for (int j = 0; j < n; ++j) {
        int temp;
        scanf("%d",&temp);
        members[i].insert(temp);
      }
    }
    string line;
    while (cin >> line) {
      if (line == "STOP") break;
      int ins;
      if (line == "ENQUEUE") {
        scanf("%d",&ins);
        int team;
        for (int i = 0; i < t; ++i)
          if (members[i].find(ins) != members[i].end()) {
            team = i;
          }
        if (q[team].size() == 0)
          master.push(team);
        q[team].push(ins);
      }
      if (line == "DEQUEUE") {
          int front = master.front();
          toPrint.push(q[front].front());
          q[front].pop();
          if (q[front].size() == 0)
            master.pop();
      }
    }
    printf("Scenario #%d\n",c++);
    while(!toPrint.empty()){
      printf("%d\n",toPrint.front());
      toPrint.pop();
    }
    printf("\n");
  }
  return 0;
}
