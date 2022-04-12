#include <iostream>
#include <iomanip>

using namespace std;

#define COLUNAS 40
#define FILEIRAS 15

int custoPoltrona(int fileira) {
    if (fileira < 4) return 50;

    if (fileira < 9) return 30;

    return 15;
}

int entradaValida(int maximo, string mensagem) {
    int valor;

    cout << mensagem;

    cin >> valor;

    while (valor < 1 || valor > maximo) {
        cout << mensagem;

        cin >> valor;
    }

    return valor;
}

void reservarPoltrona(char **poltronas, int *faturamento, int *poltronasOcupadas) {
    cout << endl;

    int fileira = entradaValida(FILEIRAS, "Fileira: ");

    int coluna = entradaValida(COLUNAS, "Poltrona: ");

    if (poltronas[fileira - 1][coluna - 1] == '.') {
        int cost = custoPoltrona(fileira - 1);

        poltronas[fileira - 1][coluna - 1] = '#';

        *faturamento += cost;

        *poltronasOcupadas += 1;

        cout << "Poltrona reservada" << endl << endl;
    } else
        cout << "Poltrona já está ocupada" << endl << endl;
}

void mostrarPoltronas(char **poltronas) {
    cout << endl;

    for (int i = 0; i < FILEIRAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            cout << setw(1) << poltronas[i][j] << " | ";
        }

        cout << endl;
    }

    cout << endl;
}

void mostrarFaturamento(const int *faturamento, const int *poltronasOcupadas) {
    cout << endl << "Qtde de lugares ocupados: " + to_string(*poltronasOcupadas) << endl;

    cout << "Valor da bilheteria: R$ " + to_string(*faturamento) << endl << endl;
}

void menu(bool *terminar, char **poltronas, int *faturamento, int *poltronasOcupadas) {
    int opt;

    cout << "0. Finalizar" << endl;

    cout << "1. Reservar poltrona" << endl;

    cout << "2. Mapa de ocupação" << endl;

    cout << "3. Faturamento" << endl;

    cout << "Opt: ";

    cin >> opt;

    switch (opt) {
        case 0: {
            *terminar = true;
            break;
        }
        case 1: {
            reservarPoltrona(poltronas, faturamento, poltronasOcupadas);
            break;
        }
        case 2: {
            mostrarPoltronas(poltronas);
            break;
        }
        case 3: {
            mostrarFaturamento(faturamento, poltronasOcupadas);
            break;
        }
        default: {
            cout << endl;
            break;
        }

    }

}

int main() {
    bool terminar = false;

    int faturamento = 0;

    int poltronasOcupadas = 0;

    char **poltronas = new char *[FILEIRAS];

    for (int i = 0; i < FILEIRAS; ++i) {
        char *coluna = new char[COLUNAS];

        for (int j = 0; j < COLUNAS; ++j) {
            coluna[j] = '.';
        }

        poltronas[i] = coluna;
    }

    while (!terminar) {
        menu(&terminar, poltronas, &faturamento, &poltronasOcupadas);
    }

    return 0;
}
