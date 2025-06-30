#include <iostream>
#include <iomanip>  
using namespace std;


void mostrarBoneco(string nome);
void mostrarHPcoracoes(int hpAtual, int hpMax);

class Pokemon {
public:
    string nome;
    int hp;
    int maxHp;    
    int ataque;
    float defesa;
    int speed;

    Pokemon(string nome, int hp, int ataque, float defesa, int speed) {
        this->nome = nome;
        this->hp = hp;
        this->maxHp = hp;  
        this->ataque = ataque;
        this->defesa = defesa;
        this->speed = speed;
    }

    void exibir() {
        cout << fixed << setprecision(1);
        mostrarBoneco(nome);
        mostrarHPcoracoes(hp, maxHp);
        cout << "⚔️ Ataque: " << ataque << endl;
        cout << "🛡️ Defesa: " << defesa << endl;
        cout << "💨 Speed: " << speed << endl;
        cout << "-----------------" << endl;
    }

    void atacar(Pokemon &alvo) {
        int dano = ataque - alvo.defesa;
        if (dano < 0) dano = 0;

        cout << "⚔️ " << nome << " ataca " << alvo.nome << " causando 💥 " << dano << " de dano!" << endl;

        alvo.hp -= dano;
        if (alvo.hp < 0) alvo.hp = 0;

        alvo.defesa -= 0.5;
        if (alvo.defesa < 0) alvo.defesa = 0;

        cout << "💢 " << alvo.nome << " perdeu " << dano << " de vida." << endl;
        mostrarHPcoracoes(alvo.hp, alvo.maxHp);
        cout << "🛡️ Defesa atual: " << alvo.defesa << endl;
        cout << "-----------------" << endl;
    }
};


void mostrarBoneco(string nome) {
    if (nome == "Pikachu") {
        cout << R"(
⚡️ Pikachu ⚡️
 (\__/)
 (o^-^)
z(_(")(")
)" << endl;
    } else if (nome == "Squirtle") {
        cout << R"(
🐢 Squirtle 🐢
  _____     ____
 /      \  |  o |
|        |/ ___\|
|_________/
 |_|_| |_|_|
)" << endl;
    } else {
        cout << nome << " apareceu! (sem arte ainda)\n";
    }
}

// Mostrar coraçoes de hp 
void mostrarHPcoracoes(int hpAtual, int hpMax) {
    int total = 10; 
    int cheios = (hpAtual * total) / hpMax;

    cout << "HP: ";
    for (int i = 0; i < total; i++) {
        if (i < cheios)
            cout << "♥";
        else
            cout << "♡";
    }
    cout << " " << hpAtual << "/" << hpMax << endl;
}

void batalhar(Pokemon &p1, Pokemon &p2) {
    int turno = 1;
    while (p1.hp > 0 && p2.hp > 0) {
        cout << "🌀 Turno " << turno << " -----------------------------" << endl;

        if (p1.speed >= p2.speed) {
            p1.atacar(p2);
            if (p2.hp <= 0) break;
            p2.atacar(p1);
        } else {
            p2.atacar(p1);
            if (p1.hp <= 0) break;
            p1.atacar(p2);
        }

        if (p1.defesa <= 0 ) {
            cout << "💥🛡️ " << p1.nome << " teve sua armadura quebrada!" << endl;
        }
        if (p2.defesa <= 0 ) {
            cout << "💥🛡️ " << p2.nome << " teve sua armadura quebrada!" << endl;
        }

        turno++;
    }

    cout << "🏁 Fim da batalha!" << endl;

    if (p1.hp <= 0)
        cout << "💀 " << p1.nome << " foi derrotado!" << endl;
    else
        cout << "🏆 " << p2.nome << " foi derrotado!" << endl;
}

int main() {
    Pokemon p1("Pikachu", 70, 20, 3.0, 2);
    Pokemon p2("Squirtle", 90, 15, 8.0, 1);

    p1.exibir();
    p2.exibir();

    batalhar(p1, p2);

    return 0;
}
