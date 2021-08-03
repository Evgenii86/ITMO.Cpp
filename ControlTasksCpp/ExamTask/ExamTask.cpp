#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "classes.h"
using namespace std;
using namespace myclasses;



class AddressBook
{
public:
    AddressBook() {}
    vector<Human*> listOfH;
    vector<Human*>::iterator it;

    void WritingToFile()
    {
        ofstream fout("list.txt", ios::app);
        for (int i = 0;i<listOfH.size();++i)
        {
            fout << (*listOfH[i]).getInfo();
        }
        fout.close();
    }
    void addHuman(Human* addHuman)
    {
        listOfH.push_back(addHuman);
    }
    void delHuman(Human* delHuman)
    {
        it = find(listOfH.begin(), listOfH.end(), delHuman);
        listOfH.erase(it);
    }
};




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Human *h1 = new Student("Николай", "Петров", 20, "СПБ, Ленина,1,3", "999-325-55-55", "ИТМО");
    Human *h2 = new Employee("Олег", "Назаров", 34, "СПБ, пр-кт Металлистов,25,14", "900-111-22-33", "Рога и копыта");
    Human *h3 = new CreativePerson("Вячеслав", "Глебов", 32, "СПБ, ул. Доблести,4,96", "955-444-55-66", "Художник");
    Human *h4 = new Employee("Вадим", "Ветров", 30, "СПБ, ул. Планерная,43,47", "998-777-88-99", "Сити груп");
    Human *h5 = new Student("Антон", "Сидоров", 21, "СПБ, ул. Малая Посадская,5,11", "995-999-88-77", "Лесотехнический университет");
    AddressBook *book = new AddressBook();
    book->addHuman(h1);
    book->addHuman(h2);
    book->addHuman(h3);
    book->addHuman(h4);
    book->addHuman(h5);
    book->WritingToFile();

    book->delHuman(h4);
    book->WritingToFile();
    delete book;

    string info = h4->getInfo();
    cout << info << endl;
    
    delete h1, h2, h3, h4, h5;

    

    return 0;
}

