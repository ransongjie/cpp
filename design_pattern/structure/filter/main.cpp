#include "filter.h"
#include <iostream>

void printPersons(std::vector<Person *> *persons);

// g++ *.cpp -std=c++11
int main()
{
    std::vector<Person *> *persons = new std::vector<Person *>();

    persons->push_back(new Person("Robert", 1, true));
    persons->push_back(new Person("John", 1, false));
    persons->push_back(new Person("Laura", 2, true));
    persons->push_back(new Person("Diana", 2, false));
    persons->push_back(new Person("Mike", 1, false));
    persons->push_back(new Person("Bobby", 1, true));

    Criteria *criteriaMale = new IsMale();
    Criteria *criteriaFemale = new IsFemale();
    Criteria *criteriaSingle = new IsSingle();
    Criteria *criteriaSingleAndMale = new And(criteriaSingle, criteriaMale);
    Criteria *criteriaSingleOrFemale = new Or(criteriaSingle, criteriaFemale);

    std::cout << "Males: " << std::endl;
    printPersons(criteriaMale->filter(persons));

    std::cout << "Females: " << std::endl;
    printPersons(criteriaFemale->filter(persons));

    std::cout << "Single Males: " << std::endl;
    printPersons(criteriaSingleAndMale->filter(persons));

    std::cout << "Single Or Females: " << std::endl;
    printPersons(criteriaSingleOrFemale->filter(persons));

    delete persons;
    delete criteriaMale;
    delete criteriaFemale;
    delete criteriaSingle;
    delete criteriaSingleAndMale;
    delete criteriaSingleOrFemale;
    persons = nullptr;
    criteriaMale = nullptr;
    criteriaFemale = nullptr;
    criteriaSingle = nullptr;
    criteriaSingleAndMale = nullptr;
    criteriaSingleOrFemale = nullptr;
}

void printPersons(std::vector<Person *> *persons)
{
    for (int i = 0; i < persons->size(); i++)
    {
        auto person = (*persons)[i];
        std::cout << "Person : [ "
                  << "Name : " << person->getName()
                  << ", Gender : " << person->getGender()
                  << ", Single : " << person->getSingle()
                  << " ]" << std::endl;
    }
}