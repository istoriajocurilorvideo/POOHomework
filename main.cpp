#include "Matrice.h"
#include "Vector.h"
#include "Graf.h"
#include "Graf_Neorientat.h"
#include "Graf_Orientat.h"

int main()
{
    cout<<"Matrix operations : ";

    Matrice<int> m(3, 0);

    m(1, 1) = 7;
    int i, j;
    int temp;
    cout<<endl;
    for(i=0; i<m.getSize(); i++){
        for(j=0; j<m.getSize(); j++)
            cout<<m(i, j)<<" ";
        cout<<endl;
    }
    //alternative
    //cout<<m;

    /*
    Matrice empty_m;
    try{
        cin>>empty_m;
    }catch(const zero_length_error& e){
        cout<<e.what()<<" "<<e.err_info();
        //exit(EXIT_FAILURE);
    }*/

    cout<<endl;
    cout<<"Vector operations : ";
    Vector<int> v2(7, 0);
    cout<<"am fost creat";
    int v[] = {1, 2, 5, 6, 7};
    int mr = 5;
    Vector<int> v3(v, mr);
    cout<<"SIeu";
    Vector<int> v1(v3);
    cout<<"aici la fel";
    for(int index=0; index < v1.getSize(); index++)
        cout<<v1[index]<<" ";
    cout<<endl;
    v1[2] = 90;
    for(int index=0; index < v1.getSize(); index++)
        cout<<v1[index]<<" ";
    v1.pushBack(30);
    cout<<endl;
    for(int index=0; index < v1.getSize(); index++)
        cout<<v1[index]<<" ";
    cout<<endl<<v1.getSize();
    cout<<endl;
    cout<<v1<<endl;
    cout<<"Grafuri neorientate: " <<endl;
    Graf_Neorientat graf(6);
    graf.addEdge(0, 1);
    graf.addEdge(1 , 3);
    graf.addEdge(2 , 3);
    graf.addEdge(4 , 5);
    graf.addEdge(2, 4);
    graf.addEdge(3, 5);
    cout<<endl<<graf<<endl;
    cout<<endl<<graf.isConnectedComponent();
    graf.deleteEdge(2,4);
    graf.deleteEdge(5,3);
    cout<<endl<<graf;
    cout<<endl<<graf.isConnectedComponent();

    cout<<endl<<"Arbore graf neorientat : "<<endl;
    Graf_Orientat tree(9);
    tree.addEdge(5, 7);
    tree.addEdge(5, 2);
    tree.addEdge(2, 3);
    tree.addEdge(2, 1);
    tree.addEdge(1, 4);
    tree.addEdge(7, 8);
    tree.addEdge(8, 0);
    tree.addEdge(4, 6);
    cout<<tree;
    tree.showTreeParents(5);
    cout<<endl;
    cout<<"Grafuri orientate: " <<endl;
    Graf_Orientat Ograf(6);
    Ograf.addEdge(0, 1);
    Ograf.addEdge(1, 3);
    Ograf.addEdge(3, 5);
    Ograf.addEdge(5, 4);
    Ograf.addEdge(4, 2);
    Ograf.addEdge(2, 3);
    cout<<endl<<Ograf<<endl;
    cout<<endl<<Ograf.isConnectedComponent();
    Ograf.deleteEdge(4,2);
    cout<<endl<<Ograf;
    cout<<endl<<Ograf.isConnectedComponent();

    cout<<endl<<"Arbore graf orientat : "<<endl;
    Graf_Neorientat Otree(9);
    Otree.addEdge(5, 7);
    Otree.addEdge(5, 2);
    Otree.addEdge(2, 3);
    Otree.addEdge(2, 1);
    Otree.addEdge(1, 4);
    Otree.addEdge(7, 8);
    Otree.addEdge(8, 0);
    Otree.addEdge(4, 6);
    cout<<Otree;
    Otree.showTreeParents(5);
    /*
    v3.deleteItemByIndex(2);
    v3.deleteItemByItem(6);
    cout<<v3;*/

    /*Graf *ptr = static_cast<Graf_Neorientat*>(&Otree);
    cout<<endl;
    ptr->showTreeParents(5);
    */
    return 0;
}
