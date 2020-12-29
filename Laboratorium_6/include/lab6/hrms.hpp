#include "employee.hpp"
#include <vector>
#include <map>
#include <algorithm>

class hrms {
    private:
        std::vector <class employee> employees;
        std::map <class employee, double> salaries;
    public:
        hrms();
        ~hrms();
        void add(employee employ, std::string departmentID, double salary);
        void printDepartment(std::string departmentID);
        void changeSalary(std::string employeeID, double salary);
        void printSalaries();
        void printSalariesSorted();
};
