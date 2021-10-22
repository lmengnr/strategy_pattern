#include <stdint.h>
#include <iostream>


/**
 * @brief IWeapons is the strategy class
 * It is encapsulating the weapons behaviors and providing and interface for other classes/objects
 */
class IWeapons
{
private:
    /* data */
    uint16_t nDamage = 0;

public:
    IWeapons(/* args */){};
    ~IWeapons(){};

    virtual int Attack() = 0;

    uint16_t getDamageVal()
    {
        return nDamage;
    }

    void setDamageVal(uint16_t nNewVal)
    {
        nDamage = nNewVal;
    }

};

class Sword : public IWeapons
{
private:
    /* data */
public:
    Sword(/* args */)
    {
        setDamageVal(20);
    }
    ~Sword(){};

    int Attack() override
    {
        std::cout << "sword goes slice!" << std::endl;
        return getDamageVal();
    }
};

class Club : public IWeapons
{
private:
    /* data */
public:
    Club(/* args */)
    {
        setDamageVal(25);
    }
    ~Club(){};

    int Attack() override
    {
        std::cout << "club goes thud!" << std::endl;
        return getDamageVal();
    }
};