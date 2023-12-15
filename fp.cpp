#include <iostream>
#include <vector>

using namespace std;

// Abstract class karakterTersesat
class karakterTersesat {
protected:
    int attack;
    int defense;
    int health;
    int level;
    int xp;

public:
    karakterTersesat(int attack, int defense, int health) : attack(attack), defense(defense), health(health), level(1), xp(0) {}

    virtual ~karakterTersesat() {}

    virtual void levelNaik() = 0;

    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getHealth() const { return health; }
    int getLevel() const { return level; }
    int getxp() const { return xp; }

    void tampilStatus() const {
        cout << "Status karakter" << endl;
        cout << "Level: " << level << endl;
        cout << "Total xp: " << xp << endl;
        cout << "Attack: " << attack << endl;
        cout << "Defense: " << defense << endl;
        cout << "Health: " << health << endl;
    }
};

// Fighter class inherits from karakterTersesat
class Fighter : public karakterTersesat {
public:
    Fighter() : karakterTersesat(4, 3, 20) {}

    ~Fighter() {}

    void levelNaik() override {
        attack++;
        cout << "Fighter kamu naik level! Attack +1" << endl;
        tampilStatus();
    }
};

// Assassin class inherits from karakterTersesat
class Assassin : public karakterTersesat {
public:
    Assassin() : karakterTersesat(6, 2, 10) {}

    ~Assassin() {}

    void levelNaik() override {
        attack++;
        cout << "Assassin kamu naik level! Attack +1" << endl;
        tampilStatus();
    }
};

// Tank class inherits from karakterTersesat
class Tank : public karakterTersesat {
public:
    Tank() : karakterTersesat(2, 6, 30) {}

    ~Tank() {}

    void levelNaik() override {
        attack++;
        cout << "Tank kamu naik level! Attack +1" << endl;
        tampilStatus();
    }
};

// Labirin class with adjacency list
class Labirin {
private:
    vector<vector<int>> adjacencyList;

public:
    // Constructor with the number of mazes
    Labirin(int numberOfMazes) : adjacencyList(numberOfMazes) {}

    // Destructor
    ~Labirin() {}

    // Method to add an edge between two mazes
    void addEdge(int maze1, int maze2) {
        adjacencyList[maze1].push_back(maze2);
        adjacencyList[maze2].push_back(maze1);
    }


};