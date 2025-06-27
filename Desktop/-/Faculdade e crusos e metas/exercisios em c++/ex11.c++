#include <iostream>
#include <string>
using namespace std;

class Endereco {
public:
    string rua;
    string cidade;
    int cep;

    Endereco(string rua = "", string cidade = "", int cep = 0) {
        this->rua = rua;
        this->cidade = cidade;
        this->cep = cep;
    }
};

class Pessoa : public Endereco {
public:
    string nome;
    int idade;


    Pessoa(string nome = "", int idade = 0, string rua = "", string cidade = "", int cep = 0)
        : Endereco(rua, cidade, cep)  
    {
        this->nome = nome;
        this->idade = idade;
    }


void cadastrarDados(){
            cout << "Digite o nome: ";
            cin >> nome;
            cout << "Digite a idade: ";
            cin >> idade;
            cout << "Digite a rua: ";
            cin >> rua;
            cout << "Digite a cidade: ";
            cin >> cidade;
            cout << "Digite o CEP: ";
            cin >> cep;
}

    void mostrarDados() {
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
        cout << "Endereço: " << rua << ", " << cidade << ", CEP: " << cep << endl;
    }
};

int main() {
    Pessoa p;
             cout << "----------------------------------" << endl;
                  cout << "Cadastrando dados da pessoa:" <<
                        endl;
    cout << "----------------------------------" << endl;

    
    p.cadastrarDados();    
    p.mostrarDados();

    return 0;
}
