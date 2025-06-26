 // ------------------------
// Questão 8 (11,0 pontos)
// ------------------------

// (a) [5 pontos]
// Crie uma classe chamada `Pagamento` usada em um sistema de e-commerce.
// Atributos:
// - comprador (string)
// - valor (float)
// - codProduto (int)
//
// Todos devem ser privados, com métodos getters e setters protegendo o acesso.
//
// No construtor parametrizado:
// - impedir que `codProduto` seja menor que 0 ou maior que 5
// - impedir que `valor` seja negativo

// Crie duas classes que herdem de Pagamento:
// - `CartaoCredito`, com atributo adicional: bandeiraCartao (string)
// - `PIX`, com atributo adicional: codBanco (int)


// (b) [5 pontos]
// Crie uma função chamada `ganhoPorProduto` com o seguinte cabeçalho:
//
// float ganhoPorProduto(int m, int n, CartaoCredito v1[], PIX v2[], int k);
//
// Essa função deve:
// - Receber um código de produto `k`
// - Receber um vetor de `CartaoCredito` (v1) com `m` elementos
// - Receber um vetor de `PIX` (v2) com `n` elementos
//
// - Se `k` < 0 ou > 5 → imprimir mensagem de erro e retornar 0
// - Senão → somar todos os valores de produtos com codProduto == k
// - Retornar esse total

// (c) [1 ponto]
// Crie a função `main()` para:
// - Declarar vetores com 10 objetos de `CartaoCredito` e 10 de `PIX`
// - Preencha os vetores com dados (pode ser fixo ou usando cin)
// - Peça ao usuário um valor de `k`
// - Chame `ganhoPorProduto()`
// - Imprima o total arrecadado com esse produto
 

 
 #include <iostream>
#include <string>
using namespace std;

class Pagamento {
private:
    string comprador;
    float valor;
    int codProduto;

public:
    Pagamento(string nome, float val, int cod) {
        setComprador(nome);
        setValor(val);
        setCodProduto(cod);
    }

    string getComprador() { return comprador; }
    float getValor() { return valor; }
    int getCodProduto() { return codProduto; }

    void setComprador(string nome) {
        comprador = nome;
    }

    void setValor(float val) {
        if (val >= 0)
            valor = val;
        else {
            cout << "Valor inválido. Não pode ser negativo." << endl;
            valor = 0;
        }
    }

    void setCodProduto(int cod) {
        if (cod >= 0 && cod <= 5)
            codProduto = cod;
        else {
            cout << "Código de produto inválido. Deve estar entre 0 e 5." << endl;
            codProduto = 0;
        }
    }
};

// ======================= Cartão ===========================
class CartaoCredito : public Pagamento {
private:
    string bandeiraCartao;

public:
    CartaoCredito(string nome, float val, int cod, string bandeira)
        : Pagamento(nome, val, cod), bandeiraCartao(bandeira) {}

    string getBandeiraCartao() {
        return bandeiraCartao;
    }
};

// ======================== PIX =============================
class PIX : public Pagamento {
private:
    int codBanco;

public:
    PIX(string nome, float val, int cod, int banco)
        : Pagamento(nome, val, cod), codBanco(banco) {}

    int getCodBanco() {
        return codBanco;
    }
};

// ================= Função solicitada ======================
float ganhoPorProduto(int m, int n, CartaoCredito v1[], PIX v2[], int k) {
    if (k < 0 || k > 5) {
        cout << "Código de produto inválido. Deve estar entre 0 e 5." << endl;
        return 0.0;
    }

    float total = 0.0;

    for (int i = 0; i < m; i++) {
        if (v1[i].getCodProduto() == k) {
            total += v1[i].getValor();
        }
    }

    for (int i = 0; i < n; i++) {
        if (v2[i].getCodProduto() == k) {
            total += v2[i].getValor();
        }
    }

    return total;
}

// ======================= MAIN =============================
int main() {
    const int m = 3;
    const int n = 2;

    CartaoCredito cartoes[m] = {
        CartaoCredito("João", 100.50, 3, "Visa"),
        CartaoCredito("Ana", 250.00, 1, "Master"),
        CartaoCredito("Carlos", 300.00, 3, "Elo")
    };

    PIX pixes[n] = {
        PIX("Maria", 200.75, 3, 104),
        PIX("Lucas", 80.00, 1, 341)
    };

    int k;
    cout << "Digite o código do produto (0 a 5): ";
    cin >> k;

    float total = ganhoPorProduto(m, n, cartoes, pixes, k);

    cout << "Total arrecadado com o produto de código " << k << ": R$ " << total << endl;

    return 0;
}
 