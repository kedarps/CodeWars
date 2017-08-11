#include <vector>
#include <string>
#include <iostream>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &array)
    {
      std::cout << "input: ";
      for(auto& x: array) {std::cout << x << " ";}
      std::cout << '\n' << "-----------------" << '\n';
      std::vector<std::string>::iterator itr = array.begin();

      while (itr != array.end()-1) {
          std::cout << "a" << '\n';

          if ((*itr == "NORTH" && *(itr+1) == "SOUTH") ||
          (*itr == "WEST" && *(itr+1) == "EAST") ||
          (*itr == "SOUTH" && *(itr+1) == "NORTH") ||
          (*itr == "EAST" && *(itr+1) == "WEST"))
          {
            std::cout << "array[i]: " << *itr << ", array[i+1]: " << *(itr+1) << '\n';
            std::cout << "deleting " << *(itr) << ":" << *(itr+1) << '\n';
            array.erase(itr, itr+2);

            if (array.empty()) { break; }
            itr = array.begin();
          }
          else{ itr++; }
      }
      return array;
    }
};

int main(int argc, char const *argv[]) {
  DirReduction dir;
  std::vector<std::string> d1 = {"NORTH", "WEST", "SOUTH", "EAST"};
  std::vector<std::string> d2 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};
  std::vector<std::string> d3 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH"};
  std::vector<std::string> d4 = {"NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH"};

  std::vector<std::string> out = dir.dirReduc(d4);

  std::cout << "output: " << '\n';
  for(auto& x: out) {std::cout << x << " ";}
  std::cout << '\n' << "-----------------" << '\n';

  return 0;
}
