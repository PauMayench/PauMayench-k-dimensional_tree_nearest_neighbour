#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <stdlib.h>
#include <time.h>
#include "k_tree.hh"

using namespace std;

class RelaxedKTree : public KTree {
public:
    RelaxedKTree(int dimensions);
    //~RelaxedKTree();

protected:
    int generarDiscriminant(int profunditat) override;
};
