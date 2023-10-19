#include "Keeper.h"
#include <iostream>
#include <fstream>

Keeper::Keeper() {
    capacity = 10;  // Начальная емкость массива
    size = 0;
    objects = new BaseHero* [capacity];
    std::cout << "Keeper constructor called" << std::endl;
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
    /*if (size == capacity) {
        // Увеличиваем емкость массива при необходимости
        Resize(capacity * 2);
    }

    if (obj) {
        objects[size] = obj;
        size++;
        std::cout << "Object added: " << obj->GetName() << std::endl;
    }*/
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
    
}

void Keeper::LoadFromFile(const std::string& filename) {

}

void Keeper::DisplayAll() const {
    for (int i = 0; i < size; i++) {
        objects[i]->DisplayInfo();
        std::cout << '\n';
    }
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