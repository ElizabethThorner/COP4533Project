#include <iostream>
#include <vector>

int main() {
    std::cout << "Input the task to be completed:" << std::endl;
    std::string taskInput;
    std::getline(std::cin, taskInput);
    int k = 0;
    if ((taskInput == "Stocks 4") || (taskInput == "Stocks 5") || (taskInput == "Stocks 6")) {
        std::cin >> k;
    }
    std::string input;
    std::getline(std::cin, input);
    int m = std::stoi(input.substr(0, input.find(' ')));
    std::vector<std::vector<int>> stocks(m);
    int n = std::stoi(input.substr(input.find(' ') + 1));
    for (int i = 0; i < m; i++) {
        std::vector<int> column(n);
        std::getline(std::cin, input);
        std::string integer;
        int columnIndex = 0;
        for (int j = 0; j < input.length(); j++) {
            if ((input[j] == ' ') || (j == input.length() - 1)) {
                column[columnIndex] = std::stoi(integer);
                integer = "";
                columnIndex++;
            } else {
                integer += input[j];
            }
        }
        stocks[i] = column;
    }
    return 0;
}


