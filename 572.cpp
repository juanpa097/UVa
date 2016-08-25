#include "bits/stdc++.h"

using namespace std;

void DFS (int x, int y, int maxX, int maxY, vector< vector <bool> > & graph) {
  if (x > maxX || y > maxY || x < 1 || y < 1  ) return;
  if (graph[x][y] == false) return; // Corta recurcion
  if (graph[x][y] == true) graph[x][y] = false;

  DFS(x + 1,y,maxX,maxY,graph);
  DFS(x - 1,y,maxX,maxY,graph);

  DFS(x,y + 1,maxX,maxY,graph);
  DFS(x,y - 1,maxX,maxY,graph);

  DFS(x+1,y+1,maxX,maxY,graph);
  DFS(x-1,y+1,maxX,maxY,graph);

  DFS(x+1,y-1,maxX,maxY,graph);
  DFS(x-1,y-1,maxX,maxY,graph);
}

int main () {
  int n, m;
  while (scanf("%d%d",&n,&m)) {
    if (n == 0 && m == 0) break;
    vector< vector <bool> > graph ((n+2),vector<bool> ((m+2),false));
    string oilIn;
    for (int i = 1; i < (n + 1); i++) {
      cin >> oilIn;
      for (int j = 1; j < (m + 1); j++) {
        char oil = oilIn[j-1];
        if (oil == '@') {
          graph[i][j] = true;
        } else {
          graph[i][j] = false;
        }
      }
    }
    int cont = 0;
    for (int i = 1; i < (n + 1); i++) {
      for (int j = 1; j < (m + 1); j++) {
        if (graph[i][j] == true) {
          DFS(i,j,n,m,graph);
          cont++;
        }
      }
    }
    cout << cont << endl;
  }
}
