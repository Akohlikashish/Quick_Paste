#include<bits/stdc++.h>

#define SET(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))
#define MAX 2001
#define NIL 0
#define INF (1<<28)


int N,M,K;

vector< int > edges[MAX]; // edges of left side
bool visited[MAX];
int Left[MAX], Right[MAX];
long long int dist[MAX][MAX];

bool dfs(int u) {
    if(visited[u]) return false;
    visited[u] = true;
    int len = edges[u].size(), i, v;
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(Right[v]==-1) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    for(i=0; i<len; i++) {
        v = edges[u][i];
        if(dfs(Right[v])) {
            Right[v] = u, Left[u] = v;
            return true;
        }
    }
    return false;
}



int match() {
    SET(Left); // left = -1
    SET(Right); // right = -1
    int i, ret = 0;
    bool done;
    do {
        done = true;
        CLR(visited); // visited = 0
        for(i=1; i<=N; i++) {
            if(Left[i]==-1 && dfs(i)) {
                done = false;
            }
        }
    } while(!done);
    for(i=1; i<=N; i++) ret += (Left[i]!=-1);
    return ret;
}


//dependencey:
//this code has been copied from https://www.hackerrank.com/challenges/bike-racers/editorial
// usefull in maximum bipartite matching problems.
