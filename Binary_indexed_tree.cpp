//triplets.cpp
//Triplets
//Author: Ashish

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
int v[MAXN], h[MAXN];
set<int> s;
map<int, int> m;

class FenwickTree
{
private:
    long long tree[MAXN];

public:
    FenwickTree()
    {
        memset(tree, 0, sizeof(tree));
    }

    long long get(int idx)
    {
        return query(idx) - query(idx - 1);
    }

    void set(int idx, long long val)
    {
        long long curr = get(idx);
        update(idx, val - curr);
    }

    void update(int idx, long long val)
    {
        while (idx <= MAXN)
        {
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }

    long long query(int idx)
    {
        long long sum = 0;
        while (idx > 0)
        {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
};

FenwickTree a, b, c;
//code for Fenwick tree, can be efficiently used for prefix sum calculation.
