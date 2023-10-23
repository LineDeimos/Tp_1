#include "Keeper.h"
#include <iostream>
#include <fstream>
#include "FileExceptions.h"

Keeper::Keeper() {
    capacity = 10;  // Начальная емкость массива
    size = 0;
    objects = new BaseHero* [capacity];
    std::cout << "Keeper constructor called" << std::endl;
}

Keeper::Keeper(int initialCapacity) : capacity(initialCapacity), size(0) {
    objects = new BaseHero * [capacity];
}

// Конструктор копирования
Keeper::Keeper(const Keeper& other) : capacity(other.capacity), size(other.size) {
    objects = new BaseHero * [capacity];
    for (int i = 0; i < size; i++) {
        // Создаем копии объектов в массиве
        if (other.objects[i]->GetType() == CharacterType::TypeHero) {
            objects[i] = new Hero(*dynamic_cast<Hero*>(other.objects[i]));
        }
        else if (other.objects[i]->GetType() == CharacterType::TypeVillain) {
            objects[i] = new Villain(*dynamic_cast<Villain*>(other.objects[i]));
        }
        else if (other.objects[i]->GetType() == CharacterType::TypeMonster) {
            objects[i] = new Monster(*dynamic_cast<Monster*>(other.objects[i]));
        }
    }
}

Keeper::~Keeper() {
    for (int i = 0; i < size; i++) {
        delete objects[i];
    }
    delete[] objects;
    std::cout << "Keeper destructor called" << std::endl;
}

void Keeper::AddObjectHero(Hero* obj) {
    if (size == capacity) {
        Resize(capacity * 2);
    }

    if (obj) {
        objects[size] = obj;
        size++;
        std::cout << "Object added: " << obj->GetName() << std::endl;
    }
}

void Keeper::AddObjectMonster(Monster* obj) {
    if (size == capacity) {
        Resize(capacity * 2);
    }

    if (obj) {
        objects[size] = obj;
        size++;
        std::cout << "Object added: " << obj->GetName() << std::endl;
    }
}

void Keeper::AddObjectVillain(Villain* obj) {
    if (size == capacity) {
        Resize(capacity * 2);
    }

    if (obj) {
        objects[size] = obj;
        size++;
        std::cout << "Object added: " << obj->GetName() << std::endl;
    }
}

void Keeper::RemoveObject(const std::string& name) {
    BaseHero* obj = FindObjectByName(name);
    if (!obj) {
        std::cout << "There is no object named " << name << "\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        if (objects[i] == obj) {
            delete objects[i];
            for (int j = i; j < size - 1; j++) {
                objects[j] = objects[j + 1];
            }
            size--;
            std::cout << "Object removed: " << name << std::endl;
            return;
        }
    }
}

void Keeper::SaveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        throw FileOpenException(filename); // Генерируем исключение при ошибке открытия файла
    }

    file << size << std::endl; // Записываем количество объектов

    for (int i = 0; i < size; i++) {
        file << CharacterTypeToInt(objects[i]->GetType()) << std::endl; // Записываем тип объекта
        file << objects[i]->GetName() << std::endl; // Записываем имя
        file << objects[i]->GetWeapon() << std::endl; // Записываем оружие

        const std::string* skills = objects[i]->GetSkills();
        int numSkills = objects[i]->GetNumSkills();
        file << numSkills << std::endl; // Записываем количество навыков

        for (int j = 0; j < numSkills; j++) {
            file << skills[j] << std::endl; // Записываем навыки
        }

        // Дополнительные поля для Villain
        if (objects[i]->GetType() == CharacterType::TypeVillain) {
            Villain* villain = dynamic_cast<Villain*>(objects[i]);
            file << villain->GetCrime() << std::endl; // Записываем злодеяние
            file << villain->GetLocation() << std::endl; // Записываем место обитания
        }

        // Дополнительные поля для Monster
        if (objects[i]->GetType() == CharacterType::TypeMonster) {
            Monster* monster = dynamic_cast<Monster*>(objects[i]);
            file << monster->GetAppearanceDescription() << std::endl; // Записываем описание внешнего вида
        }
    }

    file.close();

    std::cout << "Data saved successfully\n";
}

void Keeper::LoadFromFile(const std::string& filename) {
    Clear(); // Очищаем текущие данные

    std::ifstream file(filename);
    if (!file.is_open()) {
        throw FileOpenException(filename); // Генерируем исключение при ошибке открытия файла
    }

    int numObjects;
    file >> numObjects;
    file.ignore(); // Пропускаем символ новой строки

    for (int i = 0; i < numObjects; i++) {
        int characterTypeValue;
        file >> characterTypeValue;
        CharacterType characterType = IntToCharacterType(characterTypeValue);

        std::string name, weapon;
        file.ignore(); // Пропускаем символ новой строки

        std::getline(file, name);
        std::getline(file, weapon);

        int numSkills;
        file >> numSkills;
        file.ignore(); // Пропускаем символ новой строки

        std::string* skills = new std::string[numSkills];
        for (int j = 0; j < numSkills; j++) {
            std::getline(file, skills[j]);
        }

        if (characterType == CharacterType::TypeVillain) {
            std::string crime, location;
            std::getline(file, crime);
            std::getline(file, location);
            AddObjectVillain(new Villain(name, weapon, crime, location, skills, numSkills));
        }
        else if (characterType == CharacterType::TypeMonster) {
            std::string appearanceDescription;
            std::getline(file, appearanceDescription);
            AddObjectMonster(new Monster(name, appearanceDescription));
        }
        else {
            AddObjectHero(new Hero(name, weapon, skills, numSkills));
        }

        delete[] skills; // Освобождаем память, выделенную для навыков
    }

    file.close();
}

void Keeper::DisplayListOfObjects() const
{
    for (int i = 0; i < size; i++) {
        std::cout << "- " << objects[i]->GetName();
        std::cout << '\n';
    }
}

void Keeper::DisplayOne(const std::string& name) const
{
    BaseHero* obj = FindObjectByName(name);
    if (!obj) {
        std::cout << "There is no object named " << name << "\n";
        return;
    }

    obj->DisplayInfo();
}

void Keeper::DisplayAll() const {
    for (int i = 0; i < size; i++) {
        objects[i]->DisplayInfo();
        std::cout << '\n';
    }
}

void Keeper::Clear()
{
    for (int i = 0; i < size; i++) {
        delete objects[i];
    }
    delete[] objects;
    capacity = 10;
    objects = new BaseHero* [capacity];
    size = 0;
}

void Keeper::Resize(int newCapacity) {
    BaseHero** newArray = new BaseHero* [newCapacity];
    for (int i = 0; i < size; i++) {
        newArray[i] = objects[i];
    }
    delete[] objects;
    objects = newArray;
    capacity = newCapacity;
}

BaseHero* Keeper::FindObjectByName(const std::string& name) const {
    for (int i = 0; i < size; i++) {
        if (objects[i]->GetName() == name) {
            return objects[i];
        }
    }
    return nullptr;
}