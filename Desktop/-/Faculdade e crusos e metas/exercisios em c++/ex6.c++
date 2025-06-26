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
        cout << "Produto cadastrado com sucesso!" << endl << endl;
    }

    string getNome() { return nome; }
    float getPreco() { return preco; }
    int getQuantidade() { return quantidade; }

    void setPreco(float novoPreco) { preco = novoPreco; }
    void setQuantidade(int novaQuantidade) { quantidade = novaQuantidade; }

    void exibirProduto() {
        cout << "\n=== Informações do produto ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Preço unitário: R$ " << preco << endl;
        cout << "Quantidade em estoque: " << quantidade << endl;
        cout << "Valor total em estoque: R$ " << calcularValorTotalEmEstoque() << endl;
        cout << "==============================" << endl;
    }

    float calcularValorTotalEmEstoque() {
        return preco * quantidade;
    }
};

int main() {
    Produto produto;
    char opcao;

    produto.cadastrarProduto();

    do {
        cout << "\nO que deseja fazer?" << endl;
        cout << "1 - Mostrar valor total do estoque" << endl;
        cout << "2 - Alterar preço do produto" << endl;
        cout << "3 - Alterar quantidade do produto" << endl;
        cout << "4 - Mostrar informações do produto" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(); 

        switch (opcao) {
            case '1':
                cout << "Valor total do estoque: R$ " << produto.calcularValorTotalEmEstoque() << endl;
                break;
            case '2': {
                float novoPreco;
                cout << "Digite o novo preço: ";
                cin >> novoPreco;
                cin.ignore();
                produto.setPreco(novoPreco);
                cout << "Preço atualizado com sucesso!" << endl;
                break;
            }
            case '3': {
                int novaQuantidade;
                cout << "Digite a nova quantidade: ";
                cin >> novaQuantidade;
                cin.ignore();
                produto.setQuantidade(novaQuantidade);
                cout << "Quantidade atualizada com sucesso!" << endl;
                break;
            }
            case '4':
                produto.exibirProduto();
                break;
            case '0':
                cout << "Saindo do programa. Até mais!" << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != '0');

    return 0;
}
