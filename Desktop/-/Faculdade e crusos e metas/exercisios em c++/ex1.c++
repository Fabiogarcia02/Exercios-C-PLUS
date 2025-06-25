#include <iostream>
#include <string>
using namespace std;

class Livro {
    string titulo;
    string autor;
    int ano;

public:
 
    Livro() {
        titulo = "";
        autor = "";
        ano = 0;
    }

 
    void lerdados() {
        cout << "Digite o titulo do livro: ";
        getline(cin, titulo);  

        cout << "Digite o nome do autor do livro: ";
        getline(cin, autor);

        cout << "Digite o ano do livro: ";
        cin >> ano;

        cin.ignore(); 
    }


    void exibirdados() {
        cout << "O titulo do livro é: " << titulo << endl;
        cout << "O autor do livro é: " << autor << endl;
        cout << "O ano do livro é: " << ano << endl;
    }
};

int main() {
    Livro livro1;      
    livro1.lerdados(); 
    livro1.exibirdados(); 

    return 0;
}
