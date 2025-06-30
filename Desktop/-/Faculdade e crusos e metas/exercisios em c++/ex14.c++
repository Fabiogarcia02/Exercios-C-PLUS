#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class ContaBancaria {
private:
    string titular;
    float saldo;

public:
    void setTitular(string titular){
        this->titular = titular;
    }

    string getTitular(){
        return this->titular;
    }

    float getSaldo(){
        return this->saldo;
    }

    void setSaldo(float saldo){
        this->saldo = saldo;
    }

    void depositar(float valor){
        if(valor < 0){
            cout << "Valor inválido!" << endl;
            return;
        }
        this->saldo += valor;
    }

    void sacar(float valor){
        if(valor < 0){
            cout << "Valor inválido!" << endl;
            return;
        }
        if(valor > saldo){
            cout << "Saldo insuficiente!" << endl;
            return;
        }
        this->saldo -= valor;
    }

    void imprimirDados(){
        cout << "Titular: " << this->titular << endl;
        cout << "Saldo: R$ " << fixed << setprecision(2) << this->saldo << endl;
        cout << "-------------------------------------" << endl;
    }
};

int main() {
  

    return 0;
}
