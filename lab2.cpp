#include <iostream>
#include <string>

using namespace std;

bool isValid(string str) {
  int n = str.length();

  // Minimum length should be 4: "babb"
  if (n < 4)
    return false;

  // Must start with 'b'
  if (str[0] != 'b')
    return false;

  // All characters must be either 'a' or 'b'
  for (char c : str) {
    if (c != 'a' && c != 'b')
      return false;
  }

  // Must end with "abb"
  if (str[n - 3] == 'a' && str[n - 2] == 'b' && str[n - 1] == 'b')
    return true;

  return false;
}

int main() {
  string str;

  cout << "Enter a string: ";
  cin >> str;

  if (isValid(str))
    cout << "Valid string" << endl;
  else
    cout << "Invalid string" << endl;

  return 0;
}
