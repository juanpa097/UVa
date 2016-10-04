#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class UnionFind   // OOP style
{

private:
    vi p, rank; // remember: vi is vector<int>

public:
    UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {

        if (!isSameSet(i, j))   // if from different set
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
            else
            {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main ()
{
    int TC;
    scanf("%d", &TC);
    cin.ignore();
    cin.ignore();
    while (TC--)
    {
        int n;
        scanf("%d",&n);
        cin.ignore();
        UnionFind uf (n);
        int g = 0;
        int bad = 0;
        string p;

        while (true)
        {
            getline(cin, p);
            //cout << "P: " << p << endl;
            if (p.length() == 0) break;
            stringstream str(p);

            int a, b;
            string tok;
            string r;
            str >> r;
            str >> a;
            str >> b;
            --a;
            --b;
            if (r == "q")
            {
                if (uf.isSameSet(a,b)) {
                    ++g;
                }
                else {
                    ++bad;
                }
            }
            else if (r == "c")
            {
                uf.unionSet(a,b);
            }
        }
        if (TC != 0){
        printf("%d,%d\n\n",g,bad);
        }
        else {
            printf("%d,%d\n",g,bad);
        }
    }
}
