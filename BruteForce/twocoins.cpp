#include <iostream>
using namespace std;

int n, m; // n x m board
string a[20]; // an input of a board
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0}; // down, up, right, left

int go(int step, int x1, int y1, int x2, int y2){
    if(step == 11) return -1; // pushed the button more than 10 times

    bool fall1 = false, fall2 = false;
    if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) fall1 = true;
    if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true;
    if(fall1 && fall2) return -1; // two coins both fall
    if(fall1 || fall2) return step;

    int ans = -1; // start point (if the answer is not found, return -1)
    for(int k = 0; k < 4; k++){
        int nx1 = x1 + dx[k];
        int ny1 = y1 + dy[k]; // (x1, y1) -> (nx1, ny1)
        int nx2 = x2 + dx[k];
        int ny2 = y2 + dy[k]; // (x2, y2) -> (nx2, ny2)
        if(0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && a[nx1][ny1] == '#'){
            // trapped by a wall
            nx1 = x1;
            ny1 = y1;
        }
        if(0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#'){
            nx2 = x2;
            ny2 = y2;
        }

        int temp = go(step + 1, nx1, ny1, nx2, ny2);
        if(temp == -1) continue;
        if(ans == -1 || ans > temp){
            ans = temp; // let's find the minimum
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    int x1, y1, x2, y2;
    x1 = y1 = x2 = y2 = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'o'){
                if(x1 == -1){ // coin #1
                    x1 = i;
                    y1 = j;
                }
                else{ // coin #2
                    x2 = i;
                    y2 = j;
                }
                a[i][j] = '.'; // after checking a coin, uncoin the spot
            }
        }
    }
    cout << go(0, x1, y1, x2, y2) << '\n';
    return 0;
}
