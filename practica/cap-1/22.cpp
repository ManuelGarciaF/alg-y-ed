#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> multiplos;

  int actual = a;

  while ((int)multiplos.size() < n) {
    if (actual % b != 0) {
      multiplos.push_back(actual);
    }

    // Incrementar el numero actual.
    actual += a;
  }

  cout << multiplos.back() << endl;

  return 0;
}
