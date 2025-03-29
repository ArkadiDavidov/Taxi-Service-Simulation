#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <cmath>

class Taxi
{
private:
    int distance;
    std::string car_name;
    int price;
    std::string person_name;
    int experience;
    float rating;

public:
    Taxi(int distance1, std::string car_name1, int price1, std::string person_name1, int experience1, float rating1) {
        distance = distance1;
        car_name = car_name1;
        price = price1;
        person_name = person_name1;
        experience = experience1;
        rating = rating1;
    }

    void get_info(std::ostream& out) {
        out << "Distance: " << distance << std::endl;
        out << "Car name: " << car_name << std::endl;
        out << "The cost of the trip: " << price << std::endl;
        out << "Driver's name: " << person_name << std::endl;
    }

    void person_info(std::ostream& out) {
        out << "Driver's name: " << person_name << std::endl;
        out << "Driver's experience: " << experience << std::endl;
        out << "Driver's rating: " << rating << std::endl;
    }

    void stars(std::ostream& out, bool inputFromUser = true) {
        static int star;          
        static std::string comments;

        if (inputFromUser) {
            std::cout << "Rate the trip from 1 to 5" << std::endl;
            std::cin >> star;
            std::cin.ignore(); 

            switch (star) {
            case 5:
                std::cout << "Thanks for the review, what did you like about this driver? " << std::endl;
                std::getline(std::cin, comments);
                break;
            case 4:
            case 3:
                std::cout << "Thanks for the review, what did you like or confused about this driver? " << std::endl;
                std::getline(std::cin, comments);
                break;
            case 2:
            case 1:
                std::cout << "Thanks for the review, what did you confused about this driver? " << std::endl;
                std::getline(std::cin, comments);
                break;
            default:
                std::cout << "Invalid rating. Please try again." << std::endl;
                return;
            }
        }

)
        switch (star) {
        case 5:
            out << "Thanks for the review, what did you like about this driver? " << std::endl;
            out << comments << std::endl;
            out << "Thanks for the comment, have a good trip. " << std::endl;
            break;
        case 4:
        case 3:
            out << "Thanks for the review, what did you like or confused about this driver? " << std::endl;
            out << comments << std::endl;
            out << "Thanks for the comment, have a good trip. We will take our mistakes into account and correct them in the future." << std::endl;
            break;
        case 2:
        case 1:
            out << "Thanks for the review, what did you confused about this driver? " << std::endl;
            out << comments << std::endl;
            out << "Thanks for the comment, have a good trip. We will correct this misunderstanding soon. " << std::endl;
            break;
        }
    }

    std::string name_pack() {
        std::ifstream file("names_database.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return "";
        }

        int lineCount = 0;
        std::string line;
        while (std::getline(file, line)) {
            lineCount++;
        }

        srand(time(0));
        int randomLine = rand() % lineCount;

        file.clear();
        file.seekg(0, std::ios::beg);

        for (int i = 0; i <= randomLine; i++) {
            std::getline(file, person_name);
        }

        file.close();
        return person_name;
    }

    std::string cars_pack() {
        std::ifstream file1("cars_database.txt");
        if (!file1.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return "";
        }
        int lineCount1 = 0;
        std::string line1;
        while (std::getline(file1, line1)) {
            lineCount1++;
        }
        srand(time(0));
        int randomLine = rand() % lineCount1;

        file1.clear();
        file1.seekg(0, std::ios::beg);

        for (int i = 0; i <= randomLine; i++) {
            std::getline(file1, car_name);
        }

        file1.close();
        return car_name;
    }

    int dist_price() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(10000, 100000);

        distance = distrib(gen);

        return distance;
    }

    float rtng() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> distrib(1.0, 5.0);

        rating = distrib(gen);
        rating = floor(rating * 10 + 0.5) / 10;
        return rating;
    }

    int exp() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(1, 30);

        experience = distrib(gen);
        return experience;
    }
};
