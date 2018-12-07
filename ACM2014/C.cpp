#include <iostream>
#include <queue>

using namespace std;

struct person {
    int home;
    double kmCost;
};

struct tv {
    int loc;
    int cost;
    double weekP;
    double jackpot;
};

int main() {
    
    int np = 1, nv = 1, nr = 1, nl = 1;
    cin >> np >> nv >> nr >> nl;
    while (np + nv + nr + nl != 0) {
    
        person p[10];
        tv v[10];
        int places[255][255];
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 255; j++) {
                places[i][j] = -1;
            }
        }
    
        for (int i = 0; i < np; i++) {
            int cur;
            double curKm;
            cin >> cur >> curKm;
        
            p[i] = (person) {
                .home = cur,
                .kmCost = curKm
            };
        }
    
        for (int i = 0; i < nv; i++) {
            int num, c, wp, jp;
            double wpc, jpc;
        
            cin >> num >> c >> wp >> jp >> wpc >> jpc;
        
            v[i] = (tv) {
                .loc = num,
                .cost = c,
                .weekP = wp * wpc,
                .jackpot = jp * jpc
            };
        }
    
        for (int i = 0; i < nr; i++) {
            int s, e, l;
        
            cin >> s >> e >> l;
        
            places[s][e] = l;
            places[e][s] = l;
        }
    
        // run djikstra (magic)
        int dists[10][255];
        int tempD[10][255];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 255; j++) {
                dists[i][j] = -1234567;
                tempD[i][j] = 1000000;
            }
        }
    
        for (int i = 0; i < np; i++) {
            priority_queue<pair<int, int> > pq;
            pq.push(make_pair(0, p[i].home));
            
            while (!pq.empty()) {
                pair <int, int> cur = pq.top();
                
                if (dists[i][cur.second] != -1234567) {
                    pq.pop();
                    continue;
                }
                
                dists[i][cur.second] = (-1) * cur.first;
                
                pq.pop();
            
                for (int j = 1; j <= nl; j++) {
                    if (places[cur.second][j] != -1) {
                        if (dists[i][cur.second] + places[cur.second][j] < tempD[i][j]) {
                            tempD[i][j] = dists[i][cur.second] + places[cur.second][j];
                            // cout << tempD[i][j] << endl;
                            pq.push(make_pair((-1) * tempD[i][j], j));
                        }
                    }
                }
            }  
        }
    
        double totalCosts[10];
        int travelDist[10];
        
        for (int i = 0; i < 10; i++) {
            totalCosts[i] = 0;
            travelDist[i] = 0;
        }
        
        for (int i = 0; i < nv; i++) {
            // add up each person's travel cost
            for (int j = 0; j < np; j++) {
                totalCosts[i] += p[j].kmCost * dists[j][v[i].loc];
                travelDist[i] += dists[j][v[i].loc];
                // cout << p[j].home << " " << v[i].loc << " " << dists[j][v[i].loc] << endl;
            }
        
            totalCosts[i] += (np * v[i].cost);
        
            totalCosts[i] -= (v[i].weekP + v[i].jackpot);
            
            // cout << i << " " << totalCosts[i] << endl;
        }
    
        double min = totalCosts[0];
        for (int i = 1; i < nv; i++) {
            if (totalCosts[i] < min)
                min = totalCosts[i];
        }
    
        double asdf[10];
        for (int i = 0; i < 10; i++) asdf[i] = -1;
        for (int i = 0; i < nv; i++) {
            if (totalCosts[i] == min)
                asdf[i] = totalCosts[i];
        }
    
        double minT = 10000000;
        int ind = 0;
        for (int i = 0; i < nv; i++) {
            if (asdf[i] != -1 && travelDist[i] < minT) {
                minT = travelDist[i];
                ind = i;
            }
        }
    
        cout << "Venue " << ind + 1 << endl;
        
        cin >> np >> nv >> nr >> nl;
    }
    
    return 0;

}
        