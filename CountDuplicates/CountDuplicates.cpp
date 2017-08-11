#include <string>
#include <unordered_map>
#include <iostream>
#include <cctype>
#include <cstring>

size_t duplicateCount(const char* in)
{
  std::unordered_map<char, int> duplicateMap;
  std::string inString(in);

  for (int i = 0; i < inString.size(); i++) {
    const char thisChar = tolower(inString[i]);

    if ( isspace(thisChar) ) {
      continue;
    }

    std::unordered_map<char, int>::const_iterator mapIdx = duplicateMap.find (thisChar);
    if (mapIdx == duplicateMap.end()) {
      duplicateMap.insert(std::pair<char, int> (thisChar, 1));
    } else {
      int count  = duplicateMap[thisChar];
      duplicateMap[thisChar] = count+1;
    }
  }

  for(auto &x:duplicateMap) {
    std::cout << x.first << ":" << x.second << std::endl;
  }

  size_t numDuplicates = 0;
  for(auto &x:duplicateMap) {
     if (x.second > 1) {
       numDuplicates++;
     }
  }

  return numDuplicates;
}

int main(int argc, char const *argv[]) {
  size_t counts = duplicateCount("abcdefghijklmnopqrstuvwxyz");
  std::cout << "duplicates: " << counts << '\n';
  return 0;
}
