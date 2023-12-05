#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
* puzzle 2 approach:
* have arrays representing the numbers as words
* so eg: array containing numbers starting with t, another array containing numbers starting with o, etc
* As u iterate through sentence, if its not a digit, check if its a number if the character being checked 
* is the same starting character of a number written in a word so eg if if ur checking letter 't' then u should
* try match it with any number that starts with the letter t 
* put all the numbers u encounter into a vector
* once done, just grab the first and last element of that vector
*/

std::string strNums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int findValue(std::string input) {
  using namespace std;
  vector<int> nums;
  int len;
  for (int i = 0; i < input.length(); i++) {
    if (isdigit(input[i])) {
      nums.push_back((int(input[i]) - '0')); 
    }
    else {
      for (int j = 1; j < 10; j++) {
        len = strNums[j].length();
        //cout << "length of " << strNums[j] << ": " << len << "\n";
        if (i + len < input.length() + 1) {
          //cout << input.substr(i, len) << "\n";
          if (strNums[j] == input.substr(i, len)) {
            //cout << j << "\n";
            nums.push_back(j);
            break;
          }
        }
      }
    }
  }
  return (nums.front() * 10) + nums.back();
}

int main() {
  using namespace std;
  int sum = 0;
  string input;
  fstream file;
  file.open("test1.txt", ios::in);
  if (!file.is_open()) {
    return 1;
  }
  while (getline(file, input)) {
    sum += findValue(input);
  }
  file.close();
  cout << sum << "\n";
  return 0;
}
