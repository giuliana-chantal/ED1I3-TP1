#include <iostream>
#include <random>

using namespace std;

#define TAMANHO_BARALHO 13
#define TAMANHO_MAO 11
#define JOGADORES 4

int numeroAleatorio(int max) {
    srandom(time(0));

    return random() % (max + 1 - min) + min;

//    random_device rd;
//
//    uniform_int_distribution<int> distr(0, max);
//
//    return distr(rd);
}

string sortearCarta(string ***baralhos, string **maos) {
    int baralho = numeroAleatorio(1);
    int naipe = numeroAleatorio(3);
    int carta = numeroAleatorio(TAMANHO_BARALHO - 1);

    string cartaSorteada = baralhos[baralho][naipe][carta];

    if(cartaSorteada != ""){
        baralhos[baralho][naipe][carta] = "";
    }

    return cartaSorteada;
}

void distribuirCartas(string ***baralhos, string **maos) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < TAMANHO_MAO; ++j) {
            string cartaSorteada = sortearCarta(baralhos, maos);

            while (cartaSorteada == "") {
                cartaSorteada = sortearCarta(baralhos, maos);
            }

            maos[i][j] = cartaSorteada;
        }
    }
}

void mostrarMaos(string **maos) {
    for (int i = 0; i < JOGADORES; ++i) {
        for (int j = 0; j < TAMANHO_MAO; ++j) {
            cout << maos[i][j] << " | ";
        }

        cout << endl;
    }
}

int main() {
    string ***baralhos = new string **[2];

    for (int i = 0; i < 2; ++i) {
        string **naipes = new string *[4];

        for (int j = 0; j < 4; ++j) {
            string* cartas = new string[TAMANHO_BARALHO];

            for (int k = 0; k < TAMANHO_BARALHO; ++k) {
                // 4-10-2  ->  10 de espada do baralho 2
                cartas[k] = to_string(j + 1) + "-" + to_string(k + 1) + "-" + to_string(i + 1);
            }

            naipes[j] = cartas;
        }

        baralhos[i] = naipes;
    }

    string **maos = new string *[JOGADORES];

    for (int i = 0; i < JOGADORES; ++i) {
        maos[i] = new string[TAMANHO_MAO];
    }

    distribuirCartas(baralhos, maos);

    mostrarMaos(maos);

    return 0;
}