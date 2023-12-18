#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <windows.h>

using namespace std;

// Forward declarations
class Labirin;
class monsterLabirin;
class monsterKroco;
class monsterPenyihir;
class monsterPerusuh;

class monsterLabirin {
protected:
    int attack;
    int defense;
    int health;

public:
    monsterLabirin(int attack, int defense, int health) : attack(attack), defense(defense), health(health) {}

    virtual ~monsterLabirin() {}

    int getAttack() const { return attack; }
    int getDefense() const { return defense; }
    int getHealth() const { return health; }

    void kurangiHealth(int amount) {
        health -= amount;
    }

    virtual int getXP() const = 0;
};

class monsterKroco : public monsterLabirin {
public:
    monsterKroco() : monsterLabirin(2, 1, 10) {}

    ~monsterKroco() {}

    int getXP() const override {
        return 10;
    }
};

class monsterPenyihir : public monsterLabirin {
public:
    monsterPenyihir() : monsterLabirin(4, 3, 20) {}

    ~monsterPenyihir() {}

    int getXP() const override {
        return 15;
    }
};

class monsterPerusuh : public monsterLabirin {
public:
    monsterPerusuh() : monsterLabirin(2, 1, 10) {}

    ~monsterPerusuh() {}

    int getXP() const override {
        return 20;
    }
};

class karakterTersesat {
protected:
    int attack;
    int defense;
    int health;
    int level;
    int xp;
    bool Hidup;

public:
    karakterTersesat(int attack, int defense, int health) : attack(attack), defense(defense), health(health), level(1), xp(0), Hidup(true) {}

    virtual ~karakterTersesat() {}

    virtual void levelNaik() = 0;
    virtual void berjalan(Labirin& labirin) = 0;

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

    void generateRandomEvent() {
        int chance = rand() % 100;  // Generate a random number between 0 and 99

        if (chance < 35) {
            // 35% chance to encounter monsterKroco
            pertemuanMonster(new monsterKroco());
            xp += 10;
            if (xp >= 10) {
                xp -= 10;
                levelNaik();
            }
        } else if (chance < 60) {
            // 25% chance to encounter monsterPenyihir
            pertemuanMonster(new monsterPenyihir());
            xp += 15;
            if (xp >= 10) {
                xp -= 10;
                levelNaik();
            }
        } else if (chance < 80) {
            // 20% chance to encounter monsterPerusuh
            pertemuanMonster(new monsterPerusuh());
            xp += 20;
            if (xp >= 10) {
                xp -= 10;
                levelNaik();
            }
        } else {
            // 20% chance to gain 20 XP
            cout << "Selamat! Kamu mendapatkan 20 XP!" << endl;
            xp += 20;
            if (xp >= 10) {
                xp -= 10;
                levelNaik();
            }
        }
    }

    virtual void pertemuanMonster(monsterLabirin* monster);

    void kurangiHealth(int amount) {
        health -= amount;
    }

    bool getHidup() const {
        return Hidup;
    }

    static karakterTersesat* createKarakter(int choice);
};

// Forward declarations for monster classes
class monsterKroco;
class monsterPenyihir;
class monsterPerusuh;

class Labirin {
private:
    vector<vector<int>> adjacencyList;

public:
    Labirin(int numberOfpoints) : adjacencyList(numberOfpoints) {}

    ~Labirin() {}

    void tambahCekpoin(int point1, int point2) {
        adjacencyList[point1].push_back(point2);
        adjacencyList[point2].push_back(point1);
    }

    int getJumlahCekpoin() const {
        return adjacencyList.size();
    }
};

void karakterTersesat::pertemuanMonster(monsterLabirin* monster) {
    int round = 1;

    while (health > 0 && monster->getHealth() > 0) {
        cout << "Ronde " << round << endl;
        cout << "Health karakter: " << health << " | Health monster: " << monster->getHealth() << endl;

        // Serangan karakter ke monster
        int seranganKarakter = max(0, attack - monster->getDefense());
        monster->kurangiHealth(seranganKarakter);

        // Cek apakah monster masih hidup
        if (monster->getHealth() <= 0) {
            cout << "Monster berhasil dikalahkan!" << endl;
            break;
        }

        // Serangan monster ke karakter
        int seranganMonster = max(0, monster->getAttack() - defense);
        kurangiHealth(seranganMonster);

        // Cek apakah karakter masih hidup
        if (health <= 0) {
            cout << "Kamu kalah dalam pertarungan!" << endl;
            Hidup = false;
            break;
        }

        Sleep(3000);
        round++;
    }
}

class Fighter : public karakterTersesat {
public:
    Fighter() : karakterTersesat(4, 3, 20) {}

    ~Fighter() {}

    void berjalan(Labirin& labirin) override;

    void levelNaik() override {
        level++;

        cout << "Selamat! Kamu naik level menjadi level " << level << "!" << endl;
        tampilStatus();

        cout << "Pilih atribut yang ingin ditingkatkan:" << endl;
        cout << "1. Attack +2" << endl;
        cout << "2. Defense +2" << endl;
        cout << "3. Health +10" << endl;

        int pilihan;
        cout << "Masukkan pilihan (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                attack += 2;
                break;
            case 2:
                defense += 2;
                break;
            case 3:
                health += 10;
                break;
            default:
                cout << "Pilihan tidak valid. Atribut tetap tidak berubah." << endl;
        }
    }
};

class Assassin : public karakterTersesat {
public:
    Assassin() : karakterTersesat(8, 2, 10) {}

    ~Assassin() {}

    void berjalan(Labirin& labirin) override;

    void levelNaik() override {
        level++;

        cout << "Selamat! Kamu naik level menjadi level " << level << "!" << endl;
        tampilStatus();

        cout << "Pilih atribut yang ingin ditingkatkan:" << endl;
        cout << "1. Attack +2" << endl;
        cout << "2. Defense +2" << endl;
        cout << "3. Health +10" << endl;

        int pilihan;
        cout << "Masukkan pilihan (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                attack += 2;
                break;
            case 2:
                defense += 2;
                break;
            case 3:
                health += 10;
                break;
            default:
                cout << "Pilihan tidak valid. Atribut tetap tidak berubah." << endl;
        }
    }
};

class Tank : public karakterTersesat {
public:
    Tank() : karakterTersesat(2, 6, 30) {}

    ~Tank() {}

    void berjalan(Labirin& labirin) override;

    void levelNaik() override {
        level++;

        cout << "Selamat! Kamu naik level menjadi level " << level << "!" << endl;
        tampilStatus();

        cout << "Pilih atribut yang ingin ditingkatkan:" << endl;
        cout << "1. Attack +2" << endl;
        cout << "2. Defense +2" << endl;
        cout << "3. Health +10" << endl;

        int pilihan;
        cout << "Masukkan pilihan (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                attack += 2;
                break;
            case 2:
                defense += 2;
                break;
            case 3:
                health += 10;
                break;
            default:
                cout << "Pilihan tidak valid. Atribut tetap tidak berubah." << endl;
        }
    }
};

karakterTersesat* karakterTersesat::createKarakter(int choice) {
    switch (choice) {
        case 1:
            return new Fighter();
        case 2:
            return new Assassin();
        case 3:
            return new Tank();
        default:
            return nullptr;
    }
}

void Fighter::berjalan(Labirin& labirin) {
    int currentVertex = 0;
    while (currentVertex < labirin.getJumlahCekpoin() && getHidup()) {
        cout << "Lanjut ke cekpoin selanjutnya? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            currentVertex++;
            cout << "Kamu berjalan ke cekpoin " << currentVertex << endl;
            generateRandomEvent();
        } else {
            cout << "Perjalanan dihentikan." << endl;
            break;
        }
    }
}

void Assassin::berjalan(Labirin& labirin) {
    int currentVertex = 0;
    while (currentVertex < labirin.getJumlahCekpoin() && getHidup()) {
        cout << "Lanjut ke cekpoin selanjutnya? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            currentVertex++;
            cout << "Kamu berjalan ke cekpoin " << currentVertex << endl;
            generateRandomEvent();
        } else {
            cout << "Perjalanan dihentikan." << endl;
            break;
        }
    }
}

void Tank::berjalan(Labirin& labirin) {
    int currentVertex = 0;
    while (currentVertex < labirin.getJumlahCekpoin() && getHidup()) {
        cout << "Lanjut ke cekpoin selanjutnya? (y/n): ";
        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            currentVertex++;
            cout << "Kamu berjalan ke cekpoin " << currentVertex << endl;
            generateRandomEvent();
        } else {
            cout << "Perjalanan dihentikan." << endl;
            break;
        }
    }
}

#endif

int main() {
    cout << "Selamat Datang di Labirin Menyesatkan." << endl;
    cout << "Sebelum Masuk ke Dalam Labirin, Silahkan Pilih Salah Satu Karakter yang Sedang Tersesat!" << endl;
    cout << endl;

    cout << "Karakter : " << endl << "1. Fighter" << endl << "2. Assassin" << endl << "3. Tank" << endl;
    cout << endl;

    int karakter;
    cout << "Pilih (angka): ";
    cin >> karakter;

    karakterTersesat* karakterPilihan = karakterTersesat::createKarakter(karakter);

    karakterPilihan->tampilStatus();
    cout << endl;

    Labirin labirin(10);

    labirin.tambahCekpoin(0, 1);
    labirin.tambahCekpoin(1, 2);
    labirin.tambahCekpoin(2, 3);
    labirin.tambahCekpoin(3, 4);
    labirin.tambahCekpoin(4, 5);
    labirin.tambahCekpoin(5, 6);
    labirin.tambahCekpoin(6, 7);
    labirin.tambahCekpoin(7, 8);
    labirin.tambahCekpoin(8, 9);

    karakterPilihan->berjalan(labirin);

    if (!karakterPilihan->getHidup()) {
        cout << "Game over! Kamu kalah dalam petualangan ini." << endl;
    } else {
        cout << "Selamat! Kamu berhasil menyelesaikan petualangan ini." << endl;
    }

    delete karakterPilihan;

    return 0;
}
