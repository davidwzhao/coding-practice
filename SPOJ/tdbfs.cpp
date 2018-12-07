#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define NUM 10005

using namespace std;

struct node {
    vector<int> adj;    // adjacency list
};

node n[NUM];