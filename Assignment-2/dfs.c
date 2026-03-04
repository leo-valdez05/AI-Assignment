#include <stdio.h>

int visited[5][5];

void dfs(int x, int y) {

    if(x<0 || y<0 || x>4 || y>3 || visited[x][y])
        return;

    printf("(%d , %d)\n", x, y);

    if(x == 2 || y == 2) {
        printf("Goal reached\n");
        return;
    }

    visited[x][y] = 1;

    dfs(4, y);   // fill jug A
    dfs(x, 3);   // fill jug B
    dfs(0, y);   // empty A
    dfs(x, 0);   // empty B

    int pour = (x < (3-y)) ? x : (3-y);
    dfs(x-pour, y+pour);   // A → B

    pour = (y < (4-x)) ? y : (4-x);
    dfs(x+pour, y-pour);   // B → A
}

int main() {

    printf("DFS traversal of states:\n");

    dfs(0,0);

    return 0;
}