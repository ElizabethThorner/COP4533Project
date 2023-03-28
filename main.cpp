#include <iostream>
#include <vector>

void Task1 (std::vector<std::vector<int>>& stocks) {

}

void Task2(std::vector<std::vector<int>>& stocks) {

}

void Task3a(std::vector<std::vector<int>>& stocks) {

}

void Task3b(std::vector<std::vector<int>>& stocks) {

}

void Task4(std::vector<std::vector<int>>& stocks, int k) {

}

void Task5(std::vector<std::vector<int>>& stocks, int k) {

}

void Task6(std::vector<std::vector<int>>& stocks, int k) {

}

int main() {
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
    if (taskInput == "Stocks 1") {
        Task1(stocks);
    } else if (taskInput == "Stocks 2") {
        Task2(stocks);
    } else if (taskInput == "Stocks 3a") {
        Task3a(stocks);
    } else if (taskInput == "Stocks 3b") {
        Task3b(stocks);
    } else if (taskInput == "Stocks 4") {
        Task4(stocks, k);
    } else if (taskInput == "Stocks 5") {
        Task5(stocks, k);
    } else {
        Task6(stocks, k);
    }
    return 0;
}
