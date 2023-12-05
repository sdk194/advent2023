#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

bool isNum(std::string query) {
  using namespace std;
  for (size_t i = 0; i < query.length(); i++) {
    if (!isdigit(query[i])) {
      return false;
    }
  }
  return true;
}

bool isValid(std::string query) {
  using namespace std;
  string token;
  int queriedN;
  bool status = false;
  stringstream parse(query);
  while (getline(parse, token, ' ')) {    //parse this shit
    if (isNum(token)) {
      queriedN = stoi(token);
    }
    else if (token.find("red") != string::npos) {
      if (queriedN > 12) {
        return false;
      }
    }
    else if (token.find("green") != string::npos) {
      if (queriedN > 13) {
        return false;
      }
    }
    else if (token.find("blue") != string::npos) {
      if (queriedN > 14) {
        return false;
      }
    }
  }
  return true;
}

int main () {
  using namespace std;
  int sum  = 0;
  int id = 0;
  string input;
  fstream file;
  file.open("test1.txt", ios::in);
  if (!file.is_open()) {
    return 1;
  }
  while (getline(file, input)) {
    id += 1;
    if (isValid(input)) {
      sum += id;
    }
  }
  cout << "total games played: " << id << "\n";
  cout << sum << "\n";
}
