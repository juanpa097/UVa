#include "bits/stdc++.h"
using namespace std;

vector<string> maze;
int posi, posj;


void printMaze() {
  for (int i = 0; i < maze.size(); ++i) {
    cout << maze[i] << endl;
  }
  printf("_____\n");
}

void findStar() {
  for (int i = 0; i < maze.size(); ++i) {
    for (int j = 0; j < maze[i].size(); ++j) {
      if (maze[i][j] == '*') {
        posi = i;
        posj = j;
        break;
      }
    }
  }

}

void color(int i, int j) {
  if (maze[i][j] == 'X' || maze[i][j] == '#') return;
  if (i >= 0 && i < maze.size() && j >= 0 && j < maze[i].size()) {
    maze[i][j] = '#';
    color(i + 1, j);
    color(i - 1, j);
    color(i, j + 1);
    color(i, j - 1);
  } else return;
}

int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  cin.ignore();
  while (TC--) {
    maze.clear();
    string line;
    getline(cin, line);
    while (line != "_____") {
      maze.push_back(line);
      getline(cin, line);
    }
    findStar();
    color(posi, posj);
    printMaze();
  }
  return 0;
}
