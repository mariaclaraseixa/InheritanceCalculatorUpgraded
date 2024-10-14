#include <iostream>
#include <memory>  // Para std::shared_ptr
#include <map>
#include <functional>

// Classe abstrata
class Operacao { // Classe pai ou superclasse -> esta classe é abstrata
public:
    virtual int calcular(int operador1, int operador2) const = 0; // Método abstrato
    virtual ~Operacao() = default;  // Destrutor virtual
};

// Classe Soma que implementa Operacao
class Soma : public Operacao { // Classe filha
public:
    int calcular(int operador1, int operador2) const override {
        return operador1 + operador2;
    }
};

// Classe Subtracao que implementa Operacao
class Subtracao : public Operacao {
public:
    int calcular(int operador1, int operador2) const override {
        return operador1 - operador2;
    }
};

// Classe Multiplicacao que implementa Operacao
class Multiplicacao : public Operacao {
public:
    int calcular(int operador1, int operador2) const override {
        return operador1 * operador2;
    }
};

// Classe Divisao que implementa Operacao
class Divisao : public Operacao {
public:
    int calcular(int operador1, int operador2) const override {
        if (operador2 == 0) {
            std::cerr << "Erro: Divisao por zero!" << std::endl;
            return 0; // Evitar divisão por zero
        }
        return operador1 / operador2;
    }
};



#include <iostream>
#include <memory>
#include <map>


// Função principal
int main() {
    int num1, num2;
    char operador;

    // Pedir ao usuário os dois números e a operação
    std::cout << "Digite o primeiro numero: ";
    std::cin >> num1;
    std::cout << "Digite o segundo numero: ";
    std::cin >> num2;
    std::cout << "Digite a operacao (+, -, *, /): ";
    std::cin >> operador;

    // Ponteiro para a classe Operacao
    std::shared_ptr<Operacao> operacao;


    std::map<char, std::shared_ptr<Operacao>> operacoes {
            {'+', std::make_shared<Soma>()},
            {'-', std::make_shared<Subtracao>()},
            {'*', std::make_shared<Multiplicacao>()},
            {'/', std::make_shared<Divisao>()}
    };


    if (operacoes.find(operador) == operacoes.end()) {
        std::cerr << "Operacao invalida!" << std::endl;
        return 1;  // Saída com código de erro
    }

    operacao = operacoes[operador];

    // Chamar o método calcular da operação correspondente
    int resultado = operacao->calcular(num1, num2);
    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}