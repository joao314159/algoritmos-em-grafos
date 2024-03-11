#include <iostream>
#include <vector>

using namespace std;

class Grafo1{
    
    public:

    Grafo1(){}
    
    Grafo1(int N){
        this->N = N;
    }
    
    Grafo1(int N, unsigned* nos_pretos, unsigned* nos_coloridos){
        
        this->N = N;

        for(int i =0;i<N;i++){
            
            this->pesos.push_back(1);
            
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
        vector<unsigned> resultado;

        unsigned* lista = new unsigned[N];

        for(int i = 0;i<N;i++){
            lista[N] = 0;
        }

        for(int i = 0;i < N;i++){
            //se há mais de uma aresta chegando no vértice nos_pretos[i], nos_pretos[i] é aumentado em 1
            if(nos_pretos[i]){
                lista[nos_pretos[i]]++;
            }
            //se há mais de uma aresta chegando no vértice nos_coloridos[i], nos_coloridos[i] é aumentado em 1
            if(nos_coloridos[i]){
                lista[nos_coloridos[i]]++;
            }
        }

        for(int i = 0;i<N;i++){
            if(lista[i] == 0){
                iniciais.push_back(i);
                cout<<"vértice inicial: "<<i<<endl;
            }
        }
        
        //coloca os elementos iniciais no vetor de retorno
        for(int i = 0;i<iniciais.size();i++){
            cout<<i<<endl;
            resultado.push_back(iniciais[i]);
        }
        
        for(int i = 0;i<iniciais.size();i++){
            cout<<i<<endl;
        }
        
        return resultado;
    }
};


int main()
{
    
    unsigned nos_pretos[6] = {0,6,5,2,1,0};
    unsigned nos_coloridos[6] = {0,1,0,5,0,0};
    
    Grafo1 grafo(6,nos_pretos,nos_coloridos);
    
    grafo.ordenar();
    
    return 0;
}
