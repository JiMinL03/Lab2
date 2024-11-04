#include <iostream>
#include <string>
#include <map>

struct Student {
    std::string name;
    int mid;
    int final;
};

int main() {
    int n;
    std::map<std::string, Student> studentMap;

    std::cout << "학생 수를 입력하세요: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        Student student;
        std::cout << "이름, 중간 점수, 기말 점수를 입력하세요: ";
        std::cin >> student.name >> student.mid >> student.final;

        // std::map에 추가
        auto result = studentMap.insert({student.name, student});
        if (result.second) {
            std::cout << "\"" << student.name << "\"님이 트리에 추가되었습니다.\n";
        } else {
            std::cout << "\"" << student.name << "\"님이 트리에 이미 존재합니다.\n";
        }
    }

    std::cout << "\n학생 목록:\n";
    for (const auto &entry : studentMap) {
        const Student &s = entry.second;
        std::cout << "이름=" << s.name 
                  << ", 중간점수=" << s.mid 
                  << ", 기말점수=" << s.final << "\n";
    }

    return 0;
}

