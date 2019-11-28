#include "Graf_Neorientat.h"

Graf_Neorientat::Graf_Neorientat(int noduriGN) : Graf(noduriGN)
{
    for(int index = 0; index < nrNodes; index ++)
        gnl.addNode(Vector<int>());
}

//stil working on it
Graf_Neorientat::Graf_Neorientat(Lista<int> l) : Graf(l.getSize())
{
    gnl.emptyList();
    gnl = l;
}

Graf_Neorientat::~Graf_Neorientat()
{
    gnl.emptyList();
}

Graf_Neorientat::Graf_Neorientat(const Graf_Neorientat& other) : Graf(other.gnl.getSize())
{
    gnl.emptyList();
    gnl = other.gnl;
}

Graf_Neorientat& Graf_Neorientat::operator=(const Graf_Neorientat& rhs)
{
    if (this == &rhs)
        return *this;
    nrNodes = rhs.nrNodes;
    gnl.emptyList();
    gnl = rhs.gnl;
    return *this;
}
void Graf_Neorientat::addEdge(int nd1, int nd2)
{
    if(nd1 != nd2) {
        gnl[nd1].pushBack(nd2);
        gnl[nd2].pushBack(nd1);
    } else
        cout<<"Error: edge nodes are same";
}

void Graf_Neorientat::deleteEdge(int nd1, int nd2)
{
    gnl[nd1].deleteItemByItem(nd2);
    gnl[nd2].deleteItemByItem(nd1);
}

void Graf_Neorientat::addNode()
{
    gnl.addNode(Vector<int>());
    nrNodes++;
}

void Graf_Neorientat::deleteNode()
{
    if(nrNodes > 0) {
        nrNodes--;
        for(unsigned int index=0; index < gnl[nrNodes].getSize(); index++)
            deleteEdge(gnl[nrNodes][index], nrNodes);
        gnl.popBack();
    }
}
//vector is empty(should create a function)
bool Graf_Neorientat::checkNode(int nd) {
    if(nd < 0 || nd > nrNodes)
        throw out_of_range("Index out of range");
    return gnl[nd].isEmpty();
}
//you know what to do
bool Graf_Neorientat::checkEdge(int nd1, int nd2) {
    return gnl[nd1].searchItem(nd2) && gnl[nd2].searchItem(nd1);
}

void Graf_Neorientat::resetVisited(bool *v, int dim){
    for(unsigned int index=0; index < dim; index++)
        v[index] = false;
}

bool Graf_Neorientat::checkIfVisitedAll(bool *v, int dim){
    for(unsigned int index=0; index < dim; index++)
        if(v[index] == false)
            return false;
    return true;
}

void Graf_Neorientat::dfs(int node, bool *v, int dim) {
    v[node] = true;
    for(unsigned int index=0; index < gnl[node].getSize(); index++)
        if(!v[gnl[node][index]])
            dfs(gnl[node][index], v, nrNodes);
}

bool Graf_Neorientat::isConnectedComponent() {
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
void Graf_Neorientat::print(ostream& out) const
{
    unsigned int ind1, ind2;
    for(ind1=0; ind1 < nrNodes; ind1++) {
        out<<ind1<<" : ";
        for(ind2 = 0; ind2 < gnl[ind1].getSize(); ind2++)
            out<<gnl[ind1][ind2]<<" ";
        out<<endl;
    }
}
void Graf_Neorientat::read(istream& in) {
    if(!gnl.isListEmpty()) {
        unsigned int nd1, nd2;
        in>>nd1>>nd2;
        if((nd1 < 0 || nd1 > nrNodes) || (nd2 < 0 || nd2 > nrNodes))
            throw out_of_range("Index out of range");
        addEdge(nd1, nd2);
    }else throw zero_length_error("Oriented Graph empty");
}

void Graf_Neorientat::tree_dfs(int child, int parent, bool *v, int *pV){
    v[child] = true;
    pV[child] = parent;
    for(unsigned int index=0; index < gnl[child].getSize(); index++){
        int value = gnl[child][index];
        if(!v[value])
            tree_dfs(value, child, v, pV);
    }
}

void Graf_Neorientat::showTreeParents(int root) {
    int parentVec[nrNodes];
    bool visited[nrNodes];
    resetVisited(visited, nrNodes);
    tree_dfs(root, -1, visited, parentVec);

    for(unsigned int index = 0; index < nrNodes; index++){
        if(parentVec[index] == -1) cout<<"Root : "<<root<<endl;
        else cout<<"Node : " << index << " | Parent : " <<parentVec[index]<<endl;
    }
}
