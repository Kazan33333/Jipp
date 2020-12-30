#include "employee.hpp"
#include <vector>
#include <map>
#include <algorithm>

class HRMS {
    private:
        std::map <std::string, class Employee> employees;
        std::map <std::string, std::vector<std::string>> departments;
        std::map <std::string, double> salaries;
    public:
        HRMS();
        ~HRMS();
        void add(Employee employee, std::string departmentID, double salary);
        void printDepartment(std::string departmentID);
        void changeSalary(std::string employeeID, double salary);
        void printSalaries();
        void cmp();
        void printSalariesSorted();
};
