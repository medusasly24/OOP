#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <stdexcept>

// Base class: Vehicle
class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;

public:
    Vehicle(const std::string& make, const std::string& model, int year)
        : make(make), model(model), year(year) {}

    virtual ~Vehicle() {}

    virtual void displayInfo() const {
        std::cout << "Vehicle: " << make << " " << model << " (" << year << ")" << std::endl;
    }

    virtual void saveToFile(std::ofstream& file) const = 0; // Pure virtual method
};

// Derived class: Car
class Car : public Vehicle {


public:
    Car(const std::string& make, const std::string& model, int year)
        : Vehicle(make, model, year) {}

    void displayInfo() const override {
        std::cout << "Car: " << make << " " << model << " (" << year << ") " << std::endl;
    }

    void saveToFile(std::ofstream& file) const override {
        file << "Car," << make << "," << model << "," << year << std::endl;
    }
};

// Derived class: Truck
class Truck : public Vehicle {
    double loadCapacity;

public:
    Truck(const std::string& make, const std::string& model, int year, double loadCapacity)
        : Vehicle(make, model, year), loadCapacity(loadCapacity) {}

    void displayInfo() const override {
        std::cout << "Truck: " << make << " " << model << " (" << year << ") with load capacity of "
                  << loadCapacity << " tons" << std::endl;
    }

    void saveToFile(std::ofstream& file) const override {
        file << "Truck," << make << "," << model << "," << year << "," << loadCapacity << std::endl;
    }
};

// Function to save vehicles to a file
void saveVehiclesToFile(const std::vector<std::shared_ptr<Vehicle>>& vehicles, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }

    for (const auto& vehicle : vehicles) {
        vehicle->saveToFile(file);
    }

    file.close();
}

// Menu function
void displayMenu() {
    std::cout << "\nTransport System Menu:\n";
    std::cout << "1. Add Car\n";
    std::cout << "2. Add Truck\n";
    std::cout << "3. Display All Vehicles\n";
    std::cout << "4. Save Vehicles to File\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    std::string filename = "vehicles.txt";

    while (true) {
        displayMenu();

        int choice;
        std::cin >> choice;

        try {
            if (choice == 1) {
                std::string make, model;
                int year, doors;
                std::cout << "Enter make: ";
                std::cin >> make;
                std::cout << "Enter model: ";
                std::cin >> model;
                std::cout << "Enter year: ";
                std::cin >> year;

                vehicles.push_back(std::make_shared<Car>(make, model, year));
            } else if (choice == 2) {
                std::string make, model;
                int year;
                double loadCapacity;
                std::cout << "Enter make: ";
                std::cin >> make;
                std::cout << "Enter model: ";
                std::cin >> model;
                std::cout << "Enter year: ";
                std::cin >> year;
                std::cout << "Enter load capacity (tons): ";
                std::cin >> loadCapacity;

                vehicles.push_back(std::make_shared<Truck>(make, model, year, loadCapacity));
            } else if (choice == 3) {
                for (const auto& vehicle : vehicles) {
                    vehicle->displayInfo();
                }
            } else if (choice == 4) {
                saveVehiclesToFile(vehicles, filename);
                std::cout << "Vehicles saved to file successfully.\n";
            } else if (choice == 5) {
                std::cout << "Exiting program.\n";
                break;
            } else {
                std::cout << "Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}
