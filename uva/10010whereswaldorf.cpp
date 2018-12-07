#include <iostream>
#include <string>

using namespace std;

pair<int,int> s(string* l, string word, int h, int w) {

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int k = i, m = j, ind = 0;
            bool found = true;
            while (true) {
                if (l[k][m] != word[ind] || k >= h || m >= w) {
                    found = false;
                    break;
                }
                ind++;
                k++;
                m++;
                if (ind >= word.length())
                    break;
            }

            if (found)
                return make_pair(i, j);

            k = i, m = j, ind = 0;
            found = true;

            while (true) {
                if (l[k][m] != word[ind] || m >= w) {
                    found = false;
                    break;
                }
                ind++;
                m++;
                if (ind >= word.length())
                    break;
            }

            if (found)
                return make_pair(i, j);

            k = i, m = j, ind = 0;
            found = true;

            while (true) {
                if (l[k][m] != word[ind] || k < 0 || m >= w) {
                    found = false;
                    break;
                }
                ind++;
                k--;
                m++;
                if (ind >= word.length())
                    break;
            }

            if (found)
                return make_pair(i, j);

            k = i, m = j, ind = 0;
            found = true;

            while (true) {
                if (l[k][m] != word[ind] || k < 0) {
                    found = false;
                    break;
                }
                ind++;
                k--;
                if (ind >= word.length())
                    break;
            }

            if (found)
                return make_pair(i, j);

            k = i, m = j, ind = 0;
            found = true;

            while (true) {
                if (l[k][m] != word[ind] || k < 0 || m < 0) {
                    found = false;
                    break;
                }
                ind++;
                k--;
                m--;
                if (ind >= word.length())
                    break;
            }

            if (found)
                return make_pair(i, j);

            k = i, m = j, ind = 0;
            found = true;

            while (true) {
                if (l[k][m] != word[ind] || m < 0) {
                    found = false;
                    break;
                }
                ind++;
                m--;
                if (ind >= word.length())
                    break;
            }

            if (found)
                return make_pair(i, j);

            k = i, m = j, ind = 0;
            found = true;

            while (true) {
                if (l[k][m] != word[ind] || k >= h || m < 0) {
                    found = false;
                    break;
                }
                ind++;
                k++;
                m--;
                if (ind >= word.length())
                    break;
            }

            if (found)
                return make_pair(i, j);

            k = i, m = j, ind = 0;
            found = true;

            while (true) {
                if (l[k][m] != word[ind] || k >= h) {
                    found = false;
                    break;
                }
                ind++;
                k++;
                if (ind >= word.length())
                    break;
            }

            if (found)
                return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

string tl(string a) {
    for (int i = 0; i < a.length(); i++) {
        if (a[i] >= 'A' && a[i] <= 'Z') {
            a[i] += 32;
        }
    }
    return a;
}

int main() {

    int n, h, w;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h >> w;

        string lines[55];
        string lol;

        getline(cin, lol);

        for (int j = 0; j < h; j++) {
            getline(cin, lines[j]);
            lines[j] = tl(lines[j]);
        }

        int words;
        cin >> words;

        string word;

        for (int j = 0; j < words; j++) {
            cin >> word;
            word = tl(word);

            pair<int, int> res = s(lines, word, h, w);
            if (res != make_pair(-1, -1)) {
                cout << res.first + 1<< " " << res.second + 1<< endl;
            }
        }
        if (i != n - 1)
            cout << endl;
    }
}
