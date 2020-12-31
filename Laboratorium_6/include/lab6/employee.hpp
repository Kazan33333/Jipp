#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

class Employee {
    private:
        std::string ID;
        std::string name;
        std::string surname;
        std::string departmentID;
        std::string position;
    public:
        Employee(std::string ID, std::string name, std::string surname, std::string departmentID, std::string position);
        std::string get_ID();
        std::string get_name();
        std::string get_surname();
        std::string get_departmentID();
        std::string get_position();
        void printEmployees();
};

#endif
