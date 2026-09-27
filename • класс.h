#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

// Қызметкер (Employee) класы
// Инкапсуляция принципіне негізделген: барлық өрістер private,
// оларға қатынау тек геттер/сеттер арқылы жүзеге асады.
class Employee {
private:
    std::string fullName;   // қызметкердің аты-жөні
    std::string position;   // лауазымы
    double salary;          // жалақысы

    double* bonusHistory;   // бонустар тарихы — динамикалық жадыда (new арқылы) сақталады
    int monthsCount;        // тарихтағы айлар саны (bonusHistory массивінің өлшемі)

public:
    // ---- Конструкторлар мен деструктор ----
    Employee();                                               // әдепкі конструктор
    Employee(const std::string& fullName,
             const std::string& position,
             double salary,
             const double* bonuses,
             int monthsCount);                                 // параметрлі конструктор
    Employee(const Employee& other);                           // көшірме конструктор (deep copy)
    ~Employee();                                                // деструктор

    // ---- Геттерлер (const әдістер) ----
    std::string getFullName() const;
    std::string getPosition() const;
    double getSalary() const;
    int getMonthsCount() const;
    double getBonus(int index) const;
    void printBonusHistory() const;

    // ---- Сеттерлер ----
    void setFullName(const std::string& newFullName);
    void setPosition(const std::string& newPosition);
    void setSalary(double newSalary);
    void setBonus(int index, double value);
    void setBonusHistory(const double* bonuses, int count);

    // ---- Операторларды артық жүктеу ----
    Employee& operator=(const Employee& other);   // меншіктеу операторы (deep copy)
    bool operator==(const Employee& other) const; // теңдік: аты-жөні мен лауазымы бірдей болса, тең

    // ---- Көмекші әдіс ----
    void printInfo() const;
};

#endif // EMPLOYEE_H
