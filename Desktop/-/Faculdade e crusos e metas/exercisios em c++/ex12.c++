#include <iostream>
#include <string>
using namespace std;

class Funcionario {
public:
    string nome;
    float salario;
    string cpf;
    string data_nascimento;
    string rg;
    string Nivel;
    int temponaempresa;

    Funcionario(
        string nome = "",
        float salario = 0.0,
        string cpf = "",
        string data_nascimento = "",
        string rg = "",
        string Nivel = "",
        int temponaempresa = 0
    ) {
        this->nome = nome;
        this->salario = salario;
        this->cpf = cpf;
        this->data_nascimento = data_nascimento;
        this->rg = rg;
        this->Nivel = Nivel;
        this->temponaempresa = temponaempresa;
    }
};

class Gerente : public Funcionario {
public:
    string departamento;

    Gerente(
        string nome = "",
        float salario = 0.0,
        string cpf = "",
        string data_nascimento = "",
        string rg = "",
        string Nivel = "",
        int temponaempresa = 0,
        string departamento = ""
    ) : Funcionario(nome, salario, cpf, data_nascimento, rg, Nivel, temponaempresa) {
        this->departamento = departamento;
    }

    void CadastrarGerente() {
        cout << "Digite o nome do gerente: ";
        getline(cin >> ws, nome);
        cout << "Digite o salario do gerente: ";
        cin >> salario;
        cout << "Digite o cpf do gerente: ";
        cin >> cpf;
        cout << "Digite a data de nascimento do gerente: ";
        cin >> data_nascimento;
        cout << "Digite o rg do gerente: ";
        cin >> rg;
        cout << "Digite o nivel do gerente: ";
        cin >> Nivel;
        cout << "Digite o tempo na empresa do gerente: ";
        cin >> temponaempresa;
        cout << "Digite o departamento do gerente: ";
        cin >> departamento;
        cout << "\nGerente cadastrado com sucesso!\n" << endl;
    }

    void ExibirGerente() {
        cout << "\n--- Dados do Gerente ---" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Salario: R$" << salario << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Data de nascimento: " << data_nascimento << endl;
        cout << "RG: " << rg << endl;
        cout << "Nivel: " << Nivel << endl;
        cout << "Tempo na empresa: " << temponaempresa << " anos" << endl;
        cout << "Departamento: " << departamento << endl;
        cout << "------------------------------\n";
    }
};

int main() {
    const int MAX = 3;
    Gerente gerentes[MAX];
    int total = 0;

    int opcao;

    do {
        cout << "\n========= MENU =========" << endl;
        cout << "1. Cadastrar Gerente" << endl;
        cout << "2. Exibir um Gerente pelo número" << endl;
        cout << "3. Exibir todos os Gerentes" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (total < MAX) {
                    gerentes[total].CadastrarGerente();
                    total++;
                } else {
                    cout << "Limite de gerentes atingido!" << endl;
                }
                break;
            case 2: {
                int indice;
                cout << "Digite o número do gerente (1 a " << total << "): ";
                cin >> indice;
                if (indice >= 1 && indice <= total) {
                    gerentes[indice - 1].ExibirGerente();
                } else {
                    cout << "Índice inválido!" << endl;
                }
                break;
            }
            case 3:
                if (total == 0) {
                    cout << "Nenhum gerente cadastrado." << endl;
                } else {
                    for (int i = 0; i < total; i++) {
                        cout << "\nGerente " << (i + 1) << ":" << endl;
                        gerentes[i].ExibirGerente();
                    }
                }
                break;
            case 4:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
        }

    } while (opcao != 4);

    return 0;
}
