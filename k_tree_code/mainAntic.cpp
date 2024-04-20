#include <iostream>
#include "k_tree.hh"
#include "relaxed_k_tree.hh"
#include "squarish_k_tree.hh"
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {

    string tipusArbre = argv[1];
    vector<int> dimensions = {2,3,4,5,6};//{1,2,3,4,5,6}; // dimensions a testejar

    vector<int> mides_de_l_arbre= {10, 100, 1000, 10000, 100000}; // les diferentes mides dels arbres
    
    int n_vegades_cada_mida_arbre = 100; // son les vegades que es fara un test per a cadamida de l'arbre

    if (tipusArbre == "KTree" or tipusArbre == "RKTree" or tipusArbre == "SKTree") {

        for(int dimensio : dimensions){
            cout << "DIMENSIO: " << dimensio << endl;
            for(int mida : mides_de_l_arbre){
                cout << "   MIDA: " << mida << endl;
                cout << "   COSTS: ";
                int sum = 0;
                for (int test = 0; test < n_vegades_cada_mida_arbre; ++test){

                    KTree arbre(dimensio);    

                    if (tipusArbre == "RKTree") {
                        RelaxedKTree arbre(dimensio);
                    } 
                    else if (tipusArbre == "SKTree") {
                        SquarishKTree arbre(dimensio);
                    }
                    
                    arbre.omplir_aleatoriament(mida);
                    int cost = arbre.trobar_vei_mes_proper_a_punt_aleatori();
                    sum += cost;
                    cout << cost << " ";
                    
                    
                }
                cout << endl; cout << "   =============> MITJANA COST: "<< sum/n_vegades_cada_mida_arbre << " <===============";
                cout << endl << endl;
            }
        }
    }
    
    else {
        cout <<"USAGE: make <tipusArbre>" << endl;
        cout << "tipusArbre = { KTree_test, RKTree_test, SKTree_test}"<< endl;
    }
/*



    SquarishKTree arbre(2);
    arbre.omplir_aleatoriament(10);
    arbre.print_tree();
    */

    //arbre.trobar_vei_mes_proper({0.9,8});
}
