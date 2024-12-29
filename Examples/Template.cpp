#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T max(T a, T b) {
  if (a > b) { return a; }
  return b;
}

int main() {
  cout << "max(3, 5): " << max(3, 5) << endl;
  cout << "max('a', 'd'): " << max('a', 'd') << endl;
  cout << "max(\"Hello\", \"World\"): " << max("Hello", "World") << endl;

  return 0;
}
