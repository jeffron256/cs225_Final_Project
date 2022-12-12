#include "utils.h"
#include <sstream>
#include <fenv.h>
#include <signal.h>
#include <vector>

std::string file_to_string(const std::string& filename){
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}

std::string TrimRight(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(tmp.find_last_not_of(" ") + 1);
}

std::string TrimLeft(const std::string & str) {
    std::string tmp = str;
    return tmp.erase(0, tmp.find_first_not_of(" "));
}

std::string Trim(const std::string & str) {
    std::string tmp = str;
    return TrimLeft(TrimRight(str));
}

int SplitString(const std::string & str1, char sep, std::vector<std::string> &fields) {
    std::string str = str1;
    std::string::size_type pos;
    while((pos=str.find(sep)) != std::string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
    return fields.size();
}

bool cmp(std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
    return a.second > b.second;
}

std::string type_name(const Graph& g, std::array<char, 30>& input) {
    std::vector<Vertex> vertices = g.getVertices();
    std::string output;

    bool flag_1 = false;
    while (!flag_1) {
        if (std::fgets(input.data(), input.size(), stdin) != NULL) {
            for (auto i : vertices) {
                auto tmp = i + '\n';
                if (tmp == input.data()) {
                    flag_1 = true;
                    output = i;
                    break;
                }
            }

            if (flag_1) {
                break;
            } else {
                printf("Sorry we did not find your entered stop in our database. Please re-enter the stop name\n");
            }

        } else if (std::feof(stdin)) {
            std::puts("Your Bus stop name is too long!\n");
        } else if (std::ferror(stdin)) {
            std::puts("IO error\n");
        } else {
            std::puts("Unknown error\n");
        }
    }
    return output;
}