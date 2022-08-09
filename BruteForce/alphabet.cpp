#include <iostream>
#include <vector>
#include <string>
using namespace std;

int ans; // the number of moves
int dx[] = {0, 0, 1, -1}; // down, up, right, left
int dy[] = {1, -1, 0, 0};

void go(vector<string> &board, vector<bool> &check, int x, int y, int cnt){
    if(cnt > ans) ans = cnt; // let's find the maximum!
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(0 <= nx && nx < board.size() && 0 <= ny && ny < board[0].size()){ // if it is on the board
            if(check[board[nx][ny] - 'A'] == false){
                check[board[nx][ny] - 'A'] = true;
                go(board, check, nx, ny, cnt + 1);
                check[board[nx][ny] - 'A'] = false; // make it unvisited(restore)
            }
        }
    }
}

int main(){
    int r, c;   cin >> r >> c; // rows & columns
    vector<string> board(r);
    for(int i = 0; i < r; i++){
        cin >> board[i];
    }

    vector<bool> check(26); // check if the alphabet has been already visited
    check[board[0][0] - 'A'] = true; // first(top-left) point
    go(board, check, 0, 0, 1); // including the start point count
    cout << ans << '\n';
    return 0;
}
