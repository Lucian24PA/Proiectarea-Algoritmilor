#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character {
protected:
	string name;
	string type;
	int HP;
	int attack;
	int defense;
	int agility;

public:
	Character(const string& name, const string& type, int HP, int attack, int defense, int agility)
		: name(name), type(type), HP(HP), attack(attack), defense(defense), agility(agility)
	{}

	virtual ~Character() = default;

	bool hitLand(int precision)
	{
		int chance = precision - agility;
		int rng;
		if (chance < 20)
		{
			chance = 20;
		}
		srand(static_cast<unsigned int>(time(0)));
		rng = rand() % 100;
		if (rng < chance)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void takeDamage(int dmg)
	{
		int reducedDamage = dmg - defense;
		if (reducedDamage < 0)
		{
			reducedDamage = 1;
		}
		HP = HP - reducedDamage;
		if (HP < 0)
		{
			HP = 0;
		}
	}

	string gettype() const
	{
		return type;
	}

	int getHP() const 
	{ 
		return HP; 
	}

	int getagility() const
	{
		return agility;
	}

	int getattack() const 
	{ 
		return attack; 
	}

	int getdefense() const
	{
		return defense;
	}

	const string getName() const 
	{ 
		return name; 
	}

	bool Alive() const 
	{ 
		return HP > 0; 
	}

};