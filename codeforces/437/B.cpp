//
// Created by ahmed_drawy on 07/08/19.
// 651 C- c1 sheet
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
const long long modul = 1000000007;

ll mod(ll x) {
    return (x%modul + modul)%modul;
}

int main() {
    smile();
    int sum , limit  ; cin >> sum >> limit  ;
    map<int ,int > mmap;
    map<int , vector<int> >mvap;
    lp(i,1,limit+1){
        mmap[i&(-i)]++;
        mvap[i&(-i)].push_back(i);
    }
    vector<int >mas;
    for(auto it = mmap.rbegin() ; it!= mmap.rend() ; ++it){

        while(sum - (it->first) >= 0 && it->second){
            sum-=it->first;
            it->second--;
            mas.push_back(mvap[it->first][it->second]);
        }
    }
    if(sum == 0 ){
        cout<<mas.size()<<endl;
        for(auto it :mas){
            cout << it << " ";
        }
    }
    else cout<<-1;
}