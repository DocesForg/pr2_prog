#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct MilitaryPerson {
    std::string lastName;
    std::string firstName;
    std::string middleName;
    std::string address;
    std::string nationality;
    std::string dateOfBirth;
    std::string position;
    std::string rank;
};

int main() {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("Voen.txt");
    std::vector<MilitaryPerson> militaryPersons;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string item;

            MilitaryPerson person;
            int i = 0;
            while (std::getline(iss, item, ';')) {
                switch (i) {
                case 0:
                    person.lastName = item;
                    break;
                case 1:
                    person.firstName = item;
                    break;
                case 2:
                    person.middleName = item;
                    break;
                case 3:
                    person.address = item;
                    break;
                case 4:
                    person.nationality = item;
                    break;
                case 5:
                    person.dateOfBirth = item;
                    break;
                case 6:
                    person.position = item;
                    break;
                case 7:
                    person.rank = item;
                    break;
                }
                i++;
            }

            if (person.rank == "лейтенант") {
                militaryPersons.push_back(person);
            }
        }

        file.close();

        for (const auto& person : militaryPersons) {
            std::cout << "ФИО: " << person.lastName << " " << person.firstName << " " << person.middleName << std::endl;
            std::cout << "Домашний адрес: " << person.address << std::endl;
            std::cout << "Национальность: " << person.nationality << std::endl;
            std::cout << "Дата рождения: " << person.dateOfBirth << std::endl;
            std::cout << "Должность: " << person.position << std::endl;
            std::cout << "Звание: " << person.rank << std::endl;
            std::cout << std::endl;
        }
    }
    else {
        std::cerr << "Ошибка открытия файла!" << std::endl;
    }

    return 0;
}
