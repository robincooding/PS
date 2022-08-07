# include <iostream>
using namespace std;

int a[20];
int n, m;
int ans = 0;

void go(int i, int sum){
    if(i == n){
        if(sum == m){ // found answer!
            ans += 1;
        }
        return;
    }
    go(i + 1, sum + a[i]); // add to the subsequence
    go(i + 1, sum); // pass without addition
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i]; // input sequence
    }
    go(0, 0);
    if(m == 0) ans -= 1; // exclusion of zero-length subsequence
    cout << ans << '\n';
    return 0;
}
