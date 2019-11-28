#ifndef GRAF_ORIENTAT_H
#define GRAF_ORIENTAT_H

#include "Graf.h"
#include "Matrice.h"

class Graf_Orientat : public Graf
{
    public:
        Graf_Orientat() : Graf(0){}
        Graf_Orientat(int nr_noduri);
        Graf_Orientat(Matrice m);
        ~Graf_Orientat();
        Graf_Orientat(const Graf_Orientat& other);
        Graf_Orientat& operator=(const Graf_Orientat& other);
        void addEdge(int nd1, int nd2);
        void deleteEdge(int nd1, int nd2);
        void addNode();
        void deleteNode();
        bool checkNode(int nd);
        bool checkEdge(int nd1, int nd2);
        bool isConnectedComponent();
        void showTreeParents(int root);

    protected:

    private:
        Matrice gom;
        void resetVisited(bool *v, int dim);
        bool checkIfVisitedAll(bool *v, int dim);
        void dfs(int node, bool *v, int dim);
        void tree_dfs(int child, int parent, bool *v, int *pV);
        void print(ostream& out) const;
        void read(istream& in);
};

#endif // GRAF_ORIENTAT_H
