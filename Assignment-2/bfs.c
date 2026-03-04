#include <stdio.h>

#define MAX 100

int visited[5][5];

struct State {
    int x;
    int y;
};

struct State queue[MAX];
int front = 0;
int rear = 0;

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

struct State dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs() {

    enqueue(0,0);
    visited[0][0] = 1;

    while(!isEmpty()) {

        struct State curr = dequeue();

        int x = curr.x;
        int y = curr.y;

        printf("(%d , %d)\n", x, y);

        if(x == 2 || y == 2) {
            printf("Goal reached\n");
            return;
        }

        int next[6][2] = {
            {4, y},      // fill jug A
            {x, 3},      // fill jug B
            {0, y},      // empty A
            {x, 0},      // empty B
            {x - (3-y < x ? 3-y : x), y + (3-y < x ? 3-y : x)}, // pour A→B
            {x + (4-x < y ? 4-x : y), y - (4-x < y ? 4-x : y)}  // pour B→A
        };

        for(int i=0;i<6;i++) {
            int nx = next[i][0];
            int ny = next[i][1];

            if(nx>=0 && ny>=0 && nx<=4 && ny<=3 && !visited[nx][ny]) {
                enqueue(nx,ny);
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    printf("BFS traversal of states:\n");
    bfs();
    return 0;
}