#include "../include/item.h"
Item::Item(sf::Vector2f pos, int damage, string filename, string name, int uses, int reUse) : Actor(pos, damage,
                                                                                                    filename, name) {
    setHP(uses);
    coolDown = reUse;
    //ctor
}

void Item::act(Actor *a) {
    //Don't spam items!
    if (coolDownTimer.getElapsedTime().asMilliseconds() < coolDown)
        return;

    coolDownTimer.restart();

    if (getHP() <= 0 && getHP() != -1)
        return;

    if (getHP() != -1)
        setHP(getHP() - 1);

    if (a != nullptr)
        a->setHP(a->getHP() - this->getDamage());
}


string Item::toString() const {
    std::stringstream toRet;
    toRet << getName() << " with " << getHP() << " uses.";
    return toRet.str();
}

void Item::control() {
    ;
}

Item::~Item() {
    //dtor
}