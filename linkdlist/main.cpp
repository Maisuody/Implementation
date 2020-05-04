#include <iostream>

using namespace std;

template <typename T>
struct Node{
 T val;
 Node<T>* nxt;
 Node(const T &val, Node<T> *nxt): val(val), nxt(nxt) {}
};

template <typename T>
class lnklst{
    Node<T> *h,*t;

public:
    lnklst(): h(0),t(0){}
//ADD in he first of linkdlist
void InsertFirst(const T &v)
{
    auto n =new Node<T>(v,h);
    h=n;
    if (!t)t=n;
}
// ADD at last of the node
void InsertEnd(const T &v)
{
    auto n=new Node<T>(v,h);
    if(t)
      t->nxt=n;
    else
      h=n;

    t=n;
}
//add node between two node
void InsertAfer(Node<T> *p,const T &v )
{
auto n=new Node<T> (v, p-> nxt);
p->nxt=n;
if(t==p)t=n;
}
// delete firs element
void DeleteFirst(){
 auto temp=h;
 h=h->nxt;
 delete temp;
 if(!h)t=0;
}

void DeleteAfter(Node<T> *p)
{
    auto temp=p->next;
    p->next=temp->nxt;
    delete temp;

    if(!p->next)t=p;
}
  Node<T>* first()
  {
      return h;
  }
  Node<T>* last()
  {
      return t;
  }
};

int main()
{
    lnklst <int> m;
    m.InsertEnd(5);
    m.InsertFirst(2);
    m.InsertEnd(6);
    m.InsertAfer(m.first(), 3);
    m.InsertAfer(m.last(),7);
    m.InsertAfer(m.last(),8);


    for(auto p=m.last();p;p=p->nxt)
    cout<<p->val<<endl;

    return 0;
}
