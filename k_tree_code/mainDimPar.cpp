#include <iostream>
#include "k_tree.hh"
#include "relaxed_k_tree.hh"
#include "squarish_k_tree.hh"
#include <vector>
#include <ctime>
#include <chrono>
using namespace std;


int main(int argc, char* argv[]) {

    int dimensio = stoi(argv[1]);
    vector<int> dimensions = {dimensio};
    //vector<int> dimensions = {2,3,4,5,6};//{1,2,3,4,5,6}; // dimensions a testejar

    vector<int> mides_de_l_arbre= {10, 100, 1000, 10000};//, 100000, 1000000}; // les diferentes mides dels arbres
    
    int n_arbres_per_mida = 100; // son les vegades que es fara un test per a cadamida de l'arbre
    int n_consultes_cada_arbre = 1000;
    
    cout << "#12:55 5-10-2023" << endl;
    cout << "#n_arbres_per_mida: " << n_arbres_per_mida << endl;
    cout << "#n_consultes_cada_arbre: " << n_consultes_cada_arbre << endl;
    
        for(int dimensio : dimensions){
            cout << "DIMENSIO: " << dimensio << endl;
            for(int mida : mides_de_l_arbre){
                cout << "   MIDA: " << mida << endl;

                vector<int> costs (3,0); //costK costRK costSK
                vector<vector<double> > valorsTrobarRandom = KTree::getVectorRandomValues(n_consultes_cada_arbre, dimensio);
                for (int test = 0; test < n_arbres_per_mida; ++test){

                    vector<vector<double> > valorsOmplirRandom = KTree::getVectorRandomValues(mida, dimensio);
  
                    for(int k = 0; k < 3; ++k) {
                        if (k == 0) {
                            KTree arbre(dimensio);
                            arbre.omplirAmbVector(valorsOmplirRandom);
                            int sum = 0; 
                            vector<int> costsLocal (valorsTrobarRandom.size());
                            for (int i = 0; i < valorsTrobarRandom.size(); ++i) costsLocal[i] = arbre.trobar_vei_mes_proper(valorsTrobarRandom[i]);
                            
                            costs[k] += sum/valorsTrobarRandom.size();
                        }
                        else if(k == 1) {
                            RelaxedKTree arbre(dimensio);
                            arbre.omplirAmbVector(valorsOmplirRandom);
                            int sum = 0; 
                            for (vector<double> clau : valorsTrobarRandom) sum += arbre.trobar_vei_mes_proper(clau);
                            costs[k] += sum/valorsTrobarRandom.size();
                        }
                        else {
                            SquarishKTree arbre(dimensio);
                            arbre.omplirAmbVector(valorsOmplirRandom);
                            int sum = 0; 
                            for (vector<double> clau : valorsTrobarRandom) sum += arbre.trobar_vei_mes_proper(clau);
                            costs[k] += sum/valorsTrobarRandom.size();
                        }
                    }
                    
                }

                for (int a = 0; a < costs.size(); ++a) costs[a] = costs[a]/n_arbres_per_mida;

                cout << "   COST KTREE  " << costs[0] << endl;
                cout << "   COST RKTREE " << costs[1] << endl;
                cout << "   COST SKTREE " << costs[2] << endl;
                cout << endl;
            }
        }


}
