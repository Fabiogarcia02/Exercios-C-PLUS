#include <iostream>
#include <string>
using namespace std;

class Produto {
       string nome;
       float preco;
       int quantidade;

public:   
        Produto (string nome, float preco, int quantidade)
: nome(nome), preco(preco), quantidade(quantidade) {}

 void mostrardetalhes (){
     cout << "Nome: " << nome << endl;
    cout << "Preco: " << preco << endl;    
    cout << "Quantidade:" << quantidade << endl;
    cout << "Valor do estoquue:" << preco * quantidade << endl;
 }
 
};

int main() {
    Produto p1("Arroz", 10.50, 10);
    p1.mostrardetalhes();
    

    return 0;
}
 