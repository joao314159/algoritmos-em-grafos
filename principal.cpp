#include <iostream>
#include <vector>

using namespace std;

class Grafo1{

    Grafo(){}
    Grafo(int N){
        this->N = N;
    }
    Grafo(int N,unsigned* pesos, unsigned* nos_pretos, unsigned* nos_coloridos){
        this->N = N;

        for(int i =0;i<N;i++){

            this->nos_pretos.push_back(nos_pretos[i]);

            this->nos_coloridos.push_back(nos_coloridos[i]);
        }
        this->nos_pretos.push_back(0);
        this->nos_coloridos.push_back(0);


    }

    int N;
    int M;

    vector<unsigned> nos_pretos;
    vector<unsigned> nos_coloridos;

    vector<unsigned> pesos;

    vector<unsigned> ordenar(){

        vector<unsigned> iniciais;

        unsigned* lista = new unsigned[N];

        for(int i = 0;i<N;i++){
            lista[N] = 0;
        }

        for(int i= 0;i<N;i++){

            if(nos_pretos[i]){
                lista[nos_pretos[i]]++;
            }
            if(nos_coloridos[i]){
                lista[nos_coloridos[i]]++;
            }
        }

        for(int i = 0;i<N;i++){
            if(lista[i] > 0){
                iniciais.push_back(i);
            }

        }

    }


};













int main()
{





    cout << "Hello world!" << endl;
    return 0;
}
