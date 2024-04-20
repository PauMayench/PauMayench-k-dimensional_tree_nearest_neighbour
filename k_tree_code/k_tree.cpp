#include "k_tree.hh"
using namespace std;

//creadora
KTree::KTree(int dimensions) : arrel(nullptr), dimensions(dimensions) {}

//destructora
KTree::~KTree() {}

//inserir un element
void KTree::insert(const  vector<double>& claus) {
    arrel = insertRec(arrel, claus, 0);
}

//imprimeix el arbre en preordre (DFS desde l'arrel i sempre esquerra primer)
// els elements en una columna representen que estan en el mateix nivell de l'arbre
void KTree::print_tree(){
    printRec(arrel, 0);
}

void KTree::omplirAmbVector(const vector<vector<double>>& claus){
    for (int i = 0; i < claus.size() ; ++i) insert(claus[i]);
}

void KTree::omplir_aleatoriament(int mida) {
    random_device rd;  // Seed per al nombre random.
    default_random_engine generator(rd()); //Generador de aleatoris de la llibreria Random.
    uniform_real_distribution<double> distribution(0.0, 1.0); // Escollir rang per a la distribució contínua [0, 1]

    //double valorAleatori = distribution(generator);

    for (int i = 0; i < mida; ++i) {
        vector<double> claus(dimensions);
        for (int j = 0; j < dimensions; ++j) claus[j] = distribution(generator);
        insert(claus);
    }
}

vector<vector<double>> KTree::getVectorRandomValues(int mida, int dim){
    random_device rd;  // Seed per al nombre random.
    default_random_engine generator(rd()); //Generador de aleatoris de la llibreria Random.
    uniform_real_distribution<double> distribution(0.0, 1.0); // Escollir rang per a la distribució contínua [0, 1]

    //double valorAleatori = distribution(generator);
    vector<vector<double>>  v (mida, vector<double>(dim,0));

    for (int i = 0; i < mida; ++i) {
        for (int j = 0; j < dim; ++j) v[i][j] = distribution(generator);
    }

    return v;
}

double KTree::double_aleatori() {
    random_device rd;  // Seed per al nombre random.
    default_random_engine generator(rd()); //Generador de aleatoris de la llibreria Random.
    uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator);
}

int KTree::trobar_vei_mes_proper_a_punt_aleatori() {
    vector<double> claus(dimensions);
    for (double clau : claus) clau = double_aleatori();
    return trobar_vei_mes_proper(claus);
}


int KTree::trobar_vei_mes_proper(const vector<double>& claus) {
    vector<double> solucio(claus.size());
    int nodes_vists=0;
    double radi_minim=-1;
    aux_vei_mes_proper(arrel,claus,solucio,nodes_vists,radi_minim,0);
    /*
    for(double d : solucio){
        cout<<d<<" ";
    }
    cout<<endl;
    */
    return nodes_vists;
}

void KTree::aux_vei_mes_proper(shared_ptr<Node> node, const vector<double>& claus, vector<double>& solucio, int& nodes_vists, double& radi_minim, int profunditat){
    if (node == nullptr){
        return;
    }
    nodes_vists++;

    //Si el punt trobat esta a una distancia menor que qualsevol que haguem vist,
    //Actualitzem radi_minim i solucio
    double radi = calcular_distancia(claus, node->claus);
    if (radi < radi_minim || radi_minim==-1){
        radi_minim = radi;
        solucio = node->claus;
    }
    //Primer cas: anem pel cami al que inseririem el node
    bool esquerra = true;
    if (claus[node->discriminant] < node->claus[node->discriminant]){
        aux_vei_mes_proper(node->left,claus,solucio,nodes_vists,radi_minim,profunditat+1);
    }
    else{
        esquerra=false;
        aux_vei_mes_proper(node->right,claus,solucio,nodes_vists,radi_minim,profunditat+1);
    }

    //Segon cas: anem, si es necessari, pel cami no normal
    double distancia = node->claus[node->discriminant] - claus[node->discriminant];
    if (distancia<0) distancia = -distancia;
    //Anem pel cami no normal
    if (distancia<radi_minim){
        //Si el normal era l'esquerra, anem per la dreta i viceversa
        if (esquerra){
            aux_vei_mes_proper(node->right,claus,solucio,nodes_vists,radi_minim,profunditat+1);
        }
        else{
            aux_vei_mes_proper(node->left,claus,solucio,nodes_vists,radi_minim,profunditat+1);
        }
    }
}

double KTree::calcular_distancia(const vector<double>& a1, const vector<double>& a2){
    double suma=0;
    for(int i=0; i<a1.size(); i++){
        double diferencia = a1[i] - a2[i];
        suma += diferencia*diferencia;
    }
    return sqrt(suma);
}

int KTree::generarDiscriminant(int profunditat) {
    return (profunditat % dimensions);
}


//funcio auxiliar privada per inserir un element
shared_ptr<KTree::Node> KTree::insertRec(shared_ptr<Node> node, const vector<double>& claus, int profunditat) {

    if (node == nullptr) {
        int discriminant = generarDiscriminant(profunditat);
        return make_shared<Node>(claus, discriminant);
    }
    
    if (claus[node->discriminant] < node->claus[node->discriminant]) {
        node->left = insertRec(node->left, claus, profunditat + 1);
    }
    else {
        node->right = insertRec(node->right, claus, profunditat + 1);
    }
    return node;

}

//funcio auxiliar privada per a printejar l'arbre
void KTree::printRec(shared_ptr<Node> node, int profunditat){
    if (node != nullptr) {
        cout << " ";
        for (int i = 0; i < profunditat; ++i) cout << "   "; // es pot comentar per a no posar els espais i no diferenciar els nivells
        for (int i = 0; i < node->claus.size(); ++i) cout << node->claus[i] << " d: " << node->discriminant << " ";
        cout << endl;
        printRec(node->left, profunditat + 1);
        printRec(node->right, profunditat + 1);
    }

}

