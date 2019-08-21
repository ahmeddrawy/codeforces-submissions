//
// Created by ahmed_drawy on 18/08/19.
/// c1 sheet
#include <bits/stdc++.h>
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedMacroInspection"
using namespace std;
#define lp(i,start , end)       for(int i = start ; i<end ; ++i)
#define lllp(i,start , end)       for(ll i = start ; i<end ; ++i)
#define inN(arr ,  n) for(int i = 0 ; i< n ; ++i)  cin>>arr[i];
#define Rlp(i,start , end)      for(int i = start ; i>end ; --i)
#define all(v)                   ((v).begin(),(v).end())
#define sz(v)                  (int)((v).size())
#define clr(v,d)                memset(v , d , sizeof(v))

#define inf 0x3f3f3f3f
typedef long long               ll;
//typedef first                    ft;
//typedef second                   sd;
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
int arr[300005];
int n ;
bool solve(int indx ){

    lp(i , 1 , indx){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    lp(i,indx+2 , n){
        if(arr[i] > arr[i-1])
            return false;
    }
    return true;
}
int main() {
    smile();
    int k ;
    cin >> n >> k ;
    for (int i = 0; i < n; ++i) {
        cin >>arr[i];
    }
    vector<int > results;
    for (int j = 1; j <n ; ++j) {   /// if j and j-1 belongs to diff subarrays
        results.push_back(arr[j-1] - arr[j]);
    }
    ll ans = 0 ;
    sort(results.begin() , results.end());
    lp(i,0,k-1){ /// take the smallest k-1 because we have already a start point
        ans +=results[i];
    }
    cout << ans + arr[n-1] -arr[0]; /// the kth point

}