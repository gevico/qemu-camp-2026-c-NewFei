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
int path[100][2];
int path_len;

int dfs(int r, int c) {
    if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL) return 0;
    if (maze[r][c] || visited[r][c]) return 0;
    visited[r][c] = 1;
    if (r == MAX_ROW - 1 && c == MAX_COL - 1) {
        path[path_len][0] = r; path[path_len][1] = c; path_len++;
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        if (dfs(r + dirs[i][0], c + dirs[i][1])) {
            path[path_len][0] = r; path[path_len][1] = c; path_len++;
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    dfs(0, 0);
    for (int i = 0; i < path_len; i++)
        printf("(%d, %d)\n", path[i][0], path[i][1]);
	return 0;
}