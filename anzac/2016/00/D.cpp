#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> l;

char m[10005];
string in;
string instr;
int cur;
int incur;

int proc(int i) {
    if (instr[i] == '+') m[cur]++;
    else if (instr[i] == '-') m[cur]--;
    else if (instr[i] == '>') cur++;
    else if (instr[i] == '<') cur--;
    else if (instr[i] == '.') cout << m[cur];
    else if (instr[i] == ',') {
        m[cur] = in[incur];
        incur++;
    } else if (instr[i] == '[') {
        if (m[cur] == 0) {
            if (!l.empty() && l.top() == i) l.pop();
            stack<char> s;
            s.push('[');
            i++;
            while (!s.empty()) {
                if (instr[i] == '[') s.push('[');
                if (instr[i] == ']') s.pop();
                i++;
            }
            return i;
        } else {
            if (l.empty() || i != l.top()) l.push(i);
        }
    } else if (instr[i] == ']') {
        return l.top();
    }
    
    return i + 1;
}

int main() {
    for (int i = 0; i < 10005; i++) m[i] = 0;
    cur = 0;
    incur = 0;
    
    getline(cin, in);
    
    char next;
    while (cin >> next) {
        instr += next;
    }
    
    int i = 0;
    while (i < instr.size()) {
        i = proc(i);
    }
    
    return 0;
}