#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define vii vector<ll>
#define   endl '\n'

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q ; cin >> q;
    while(q--){
        ll m , c , x; cin >> c >> m>> x;
        if(m> c) {
            swap(c, m);
        }
        if(x + c >= 2*m){
            cout <<m <<endl;
        }
        else { /// if we have min and the rest can't make it to min
            ll v = ceil((2.0*m - x- c)*1.0/3);
            cout << m - v<<endl ;
        }

    }
}