#ifndef _PROXY_H_
#define _PROXY_H_

class Wedding
{
public:
    virtual void wed() = 0;
    virtual ~Wedding() {}
};

// 新郎新娘
class BrideGroom : public Wedding
{
public:
    void wed() override;
    virtual ~BrideGroom() {}
};

class WedCompany : public Wedding
{
private:
    BrideGroom brideGroom;
public:
    WedCompany(const BrideGroom &brideGroom):brideGroom(brideGroom){}
    void wed() override;
    virtual ~WedCompany() {}
};

#endif