/*************************************************************************************
Programming Skills Challenge - Siemens
Exercicio 4. O programa verifica se é possível transformar a string s na string t com 
k ou mais movimentos (*obs: deletar ou concatenar string vazias são considerados movimentos)
For validation purpose, please go to: https://www.onlinegdb.com/maRpqFfZKH

Criado em 01/03/2024 - 06:52pm
Autora: Mariana Uzeda - mariana.uzeda@gmail.com
*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

// Função para verificar se é possível converter s em t usando k operações
string ConcatRemove(string s, string t, int k) {
    int LetrasIguais = 0;

    // Percorrendo s e t e contando o número de letras iguais
    for (int i = 0; i < min(s.length(), t.length()); ++i) {
        if (s[i] == t[i]) {
            LetrasIguais++;
        } else {
            break; // Ao percorrer, caso alguma letra não seja igual, interrompe-se o processo
        }
    }

    // Calcula o número de operações após as letras iguais iniciais.
    int NumOperacoes = s.length() - LetrasIguais + t.length() - LetrasIguais;

    // Verifica se é possível transformar s em t usando k operações*
    if (NumOperacoes <= k || k >= s.length() + t.length()) {
        return "Sim";
    } else {
        return "Não";
    }
}

int main() {
    // Entrada
    string s, t;
    int k;

    // Leitura da entrada
    cout << "Digite a string inicial (s): ";
    getline(cin, s);

    cout << "Digite a string desejada (t): ";
    getline(cin, t);

    cout << "Digite o número de operações (k): ";
    cin >> k;

    // Restrições
    if (s.length() < 1 || s.length() > 100 || t.length() < 1 || t.length() > 100 || k < 1 || k > 100) {
        cout << "Erro: Restrições para s,t e k não foram atendidas." << endl;
        return 1;
    }

    // Exibir o resultado
    cout << "Resultado: " << ConcatRemove(s, t, k) << endl;

    return 0;
}

