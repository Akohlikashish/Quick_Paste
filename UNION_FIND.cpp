#include<bits/stdc++.h>
using namespace std;

void initialize(int arr[],int n){
for(int i=0;i<n;i++){
    arr[i]=-1;

}
}
int find_(int arr[],int x){

if(arr[x]<0) return x;
return(arr[x]=find_(arr,arr[x]));

}

void union_(int arr[],int x,int y){
int temp= find_(arr,x);
int temp1=find_(arr,y);
if(temp==temp1) return ;
if(arr[temp]<arr[temp1]){swap(temp,temp1);}
 arr[temp]=arr[temp]+arr[temp1]; arr[temp1]=temp;

}


int main(){

int n,l;
cin>>n>>l;
int arr[n+1];
initialize(arr,n);

while(l--){

    int a,b;
    cin>>a>>b;
    union_(arr,a,b);

}
vector<int> v;
for(int i=0;i<n;i++){ if(arr[i]<0) v.push_back(-arr[i]); }


long long int value=v[0],ans=0;

for(int i=1;i<v.size();i++){

ans+=(value*v[i]);
value+=v[i];
}
cout<<ans<<endl;
}
