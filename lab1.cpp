#include <cctype>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct SymbolEntry {
  string token;
  string category;
};

vector<SymbolEntry> symbolTable;

set<string> keywords = {"int",     "float", "double",   "char",   "void",
                        "bool",    "if",    "else",     "while",  "for",
                        "return",  "break", "continue", "switch", "case",
                        "default", "do"};

set<string> operators = {"+", "-",  "*",  "/",  "%",  "=",  "==", "!=",
                         "<", ">",  "<=", ">=", "&&", "||", "++", "--",
                         "!", "+=", "-=", "*=", "/=", "%="};

set<char> delimiters = {'(', ')', '{', '}', '[', ']', ';', ',', ':'};

bool isKeyword(const string &s) { return keywords.count(s); }

bool isOperator(const string &s) { return operators.count(s); }

bool isDelimiter(char c) { return delimiters.count(c); }

void addToken(string token, string category) {
  symbolTable.push_back({token, category});
}

int main() {
  ifstream file("code.txt");

  if (!file) {
    cout << "Cannot open code.txt\n";
    return 1;
  }

  string line;

  while (getline(file, line)) {
    int i = 0;

    while (i < line.length()) {

      // Ignore whitespace
      if (isspace(line[i])) {
        i++;
        continue;
      }

      // Identifier or Keyword
      if (isalpha(line[i]) || line[i] == '_') {
        string token;

        while (i < line.length() && (isalnum(line[i]) || line[i] == '_')) {
          token += line[i];
          i++;
        }

        if (isKeyword(token))
          addToken(token, "Keyword");
        else
          addToken(token, "Identifier");

        continue;
      }

      // Number (integer or float)
      if (isdigit(line[i])) {
        string token;
        int dotCount = 0;

        while (i < line.length() && (isdigit(line[i]) || line[i] == '.')) {

          if (line[i] == '.')
            dotCount++;

          token += line[i];
          i++;
        }

        if (dotCount == 0)
          addToken(token, "Integer Constant");
        else
          addToken(token, "Float Constant");

        continue;
      }

      // Two-character operators
      if (i < line.length() - 1) {
        string twoCharOp = line.substr(i, 2);

        if (isOperator(twoCharOp)) {
          addToken(twoCharOp, "Operator");
          i += 2;
          continue;
        }
      }

      // One-character operator
      string oneCharOp(1, line[i]);
      if (isOperator(oneCharOp)) {
        addToken(oneCharOp, "Operator");
        i++;
        continue;
      }

      // Delimiter
      if (isDelimiter(line[i])) {
        addToken(string(1, line[i]), "Delimiter");
        i++;
        continue;
      }

      // Unknown character
      addToken(string(1, line[i]), "Unknown");
      i++;
    }
  }

  file.close();

  cout << "\n    SYMBOL TABLE\n\n";
  cout << "| LEXEME\t| TOKEN\n";
  cout << "---------------------------------------\n";

  for (auto entry : symbolTable) {
    if (entry.token.length() < 6)
      cout << "| " << entry.token << "\t\t| " << entry.category << endl;
    else
      cout << "| " << entry.token << "\t| " << entry.category << endl;
  }

  return 0;
}
