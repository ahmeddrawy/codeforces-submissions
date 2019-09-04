//
// Created by ahmed_drawy on 03/09/19.
/// Manthan, Codefest 19 (open for everyone, rated, Div. 1 + Div. 2)
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
typedef vector<int>             vi;
typedef vector  <ll>            vll;
typedef vector<vector<int> >    adj;
typedef pair<int ,int>          pii;
const double EPS =1e-7;
const int OO = 1e6;
#define endl '\n'
bool sortpair( const pair<int , int> & x, const pair<int , int> & y){
    return  x.first != y.first ? x.first < y.first : x.second > y.second ;
}
int dcomp(double x , double y){
    return fabs(x-y) <= EPS? 0: x>y?1:-1;
}
void smile() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/tw3/Desktop/Desktop/training/in.txt", "r", stdin);
//    freopen("/home/tw3/Desktop/Desktop/training/out.txt" , "w" , stdout);
#endif // ONLINE_JUDGE
}
int main() {
    smile();
    int n ; cin >> n ;
    vector<int> arr(n);
    inN(arr , n );
    set<int > mm;
    unordered_map<int , int> mmap;
    lp(i,0,n)mmap[arr[i]]++;
    int mn = INT_MAX;int cnt = 0 ;
    unordered_map<int , int > frq1;
    lp(left , 0 , n ){
        bool invalid = 0;
        for (int i = 0; i <left ; ++i) {
            frq1[arr[i]]++;
            if(frq1[arr[i]] >1){
                invalid= 1;
                break;
            }
        }
        int validIndx = n;
        for (int j = n-1; j >=left ; --j) {
           frq1[arr[j]]++;
           if(frq1[arr[j]] == 1){
               validIndx = j;
           }
           else break;
        }
        if(!invalid)
            mn = min(mn , validIndx - left);
        frq1.clear();

    }

    cout << mn ;
}