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

    string getNome() {
        return nome;
    }

    float getPreco() {
        return preco;
    }

    int getQuantidade() {
        return quantidade;
    }

    void cadastrarProduto() {
        cout << "Digite o nome do produto: ";
        cin >> nome;
        cout << "Digite o preco do produto: ";
        cin >> preco;
        cout << "Digite a quantidade do produto: ";
        cin >> quantidade;
    }

    void setMudarPreco(float novoPreco) {
        preco = novoPreco;
    }

    void setMudarQuantidade(int novaQuantidade) {
        quantidade = novaQuantidade;
    }

    float calcularValorTotalEmEstoque() {
        return preco * quantidade;
    }

    void exibirResumo() {
        cout << "Produto: " << nome << " | Preço: R$ " << preco
             << " | Quantidade: " << quantidade
             << " | Total em estoque: R$ " << calcularValorTotalEmEstoque()
             << endl;
    }
};

int main() {
    const int TAM = 5;
    Produto produtos[TAM];

    cout << "=== Cadastro de Produtos ===" << endl;

    for (int i = 0; i < TAM; i++) {
        cout << "\nCadastro do produto " << (i + 1) << ":" << endl;
        produtos[i].cadastrarProduto();

        char opcao;
        cout << "Deseja ver o valor em estoque deste produto? (s/n): ";
        cin >> opcao;
        if (opcao == 's' || opcao == 'S') {
            produtos[i].exibirResumo();
        }
    }

    cout << "\n=== Resumo Final dos Produtos ===" << endl;
    for (int i = 0; i < TAM; i++) {
        produtos[i].exibirResumo();
    }

    return 0;
}
