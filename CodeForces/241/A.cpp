#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct question {
    char sign[3];
    int number;
    int answer;
};

bool sortFunction (question a, question b) {

    if (a.sign[0] == '>') {
        if (a.sign[1] == '=') {
            if (b.sign[0] == '>') {
                return false;
            } else {
                return true;
            }
        }
        return true;
    } else if (a.sign[0] == '<') {
        if (a.sign[1] == '=') {
            return false;
        } else if (b.sign[0] == '>') {
            return false;
        }
        return true;
    }
}

int main () {

    int numQuestions = 0;
    question questions[10005];
    char trueFalse;
    
    scanf ("%d", &numQuestions);
    
    for (int i = 0; i < numQuestions; i++) {
        scanf ("%s %d %c", &questions[i].sign, &questions[i].number, &trueFalse);
        if (trueFalse == 'Y') {
            questions[i].answer = 1;
        } else {
            questions[i].answer = 0;
        }
    }
    
    for (int i = 0; i < numQuestions; i++) {
        if (strcmp (questions[i].sign, ">") == 0) {
            if (questions[i].answer == 0) {
                questions[i].sign[0] = '<';
                questions[i].sign[1] = '=';
            }
        } else if (strcmp (questions[i].sign, ">=") == 0) {
            if (questions[i].answer == 0) {
                questions[i].sign[0] = '<';
                questions[i].sign[1] = '\0';
            }
        } else if (strcmp (questions[i].sign, "<") == 0) {
            if (questions[i].answer == 0) {
                questions[i].sign[0] = '>';
                questions[i].sign[1] = '=';
            }
        } else if (strcmp (questions[i].sign, "<=") == 0) {
            if (questions[i].answer == 0) {
                questions[i].sign[0] = '>';
                questions[i].sign[1] = '\0';
            }
        }
    }
    
    sort (questions, questions+numQuestions, sortFunction);
    
    int max = -2000000000;
    int i = 0;
    while (strcmp (questions[i].sign, ">") == 0 && i < numQuestions) {
        if (questions[i].number >= max) {
            max = questions[i].number + 1;
        }
        i++;
    }
    
    while (strcmp (questions[i].sign, ">=") == 0 && i < numQuestions) {
        if (questions[i].number > max) {
            max = questions[i].number;
        }
        i++;
    }
    
    int min = 2000000000;
    while (strcmp (questions[i].sign, "<") == 0 && i < numQuestions) {
        if (questions[i].number <= min) {
            min = questions[i].number - 1;
        }
        i++;
    }
    
    while (strcmp (questions[i].sign, "<=") == 0 && i < numQuestions) {
        if (questions[i].number < min) {
            min = questions[i].number;
        }
        i++;
    }
    
    if (max <= min) {
        printf ("%d\n", max);
    } else {
        printf ("Impossible\n");
    }
    
    return 0;
    
}
