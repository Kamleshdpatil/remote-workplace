#include <vector>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>
#include <sstream>

#define NUM_FIELDS 4

struct SplitLine {
    std::string fields[NUM_FIELDS];
};

std::map<std::string, int> processData(std::vector<struct SplitLine> data) {
    std::map<std::string, std::pair<int, int>> department_to_id_salary;
    std::map<std::string, int> ret_val;

    for (const auto& line : data) {
        int emp_id = std::stoi(line.fields[0]);
        std::string department = line.fields[2];
        int salary = std::stoi(line.fields[3]);

        if (department_to_id_salary.find(department) == department_to_id_salary.end() ||
            emp_id > department_to_id_salary[department].first) {
            department_to_id_salary[department] = std::make_pair(emp_id, salary);
        }
    }

    for (const auto& entry : department_to_id_salary) {
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
        for (int i = 0; i < NUM_FIELDS; i++) {
            if (i != NUM_FIELDS - 1)
                std::getline(in, line.fields[i], ',');
            else
                std::getline(in, line.fields[i]);
        }
        if (line.fields[0] == "") continue;
        input_data.push_back(line);
    }

    std::ofstream out("output.txt");
    std::map<std::string, int> ret_val = processData(input_data);

    for (std::map<std::string, int>::iterator it = ret_val.begin(); it != ret_val.end(); it++) {
        out << it->first << ": " << it->second << std::endl;
    }

    return 0;
}