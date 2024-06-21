#ifndef _FILTER_H_
#define _FILTER_H_
#include <string>
#include <vector>
class Person
{
private:
    std::string name;
    int gender;  // 1 male, 2 female
    bool single; // true single, false non-single
public:
    Person(const std::string &name, int gender, bool single) : name(name), gender(gender), single(single) {}
    virtual ~Person() {}
    inline std::string getName() const
    {
        return name;
    }
    inline int getGender() const
    {
        return gender;
    }
    inline bool getSingle() const
    {
        return single;
    }
    inline void setName(std::string &name)
    {
        this->name = name;
    }
    inline void setGender(int gender)
    {
        this->gender = gender;
    }
    inline void setSingle(bool single)
    {
        this->single = single;
    }
};

class Criteria
{
public:
    virtual ~Criteria() {}
    virtual std::vector<Person *> *filter(std::vector<Person *> *persons) = 0;
};

class IsMale : public Criteria
{
public:
    virtual ~IsMale() {}
    std::vector<Person *> *filter(std::vector<Person *> *persons) override;
};

class IsFemale : public Criteria
{
public:
    virtual ~IsFemale() {}
    std::vector<Person *> *filter(std::vector<Person *> *persons) override;
};

class IsSingle : public Criteria
{
public:
    virtual ~IsSingle() {}
    std::vector<Person *> *filter(std::vector<Person *> *persons) override;
};

class And : public Criteria
{
private:
    Criteria *criteria1;
    Criteria *criteria2;

public:
    And(Criteria *criteria1, Criteria *criteria2) : criteria1(criteria1), criteria2(criteria2) {}
    virtual ~And() // 析构指针成员
    {
        delete criteria1;
        delete criteria2;
        criteria1 = nullptr;
        criteria2 = nullptr;
    }
    std::vector<Person *> *filter(std::vector<Person *> *persons) override;
};

class Or : public Criteria
{
private:
    Criteria *criteria1;
    Criteria *criteria2;

public:
    Or(Criteria *criteria1, Criteria *criteria2) : criteria1(criteria1), criteria2(criteria2) {}
    virtual ~Or()
    {
        delete criteria1;
        delete criteria2;
        criteria1 = nullptr;
        criteria2 = nullptr;
    }
    std::vector<Person *> *filter(std::vector<Person *> *persons) override;
};

#endif