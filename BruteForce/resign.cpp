#include <iostream>
#include <vector>
using namespace std;

int n, ans; // days until qutting and the maximum pay
vector<int> t; // required time for the job
vector<int> p; // pay

void go(int day, int sum){
    if(day == n){
        if(ans < sum) ans = sum; // let's find the maximum!
        return;
    }
    if(day > n ){ // after quitting the job
        return;
    }
    go(day + 1, sum);
    go(day + t[day], sum + p[day]);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int tv, pv;
        cin >> tv >> pv;
        t.push_back(tv);
        p.push_back(pv);

    }
    go(0, 0);
    cout << ans << '\n';
    return 0;
}
