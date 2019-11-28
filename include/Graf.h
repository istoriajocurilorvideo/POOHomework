#ifndef GRAF_H
#define GRAF_H
#include "Universal.h"

class Graf : public ArrayStream
{
    public:
        Graf(int nr_noduri) : nrNodes(nr_noduri) {};
        virtual ~Graf() = default;
        virtual void addEdge(int nd1, int nd2) = 0;
        virtual void deleteEdge(int nd1, int nd2) = 0;
        virtual void addNode() = 0;
        virtual void deleteNode() = 0;
        virtual bool checkNode(int nd) = 0;
        virtual bool checkEdge(int nd1, int nd2) = 0;
        virtual bool isConnectedComponent() = 0;
        virtual void showTreeParents(int root) = 0;

    protected:
        unsigned int nrNodes;
        virtual void print(ostream& out) const = 0;
        virtual void read(istream& in) = 0;
};

#endif // GRAF_H
