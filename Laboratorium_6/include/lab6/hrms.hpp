#include "employee.hpp"
#include <vector>
#include <list>
#include <map>
#include <algorithm>

class HRMS {
    private:
        std::list <class Employee> employees;
        std::map <std::string, class employee> departments;
        std::map <class Employee, double> salaries;
        std::vector <class Employee, double> sort;
    public:
        HRMS();
        ~HRMS();
        void add(Employee employee, std::string departmentID, double salary);
        void printDepartment(std::string departmentID);
        void changeSalary(std::string employeeID, double salary);
        void printSalaries();
        void printSalariesSorted();
};
