#include <iostream>
using namespace std;

#define QTD_NUMEROS 30

#pragma region Funcoes Pilha
struct Pilha {
	int qtde;
	float elementos[QTD_NUMEROS];
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
};

int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < QTD_NUMEROS);
	if (podeEmpilhar) {
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

float pop(Pilha *p) {
	int podeDesempilhar = (p->qtde > 0);
	float ret;
	if (podeDesempilhar) {
		ret = p->elementos[p->qtde-1];
		p->qtde--;
	}
	else
	{
		ret = NULL;
	}
	return ret;
}

int count(Pilha *p) {
	return (p->qtde);
}

int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

void print(Pilha *p) {
	for(int i = p->qtde-1; i>=0; --i) {
		cout << p->elementos[i] << endl;
	}
	cout << "----------" << endl;
}
#pragma endregion


void digitarNumeros(Pilha *pilhaImpares, Pilha *pilhaPares)
{
    int num, maiorNumero = NULL;
    for(int i = 0; i < QTD_NUMEROS; i ++)
    {
		do
    	{
			cout << "Digite o " << i + 1 << "º numero: ";
			cin >> num;
			
			if(i == 0){
				maiorNumero = num;
			}
			
			if(num <= maiorNumero && i != 0)
	        {
	        	cout << "Numero invalido, digite um numero maior que anterior" << endl;	
			}
	     	
	    }while(num <= maiorNumero && i != 0);
	    
	    maiorNumero = num;
	    
        if(num % 2 == 0){
            push(pilhaPares, num);
        }else{
            push(pilhaImpares, num);
        }
    }
}


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

	Pilha *pilhaImpares;
    Pilha *pilhaPares;

	pilhaImpares = init();
    pilhaPares = init();

	digitarNumeros(pilhaImpares, pilhaPares);
	
    cout << endl << "Pilha de impares: " << endl;
    print(pilhaImpares);

    cout << endl << "Pilha de pares: " << endl;
    print(pilhaPares);
		
	return 0;
}
