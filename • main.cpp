#include <iostream>
#include "Employee.h"

int main() {
    // 1. Параметрлі конструктор арқылы объект жасау
    double bonuses1[] = {50000, 60000, 45000};
    Employee emp1("Асанов Асан Асанулы", "Бағдарламашы", 350000.0, bonuses1, 3);

    std::cout << "=== emp1 (параметрлі конструктор) ===" << std::endl;
    emp1.printInfo();
    emp1.printBonusHistory();

    // 2. Көшірме конструктор (deep copy тексеру)
    Employee emp2 = emp1;
    emp2.setBonus(0, 99999);   // emp2-нің бонусын өзгертеміз
    emp2.setFullName("Асанов Асан Асанулы (көшірме)");

    std::cout << "\n=== emp2 (emp1-ден көшірілген, содан кейін өзгертілген) ===" << std::endl;
    emp2.printInfo();
    emp2.printBonusHistory();

    std::cout << "\n=== emp1 өзгеріссіз қалды ма? (deep copy дәлелі) ===" << std::endl;
    emp1.printBonusHistory();

    // 3. Меншіктеу операторы (=)
    double bonuses3[] = {70000, 72000};
    Employee emp3("Қалиев Бауыржан Серикулы", "Менеджер", 500000.0, bonuses3, 2);
    Employee emp4;
    emp4 = emp3;   // operator=

    std::cout << "\n=== emp4 (emp3-тен меншіктелген) ===" << std::endl;
    emp4.printInfo();
    emp4.printBonusHistory();

    // 4. Теңдік операторы (==)
    Employee emp5("Қалиев Бауыржан Серикулы", "Менеджер", 480000.0, nullptr, 0);
    std::cout << "\n=== Теңдік тексеру (==) ===" << std::endl;
    std::cout << "emp3 == emp5 : " << (emp3 == emp5 ? "true (тең)" : "false (тең емес)")
              << " (аты-жөні мен лауазымы бірдей, жалақы әртүрлі болса да)" << std::endl;
    std::cout << "emp1 == emp3 : " << (emp1 == emp3 ? "true (тең)" : "false (тең емес)") << std::endl;

    // 5. Тұрақты (const) объект және const геттерлер
    const Employee constEmp("Нурланова Гүлмира Ерлановна", "Бухгалтер", 300000.0, bonuses3, 2);
    std::cout << "\n=== Тұрақты (const) объект ===" << std::endl;
    std::cout << "Аты-жөні (const get): " << constEmp.getFullName() << std::endl;
    std::cout << "Жалақысы (const get): " << constEmp.getSalary() << std::endl;
    // constEmp.setSalary(400000); // <- бұл жол компиляцияланбайды, себебі constEmp тұрақты объект

    return 0;
}
