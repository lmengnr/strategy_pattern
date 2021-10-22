#include "cWeapons.h"
#include <memory>


/**
 * @brief character class is like the context base class
 * 
 */
class cCharacters
{
private:
    /* data */
    
public:
    cCharacters(/* args */){};
    ~cCharacters(){};

    int nHP = 100;
    IWeapons* weapon;

    void equipWeapon(IWeapons* newWeapon)
    {
        weapon = newWeapon;
    }

    virtual void performAttack()
    {}

    void recieveDmg(int dmg)
    {
        nHP = nHP - dmg;
    }

    int getHP()
    {
        return nHP;
    }
};

class King : public cCharacters
{
private:
    /* data */
public:
    King(IWeapons* kingWeapon)
    {
        equipWeapon(kingWeapon);
    }
    ~King(){};

    void performAttack() override
    {
        std::cout << "The king did a kingly attack | Did damage == " << weapon->Attack() << std::endl;

    }
};

class Knight : public cCharacters
{
private:
    /* data */
public:
    Knight(IWeapons* knightWeapon)
    {
        equipWeapon(knightWeapon);
    }
    ~Knight(){};

    void performAttack() override
    {
        std::cout << "The knight did a yee horsy attack | Damage == " << weapon->Attack() << std::endl;
    }
};
