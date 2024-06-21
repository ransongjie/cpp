#include "filter.h"

std::vector<Person *> *IsMale::filter(std::vector<Person *> *persons)
{
    std::vector<Person *> *males = new std::vector<Person *>();
    for (int i = 0; i < persons->size(); i++)
    {
        auto person = (*persons)[i];
        if (person->getGender() == 1)
        {
            males->push_back(person);
        }
    }
    return males;
}

std::vector<Person *> *IsFemale::filter(std::vector<Person *> *persons)
{
    std::vector<Person *> *females = new std::vector<Person *>();
    for (int i = 0; i < persons->size(); i++)
    {
        auto person = (*persons)[i];
        if (person->getGender() == 2)
        {
            females->push_back(person);
        }
    }
    return females;
}

std::vector<Person *> *IsSingle::filter(std::vector<Person *> *persons)
{
    std::vector<Person *> *singles = new std::vector<Person *>();
    for (int i = 0; i < persons->size(); i++)
    {
        auto person = (*persons)[i];
        if (person->getSingle())
        {
            singles->push_back(person);
        }
    }
    return singles;
}

std::vector<Person *> *And::filter(std::vector<Person *> *persons)
{
    // 先交给第一个标准过滤，再将过滤结果交给第二个标准过滤
    std::vector<Person *> *persons1 = this->criteria1->filter(persons);
    std::vector<Person *> *persons2 = this->criteria2->filter(persons1);

    return persons2;
}

std::vector<Person *> *Or::filter(std::vector<Person *> *persons)
{
    // 第一二两个标准可以同时过滤，最后取并集即可
    std::vector<Person *> *persons1 = this->criteria1->filter(persons);
    std::vector<Person *> *persons2 = this->criteria2->filter(persons);
    std::vector<Person *> *ans = new std::vector<Person *>();
    for (int i = 0; i < persons1->size(); i++)
    {
        ans->push_back((*persons1)[i]);
    }
    for (int i = 0; i < persons2->size(); i++)
    {
        auto person = (*persons2)[i];
        auto it = std::find(ans->begin(), ans->end(), person);
        if (it == ans->end())
        {
            ans->push_back(person);
        }
    }
    return ans;
}