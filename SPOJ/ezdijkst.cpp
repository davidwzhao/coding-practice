#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 10000
#define NUM 10005

using namespace std;

struct node {
    vector<int> adj;    // adjacency list
    vector<int> w;      // weights
};

node n[NUM];

vector<int> dijkstra(int s) {
    vector<int> dist(NUM, -1);
    priority_queue<pair<int, int> > pq;

    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        cur.first *= -1;
        pq.pop();
        if (dist[cur.second] != -1)
            continue;
        dist[cur.second] = cur.first;

        for (int i = 0; i < n[cur.second].adj.size(); i++) {
            int curAdj = n[cur.second].adj[i];
            if (dist[curAdj] != -1)
                continue;
            pq.push(make_pair((-1) * (cur.first + n[cur.second].w[i]), curAdj));
        }
    }

    return dist;
}

void clear() {
    for (int i = 0; i < NUM; i++)
        n[i] = *(new node());
}

int main() {
    int num;

    cin >> num;

    for (int j = 0; j < num; j++) {
        clear();
        int v, e;
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int e1, e2, ww;
            cin >> e1 >> e2 >> ww;

            n[e1].adj.push_back(e2);
            n[e1].w.push_back(ww);
            // n[e2].adj.push_back(e1);
            // n[e2].w.push_back(ww);
        }

        int st, ta;
        cin >> st >> ta;

        vector<int> dists = dijkstra(st);

        if (dists[ta] != -1)
            cout << dists[ta] << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
