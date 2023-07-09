#include <iostream>
#include <fstream>
#include <string>

void inspectSegment(const std::string& segment) {
    std::string path = "/proc/" + segment;
    std::ifstream file(path);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }
}

int main() {
    std::cout << "Kernel Parameter Inspection" << std::endl;

    std::string segment;
    std::cout << "Enter the segment you want to inspect: ";
    std::cin >> segment;

    inspectSegment(segment);

    return 0;
}
