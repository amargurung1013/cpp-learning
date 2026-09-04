#include <iostream>

class Weapon {
public:
    std::string Name;
};

class Character {
public:
    Character(Weapon& Sword): mSword{Sword} {}
    Weapon GetWeapon() { return mSword; }

private:
    Weapon& mSword;
};

int main() {
    Weapon PlayerWeapon{"Wooden Sword"};
    Character Player{PlayerWeapon};
    std::cout << Player.GetWeapon().Name << '\n';
    PlayerWeapon.Name = "Steel Sword";
    std::cout << Player.GetWeapon().Name;
}
