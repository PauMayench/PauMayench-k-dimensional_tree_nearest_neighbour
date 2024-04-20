#include "squarish_k_tree.hh"
using namespace std;
SquarishKTree::SquarishKTree(int dimensions) : KTree(dimensions) {}


//inserir un element
void SquarishKTree::insert(const vector<double>& claus) {
    vector<double> boundingBoxMin (dimensions,0);
    vector<double> boundingBoxMax (dimensions,1);

    arrel = insertRecSquarish(arrel, claus, boundingBoxMin, boundingBoxMax);
}

shared_ptr<KTree::Node> SquarishKTree::insertRecSquarish(shared_ptr<KTree::Node> node, const vector<double>& claus,
                                            vector<double>& boundingBoxMin, vector<double>& boundingBoxMax) {

    if (node == nullptr) {
        int discriminant = computaDiscriminant(boundingBoxMin, boundingBoxMax);
        return make_shared<KTree::Node>(claus, discriminant);
    }
    
    if (claus[node->discriminant] < node->claus[node->discriminant]) {
        boundingBoxMax[node->discriminant] = node->claus[node->discriminant];
        node->left = insertRecSquarish(node->left, claus,boundingBoxMin,boundingBoxMax);
    }
    else {
        boundingBoxMin[node->discriminant] = node->claus[node->discriminant];
        node->right = insertRecSquarish(node->right, claus, boundingBoxMin, boundingBoxMax);
    }
    return node;

}

int SquarishKTree::computaDiscriminant(const vector<double>& bbmin, const vector<double>& bbmax) {
    int discriminant = 0;
    double interval_maxim = 0;
    for(int i= 0; i < bbmin.size(); ++i){
        if ((bbmax[i] - bbmin[i]) > interval_maxim) {
            discriminant = i;
            interval_maxim = bbmax[i] - bbmin[i];
        }
    }
    return discriminant;
}
