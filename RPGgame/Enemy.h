#pragma once
#include "Player.h"

using namespace std;

class Enemy : public Character 
{
public:
    Enemy(const string& name, const string& type, int HP, int attack, int defense, int agility)
        : Character(name, type, HP, attack, defense, agility) 
    {}
};