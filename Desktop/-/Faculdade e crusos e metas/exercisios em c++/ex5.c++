#include <iostream>
#include <string>
using namespace std;

class Pessoa {
private:
    int idade;
    string nome;

public:
    // Construtor
    Pessoa(string n, int i) : nome(n), idade(i) {}

    // Getters
    int getIdade() {
        return idade;
    }

    string getNome() {
        return nome;
    }


    void exibirDados() {
        cout << "O nome da pessoa é: " << getNome()
             << " e a idade é: " << getIdade() << " anos" << endl;
    }
};

int main() {
    string nome;
    int idade;

    cout << "Digite o nome da pessoa: ";
    getline(cin, nome); 

    cout << "Digite a idade da pessoa: ";
    cin >> idade;

    Pessoa p1(nome, idade);
    p1.exibirDados();

    return 0;
}
