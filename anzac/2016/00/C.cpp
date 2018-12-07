#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, int> si;

int main() {
    map<string, vector<si> > m;
    map<string, int> nums;
    
    int w, o;
    cin >> w;
    
    for (int i = 0; i < w; i++) {
        int n;
        string s;
        
        cin >> n >> s;
        vector<si> v;
        
        for (int j = 0; j < n; j++) {
            int q;
            string ss;
            
            cin >> q >> ss;
            
            v.push_back(make_pair(ss, q));
        }
        
        m[s] = v;
    }
    
    cin >> o;
    
    map<string, int> out;
    for (int i = 0; i < o; i++) {
        int n;
        string s;
        cin >> n >> s;
        
        for (int j = 0; j < m[s].size(); j++) {
            out[m[s][j].first] += m[s][j].second * n;
        }
    }
    
    vector<si> vout;
    for (map<string, int>::iterator it = out.begin(); it != out.end(); it++) {
        if (it->second > 0) {
            vout.push_back(make_pair(it->first, it->second));
        }
    }
    
    sort(vout.begin(), vout.end());
    
    for (int i = 0; i < vout.size(); i++) {
        cout << vout[i].second << " " << vout[i].first << endl;
    }
    
    return 0;
}