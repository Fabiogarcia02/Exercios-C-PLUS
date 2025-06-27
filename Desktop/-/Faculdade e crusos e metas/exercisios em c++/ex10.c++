#include <iostream>
#include <string>
using namespace std;

class Produto {
private:
    string nome;
    float preco;
    int quantidade;

public:
    Produto(string nome = "", float preco = 0.0, int quantidade = 0) {
        this->nome = nome;
        this->preco = preco;
        this->quantidade = quantidade;
    }

    void cadastrarProduto() {
        cout << "Digite o nome do produto: ";
        cin.ignore();
        getline(cin, nome);
        cout << "Digite o preco do produto: ";
        cin >> preco;
        cout << "Digite a quantidade do produto: ";
        cin >> quantidade;
    }

    void exibirProduto() {
        cout << "Produto: " << nome << endl;
        cout << "Preco: R$ " << preco << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    Produto produtos[5];
    int opcao;
    int produtosCadastrados = 0;

    do {
        cout << "\nMenu:\n";
        cout << "1 - Cadastrar produto\n";
        cout << "2 - Exibir todos os produtos\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (produtosCadastrados < 5) {
                    cout << "\nCadastro do produto " << (produtosCadastrados + 1) << ":\n";
                    produtos[produtosCadastrados].cadastrarProduto();
                    produtosCadastrados++;
                } else {
                    cout << "Limite de 5 produtos atingido.\n";
                }
                break;

            case 2:
                if (produtosCadastrados == 0) {
                    cout << "Nenhum produto cadastrado.\n";
                } else {
                    cout << "\nLista de produtos cadastrados:\n";
                    for (int i = 0; i < produtosCadastrados; i++) {
                        produtos[i].exibirProduto();
                    }
                }
                break;

            case 0:
                cout << "Saindo...\n";
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}
