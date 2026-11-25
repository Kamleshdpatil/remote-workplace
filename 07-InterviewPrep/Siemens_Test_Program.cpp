#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>

#define NUM_FIELDS 4
struct SplitLine {
  std::string fields[NUM_FIELDS];
};

/* DONT MAKE ANY CHANGES ABOVE THIS LINE */

/* If you wish you can include any more files here.
   (from standard libraries only) */

std::map<std::string, int> processData(std::vector<struct SplitLine> data) {
  std::map<std::string, std::pair<int, int>> deptInfo;
  
  for(const auto& row : data)
  {
    int empId = std::stoi(row.fields[0]);
    std::string dept = row.fields[2];
    int salary = std::stoi(row.fields[3]);
    
    auto it = deptInfo.find(dept);
    
    if(it == deptInfo.end() || empId > it->second.first)
    {
      deptInfo[dept] = {empId, salary};
    }
  }
  
  std::map<std::string, int> ret_val;
  
  for(const auto& entry : deptInfo)
  {
    ret_val[entry.first] = entry.second.second;
  }
  
  return ret_val;
}

/* DONT MAKE ANY CHANGES BELOW THIS LINE */

int main(void) {
  std::ifstream in("input.txt");
  std::vector<struct SplitLine> input_data;
  while (in) {
    struct SplitLine line;
    for (int i=0; i<NUM_FIELDS; i++) {
      if (i==NUM_FIELDS-1)
        std::getline(in, line.fields[i]);
      else
        std::getline(in, line.fields[i], ',');
    }
    if (line.fields[0] != "")
      input_data.push_back(line);
  }
  std::ofstream out("output.txt");
  std::map<std::string, int> ret_val = processData(input_data);
  for (std::map<std::string, int>::iterator it = ret_val.begin();
       it != ret_val.end();
       it++) {
    out << it->first << ": " << it->second << std::endl;
  }
  return 0;
}
