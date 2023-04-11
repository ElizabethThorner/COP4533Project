#include <iostream>
#include <vector>
#include <chrono>
#include <random> 
#include <tuple>
#include <algorithm>

void Task1 (std::vector<std::vector<int>>& stocks) {
    int profit = 0;
    int stock = 0;
    int buyDay = 0;
    int sellDay = 0;
    for (int i = 0; i < stocks.size(); i++) { //This loops through the stocks
        for (int j = 0; j < stocks[i].size() - 1; j++) { //This loops through the potential buy days
            int buy = stocks[i][j]; //Buy day stock price
            for (int k = j + 1; k < stocks[i].size(); k++) { //This loops through the potential sell days
                int tempProfit = stocks[i][k] - buy; //Sell day stock price minus buy day stock price
                if (tempProfit > profit) {
                    profit = tempProfit;
                    stock = i;
                    buyDay = j;
                    sellDay = k;
                }
            }
        }
    }
    std::cout << stock << " " << buyDay << " " << sellDay << std::endl;
}

void Task2(std::vector<std::vector<int>>& stocks) {
    int profit = 0;
    int stock = 0;
    int buyDay = 0;
    int sellDay = 0;
    for (int i = 0; i < stocks.size(); i++) {
        int minPrice = INT_MAX;
        int minIndex = -1;
        //minPrice and minIndex values are placeholders
        for (int j = 0; j < stocks[i].size(); j++) {
            int tempProfit = stocks[i][j] - minPrice;
            //tempProfit stores the current stock price subtracted by the smallest stock price stored for this stock
            if (tempProfit < 0) {
                /* If tempProfit is less than zero then stocks[i][j] is less than minPrice.
                 This will always be true on the first loop */
                minPrice = stocks[i][j];
                minIndex = j;
            } else if (tempProfit > profit) { //Can't be true if first branch is true because profit is 0 at minimum
                profit = tempProfit;
                stock = i;
                buyDay = minIndex;
                sellDay = j;
            }
        }
    }
    std::cout << stock << " " << buyDay << " " << sellDay << std::endl;
}

void Task3a(std::vector<std::vector<int>>& stocks) {

}

void Task3b(std::vector<std::vector<int>>& stocks) {
    /*int profit = 0;
    int stock = 0;
    int buyDay = 0;
    int sellDay = 0;
    for (int i = 0; i < stocks.size(); i++) {
        std::vector<int> differences(stocks.size() - 1);
        for (int j = 0; j < stocks[i].size() - 1; j++) {
            differences[i] = stocks[i][j + 1] - stocks[i][j];
        }
        int localMax = 0;
        int max = 0;
        for (int j = 0; j < differences.size(); j++) {
            localMax = std::max(differences[i], differences[i] + localMax);
            if ()

        }
    }*/

}

void Task4(std::vector<std::vector<int>>& stocks, int k) {
    std::vector<std::tuple<int, int, int>> vecTrans; //This stores the stock, buy day, and sell day values for different transactions

    for (int numTransact = 0; numTransact < k; numTransact++) {
        int profit = 0;
        int stock = 0;
        int buyDay = 0;
        int sellDay = 0;

        for (int i = 0; i < stocks.size(); i++) {
            for (int j = 0; j < stocks[i].size(); j++) {
                int buy = stocks[i][j];
                for (int s = j + 1; s < stocks[i].size(); s++) {
                    int tempProfit = stocks[i][s] - buy;
                    if (tempProfit > profit) {
                        bool addCheck = true;
                        for (auto&& v : vecTrans) { 
                            //Need to ensure that the buy and sell days don't intersect with 
                            //what was stored for any previous transaction, because we can only hold one stock at a time
                            if ((buyDay >= std::get<1>(v) && buyDay <= std::get<2>(v)) || (sellDay >= std::get<1>(v) && sellDay <= std::get<2>(v))) {
                                addCheck = false;
                            }
                        }
                        if (addCheck) {
                            profit = tempProfit;
                            stock = i;
                            buyDay = j;
                            sellDay = s;
                        }
                    }
                }
            }
        }
        vecTrans.emplace_back(stock, buyDay, sellDay);
    }
    
    for(auto&& v : vecTrans){
        std::cout << std::get<0>(v)  << " " << std::get<1>(v) << " " << std::get<2>(v) << std::endl;
        //This prints the stock, buy day, and sell day for each transaction
    }
}

void Task5(std::vector<std::vector<int>>& stocks, int k) {

}

void Task6(std::vector<std::vector<int>>& stocks, int k) {

}

int main(int argc, char *argv[]) {
    std::string taskInput = argv[0]; //This takes in the argument indicating the task to be executed
    int k = 0;
    if ((taskInput == "Stocks 4") || (taskInput == "Stocks 5") || (taskInput == "Stocks 6")) { //Because k is only used for Problem 2
        std::cin >> k; //This takes in line 1 of the input for Problem 2
    }
    std::string input;
    std::getline(std::cin, input); //This takes in line 1 for the input for Problem 1 or line 2 of the input for Problem 2
    int m = std::stoi(input.substr(0, input.find(' '))); //This parses the input to find m
    std::vector<std::vector<int>> stocks(m); //This initializes the matrix
    int n = std::stoi(input.substr(input.find(' ') + 1)); //This parses the input to find n
    for (int i = 0; i < m; i++) { //This goes through the following m lines of input
        std::vector<int> column(n); //This initializes the column to be added to the matrix
        std::getline(std::cin, input); //This takes in the input
        std::string integer;
        int columnIndex = 0;
        for (int j = 0; j < input.length(); j++) { //This loop parses the input to add each integer to the column
            if ((input[j] == ' ') || (j == input.length() - 1)) {
                column[columnIndex] = std::stoi(integer);
                integer = "";
                columnIndex++;
            } else {
                integer += input[j];
            }
        }
        stocks[i] = column; //The column is added to the matrix
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

