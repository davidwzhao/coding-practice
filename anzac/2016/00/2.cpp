#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int po, s, pe, q, d;
    cin >> po >> s >> pe >> q >> d;
    
    double cost = po * 240 + s * 12 + pe;
    double prior = round(cost * q);
    
    cost *= ((100 - d) / 100.0);
    double unit = round(cost);
    
    cost *= q;
    cost = round(cost);
    
    int r = 0;
    po = prior / 240;
    r = (int) prior % 240;
    s = r / 12;
    r = r % 12;
    pe = r;
    
    cout << po << " " << s << " " << pe << endl;
    
    po = cost / 240;
    r = (int) cost % 240;
    s = r / 12;
    r = r % 12;
    pe = r;
    
    cout << po << " " << s << " " << pe << endl;
    
    po = unit / 240;
    r = (int) unit % 240;
    s = r / 12;
    r = r % 12;
    pe = r;
    
    cout << po << " " << s << " " << pe << endl;
    
    return 0;
}