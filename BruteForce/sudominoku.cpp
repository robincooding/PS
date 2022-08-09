#include <iostream>
#include <cstring> // for memset function
#include <tuple>
using namespace std;

int n = 9; // 9 x 9
int a[10][10];
bool c[10][10]; // for checking the row (second index means the number 1~9)
bool c2[10][10]; // for checking the column
bool c3[10][10]; // for checking the square
bool domino[10][10];
int dx[] = {0, 1};
int dy[] = {1, 0};

pair<int, int> convert(string s){ // convert locations of dominos(string) into coordinates
    return make_pair(s[0] - 'A', s[1] - '1');
}

int square(int x, int y){
    return (x / 3) * 3 + (y / 3);
}

bool check_range(int x, int y){
    return (0 <= x && x < n && 0 <= y && y < n); // check if it is on the board
}

void check(int x, int y, int num, bool tf){
    c[x][num] = tf; // check number in row x
    c2[y][num] = tf; // check number in column y
    c3[square(x, y)][num] = tf; // check number in a square
}

bool can(int x, int y, int num){ // if the number can be placed on that blank
    return (c[x][num] == false && c2[y][num] == false && c3[square(x, y)][num] == false);
}

bool go(int z){
    if(z == 81){
        for(int i = 0; i < n; i++){ // print out the answer
            for(int j = 0; j < n; j++){
                cout << a[i][j];
            }
            cout << '\n';
        }
        return true;
    }
    int x = (z / n), y = (z % n); // row, column
    if(a[x][y] != 0){ // if it is not a blank
        return go(z + 1);
    }
    else{
        for(int k = 0; k < 2; k++){
            int nx = x + dx[k]; // domino: (x, y) ~ (nx, ny)
            int ny = y + dy[k];
            if(!check_range(nx, ny)) continue;
            if(a[nx][ny] != 0) continue;

            for(int i = 1; i <= 9; i++){ // get a pair of numbers in a domino
                for(int j = 1; j <= 9; j++){
                    if(i == j) continue;
                    if(domino[i][j]) continue;
                    if(can(x, y, i) && can(nx, ny, j)){
                        check(x, y, i, true);
                        check(nx, ny, j, true);
                        domino[i][j] = domino[j][i] = true;
                        a[x][y] = i;
                        a[nx][ny] = j;
                        if(go(z + 1)) return true;
                        check(x, y, i, false); // restore all
                        check(nx, ny, j, false);
                        domino[i][j] = domino[j][i] = false;
                        a[x][y] = 0;
                        a[nx][ny] = 0;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    int tc = 1; // testcases
    while(true){
        memset(c, false, sizeof(c));
        memset(c2, false, sizeof(c2));
        memset(c3, false, sizeof(c3));
        memset(a, 0, sizeof(a));
        memset(domino, false, sizeof(domino));

        int m;  cin >> m; // the number of filled dominos
        if(m == 0) break;
        for(int i = 0; i < m; i++){
            int n1, n2;
            string s1, s2; // location of a domino
            cin >> n1 >> s1 >> n2 >> s2;
            int x1, y1, x2, y2;
            tie(x1, y1) = convert(s1);
            tie(x2, y2) = convert(s2); // strings to coordinates
            a[x1][y1] = n1;
            a[x2][y2] = n2;
            domino[n1][n2] = domino[n2][n1] = true; // the pair is occupied
            check(x1, y1, n1, true);
            check(x2, y2, n2, true);
        }

        for(int i = 1; i <= 9; i++){
            /* check already filled numbers(1-9 in order) before solved */
            string s;   cin >> s;
            int x, y;
            tie(x, y) = convert(s);
            a[x][y] = i;
            check(x, y, i, true);
        }

        cout << "Puzzle " << tc << '\n';
        go(0);
        tc += 1;
    }
    return 0;
}
