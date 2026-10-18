#include<bits/stdc++.h>
using namespace std;


int query(int l, int r){
    cout << "? " << l << " " << r << endl;
    int answer; cin >> answer;
    return answer;
}


void solve(){

    int n; cin >> n;
    if(n <= 3){
        cout << "! -1" << endl;
        return ;
    }

    vector<int> d(n + 10);
    bool all_same = true;

    for(int i = 1; i <= n - 1; i ++){
        int answer = query(i, i + 1);
        if(answer == 3){
            d[i] = 1;
            all_same = false;
        }
        else d[i] = 0;
    }

    if(all_same){
        cout << "! -1" << endl;
        return ;
    }

    vector<int> a(n + 10), b(n + 10);
    a[1] = 0, b[1] = 1;
    for(int i = 2; i <= n; i ++){
        a[i] = a[i - 1] ^ d[i - 1];
        b[i] = b[i - 1] ^ d[i - 1];
    }

    vector<int> prea(n + 10);
    for(int i = 1; i <= n; i ++){
        if(i == 1) prea[i] = a[i];
        else prea[i] = prea[i - 1] + a[i];
    }

    for(int l = 1; l <= n; l ++){
        for(int r = l; r <= n; r ++){
            int len = r - l + 1;
            int suma = prea[r] - prea[l - 1];
            int sumb = len - suma;

            if((suma | len) != (sumb | len)){
                cout << "! ";
                int answer = query(l, r);
                if(answer == (suma | len)){
                    for(int i = 1; i <= n; i ++) cout << a[i] << " ";
                }
                else{
                    for(int i = 1; i <= n; i ++) cout << b[i] << " ";
                }
                cout << endl;
                return ;
            }
        }
    }

    cout << "! -1" << endl;
    return ;
}
int main(){

    int tt; cin >> tt;
    while(tt --) solve();
    return 0;
}