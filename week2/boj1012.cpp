#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[51][51];
bool vis[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int m, n, k;

void bfs(int x, int y) {
  vis[x][y] = true;
  q.push({ x,y });
  while (!q.empty()) {
    auto cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vis[nx][ny] || board[nx][ny] != 1) continue;
      vis[nx][ny] = true;
      q.push({ nx,ny });
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}
