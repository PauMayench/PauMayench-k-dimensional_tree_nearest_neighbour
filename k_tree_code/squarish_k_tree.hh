#include "k_tree.hh"

using namespace std;

class SquarishKTree : public KTree {
public:
    SquarishKTree(int dimensions);

    void insert(const  vector<double>& claus) override;
    shared_ptr<KTree::Node> insertRecSquarish(shared_ptr<KTree::Node> node, const vector<double>& claus,
                                            vector<double>& boundingBoxMin, vector<double>& boundingBoxMax) ;
private:
    int computaDiscriminant(const vector<double>& boundingBoxMin, const vector<double>& boundingBoxMax);
};

