#include "relaxed_k_tree.hh"
using namespace std;

RelaxedKTree::RelaxedKTree(int dimensions) : KTree(dimensions) {}

//Genera el discriminant aleatori en el rang [0, k].
int RelaxedKTree::generarDiscriminant(int profunditat) {
    return rand() % (dimensions);
}
