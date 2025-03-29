#include <iostream>
#include <string>
#include "Taxi.h"
#include <iomanip>
#include <fstream>

int main() {
    int distance = 0, price = 0, experience = 0;
    std::string car_name, person_name;
    float rating = 0.0;
    int choice;

    Taxi taxi1(distance, car_name, price, person_name, experience, rating);

    std::ofstream out("save_database.txt");
    if (!out.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::cout << "1. Call a taxi\n2. Information about the driver\n3. Leave a review about the trip\n4. Exit" << std::endl;
   
    while (true) {
        std::cin >> choice;

        if (choice == 1) {
            // Генерируем новые данные при каждом вызове такси
            car_name = taxi1.cars_pack();
            person_name = taxi1.name_pack();
            experience = taxi1.exp();
            rating = taxi1.rtng();
            distance = taxi1.dist_price();
            price = distance * 0.3;
            taxi1 = Taxi(distance, car_name, price, person_name, experience, rating);

            std::cout << "Taxi search...\n";
            std::cout << "The taxi has been found, we are updating the information.\n";
            out << "Taxi search...\n";
            out << "The taxi has been found, we are updating the information.\n";
            taxi1.get_info(std::cout);
            taxi1.get_info(out);
        }
        else if (choice == 2) {
            taxi1.person_info(std::cout);
            taxi1.person_info(out);
        }
        else if (choice == 3) {
            // Первый вызов - ввод данных и вывод в консоль
            taxi1.stars(std::cout, true);
            // Второй вызов - вывод в файл (без запроса ввода)
            taxi1.stars(out, false);
        
    }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    out.close();
    return 0;
}