#include <stdio.h>
#include <stdbool.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

int visited[MAX_ROW][MAX_COL];
int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int prev[MAX_ROW][MAX_COL][2];
int qr[100], qc[100];
int head, tail;

int main(void)
{
    qr[tail] = 0; qc[tail] = 0; tail++;
    visited[0][0] = 1;
    prev[0][0][0] = -1; prev[0][0][1] = -1;
    int found = 0;
    while (head < tail && !found) {
        int r = qr[head], c = qc[head]; head++;
        if (r == MAX_ROW - 1 && c == MAX_COL - 1) { found = 1; break; }
        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0], nc = c + dirs[i][1];
            if (nr >= 0 && nr < MAX_ROW && nc >= 0 && nc < MAX_COL && !maze[nr][nc] && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                prev[nr][nc][0] = r; prev[nr][nc][1] = c;
                qr[tail] = nr; qc[tail] = nc; tail++;
            }
        }
    }
    int path[100][2], len = 0;
    int r = MAX_ROW - 1, c = MAX_COL - 1;
    while (r != -1) {
        path[len][0] = r; path[len][1] = c; len++;
        int pr = prev[r][c][0], pc = prev[r][c][1];
        r = pr; c = pc;
    }
    for (int i = 0; i < len; i++)
        printf("(%d, %d)\n", path[i][0], path[i][1]);
	return 0;
}