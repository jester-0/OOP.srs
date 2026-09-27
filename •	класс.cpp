#include "Employee.h"
#include <iostream>
#include <stdexcept>

// ---- Әдепкі конструктор ----
Employee::Employee()
    : fullName(""), position(""), salary(0.0),
      bonusHistory(nullptr), monthsCount(0) {
}

// ---- Параметрлі конструктор ----
Employee::Employee(const std::string& fullName,
                    const std::string& position,
                    double salary,
                    const double* bonuses,
                    int monthsCount)
    : fullName(fullName), position(position), salary(salary),
      bonusHistory(nullptr), monthsCount(monthsCount) {
    if (monthsCount > 0 && bonuses != nullptr) {
        bonusHistory = new double[monthsCount];
        for (int i = 0; i < monthsCount; ++i) {
            bonusHistory[i] = bonuses[i];
        }
    }
}

// ---- Көшірме конструктор (deep copy) ----
// bonusHistory динамикалық жадыда сақталатындықтан, жаңа жад бөлініп,
// мәндер сол жерге көшіріледі (тек указательді көшірмейміз).
Employee::Employee(const Employee& other)
    : fullName(other.fullName), position(other.position),
      salary(other.salary), bonusHistory(nullptr),
      monthsCount(other.monthsCount) {
    if (monthsCount > 0 && other.bonusHistory != nullptr) {
        bonusHistory = new double[monthsCount];
        for (int i = 0; i < monthsCount; ++i) {
            bonusHistory[i] = other.bonusHistory[i];
        }
    }
}

// ---- Деструктор ----
Employee::~Employee() {
    delete[] bonusHistory;
    bonusHistory = nullptr;
}

// ---- Геттерлер ----
std::string Employee::getFullName() const {
    return this->fullName;
}

std::string Employee::getPosition() const {
    return this->position;
}

double Employee::getSalary() const {
    return this->salary;
}

int Employee::getMonthsCount() const {
    return this->monthsCount;
}

double Employee::getBonus(int index) const {
    if (index < 0 || index >= monthsCount) {
        throw std::out_of_range("Bonus index out of range");
    }
    return bonusHistory[index];
}

void Employee::printBonusHistory() const {
    std::cout << this->fullName << " бонустар тарихы: ";
    if (monthsCount == 0) {
        std::cout << "(деректер жоқ)";
    }
    for (int i = 0; i < monthsCount; ++i) {
        std::cout << bonusHistory[i];
        if (i != monthsCount - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

// ---- Сеттерлер ----
void Employee::setFullName(const std::string& newFullName) {
    this->fullName = newFullName;
}

void Employee::setPosition(const std::string& newPosition) {
    this->position = newPosition;
}

void Employee::setSalary(double newSalary) {
    if (newSalary < 0) {
        throw std::invalid_argument("Salary cannot be negative");
    }
    this->salary = newSalary;
}

void Employee::setBonus(int index, double value) {
    if (index < 0 || index >= monthsCount) {
        throw std::out_of_range("Bonus index out of range");
    }
    this->bonusHistory[index] = value;
}

// Бонустар тарихын толығымен ауыстырады (ескі жад тазаланып, жаңа жад бөлінеді)
void Employee::setBonusHistory(const double* bonuses, int count) {
    delete[] this->bonusHistory;
    this->bonusHistory = nullptr;
    this->monthsCount = count;
    if (count > 0 && bonuses != nullptr) {
        this->bonusHistory = new double[count];
        for (int i = 0; i < count; ++i) {
            this->bonusHistory[i] = bonuses[i];
        }
    }
}

// ---- Меншіктеу операторы (=) ----
Employee& Employee::operator=(const Employee& other) {
    if (this == &other) {          // өзін-өзіне меншіктеуден сақтану
        return *this;
    }

    this->fullName = other.fullName;
    this->position = other.position;
    this->salary = other.salary;

    delete[] this->bonusHistory;   // ескі жадты босату
    this->bonusHistory = nullptr;
    this->monthsCount = other.monthsCount;

    if (monthsCount > 0 && other.bonusHistory != nullptr) {
        this->bonusHistory = new double[monthsCount];
        for (int i = 0; i < monthsCount; ++i) {
            this->bonusHistory[i] = other.bonusHistory[i];
        }
    }

    return *this;
}

// ---- Теңдік операторы (==) ----
// Тапсырма бойынша: аты-жөні мен лауазымы бірдей болса, объектілер тең деп саналады
bool Employee::operator==(const Employee& other) const {
    return (this->fullName == other.fullName) &&
           (this->position == other.position);
}

// ---- Ақпаратты шығару ----
void Employee::printInfo() const {
    std::cout << "Аты-жөні: " << fullName
              << " | Лауазымы: " << position
              << " | Жалақысы: " << salary << std::endl;
}
