#include "../include/lab6/employee.hpp"

Employee::Employee(std::string ID, std::string name, std::string surname, std::string departmentID, std::string position) {
    this -> ID = ID;
    this -> name = name;
    this -> surname = surname;
    this -> departmentID = departmentID;
    this -> position = position;
}

Employee::Employee(){}

std::string Employee::get_ID() {
    return this -> ID;
}

std::string Employee::get_name() {
    return this -> name;
}

std::string Employee::get_surname() {
    return this -> surname;
}

std::string Employee::get_departmentID() {
    return this -> departmentID;
}

std::string Employee::get_position() {
    return this -> position;
}

void Employee::printEmployees() {
    std::cout << "ID: " << this -> get_ID() << std::endl;
    std::cout << "Name: " << this -> get_name() << std::endl;
    std::cout << "Surname: " << this -> get_surname() << std::endl;
    std::cout << "Position: " << this -> get_position() << std::endl;
    std::cout << "Department ID: " << this -> get_departmentID() << std::endl;
}
