#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

struct Expense {
    std::string date;
    std::string category;
    double amount;
};

class ExpenseManager {
private:
    std::vector<Expense> expenses;

    void saveToFile() {
        std::ofstream file("expenses.txt");
        if (file.is_open()) {
            for (const auto& expense : expenses) {
                file << expense.date << "," << expense.category << "," << expense.amount << "\n";
            }
            file.close();
        }
    }

    void loadFromFile() {
        std::ifstream file("expenses.txt");
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                Expense expense;
                size_t pos1 = line.find(",");
                size_t pos2 = line.rfind(",");
                expense.date = line.substr(0, pos1);
                expense.category = line.substr(pos1 + 1, pos2 - pos1 - 1);
                expense.amount = std::stod(line.substr(pos2 + 1));
                expenses.push_back(expense);
            }
            file.close();
        }
    }

public:
    ExpenseManager() {
        loadFromFile();
    }

    ~ExpenseManager() {
        saveToFile();
    }

    void addExpense(const std::string& date, const std::string& category, double amount) {
        expenses.push_back({date, category, amount});
        std::cout << "Expense added successfully!\n";
    }

    void viewExpenses() {
        std::cout << std::setw(15) << "Date" << std::setw(15) << "Category" << std::setw(10) << "Amount\n";
        for (const auto& expense : expenses) {
            std::cout << std::setw(15) << expense.date << std::setw(15) << expense.category
                      << std::setw(10) << expense.amount << "\n";
        }
    }

    void viewSummaryByCategory() {
        std::map<std::string, double> categorySummary;
        for (const auto& expense : expenses) {
            categorySummary[expense.category] += expense.amount;
        }
        std::cout << "Category-wise Summary:\n";
        for (const auto& summary : categorySummary) {
            std::cout << summary.first << ": $" << summary.second << "\n";
        }
    }
};

int main() {
    ExpenseManager manager;
    int choice;

    do {
        std::cout << "\nExpense Tracker Menu:\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. View All Expenses\n";
        std::cout << "3. View Summary by Category\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string date, category;
            double amount;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::cin >> date;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cout << "Enter amount: ";
            std::cin >> amount;
            manager.addExpense(date, category, amount);
            break;
        }
        case 2:
            manager.viewExpenses();
            break;
        case 3:
            manager.viewSummaryByCategory();
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
