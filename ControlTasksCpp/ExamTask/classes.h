#pragma once
#include <string>
using namespace std;

namespace myclasses
{
    class Human
    {
    public:
        Human(string n, string ln, int age, string a, string t) : name(n), lastName(ln), age(age), address(a), telefon(t) {}
        string name;
        string lastName;
        int age;
        string address;
        string telefon;
        virtual string getInfo()
        {
            ostringstream info;
            info << "���: " << name << " �������: " << lastName << " �������: " << age << " �������: " << telefon << " ����� : " << address << endl;
            return info.str();
        }
    };

    class Employee : public Human
    {
    public:
        string company;
        Employee(string n, string ln, int age, string a, string t, string c) :Human(n, ln, age, a, t)
        {
            company = c;
        }

        string getInfo()
        {
            ostringstream info;
            info << "���: " << name << " �������: " << lastName << " �������: " << age << " �������: " << telefon << " ����� : " << address << " ��������: " << company << endl;
            return info.str();
        }
    };

    class Student : public Human
    {
    public:
        string university;
        Student(string n, string ln, int age, string a, string t, string u) : Human(n, ln, age, a, t)
        {
            university = u;
        }
        string getInfo()
        {
            ostringstream info;
            info << "���: " << name << " �������: " << lastName << " �������: " << age << " �������: " << telefon << " ����� : " << address << " �����������: " << university << endl;
            return info.str();
        }

    };

    class CreativePerson : public Human
    {
    public:
        string occupation;
        CreativePerson(string n, string ln, int age, string a, string t, string occ) : Human(n, ln, age, a, t)
        {
            occupation = occ;
        }
        string getInfo()
        {
            ostringstream info;
            info << "���: " << name << " �������: " << lastName << " �������: " << age << " �������: " << telefon << " ����� : " << address << " ��� �������: " << occupation << endl;
            return info.str();
        }
    };
}
