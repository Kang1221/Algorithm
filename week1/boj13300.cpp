#include <bits/stdc++.h>
using namespace std;

int N, K, ans=0;
int s[2][7]={};  // 성별/반별 학생 수

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  
  // 학생 수 저장
  for (int i=0; i<N; ++i) {
    int a, b;
    cin >> a >> b;
    s[a][b]++;
  }

  // 필요한 방의 개수
  for (int i=0; i<2; ++i) {
    for (int j=1; j<7; ++j) {
      ans += s[i][j] / K;
      // 학생이 남을 경우
      if (s[i][j] % K) ++ans;
    }
  }

  //정답 출력
  cout << ans;
}
