//
// Created by ahmed_drawy on 23/08/19.
/// educational contest 68
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

bool check(map<int , vector<int> > &mmap , int x){

    for(auto it :   mmap){
        int sum = 0 ;
        for(auto item : it.second){
                sum++;
        }
        if(sum == x)return true;


    }
    return false;
}

int main() {
    smile();
    int t; cin >> t;
    while(t--) {
        int n , m ;cin>> n >> m ;
        map<int ,int  > rows;
        map<int ,int > columns;
        int rmx = 0 ,ri = 0 ,cmx = 0, ci = 0;
        vector<int> rindices;
        vector<int> cindices;
        vector<vector<char> > mvec(n);
        lp(i,0,n){
            lp(j,0,m){
                char x ; cin >>x;
                mvec[i].push_back(x);
                if(x == '*'){
                    rows[i]++;
                    columns[j]++;
                }
//                if(rows[i] > rmx){
//                    rmx= rows[i];
////                    ri  = i;
//                    rindices.clear();
//                    rindices.push_back(i);
//                }
//                else if(rows[i] == rmx){
//                    rindices.push_back(i);
//                }
//                if( columns[j] > cmx){
//                    cmx = columns[j];
////                    ci = j ;
//                    cindices.clear();
//                    cindices.push_back(j);
//                }
//                else if(columns[j] == cmx){
//                    cindices.push_back(j);
//                }
            }
        }
//        int ans = 0 ;
        int ans = n+m ;
        lp(i,0,n){
            lp(j,0,m){
                ans = min (ans , n - rows[i]+ m - columns[j] - (mvec[i][j] == '.') );
            }
//            if(ans) break;
        }
        cout<<ans<<endl;
//        if(!ans)
//            cout<< (n- rmx) + (m-cmx) - (mvec[rindices[0]][cindices[0]] == '.'?1 : 0 )<<endl;
    }
}