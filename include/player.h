#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"

using std::vector;

class Player : public Actor {
public:
    Player(int, int, int, string);

    Player(sf::Vector2f, int, string);

    std::string toString() const;

    void control();

    virtual ~Player();

protected:
private:
    void updateInput();

    void parseInput();

    vector<sf::Keyboard::Key> input;

    void control(sf::Keyboard::Key);

    sf::Vector2f direction;
    float terminalVelocity;
};

#endif // PLAYER_H
