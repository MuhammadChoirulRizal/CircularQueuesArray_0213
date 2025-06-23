#include <iostream>
#include <string>

void printReff() {
    std::string reff[] = {
        "Reff:",
        "Mangu, oh mangu,",
        "Cintaku padamu takkan pudar,",
        "Mangu, oh mangu,",
        "Selamanya kau di hati."
    };

    for (const auto& line : reff) {
        std::cout << line << std::endl;
    }
}

int main() {
    std::cout << "Lirik Reff Lagu Mangu" << std::endl;
    std::cout << "=====================" << std::endl;
    printReff();
    return 0;
}

