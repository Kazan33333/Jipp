#include "../include/lab6/hrms.hpp"

int main()
{
    Employee a("11", "Michael", "Scott", "D1", "Regional Manager");
    Employee b("12", "Pam", "Beesly", "D1", "Office Administrator");
    Employee c("13", "Darryl", "Philbin", "D1", "Warehouse Manager");
    Employee d("21", "Jim", "Halpert", "D2", "Sales Representative");
    Employee e("22", "Dwight", "Schrute", "D2", "Sales Representative");
    Employee f("23", "Andy", "Bernard", "D2", "Sales Representative");
    Employee g("24", "Stanley", "Hudson", "D2", "Sales Representative");
    Employee h("25", "Phyllis", "Vance", "D2", "Sales Representative");
    Employee i("31", "Angela", "Martin", "D3", "Senior Accountant");
    Employee j("32", "Oscar", "Martinez", "D3", "Accountant");
    Employee k("33", "Kevin", "Malone", "D3", "Accountant");
    Employee l("41", "Creed", "Bratton", "D4", "Quality Assurance");
    Employee m("42", "Kelly", "Kapoor", "D4", "Customer Service");
    Employee n("43", "Meredith", "Palmer", "D4", "Supplier Relations");
    Employee o("44", "Erin", "Hannon", "D4", "Receptionist");
    Employee p("45", "Ryan", "Howard", "D4", "Temp");

    HRMS workers;
    workers.add(a, "D1", 5000);
    workers.add(b, "D1", 3800);
    workers.add(c, "D1", 3500);
    workers.add(d, "D2", 4000);
    workers.add(e, "D2", 4500);
    workers.add(f, "D2", 3500);
    workers.add(g, "D2", 3400);
    workers.add(h, "D2", 3300);
    workers.add(i, "D3", 4000);
    workers.add(j, "D3", 3800);
    workers.add(k, "D3", 3600);
    workers.add(l, "D4", 3200);
    workers.add(m, "D4", 3500);
    workers.add(n, "D4", 3200);
    workers.add(o, "D4", 2800);
    workers.add(p, "D4", 3000);

    workers.printDepartment("D4");
    std::cout << "\n\n\n\n";
    
    workers.printDepartment("D1");
    std::cout << "\n\n\n\n";

    workers.printSalaries();
    std::cout << "\n\n\n\n";

    workers.changeSalary(l.get_ID(), 3500);
    workers.changeSalary(o.get_ID(), 3300);
    workers.changeSalary(f.get_ID(), 4300);

    workers.printSalaries();
    std::cout << "\n\n\n\n";

    workers.printSalariesSorted();

    return 0;
}
