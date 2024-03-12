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
           
            resultado.push_back(iniciais[i]);
        }
        
        
        while((iniciais[0] != 0) || (iniciais[iniciais.size()] != 0)){
            
            cout<<"teste"<<endl;
            
            for(int i = 0;i<iniciais.size();i++){
                
                cout<<"teste"<<endl;
                
                //para evitar repetir
                if(i == 1){
                    
                    cout<<"teste2"<<endl;
                    
                    if(iniciais[0] == iniciais[1]){
                        
                        cout<<"e"<<endl;
                        
                        continue;
                    }
                }
                
                cout<<"teste"<<endl;
                
                //muda o inicial para o vértice colorido para o qual ele aponta
                if(nos_coloridos[iniciais[i]-1] != 0){
                    
                    cout<<"teste"<<endl;
                    
                    iniciais[i] = nos_coloridos[iniciais[i]-1];
                }
                else{
                    
                    cout<<"teste"<<endl;
                
                    //muda o inicial para o vértice para o qual ele aponta (colocar -1 no índice porque o índice é 1 a menos que o valor do vértice)
                    iniciais[i] = nos_pretos[iniciais[i]-1];
                
                }
            }
            
            for(int i = 0;i<iniciais.size();i++){
                
               resultado.push_back(iniciais[i]);    
               cout<<iniciais[i]<<endl;
                
            }
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
