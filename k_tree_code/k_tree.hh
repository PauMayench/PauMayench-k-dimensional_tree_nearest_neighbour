#ifndef K_TREE_HH
#define K_TREE_HH

#include <vector>
#include <memory>
#include <cmath>
#include <random>
#include <iostream>
#include <time.h>

using namespace std;


class KTree {
public:
    KTree(int dimensions);
    ~KTree();
    static vector<vector<double>> getVectorRandomValues(int mida, int dim);
    virtual void insert(const  vector<double>& claus);
    void print_tree();

    void omplir_aleatoriament(int mida);
    void omplirAmbVector(const vector<vector<double>>& claus);
    int trobar_vei_mes_proper_a_punt_aleatori();
    int trobar_vei_mes_proper(const vector<double>& claus);

protected:

    struct Node {   
        
        vector<double> claus;
        int discriminant;
        shared_ptr<Node> left;
        shared_ptr<Node> right;

        Node(const vector<double>& c, int d, shared_ptr<Node> l = nullptr, shared_ptr<Node> r = nullptr)
        : claus(c), discriminant(d), left(l), right(r) {}
    };

    shared_ptr<Node> arrel;
    int dimensions;
    virtual int generarDiscriminant(int profunditat);

    shared_ptr<Node> insertRec(shared_ptr<Node> node, const  vector<double>& claus, int profunditat);
    void printRec(shared_ptr<Node> node, int profunditat);
    double double_aleatori();
    void aux_vei_mes_proper(shared_ptr<Node> node, const vector<double>& claus, vector<double>& solucio, int& nodes_vists, double& radi_minim, int profunditat);
    
    double calcular_distancia(const vector<double>& a1, const vector<double>& a2);
}; 


#endif