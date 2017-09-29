#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void riverstead();
void aragornHouse();
void stage1();
void stage2();
void stage3();
void stage4(int &sword, int &gold);
void ratCave();
void attackThief(int &pHealth, int &tHealth);
void thiefDead();
void searchBody();
void questUpdate();
void end();

int input;
int stages[5] = {1, 0, 0, 0, 0};
string qUpdates;
string qStages;

int main() {

    srand (time(NULL));

    system("cls");
    cout << "\n Welcome to RPG!" << endl;
    cout << "\n 1. Play" << endl;
    cout << "\n 2. Exit" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        qUpdates = "Quest begun";
        qStages = "Talk to Aragorn in his house";
        questUpdate();

        riverstead();

        case 2:
        exit(0);

    }
}

void riverstead() {

    system("cls");
    cout << "\n You are in the town of Riverstead. Where would you like to go?" << endl;
    cout << "\n 1. Aragorn's House" << endl;
    cout << "\n 2. Rat Cave" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        aragornHouse();

        case 2:
        ratCave();

    }
}

void aragornHouse() {

    if (stages[0] == 1) {
        system("cls");
        cout << "\n Aragorn: You interested in doing something for me? There's gold in it for you." << endl;
        cout << "\n 1. What do you need?" << endl;
        cout << "\n 2. I'm kind of busy at the moment." << endl;
        cout << "\n> ";
        cin >> input;
        switch (input) {

            case 1:
            stage1();

            case 2:
            system("cls");
            cout << "\n If you find the time, I'll be here." << endl;
            cout << "\n ";
            system("pause");
            riverstead();

        }
    }

    if (stages[1] == 1) {
        stage2();
    }

    if (stages[2] == 1) {
        stage3();
    }

    else {
        stage4(sword);
    }
}

void stage1() {

    system("cls");
    cout << "\n There's a sword that has been in my family for generations and it was recently" << endl;
    cout << "\n passed down to me from my father. " << endl;
    cout << "\n ";
    system("pause");

    system("cls");
    cout << "\n I was walking back from the market the other day and I saw this thief sneaking" << endl;
    cout << "\n out of my house with the sword! " << endl;
    cout << "\n ";
    system("pause");

    system("cls");
    cout << "\n He ran and I followed him to a nearby cave, it's called Rat Cave." << endl;
    cout << "\n ";
    system("pause");

    system("cls");
    cout << "\n I didn't go inside because I had no way to defend myself." << endl;
    cout << "\n 1. I could get that sword for you." << endl;
    cout << "\n 2. I don't think I'm the right person for the job." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        stages[0] = 0;
        stages[2] = 1;
        system("cls");
        cout << "\n That's great! I'll be waiting right here." << endl;
        cout << "\n ";
        system("pause");

        qUpdates = "Quest updated";
        qStages = "Kill the thief in Rat Cave";
        questUpdate();

        riverstead();

        case 2:
        stages[0] = 0;
        stages[1] = 1;
        system("cls");
        cout << "\n Maybe I could find someone else to do this for me." << endl;
        cout << "\n ";
        system("pause");
        riverstead();

    }
}

void stage2() {

    system("cls");
    cout << "\n Have you changed your mind? Will you retrieve my sword?" << endl;
    cout << "\n 1. Yes, I'm ready to retrieve the sword." << endl;
    cout << "\n 2. I still don't feel like retrieving it." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        stages[0] = 0;
        stages[1] = 0;
        stages[2] = 1;
        system("cls");
        cout << "\n That's great! I'll be waiting right here." << endl;
        cout << "\n ";
        system("pause");

        qUpdates = "Quest updated";
        qStages = "Kill the thief in Rat Cave";
        questUpdate();

        riverstead();

        case 2:
        system("cls");
        cout << "\n That's a shame. Talk to me if you change your mind." << endl;
        cout << "\n ";
        system("pause");
        riverstead();

    }
}

void stage3() {

    system("cls");
    cout << "\n Have you retrieved the sword yet?" << endl;
    cout << "\n 1. I'm working on it." << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        system("cls");
        cout << "\n Let's hope the thief is still there by the time you get round to doing it." << endl;
        cout << "\n ";
        system("pause");
        riverstead();

    }
}

void stage4(int &gold, int &sword) {

    system("cls");
    cout << "\n Have you retrieved the sword yet?" << endl;
    cout << "\n 1. Yup. Was a piece of cake." << endl;
    cout << "\n 2. Yes, at the price of almost getting killed." << endl;
    cout << "\n> ";
    cin >> input;

    system("cls");
    cout << "\n That's brilliant! I knew you were the right man for the job. Here is the gold," << endl;
    cout << "\n as promised." << endl;
    cout << "\n ";
    system("pause");

    sword = 0;
    system("cls");
    cout << "\n Item removed - Aragorn's Sword" << endl;
    cout << "\n ";
    system("pause");

    gold = gold + 100;
    system("cls");
    cout << "\n Item added - 100 Gold" << endl;
    cout << "\n ";
    system("pause");

    qUpdates = "Quest complete";
    qStages = " ";
    questUpdate();

    end();

}

void ratCave() {

    int pHealth;
    int pDamage;
    int tHealth;
    int tDamage;
    int turn;

    if (stages[0] == 1 || stages[1] == 1) {
        system("cls");
        cout << "\n I haven't really got a good reason to go here." << endl;
        cout << "\n ";
        system("pause");
        riverstead();
    }

    system("cls");
    cout << "\n Thief: I'm warning you, stranger. Leave now!" << endl;
    cout << "\n 1. I've come for my friend's sword." << endl;
    cout << "\n 2. Okay, okay, I'm leaving!" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        system("cls");
        cout << "\n Ha! You won't be leaving with it!" << endl;
        cout << "\n ";
        system("pause");

        pHealth = rand() % 40 + 80;
        tHealth = rand() % 20 + 40;

        turn = rand() % 2;

        if (turn == 1) {
            system("cls");
            cout << "\n The thief has the first turn." << endl;
            cout << "\n ";
            system("pause");

            tDamage = rand() % 5 + 10;

            pHealth = pHealth - tDamage;
            system("cls");
            cout << "\n The thief attacks you for " << tDamage << " damage!" << endl;
            cout << "\n ";
            system("pause");

        }

        else {
            system("cls");
            cout << "\n You have the first turn." << endl;
            cout << "\n ";
            system("pause");
        }

        attackThief(pHealth, tHealth);

        case 2:
        system("cls");
        cout << "\n That's what I thought." << endl;
        cout << "\n ";
        system("pause");
        riverstead();

    }
}

void attackThief(int &pHealth, int &tHealth) {

    int pDamage;
    int tDamage;

    pDamage = rand() % 10 + 10;
    tDamage = rand() % 5 + 10;

    system("cls");
    cout << "\n Your health: " << pHealth << endl;
    cout << "\n Thief's health:  " << tHealth << endl;
    cout << "\n What would you like to do?" << endl;
    cout << "\n 1. Attack the thief" << endl;
    cout << "\n 2. Attempt to flee" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        tHealth = tHealth - pDamage;
        system("cls");
        cout << "\n You attack the thief for " << pDamage << " damage!" << endl;
        cout << "\n ";
        system("pause");

        if (tHealth < 1) {
            system("cls");
            cout << "\n You have killed the thief!" << endl;
            cout << "\n ";
            system("pause");
            thiefDead();
        }

        pHealth = pHealth - tDamage;
        system("cls");
        cout << "\n The thief attacks you for " << tDamage << " damage!" << endl;
        cout << "\n ";
        system("pause");

        if (pHealth < 1) {
            system("cls");
            cout << "\n You have been killed by the thief!" << endl;
            cout << "\n ";
            system("pause");
            exit(0);
        }

        attackThief(pHealth, tHealth);

        case 2:
        system("cls");
        cout << "\n Your attempt to flee is unsuccessful." << endl;
        cout << "\n ";
        system("pause");
        attackThief(pHealth, tHealth);

    }
}

void thiefDead() {

    qUpdates = "Quest updated";
    qStages = "Retrieve Aragorn's Sword";
    questUpdate();

    system("cls");
    cout << "\n What would you like to do?" << endl;
    cout << "\n 1. Search the thief's body" << endl;
    cout << "\n 2. Leave the cave" << endl;
    cout << "\n> ";
    cin >> input;
    switch (input) {

        case 1:
        searchBody();

        case 2:
        riverstead();

    }
}

void searchBody() {

    int gold;
    int sword;

    gold = gold + 20;
    sword = 1;
    stages[2] = 0;
    stages[3] = 1;

    system("cls");
    cout << "\n You found 20 gold and Aragorn's Sword!" << endl;
    cout << "\n ";
    system("pause");

    qUpdates = "Quest updated";
    qStages = "Return to Aragorn";
    questUpdate();

    return;

}

void questUpdate() {

    system("cls");
    cout << "\n " << qUpdates << " - Aragorn's Sword" << endl;
    cout << "\n ";
    system("pause");

    if (qStages != " ") {
        system("cls");
        cout << "\n " << qStages << endl;
        cout << "\n ";
        system("pause");
    }

    return;

}

void end() {

    system("cls");
    cout << "\n Thank you for playing RPG! A game made by Elliot Morgan." << endl;
    cout << "\n ";
    system("pause");
    main();

}
