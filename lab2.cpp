#include <iostream>
#include <string>

using namespace std;

bool isValid(string str) {
  // Only a and b are allowed
  for (char c : str) {
    if (c != 'a' && c != 'b')
      return false;
  }

  // Must end with "abb"
  int n = str.length();

  if (n >= 3 && str[n - 3] == 'a' && str[n - 2] == 'b' && str[n - 1] == 'b')
    return true;

  return false;
}

int main() {
  string str;

  cout << "Enter a string: ";
  cin >> str;

  if (isValid(str))
    cout << "Valid string\n";
  else
    cout << "Invalid string\n";

  return 0;
}
