#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <chrono>
#include <thread>
#include "Player.h"
#include "Enemy.h"

using namespace std;

void drawPath()
{
    cout << "Hello traveler, your journey begins here!\nIn your eyes you have your path\n\n\n\n\n";
    cout << "      |       |                     " << endl;
    cout << "      |       |                     " << endl;
    cout << "      |       |                     " << endl;
    cout << "      |       |                     " << endl;
    cout << "   ^  |       |                     " << endl;
    cout << "   |  |       |_____________        " << endl;
    cout << "      |                             " << endl;
    cout << "   S  |                             " << endl;
    cout << "   W  |        _____________        " << endl;
    cout << "   A  |       |  FOREST ->          " << endl;
    cout << "   M  |       |                     " << endl;
    cout << "   P  |       |                     " << endl;
    cout << "      |       |                     " << endl;
    cout << "      |       |                     " << endl;
    cout << "      |       |                     " << endl;
    cout << "\n\n\nWhat will you do?\n";
    cout << "1. Proceed foward  2. Take the right\n\n\n";
    
}

void drawWorm()
{
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
    cout << "                 ____          " << endl;
    cout << "                /              " << endl;
    cout << "         ______/               " << endl;

    for (int j = 0; j < 5; j++)
    {
        cout << endl;
    }
}

void drawMudMan()
{
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
    }
    cout << "          (-_-)                " << endl;
    cout << "      _____|_|_____            " << endl;
    cout << "      |  _    _  |             " << endl;
    cout << "      | ||    || |             " << endl;
    cout << "      |_||____||_|             " << endl;
    cout << "         | || |                " << endl;
    cout << "         |_||_|                " << endl;

    for (int j = 0; j < 3; j++)
    {
        cout << endl;
    }
}

void drawBook()
{
    for (int i = 0; i < 4; i++)
    {
        cout << endl;
    }
    cout << "                               " << endl;
    cout << "     ____________              " << endl;
    cout << "    /__________ /|             " << endl;
    cout << "    |__________|/|             " << endl;
    cout << "    |__________|/              " << endl;

    for (int j = 0; j < 4; j++)
    {
        cout << endl;
    }

}

void playerTurn(Character& player, Character& enemy)
{
    if (enemy.getName()=="MudMan")
    {
        drawMudMan();
    }
    else if (enemy.getName() == "Book")
    {
        drawBook();
    }
    else
    {
        drawWorm();
    }
    cout << endl << player.getName() << "'s Turn!" << endl;
    cout << "1. Attack        2. Throw fire match\n";
    cout << "3. Use watergun  4. Inspect stats \n\nChoose an action : ";
    int choice;
    cin >> choice;

    if (choice == 1) 
    {
        cout << player.getName() << " attacks!\n";
        enemy.takeDamage(player.getattack() / 2);
    }
    else if (choice == 2) 
    {
        cout << player.getName() << " throwed a fire match at the enemy\n";
        if (enemy.hitLand(30))
        {
            if (enemy.gettype() == "Monster")
            {
                cout << "The enemy resists fire type moves, its not very effective.\n";
                enemy.takeDamage(player.getattack());
            }
            else if (enemy.gettype() == "Magic")
            {
                cout << "The enemy is weak to fire type moves, its very effective.\n";
                enemy.takeDamage(player.getattack() * 3);
            }
            else
            {
                cout << player.getName() << " hits for " << player.getattack() * 2;
                enemy.takeDamage(player.getattack() * 2);
            }
        }
        else
        {
            cout << player.getName() << " misses...\n";
        }
    }
    else if (choice == 3)
    {
        cout << player.getName() << " aimed the water gun and pressed the trigger\n";
        if (enemy.hitLand(70))
        {
            if (enemy.gettype() == "Monster")
            {
                cout << "The enemy is weak to water type moves, its very effective.\n";
                enemy.takeDamage(player.getattack() * 2);
            }
            else if (enemy.gettype() == "Magic")
            {
                cout << "The enemy resists water type moves, its not very effective.\n";
                enemy.takeDamage(player.getattack() / 2);
            }
            else
            {
                cout << player.getName() << " hits for " << player.getattack() * 2;
                enemy.takeDamage(player.getattack());
            }
        }
        else
        {
            cout << player.getName() << " misses...\n";
        }
    }
    else if (choice == 4)
    {
        cout << player.getName() << " looked at the enemy and found out this:\n\n\n";
        if (enemy.getName() == "Worm")
        {
            cout << "Name:Worm\nHe's to tiny to figure out anything about him, try all your options...\n";
        }
        else if (enemy.getName() == "MudMan")
        {
            cout << "Name: MudMan      Type: Monster\n";
            cout << "HP:" << enemy.getHP() << " AT:" << enemy.getattack() << " DF:" << enemy.getdefense() << " AG:" << enemy.getagility() << endl;
            cout << "He is an spirit of the swamp" << endl << "who took the form of a man made" << endl << "out of mud. When is hot outside" << endl << "mud turns to stone, so try" << endl << "watering him down!" << endl;
        }
        else if (enemy.getName() == "Book")
        {
            cout << "Name: Magic Book   Type: Magic\n";
            cout << "HP:" << enemy.getHP() << " AT:" << enemy.getattack() << " DF:" << enemy.getdefense() << " AG:" << enemy.getagility() << endl;
            cout << "A magic floating book lost in" << endl << "the forest. It has a shiny" << endl << "bookcover that protects it" << endl << "form water.Try burning it down!" << endl;
        }
    }
    else 
    {
        cout << "You really wanted to see what happens when you enter an invalid option?\nOh well, here is your prize!\nSkipping turn...\n";
    }
}

void enemyTurn(Character& enemy, Character& player) 
{
    cout << "\n" << enemy.getName() << "'s Turn!\n";
    int damage = enemy.getattack();
    if (enemy.getName() == "MudMan")
    {
        cout << enemy.getName() << " uses Mud Ball \n";
        if (player.hitLand(50))
        {
            player.takeDamage(damage);
        }
        else
        {
            cout << enemy.getName() << " missed";
        }
    }
    else if (enemy.getName() == "Book")
    {
        cout << enemy.getName() << " uses Razor Pages \n";
        if (player.hitLand(70))
        {
            player.takeDamage(damage);
        }
        else
        {
            cout << enemy.getName() << " missed";
        }
    }
    else
    {
        cout << enemy.getName() << " uses Cosmic Black Hole \n";
        if (player.hitLand(80))
        {
            player.takeDamage(damage);
        }
        else
        {
            cout << enemy.getName() << " missed";
        }
    }
    
}



int main() 
{
    srand(static_cast<unsigned int>(time(0)));
    Character player("Hero", "Human", 100, 10, 5, 15);
    Enemy enemy("default", "default", 1, 0, 0, 0);

    int i,path;
    drawPath();

    cin >> path;

    if (path == 1)
    {
        cout << "So you'll go foward...\n Oh no... something is approaching!\n";
        Enemy MudMan("MudMan", "Monster", 100, 15, 5, 0);
        enemy = MudMan;
    }
    else if (path == 2)
    {
        cout << "So you'll take the right...\n Oh no... something is approaching!\n";
        Enemy Book("Book", "Magic", 50, 10, 2, 5);
        enemy = Book;
    }
    else
    {
        cout << "You can't decide what to do?\n*You stayed in place\n Oh no... something is approaching from behind!\n";
        Enemy Worm("Worm", "Insect", 25, 25, 0, 50);
        enemy = Worm;
    }

    while (player.Alive() && enemy.Alive()) {
        cout << "\n--- Combat Status ---\n";
        cout << player.getName() << endl << " - Health:  ";
        for (i = 0; i < player.getHP(); i = i + 5)
        {
            cout << "|";
        }
        cout << "  " << player.getHP() << endl;
        cout << enemy.getName() << endl << " - Health:  ";
        for (i = 0; i < enemy.getHP(); i = i + 5)
        {
            cout << "|";
        }
        cout << "  " << enemy.getHP() << endl;
        

        playerTurn(player, enemy);
        if (!enemy.Alive()) {
            cout << enemy.getName() << " is defeated!\n";
            break;
        }

        enemyTurn(enemy, player);
        if (!player.Alive()) {
            cout << player.getName() << " is defeated!\n";
            break;
        }
    }

    cout << "\nCombat has ended!\n";
    cout << "Thank you for playing this demo!\nCREDITS:\n\n\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << ".\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "..\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "...\n";
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Project manager: Sava Lucian\nLead programmer: Sava Lucian\nSprite artist: Sava Lucian\nQuality manager: Sava Lucian\nTesters: Sava Lucian\nAlpha testers: Sava Lucian\n";
    return 0;
}