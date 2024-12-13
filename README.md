Transport System Application

This project is a C++ program that allows users to manage a collection of vehicles, including cars and trucks. The program provides a menu-driven interface to add vehicles, display their details, and save the vehicle information to a file.

Features

1. Add Car: Users can input the make, model, and year of a car to add it to the system.
2. Add Truck: Users can input the make, model, year, and load capacity of a truck to add it to the system.
3. Display All Vehicles: Displays the details of all vehicles currently in the system.
4. Save Vehicles to File: Saves all vehicle information to a text file named `vehicles.txt`.
5. Exit: Exits the program.

## Code Overview

Classes

- Vehicle: A base class that represents a generic vehicle. It contains:
  - `make`, `model`, and `year` attributes.
  - A virtual method `displayInfo()` for displaying vehicle details.
  - A pure virtual method `saveToFile()` for saving vehicle details to a file.

- Car: A derived class of `Vehicle` for representing cars. It overrides:
  - `displayInfo()` to display car-specific details.
  - `saveToFile()` to save car-specific details to a file.

- Truck: A derived class of `Vehicle` for representing trucks. It includes:
  - An additional `loadCapacity` attribute.
  - Overrides for `displayInfo()` and `saveToFile()` methods.

Functions

- `saveVehiclesToFile()`: Accepts a vector of vehicles and a filename, and saves the vehicle data to the specified file.
- `displayMenu()`: Displays the program menu to the user.

### Main Function

The `main()` function implements a menu-driven interface where users can interact with the program. Based on user input, it:
- Adds cars or trucks to a vector.
- Displays details of all vehicles.
- Saves the vehicle data to a file.
- Handles errors and invalid inputs gracefully.

How to Run the Program

1. Compile the Program:
   Use a C++ compiler (e.g., g++, Code::Blocks, Visual Studio) to compile the program.

   ```bash
   g++ -o transport_system main.cpp
   ```

2. Run the Executable:
   ```bash
   ./transport_system
   ```

3. Follow the Menu:
   Use the on-screen menu to interact with the system.

File Output

When you save vehicles to a file, they are stored in `vehicles.txt` in the following format:
- Cars: `Car,<make>,<model>,<year>`
- Trucks: `Truck,<make>,<model>,<year>,<loadCapacity>`

Example:
```
Car,Toyota,Corolla,2022
Truck,Ford,F-150,2021,5.0
```

Error Handling

- The program checks for file access errors when saving to a file.
- It also validates user input and displays appropriate error messages for invalid choices or unexpected conditions.

Dependencies

This project relies on the C++ Standard Library, which provides the following key functionalities:

- <iostream>: Enables input and output operations (e.g., reading user input, printing to the console).
- <vector>: Provides dynamic arrays to store and manage collections of vehicles.
- <string>: Offers robust string manipulation capabilities for vehicle attributes like make and model.
- <fstream>: Supports file operations to read from and write to external files (e.g., saving vehicle data).
- <memory>: Provides smart pointers (e.g., `std::shared_ptr`) to manage dynamic memory allocation safely and efficiently.
- <stdexcept>: Facilitates exception handling for robust error management (e.g., file access errors).

