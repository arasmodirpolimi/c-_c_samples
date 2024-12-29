#include <iostream>
using std::cout;
using std::endl;


int main() {

int i = 0, j = 1;
cout << "i: " << i << endl;
int *ptr = &i;
cout << "i1: " << i << endl;

i = 2;
cout << "i2: " << i << endl;
*ptr = 3;

ptr = &j;
cout << "i3: " << i << endl;
j = i;
*ptr = 4;
cout << "i4: " << i << endl;

  return 0;
}
