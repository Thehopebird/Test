#include "classMob.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
player battle(player account);
player calcEXP(player account,classMob monster);
player levelUp(player account);
void death();

int main()
{
    string name = "marcus";
    int LocRan;
    LocRan= rand() %4;
    string notName;
    int option1;
    cout << "Welcome, please enter your name\n";
    cin >> notName;
    cout<<"hmmm..." <<notName<<" is not a good name for this game, lets just call you "<<name;
    string location[4] = {"in a sex dungeon","in homo erotic orgy","naked in a cage","on a table filled with dildos"};
    player account(name,location[LocRan],1,0);
    cout <<"\nWelcome "<<account.getName() << " you find your self " << account.getArea() << "\nand with your hands and feet tied together \n";
    while (1)
    {
        Sleep(500);
        cout <<"write 1 to stay or 2 to crawl to a gloryhole or 3 to roll through a hole in the wall\n";
        cin >> option1;
        if (option1 >=1 && option1 <=3)
        {
            Sleep(50*(option1));
            srand(time(NULL));
            if (rand() %3 == option1-1){
                account = battle(account);
            }

        }
        else{
            cout << "\n#@#Error#@# Please enter a number between 1 and 3\n\n";
            cin.clear();
            cin.ignore();
        }
    }
    return 0;

}




player battle(player account)
{
    string option;
    string location[4] = {"in a sex dungeon","in a cave","in the mauntains","in a castle"};
    string monsters[5][3] = {{"gimp","naked man","giant dildo"},{"rat","snake","trolls"},{"Dragon","Dragon","Dragon"},{"Evil knight","The mad king","Joffrey Baratheon"}};
    Sleep(20);
    srand(time(NULL));
    int ranM = (rand() % 3); //random monster
    int ranD = (rand() % 5)+1; //random diff
    classMob monster(monsters[account.getLevel()-1][ranM],account.getLevel(),account.getArea(),ranD);
    cout <<"Suddently you meet a "<< monster.getName() <<", be ready for battle" << "\n";
    Sleep(2000);
    do
    {
        cout << "\n\n\n ######################################\nHP:"<< account.getHealth() << "                                         "<< monster.getName()<<"HP:"<<monster.getHealth()<<" difficulty:"<<monster.getDifficulty() << "\n";
        cout << "Write A for attack or R for retreat" << "\n";
        cin >> option;
        srand(time(NULL));
        if (option == "R" || option == "r")
        {
            if ((rand() % 2) == 1){
                cout << "retreat sucessfull" << "\n";
                monster.setHealth(0);
            }
            else{
                cout << "retreat failed, the monster get a free attack and you lose 5 health\n";
                account.setHealth(account.getHealth()-5);
                option ="A";
            }
        }
        if (option == "A" || option == "a")
        {
            int attack =rand()%(account.getDamage());
            srand(time(NULL));
            int mobAttack = rand()%(monster.getDamage());
            monster.setHealth(monster.getHealth()-attack);
            account.setHealth(account.getHealth()-mobAttack);
            cout << "you attack the monster for " << attack << " damage\n";
            Sleep(500);
            cout << "the monster counter attacks for " << mobAttack << " damage\n";
            Sleep(500);
        }
    } while (monster.getHealth() >0 && account.getHealth() > 0);
    cout << "\n\n\n ######################################\nHP:"<< account.getHealth() << "                                         "<< monster.getName()<<"HP:"<<monster.getHealth()<<" difficulty:"<<monster.getDifficulty() << "\n";
    if (account.getHealth() <= 0)
    {
        death();
        exit(0);
    }
    account = calcEXP(account,monster);
    return account;
}



void death()
{
    cout << "Sorry you failed your epic quest\n";
}

player calcEXP(player account,classMob monster)
{
    cout << "#########\ncalculating EXP\n#########\n";
    Sleep(500);
    account.setEXP(account.getEXP() + monster.getEXP());
    cout << "EXP: " <<account.getEXP() << "/" << account.getEXPReq() << "\n";
    if (account.getEXP() >= account.getEXPReq())
    {
        levelUp(account);
    }
    return account;
}

player levelUp(player account)
{
    account.setLevel(account.getLevel()+1);
    account.setEXPReq();
    account.setMaxHealth();
    account.setHealth(account.getMaxHealth());
    cout << "Level up! you are now level: " << account.getLevel() << "!\n";
    return account;
}
