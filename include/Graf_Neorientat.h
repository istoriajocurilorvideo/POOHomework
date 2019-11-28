#ifndef GRAF_NEORIENTAT_H
#define GRAF_NEORIENTAT_H

#include "Graf.h"
#include "Lista.h"


class Graf_Neorientat : public Graf
{
    public:
        Graf_Neorientat() : Graf(0) {};
        Graf_Neorientat(int noduriGN);
        Graf_Neorientat(Lista l);
        ~Graf_Neorientat();
        Graf_Neorientat(const Graf_Neorientat& other);
        Graf_Neorientat& operator=(const Graf_Neorientat& other);
        void addEdge(int nd1, int nd2);
        void deleteEdge(int nd1, int nd2) ;
        void addNode();
        void deleteNode();
        bool checkNode(int nd);
        bool checkEdge(int nd1, int nd2);
        bool isConnectedComponent();
        void showTreeParents(int root);

    private:
        Lista gnl;
        void resetVisited(bool *v, int dim);
        bool checkIfVisitedAll(bool *v, int dim);
        void tree_dfs(int child, int parent, bool *v, int *pV);
        void dfs(int node, bool *v, int dim);
        void print(ostream& out) const;
        void read(istream& in);

};

#endif // GRAF_NEORIENTAT_H
