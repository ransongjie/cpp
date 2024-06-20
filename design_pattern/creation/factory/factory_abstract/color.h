#ifndef _COLOR_H_
#define _COLOR_H_

enum ECOLOR
{
    RED,
    GREEN,
    BLUE
};

class Color
{
public:
    virtual void fill() = 0;
};

class Red : public Color
{
public:
    void fill() override;
};

class Blue : public Color
{
public:
    void fill() override;
};

class Green : public Color
{
public:
    void fill() override;
};

#endif