#include <iostream>

class employee {
    friend class hrms;
    private:
        std::string ID;
        std::string name;
        std::string surname;
        std::string departmentID;
        std::string position;
    public:
        employee(std::string ID, std::string name, std::string surname, std::string departmentID, std::string position);
        ~employee();
        std::string get_ID();
        std::string get_name();
        std::string get_surname();
        std::string get_departmentID();
        std::string get_position();
};