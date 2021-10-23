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

protected:
    int nHP = 100;
    /// unique pointer should work well as there shouldn't be any shared ownership involved here
    std::unique_ptr<IWeapons> weapon;
    
public:
    cCharacters(/* args */){};
    ~cCharacters(){};

    void equipWeapon(IWeapons* newWeapon)
    {
        weapon.reset(newWeapon);
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
