#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Kata
{
public:
    std::vector<std::string> sortByLength(std::vector<std::string> array)
    {
        std::vector<std::string> sortedArray;
        std::vector< std::pair<int, int> > strLens;

        for (int i = 0; i < array.size(); i++) {
          std::pair<int, int> thisPair (array[i].size(), i);
          strLens.push_back(thisPair);
        }

        std::sort(strLens.begin(), strLens.end());
        for(auto& x:strLens) {
          std::cout << "value: " << x.first << ", index: " << x.second << '\n';
          sortedArray.push_back(array[x.second]);
        }

        for(auto& x:sortedArray) {std::cout << x << '\n';}

        return sortedArray;
    }
};

int main(int argc, char const *argv[]) {

  Kata kata;
  std::vector<std::string> actual = kata.sortByLength({ "Longer", "Longest", "Short" });

  return 0;
}
