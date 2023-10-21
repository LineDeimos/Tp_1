#pragma once
#include "BaseHero.h"
#include "Hero.h"
#include "Monster.h"
#include "Villain.h"

class Keeper {
public:
    Keeper();
    Keeper(int initialCapacity);
    Keeper(const Keeper& other);
    ~Keeper();

    void AddObjectHero(Hero* obj);
    void AddObjectMonster(Monster* obj);
    void AddObjectVillain(Villain* obj);
    void RemoveObject(const std::string& name);
    void SaveToFile(const std::string& filename);
    void LoadFromFile(const std::string& filename);
    void DisplayAll() const;
    void Clear();

private:
    BaseHero** objects;  // ������������ ������ ����������
    int capacity;    // ������� �������
    int size;        // ������� ������ �������

    void Resize(int newCapacity);  // ����� ��� ��������� ������� �������
    BaseHero* FindObjectByName(const std::string& name) const;
};