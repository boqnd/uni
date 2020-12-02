#include <iostream>

using namespace std;

int main() {
  int N, M, S;

  cin >> N >> M >> S;

  for (int i = M; i >= N; i--)
  {
    if (i%2 == 0 && i%3 == 0)
    {
      if (i == S)
      {
        break;
      }
      cout << i << " ";
    }
  }

  return 0;
}