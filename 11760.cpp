//
//  main.cpp
//  11760
//
//  Created by Juan Pablo Peñaloza Botero on 4/13/16.
//  Copyright © 2016 Juan Pablo Peñaloza Botero. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool canMoveAt (vector< vector <int> > &vec, int x, int y, int r, int c) {
    for (int i = 0; i < r; i++) {
        if (vec[y][i] == 1) return false;
    }
    for (int i = 0; i < c; i++) {
        if (vec[i][x] == 1) return false;
    }
    return true;
}


int main(int argc, const char * argv[]) {
    int r, c, n;
    int t = 1;
    while (cin >> r >> c >> n) {
        if (r == 0 && c == 0 && n == 0) break;
        vector< vector <int> > vec(c, vector<int> (r,0));
        int x = 0, y = 0;
        for (int i = 0; i <= n; i++) {
            cin >> x >> y;
            if (i != n) vec[y][x] = 1;
            else vec[y][x] = 2;
        }
        
        bool flag = false;
        
        for (int i = 0; i < 4; i++) {
            if (x + 1 < c) {
                flag = canMoveAt(vec, x+1, y, r, c);
                if (flag) break;
            }
            if (x - 1 >= 0) {
                flag = canMoveAt(vec, x-1, y, r, c);
                if (flag) break;
            }
            if (y + 1 < r) {
                flag = canMoveAt(vec, x, y+1, r, c);
                if (flag) break;
            }
            if (y - 1 >= 0) {
                flag = canMoveAt(vec, x, y-1, r, c);
                if (flag) break;
            }
        }
        
        
        if (flag) cout << "Case " << t <<": " << "Escaped again! More 2D grid problems!" << endl;
        else cout << "Case " << t <<": " << "Party time! Let's find a restaurant!" << endl;
        
        t++;
    }
    return 0;
}
