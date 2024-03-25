#include <iostream>
#include <vector>

#define NUM_MAX_OP 7

using namespace std;

class Grafo1{

    public:

    Grafo1(){}

    Grafo1(int quantidade_nos){
        this->quantidade_nos = quantidade_nos;
    }

    Grafo1(int quantidade_nos, unsigned* nos_pretos, unsigned* nos_coloridos){

        this->quantidade_nos = quantidade_nos;

        for(int i =0;i<quantidade_nos;i++){

            this->pesos.push_back(1);

            this->nos_pretos.push_back(nos_pretos[i]);

            this->nos_coloridos.push_back(nos_coloridos[i]);
        }
        this->nos_pretos.push_back(0);
        this->nos_coloridos.push_back(0);

    }

    int quantidade_nos;

    vector<unsigned> nos_pretos;
    vector<unsigned> nos_coloridos;

    vector<unsigned> pesos;

    vector<unsigned> caminhada(){

        unsigned auxiliar;
        unsigned auxiliar2;

        unsigned vertice_atual;

        vector<unsigned> iniciais;
        vector<unsigned> resultado;

        unsigned* grau_no = new unsigned[quantidade_nos];

        for(int i = 1;i<(quantidade_nos);i++){
            grau_no[i] = 0;
        }

        for(int i = 0;i < quantidade_nos;i++){

            //se há mais de uma aresta chegando no vértice nos_pretos[i], nos_pretos[i] é aumentado em 1
            if(nos_pretos[i]){
                grau_no[nos_pretos[i]]++;
            }

            //se há mais de uma aresta chegando no vértice nos_coloridos[i], nos_coloridos[i] é aumentado em 1
            if(nos_coloridos[i]){
                grau_no[nos_coloridos[i]]++;
            }

        }

        for(int i = 1;i<(quantidade_nos);i++){
            if(grau_no[i] == 0){
                iniciais.push_back(i);

                cout<<"vértice inicial: "<<i<<endl;

            }
        }


        //agora foram selecionados os iniciais, a partir deles diminuímos o grau de entrada dos nós para os quais eles apontam, adicionamos a iniciais os nós com grau de entrada 0 e removemos os graus de entrada antigos




        //cout<<"O nó inicial "<<iniciais[0]<<" aponta para " << nos_pretos[iniciais[0]-1]<<endl;
        // cout<<"O nó inicial "<<iniciais[1]<<" aponta para " << nos_pretos[iniciais[1]-1]<<endl;

        //para cada nó inicial reduzimos o grau do nó para qual ele aponta
        while(iniciais.size()>0){

            vertice_atual = iniciais.back();

            cout<<"vértice atual: "<<vertice_atual<<endl;

            resultado.push_back(vertice_atual);

            iniciais.pop_back();

            if(nos_pretos[vertice_atual] != 0) {
                grau_no[nos_pretos[vertice_atual]]--;
                if(grau_no[nos_pretos[vertice_atual]] == 0){
                    iniciais.push_back(nos_pretos[vertice_atual]);
                }
            }
            if(nos_coloridos[vertice_atual] != 0) {
                grau_no[nos_coloridos[vertice_atual]]--;
                if(grau_no[nos_coloridos[vertice_atual]] == 0){
                    iniciais.push_back(nos_coloridos[vertice_atual]);
                }
            }
        }

/*
            if( (nos_pretos[vertice_atual] == 0)&& (nos_coloridos[vertice_atual] == 0 )){
                //caso o inicial não aponta para nenhum nó pela aresta preta nem pela aresta colorida
                cout<<"O nó "<<iniciais.back()<<" não tem arestas pretas nem coloridas"<<endl;
                iniciais.pop_back();
            }*/

          //  else if(nos_coloridos[iniciais.back()-1] == 0){
         //       //caso o inicial não aponta para nenhum nó pela aresta colorida, mas aponta pela aresta preta

        //        //diminuímos o grau da variável para a qual o inicial aponta pela aresta preta
        //        grau_no[nos_pretos[iniciais.back()-1]]--;
        //        cout<<"O nó "<<iniciais.back()<<" aponta para "<<nos_pretos[iniciais.back()-1]<<" pela aresta preta"<<endl;

        //        cout<<"grau do nó "<<iniciais.back()<<": "<< grau_no[nos_pretos[iniciais.back()-1]]<<endl;

        //        //salvamos o valor da variável para a qual o inicial aponta pela aresta preta
        //        auxiliar = nos_pretos[iniciais.back() -1];
//
         //       cout<<auxiliar<<endl;
        //        cout<<"inicial: "<< iniciais.back();

         //       resultado.push_back(iniciais.back());
         //       iniciais.pop_back();

        //        //se um nó passou a ter grau de entrada zero, ele é inicial
         //       if(grau_no[auxiliar] <= 0){
         //           cout<<"no fim da lista colocamos o nó "<<auxiliar<<endl;
       //            iniciais.push_back(auxiliar);
     //          }
     //       }
        /*    else{

                //caso o nó inicial aponta para outro nó pela aresta preta, e para outro nó pela aresta colorida

                //diminuímos o grau da variável para a qual o inicial aponta pela aresta preta,e pela aresta colorida
                grau_no[nos_pretos[iniciais.back()-1]]--;
                grau_no[nos_coloridos[iniciais.back()-1]]--;


                //salvamos o valor da variável para a qual o inicial aponta pela aresta preta, e pela aresta colorida
                auxiliar = nos_pretos[iniciais.back() -1];
                auxiliar2 = nos_coloridos[iniciais.back()-1];

                resultado.push_back(iniciais.back());
                iniciais.pop_back();

                if(grau_no[auxiliar] <= 0){
                     iniciais.push_back(auxiliar);
                }
                if(grau_no[auxiliar2] <= 0){
                     iniciais.push_back(auxiliar2);
                }


            }
        }




        //coloca os elementos iniciais no vetor de retorno
 //       for(int i = 0;i<iniciais.size();i++){

  //         resultado.push_back(iniciais[i]);
 //       }


  //      for(int i = 0;i<iniciais.size();i++){

            //muda o inicial para o vértice para o qual ele aponta (colocar -1 no índice porque o índice é 1 a menos que o valor do vértice)
 //           iniciais[i] = nos_pretos[iniciais[i]-1];

  //      }
*/

        cout<<"resultado: "<<endl;

        for(int i = 0;i<resultado.size();i++){

           cout<<resultado[i]<<endl;

        }


        return resultado;



    }
};


int main()
{
    unsigned nos_pretos[NUM_MAX_OP] = {0,0,6,5,2,1,0};
    unsigned nos_coloridos[NUM_MAX_OP] = {0,0,1,6,5,0,0};

    Grafo1 grafo(6,nos_pretos,nos_coloridos);

    grafo.caminhada();

    return 0;
}
