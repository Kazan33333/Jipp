#include "../include/lab6/hrms.hpp"

void HRMS::add(Employee employee, std::string departmentID, double salary)
{
    this -> employees[employee.get_ID()];
    this -> departments[employee.get_departmentID()].push_back(employee.get_ID());
    this -> salaries[employee.get_ID()] = salary;
}

void HRMS::printDepartment(std::string departmentID)
{
    std::cout << "Employees from " << departmentID << " department: " << std::endl;
    for(auto &element : departments[departmentID]) {
        std::cout << element << std::endl;
        employees.at(element).printEmployees();
    }
}

void HRMS::changeSalary(std::string employeeID, double salary)
{
    this -> salaries[employeeID] = salary;
}

void HRMS::printSalaries()
{
    std::cout << "|--------------- List of employees: ---------------|" << std::endl;
    for(auto &element : this -> salaries) {
        std::cout << "ID: " << element.first << std::endl;
        std::cout << "Name: " << employees.at(element.first).get_name() << std::endl;
        std::cout << "Surname: " << employees.at(element.first).get_surname() << std::endl;
        std::cout << "Department: " << employees.at(element.first).get_departmentID() << std::endl;
        std::cout << "Position: " << employees.at(element.first).get_position() << std::endl;
        std::cout << "Salary: " << element.second << std::endl;
        std::cout << "---------------------------------------------------" << std::endl << std::endl;
    }
}

void HRMS::printSalariesSorted()
{
    std::vector < std::pair <Employee, double>> sorted;
    for(auto &element : employees) {
        sorted.push_back(std::make_pair(element.second, this -> salaries[element.second.get_ID()]));
    }

    std::sort(sorted.begin(), sorted.end(), [](std::pair <Employee, double>& a, std::pair <Employee, double>& b) {
        return (a.second > b.second);
    });

    std::cout << "|------- List of employees sorted by salary: -------|" << std::endl;
    for(auto &element : sorted) {
        std::cout << "ID: " << element.first.get_ID() << std::endl;
        std::cout << "Name: " << element.first.get_name() << std::endl;
        std::cout << "Surname: " << element.first.get_surname() << std::endl;
        std::cout << "Department: " << element.first.get_departmentID() << std::endl;
        std::cout << "Position: " << element.first.get_position() << std::endl;
        std::cout << "Salary: " << element.second << std::endl;
        std::cout << "----------------------------------------------------" << std::endl << std::endl;
    }
}
