#include <iostream>
#include <string>
#include <vector>

using namespace std;

void removeLeftRecursion(string nt, vector<string> prods) {
  vector<string> alpha, beta;

  for (string p : prods) {
    if (p == "e") {
      beta.push_back("");
    } else if (!p.empty() && p[0] == nt[0]) {
      alpha.push_back(p.substr(1));
    } else {
      beta.push_back(p);
    }
  }

  // No left recursion case
  if (alpha.empty()) {
    cout << nt << " -> ";
    for (int i = 0; i < prods.size(); i++) {
      cout << prods[i];
      if (i != prods.size() - 1)
        cout << " | ";
    }
    cout << "\nNo left recursion in " << nt << "\n\n";
    return;
  }

  string newNT = nt + "'";

  // Print A → βA'
  cout << nt << " -> ";
  bool first = true;

  for (string b : beta) {
    if (!first)
      cout << " | ";
    first = false;

    if (b == "")
      cout << newNT;
    else
      cout << b << newNT;
  }
  cout << "\n";

  // Print A' → αA' | ε
  cout << newNT << " -> ";

  for (int i = 0; i < alpha.size(); i++) {
    cout << alpha[i] << newNT << " | ";
  }

  cout << "e\n\n";
}

int main() {
  int n;
  cout << "Enter number of non-terminals: ";
  cin >> n;

  while (n--) {
    string nt;
    int m;

    cout << "Enter Non-Terminal: ";
    cin >> nt;

    cout << "Number of productions: ";
    cin >> m;

    vector<string> prods(m);

    cout << "Enter productions (use 'e' for epsilon):\n";
    for (int i = 0; i < m; i++) {
      cin >> prods[i];
    }

    cout << "\nResult:\n";
    removeLeftRecursion(nt, prods);
  }

  return 0;
}
