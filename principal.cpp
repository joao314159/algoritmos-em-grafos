#include <iostream>
#include <vector>

using namespace std;

class Grafo{

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
        
    }

    int N;
    int M;

    vector<unsigned> nos_pretos;
    vector<unsigned> nos_coloridos;

    vector<unsigned> pesos;


};













int main()
{





    cout << "Hello world!" << endl;
    return 0;
}
