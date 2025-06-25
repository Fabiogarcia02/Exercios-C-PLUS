#include <iostream>
#include <string>
using namespace std;

class Pessoa {
public:
    string nome;
    string cpf;  // faltava declarar aqui

    Pessoa(string n, string cp) : nome(n), cpf(cp) {}
};

class Aluno : public Pessoa {
public:
    int matricula;
    string curso;

    Aluno(string n, string cp, int m, string c) : Pessoa(n, cp), matricula(m), curso(c) {}
};

class Professor : public Pessoa {
public:
    string disciplina;
    float salario;

    Professor(string n, string cp, string d, float s) : Pessoa(n, cp), disciplina(d), salario(s) {}
};

class Funcionario : public Pessoa {
public:
    string setor;
    float salario;

    Funcionario(string n, string cp, string s, float sal) : Pessoa(n, cp), setor(s), salario(sal) {}
};

int main() {
    // Testando as classes
    Aluno a("Joao", "12345678900", 2025001, "Engenharia");
    Professor p("Maria", "98765432100", "Matematica", 4500.50);
    Funcionario f("Carlos", "55566677788", "Financeiro", 3500);

    cout << "Aluno: " << a.nome << ", CPF: " << a.cpf << ", Matricula: " << a.matricula << ", Curso: " << a.curso << endl;
    cout << "Professor: " << p.nome << ", CPF: " << p.cpf << ", Disciplina: " << p.disciplina << ", Salario: " << p.salario << endl;
    cout << "Funcionario: " << f.nome << ", CPF: " << f.cpf << ", Setor: " << f.setor << ", Salario: " << f.salario << endl;

    return 0;
}
