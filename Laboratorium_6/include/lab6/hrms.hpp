#ifndef HRMS_HPP
#define HRMS_HPP
#include "employee.hpp"
#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>

class HRMS {
    private:
        std::map <std::string, class Employee> employees;
        std::map <std::string, std::vector<std::string>> departments;
        std::map <std::string, double> salaries;
    public:
        HRMS();
        void add(Employee employee, std::string departmentID, double salary) noexcept(false);
        void printDepartment(std::string departmentID) noexcept(false);
        void changeSalary(std::string employeeID, double salary) noexcept(false);
        void printSalaries();
        void printSalariesSorted();
};

#endif
