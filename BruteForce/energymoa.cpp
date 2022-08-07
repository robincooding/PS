#include <iostream>
#include <vector>
using namespace std;

int go(vector<int> &a){
    int n = a.size(); // the number of energy balls
    if(n == 2) return 0; // final state
    int ans = 0;
    for(int i = 1; i < n - 1; i++){ // excluding the first and last ones
        int energy = a[i - 1] * a[i + 1];
        vector<int> b(a);
        b.erase(b.begin() + i);
        energy += go(b);
        if(ans < energy){
            ans = energy; // let's find the maximum
        }
    }
    return ans;
}

int main(){
    int n;  cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << go(a) << '\n';
    return 0;
}
