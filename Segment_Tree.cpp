#include<bits/stdc++.h>
using namespace std;
//not useful struct in this snippet
//this code snippet is used for RMQ;
//but after few changes can be used for other segment tree usage.

const int MAX_N = 1e5;
int h[MAX_N], last[MAX_N * 10], C[MAX_N * 10], N, T[MAX_N * 4];

int query(int n, int L, int R, int i, int j){
  if(R < i || j < L) return -1;
  if(i <= L && R <= j) return T[n];
  return max(query(n * 2, L, (L + R) / 2, i, j), query(n * 2 + 1, (L + R) / 2 + 1, R, i, j));
}
void build(int n, int L, int R){
  if(L == R) {T[n]=h[L]}
  else {
    build(n * 2, L, (L + R) / 2);
    build(n * 2 + 1, (L + R) / 2 + 1, R);
    T[n] = max(T[n * 2], T[n * 2 + 1]);
  }
}
int rmq(int i, int j){
  return query(1, 0, N - 1, i, j);
}
int main(){

}
