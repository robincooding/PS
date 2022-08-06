#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(vector<int> &perm, vector<char> &a){
    // if the comparison doesn't match, return false
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '<' && perm[i] > perm[i + 1]){
            return false;
        }
        if(a[i] == '>' && perm[i] < perm[i + 1]){
            return false;
        }
    }
    return true;
}

int main(){
    int k;  cin >> k;
    vector<char> a(k);
    for(int i = 0; i < k; i++){
        cin >> a[i]; // input : the '<' or '>' symbols
    }

    vector<int> small(k + 1); // for finding the smallest sequence
    vector<int> big(k + 1); // for finding the biggest sequence
    for(int i = 0; i <= k; i++){
        small[i] = i;
        big[i] = 9 - i;
    }

    /* checking all the sequences one by one until the biggest and smallest
    ones(the answer) are found */
    do{
        if(check(small, a)) {
            break;
        }
    } while(next_permutation(small.begin(), small.end()));
    do{
        if(check(big, a)) {
            break;
        }
    } while(prev_permutation(big.begin(), big.end()));

    for(int i = 0; i < big.size(); i++) {
        cout << big[i];
    }
    cout << '\n';
    for(int i = 0; i < small.size(); i++) {
        cout << small[i];
    }
    cout << '\n';
    return 0;
}
