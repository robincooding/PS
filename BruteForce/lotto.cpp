#include <iostream>
#include <vector>
using namespace std;

vector<int> lotto; // the number set chosen from the function
void solve(vector<int> &a, int index, int cnt){
    if(cnt == 6){
        for(int num : lotto){
            printf("%d ", num);
        } // print the lotto set
        printf("\n");
        return;
    }
    /* set up part for the iteration */
    int n = a.size();
    if(n == index) return; // end up in fail
    lotto.push_back(a[index]); // chosen
    solve(a, index + 1, cnt + 1);
    lotto.pop_back(); // not chosen (keep in mind the ascending order)
    solve(a, index + 1, cnt);
}

int main(){
    while(true){
        int n;  cin >> n;
        if(n == 0) break;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        } // input set of numbers
        solve(a, 0, 0);
        cout << '\n';
    }
    return 0;
}
