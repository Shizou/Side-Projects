#include "segtree.h"

template <typename T>
T segment_tree<T>::query(int it){
  qlo = qhi = it;
  return _query(1,1,N);
}


segment_tree<int> tree(1000);

int main(){
    //tree.update(0,500);
    //tree.update(9,1000);

    for(int i = 1;i <= 5;i++)
        tree.update(i,500);
    cout << tree.query(1,5) << endl;
    tree.update(1,5,500);

    cout << tree.query(1,5) << endl;
    cout << tree.query(1,2) << endl;
    cout << tree.query(1,3) << endl;
}