#include "Graf_Orientat.h"

Graf_Orientat::Graf_Orientat(Matrice m) : Graf(m.getSize())
{
    gom = m;
}

Graf_Orientat::Graf_Orientat(int nr_noduri) : Graf(nr_noduri)
{
    gom.resize(nrNodes);
    Matrice *t_m = new Matrice(nr_noduri);
    gom = *t_m;
}

Graf_Orientat::~Graf_Orientat()
{
    gom.resize(0);
    nrNodes = 0;
}

Graf_Orientat::Graf_Orientat(const Graf_Orientat& other) : Graf(other.gom.getSize())
{
    gom.resize(other.gom.getSize());
    gom = other.gom;
}

Graf_Orientat& Graf_Orientat::operator=(const Graf_Orientat& rhs)
{
    if (this == &rhs)
        return *this;
    gom.resize(rhs.gom.getSize());
    gom = rhs.gom;
    nrNodes = rhs.gom.getSize();
    return *this;
}

void Graf_Orientat::addEdge(int nd1, int nd2){
    gom(nd1, nd2) = 1;
}
void Graf_Orientat::deleteEdge(int nd1, int nd2){
    gom(nd1, nd2) = 0;
}
void Graf_Orientat::addNode(){
    gom.resize(nrNodes+1, true);
    nrNodes++;
}
void Graf_Orientat::deleteNode(){
    for(unsigned int index=0; index < nrNodes-1; index++){
        gom(nrNodes-1, index) = 0;
        gom(index, nrNodes-1) = 0;
    }
    gom.resize(nrNodes-1, true);
}
bool Graf_Orientat::checkNode(int nd){
    if(nd < 0 || nd > nrNodes)
        throw out_of_range("Index out of range");
    for(unsigned int index=0 ;index < nrNodes; index++)
        if(index != nd)
            if(gom(nd, index) == 1 || gom(index, nd) == 1)
                return false;
    return true;
}
bool Graf_Orientat::checkEdge(int nd1, int nd2){
    return gom(nd1, nd2) == 1;
}

void Graf_Orientat::resetVisited(bool *v, int dim){
    for(unsigned int index=0; index < dim; index++)
        v[index] = false;
}

bool Graf_Orientat::checkIfVisitedAll(bool *v, int dim){
    for(unsigned int index=0; index < dim; index++)
        if(v[index] == false)
            return false;
    return true;
}

void Graf_Orientat::dfs(int node, bool *v, int dim) {
    v[node] = true;
    for(unsigned int index=0; index < nrNodes; index++)
        if(!v[index] && gom(node, index))
            dfs(index, v, nrNodes);
}

bool Graf_Orientat::isConnectedComponent(){
    bool visited[nrNodes];
    resetVisited(visited, nrNodes);
    bool result = false;
    for(unsigned int index=0 ;index < nrNodes && !result; index++){
        dfs(index, visited, nrNodes);
        result = checkIfVisitedAll(visited, nrNodes);
        resetVisited(visited, nrNodes);
    }
    return result;
}

void Graf_Orientat::tree_dfs(int child, int parent, bool *v, int *pV){
    v[child] = true;
    pV[child] = parent;
    for(unsigned int index=0; index < nrNodes; index++){
        if(!v[index] && gom(child, index) == 1)
            tree_dfs(index, child, v, pV);
    }
}

void Graf_Orientat::showTreeParents(int root){
    int parentVec[nrNodes];
    bool visited[nrNodes];
    resetVisited(visited, nrNodes);
    tree_dfs(root, -1, visited, parentVec);

    for(unsigned int index = 0; index < nrNodes; index++){
        if(parentVec[index] == -1) cout<<"Root : "<<root<<endl;
        else cout<<"Node : " << index << " | Parent : " <<parentVec[index]<<endl;
    }
}

void Graf_Orientat::print(ostream& out) const {
    out<<"Matrice de adiacenta : "<<endl;
    unsigned int i, j;
    out<<"    ";
    for(i=0; i<nrNodes; i++)
        out<<i<<" ";
    out<<endl;
    for(i=0; i<nrNodes; i++){
        out<<i<<" : ";
        for(j=0; j<nrNodes; j++)
            out<<gom(i, j)<<" ";
        out<<endl;
    }
}

void Graf_Orientat::read(istream& in) {

}
