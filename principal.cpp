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

    vector<unsigned> caminhada(){

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


        //agora foram selecionados os iniciais, a partir deles diminuímos o grau de entrada dos nós para os quais eles apontam, adicionamos a iniciais os nós com grau de entrada 0 e removemos os graus de entrada antigos




        cout<<"O nó inicial "<<iniciais[0]<<" aponta para " << nos_pretos[iniciais[0]-1]<<endl;
        cout<<"O nó inicial "<<iniciais[1]<<" aponta para " << nos_pretos[iniciais[1]-1]<<endl;

        //para cada nó inicial reduzimos o grau do nó para qual ele aponta
        while(iniciais.size()>0){
            
            if( (nos_pretos[iniciais[i]-1] == 0)&& (nos_coloridos[iniciais[i]-1] == 0 )){
                //caso o inicial não aponta para nenhum nó pela aresta preta nem pela aresta colorida
                iniciais.pop();
            }
            else if(nos_coloridos[iniciais[i]-1] == 0){
                //caso o inicial não aponta para nenhum nó pela aresta colorida
            }    
            else{
                
            lista[nos_pretos[iniciais[i]-1]]--;
            //também é necessário fazer isso com os nós coloridos
            }
        }




        //coloca os elementos iniciais no vetor de retorno
        for(int i = 0;i<iniciais.size();i++){

            resultado.push_back(iniciais[i]);
        }


        for(int i = 0;i<iniciais.size();i++){

            //muda o inicial para o vértice para o qual ele aponta (colocar -1 no índice porque o índice é 1 a menos que o valor do vértice)
            iniciais[i] = nos_pretos[iniciais[i]-1];

        }

        for(int i = 0;i<iniciais.size();i++){

           cout<<iniciais[i]<<endl;

        }



        return resultado;
    }
};


int main()
{
    unsigned nos_pretos[6] = {0,6,5,2,1,0};
    unsigned nos_coloridos[6] = {0,1,0,5,0,0};

    Grafo1 grafo(6,nos_pretos,nos_coloridos);

    grafo.caminhada();

    return 0;
}
