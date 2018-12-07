#include <iostream>
#include <string>

using namespace std;

bool eq = true;

string check(string a, string b) {

    // cout << "a: " << a.length() << ": " << a << endl;
    // cout << "b: " << b.length() << ": " << b << endl;

    int la = a.length();
    int lb = b.length();

    if (a.compare(b) == 0)
        equal = equal && true;
        return;
    else if (la == 1 && lb == 1)
        equal = false;
        return;
    else {
        string a1, a2, b1, b2;

        if (la % 2 == 0 && lb % 2 == 0) {
            a1 = a.substr(0, la / 2);
            a2 = a.substr(la / 2, la);
            b1 = b.substr(0, lb / 2);
            b2 = b.substr(lb / 2, lb);
        } else {
            a1 = a.substr(0, la / 2 + 1);
            a2 = a.substr(la / 2, la);
            b1 = b.substr(0, lb / 2 + 1);
            b2 = b.substr(lb / 2, lb);
        }

        // return (check(a1, b2) && check(a2, b1)) || (check(a1, b1) && check(a2, b2));
    }
}

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    if (check(s1, s2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
