#include <iostream>
#include <cstring> // for memset function
using namespace std;

int n = 9; // 9 x 9 board
int a[10][10];
bool c[10][10]; // for checking the row (second index means the number 1~9)
bool c2[10][10]; // for checking the column
bool c3[10][10]; // for checking the square

int square(int x, int y){
    return (x / 3) * 3 + (y / 3);
}

void go(int z){
    if(z == 81){
        for(int i = 0; i < n; i++){ // print out the answer
            for(int j = 0; j < n; j++){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    int x = (z / n), y = (z % n); // row, column
    if(a[x][y] != 0){ // if it is not a blank
        go(z + 1);
    }
    else{ // if it is a blank(need to fill in)
        for(int i = 1; i <= 9; i++){
            if(c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0){
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
                a[x][y] = i; // fill in the blank
                go(z + 1);
                a[x][y] = 0; // restore all
                c[x][i] = c2[y][i] = c3[square(x, y)][i] = false;
            }
        }
    }
}

int main(){
    memset(c, false, sizeof(c));
    memset(c2, false, sizeof(c2));
    memset(c3, false, sizeof(c3));
    memset(a, 0, sizeof(a));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] != 0){ // if it is not a blank
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i, j)][a[i][j]] = true;
            }
        }
    }
    go(0);

    return 0;
}
