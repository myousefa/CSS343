#include <iostream>

using namespace std;

int Ackerman(int m, int n) {
  if (m == 0)
    return n + 1;
  if (m > 0 && n == 0)
    return Ackerman(m - 1, 1);
  return Ackerman(m - 1, Ackerman(m, n - 1));
}

int main() {
  for (int mi = 0; mi < 3; ++mi) {
    for (int ni = 0; ni < 3; ++ni) {
      int result = Ackerman(mi, ni);
      cout << "Ackerman(" << mi << "," << ni << ") = " << result << endl;
    }
  }
  return 0;
}
