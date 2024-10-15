Esta versão aprimorada da calculadora em C++ utiliza herança, polimorfismo e a estrutura de dados std::map 
para associar operadores aritméticos às respectivas operações. O código elimina a necessidade de condicionais múltiplas,
centralizando a escolha das operações no mapa, tornando o código mais eficiente e escalável.

Funcionalidades

	•	Suporte para operações: +, -, *, /
	•	Utilização de herança para definir operações aritméticas em classes especializadas
	•	Implementação de polimorfismo para realizar operações de forma flexível
	•	std::map para associar operadores a suas respectivas implementações
	•	Verificação de divisão por zero

Estrutura do Código

	•	Classe base Operacao: Define o método abstrato calcular(), implementado pelas subclasses.
	•	Subclasses: Soma, Subtracao, Multiplicacao, e Divisao, cada uma define como realizar a operação correspondente.
	•	std::map: Mapeia os operadores (+, -, *, /) para as suas respectivas classes, evitando o uso de estruturas condicionais (if-else).
