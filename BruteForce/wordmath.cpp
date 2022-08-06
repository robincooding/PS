#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

char alpha[256];
int calc(vector<string> &a, vector<char> &letters, vector<int> &d){
    int m = letters.size();
    int sum = 0;
    for(int i = 0; i < m; i++){
        alpha[letters[i]] = d[i]; // the value of i-th alphbet in a word
    }
    for(string s : a){
        int now = 0;
        for (char x : s){
            now = now * 10 + alpha[x];
        } // calculate the value of each word shifting to match the place value
        sum += now;
    }
    return sum;
}

int main(){
    int n;  cin >> n;
    vector<string> a(n); // each word
    vector<char> letters; // each alphabet forming a word
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(char x : a[i]){
            letters.push_back(x);
        }
    }
    /* to get rid of duplicate numbers */
    sort(letters.begin(), letters.end());
    letters.erase(unique(letters.begin(), letters.end()), letters.end());

    int m = letters.size();

    vector<int> d;
    for(int i = 9; i > 9 - m; i--){
        d.push_back(i);
    }
    sort(d.begin(), d.end()); // to use next_permutation function
    int ans = 0;
    do{
        int now = calc(a, letters, d);
        if(ans < now){
            ans = now; // find the maximum
        }
    } while(next_permutation(d.begin(), d.end()));
    cout << ans << '\n';
    return 0;
}