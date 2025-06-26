#include <iostream>
#include <string>
using namespace std;

class Produto {
private:
    string nome;
    float preco;
    int quantidade;

public:
    Produto() : nome(""), preco(0.0), quantidade(0) {}

    void cadastrarProduto() {
        cout << "Digite o nome do produto: ";
        getline(cin, nome);
        cout << "Digite o preco do produto: ";
        cin >> preco;
        cout << "Digite a quantidade do produto: ";
        cin >> quantidade;
        cin.ignore(); 
        cout << "Produto cadastrado com sucesso!\n" << endl;
    }

    void exibirProduto() {
        cout << "\n=== Produto ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Preço: R$ " << preco << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Valor em estoque: R$ " << calcularValorTotalEmEstoque() << endl;
    }

    float calcularValorTotalEmEstoque() {
        return preco * quantidade;
    }
};

int main() {
    Produto produtos[5]; 
    char opcao;
    bool cadastrados = false;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1 - Cadastrar 5 produtos" << endl;
        cout << "2 - Exibir todos os produtos" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();  

        switch (opcao) {
            case '1':
                for (int i = 0; i < 5; i++) {
                    cout << "\nCadastrando produto " << i + 1 << ":" << endl;
                    produtos[i].cadastrarProduto();
                }
                cadastrados = true;
                break;

            case '2':
                if (!cadastrados) {
                    cout << "Nenhum produto cadastrado ainda!" << endl;
                } else {
                    for (int i = 0; i < 5; i++) {
                        produtos[i].exibirProduto();
                    }
                }
                break;

            case '0':
                cout << "Saindo do programa." << endl;
                break;

            default:
                cout << "Opção inválida. Tente novamente!" << endl;
        }

    } while (opcao != '0');

    return 0;
}
