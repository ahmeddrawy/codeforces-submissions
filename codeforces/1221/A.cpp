#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'
/// since the sum of all numbers under 2048 is 2046 if we add just one number it will propagate to the others
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) {
        int n ; cin >> n ;
        vector<int > mvec(n);
        ll sum = 0 ;
        for (int i = 0; i <n ; ++i) {
            cin >> mvec[i];
            if(mvec[i] <= 2048){
                sum+=mvec[i];
            }

        }
        if(sum >= 2048) cout << "YES"<<endl;

        else cout <<"NO" <<endl;


    }
}