#include <iostream>
#include <string>

//today I found out there is a built in function to find substrings in c++
//Solution would have looked a lot nicer if I knew beforehand -_-

int main() {
  std::string main = "thisoneisastring";
  std::string subString;
  std::cin >> subString;
  std::size_t found = main.find(subString);
  if (found != std::string::npos) {
    std::cout << subString << " is first found starting at index " << found << "\n";
  }
  else {
    std:: cout << "not found\n";
  }
  return 0;
}
