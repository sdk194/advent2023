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

int minCubes(std::string query) {
  using namespace std;
  int rgb[] = {0, 0, 0};
  int sum = 1;
  string token;
  int queriedN;
  bool status = false;
  stringstream parse(query);
  while (getline(parse, token, ' ')) {    //parse this shit
    if (isNum(token)) {
      queriedN = stoi(token);
    }
    else if (token.find("red") != string::npos) {
      if (queriedN > rgb[0]) {
        rgb[0] = queriedN;
      }
    }
    else if (token.find("green") != string::npos) {
      if (queriedN > rgb[1]) {
        rgb[1] = queriedN;
      }
    }
    else if (token.find("blue") != string::npos) {
      if (queriedN > rgb[2]) {
        rgb[2] = queriedN;
      }
    }
  }

  for (size_t i = 0; i < 3; i++) {
    sum = sum * rgb[i];
  }
  return sum;
}

int main () {
  using namespace std;
  int sum  = 0;
  //int id = 0;
  string input;
  fstream file;
  file.open("test1.txt", ios::in);
  if (!file.is_open()) {
    return 1;
  }
  while (getline(file, input)) {
    sum += minCubes(input);
  }
  //cout << "total games played: " << id << "\n";
  cout << sum << "\n";
}
