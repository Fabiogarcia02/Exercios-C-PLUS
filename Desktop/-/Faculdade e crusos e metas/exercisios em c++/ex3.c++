#include <iostream>
#include <string>
using namespace std;

class ContaBancaria {
private:
    float saldo;

public:
    string titular;

    ContaBancaria(string nome) : titular(nome), saldo(0.0f) {}

    float getSaldo() {
        return saldo;
    }

    void depositar(float valor) {
        if (valor > 0) saldo += valor;
    }

    void sacar(float valor) {
        if (valor <= saldo)
            saldo -= valor;
        else
            cout << "Saldo insuficiente.\n";
    }
};

int main() {
    ContaBancaria conta("João");
    conta.depositar(250.99f);
    conta.sacar(100.00f);

    // Exibindo o saldo atual
    cout << "Saldo de " << conta.titular << ": R$ " << conta.getSaldo() << endl;

    return 0;
}
