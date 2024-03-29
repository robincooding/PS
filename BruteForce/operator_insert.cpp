#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// calculation function
int calc(vector<int> &a, vector<int> &b){
    int n = a.size();
    int ans = a[0];
    for(int i = 1; i < n; i++){
        if(b[i - 1] == 0){
            ans = ans + a[i];
        }
        else if(b[i - 1] == 1){
            ans = ans - a[i];
        }
        else if(b[i - 1] == 2){
            ans = ans * a[i];
        }
        else{
            ans = ans / a[i];
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

    vector<int> b;
    for(int i = 0; i < 4; i++){ // input operators: +, -, *, /
        int cnt;    cin >> cnt;
        for(int k = 0; k < cnt; k++) {
            b.push_back(i);
        }
    }
    sort(b.begin(), b.end()); // to use the next_permutation function

    vector<int> result;
    /* store all the results of calculations */
    do{
        int temp = calc(a, b);
        result.push_back(temp);
    } while(next_permutation(b.begin(), b.end()));

    auto ans = minmax_element(result.begin(), result.end()); // pick min/max values
    cout << *ans.second << '\n'; // maximum
    cout << *ans.first << '\n'; // minimum
    return 0;
}
