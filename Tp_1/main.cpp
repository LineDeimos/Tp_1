#include <iostream>
#include "Keeper.h"

int main() {
    Keeper keeper;

    while (true) {
        std::cout << "\nMenu:\n\n";
        std::cout << "1. Add an object \"Hero\"\n";
        std::cout << "2. Add an object \"Monster\"\n";
        std::cout << "3. Add an object \"Villain\"\n";
        std::cout << "4. Remove an object\n";
        std::cout << "5. Save to a file\n";
        std::cout << "6. Load from a file\n";
        std::cout << "7. Display object\n";
        std::cout << "8. Display all objects\n";
        std::cout << "0. Exit\n\n";
        std::cout << ">> ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();  // Очистить буфер после ввода числа
        std::cout << '\n';

        switch (choice) {
        case 1: {
            std::string name, weapon;
            std::string skills[MAX_SKILLS];
            int numSkills = 0;

            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter weapon: ";
            std::getline(std::cin, weapon);
            std::cout << "Enter skills (one per line, empty line to finish, maximum " << MAX_SKILLS << " skills):\n";

            while (numSkills < MAX_SKILLS) {
                std::string skill;
                std::getline(std::cin, skill);
                if (skill.empty()) {
                    break;
                }
                skills[numSkills] = skill;
                numSkills++;
            }

            Hero* obj = new Hero(name, weapon, skills, numSkills);
            keeper.AddObjectHero(obj);
            system("Pause");
            break;
        }
        case 2: {
            std::string name, description;

            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter appearance description: ";
            std::getline(std::cin, description);

            Monster* obj = new Monster(name, description);
            keeper.AddObjectMonster(obj);
            system("Pause");
            break;
        }
        case 3: {
            std::string name, weapon, crime, location;
            std::string skills[MAX_SKILLS];
            int numSkills = 0;

            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter weapon: ";
            std::getline(std::cin, weapon);
            std::cout << "Enter crime: ";
            std::getline(std::cin, crime);
            std::cout << "Enter location: ";
            std::getline(std::cin, location);
            std::cout << "Enter skills (one per line, empty line to finish, maximum " << MAX_SKILLS << " skills):\n";

            while (numSkills < MAX_SKILLS) {
                std::string skill;
                std::getline(std::cin, skill);
                if (skill.empty()) {
                    break;
                }
                skills[numSkills] = skill;
                numSkills++;
            }

            Villain* obj = new Villain(name, weapon, crime, location, skills, numSkills);
            keeper.AddObjectVillain(obj);
            system("Pause");
            break;
        }
        case 4: {
            std::string name;
            std::cout << "Enter the name of the object to remove: ";
            std::getline(std::cin, name);
            keeper.RemoveObject(name);
            system("Pause");
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Enter the filename to save to: ";
            std::getline(std::cin, filename);
            keeper.SaveToFile(filename);
            system("Pause");
            break;
        }
        case 6: {
            std::string filename;
            std::cout << "Enter the filename to load from: ";
            std::getline(std::cin, filename);
            keeper.LoadFromFile(filename);
            system("Pause");
            break;
        }
        case 7: {
            std::string name;
            system("cls");
            keeper.DisplayListOfObjects();
            std::cout << "Enter the name of the object to display: ";
            std::getline(std::cin, name);
            std::cout << '\n';
            keeper.DisplayOne(name);
            system("Pause");
            break;
        }
        case 8: {
            keeper.DisplayAll();
            system("Pause");
            break;
        }
        case 0:
            return 0;

        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
            system("Pause");
        }
        system("cls");
    }

	return 0;
}