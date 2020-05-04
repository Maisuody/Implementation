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
    int sz;

public:
    lnklst(): h(0),t(0), sz(0){}

//Construcor
lnklst(const lnklst<T> &m):lnklst(){
     for(auto p=m.last();p;p=p->nxt)
     InsertEnd(p->val);
}

//distructor
~lnklst(){
    while (sz)
    DeleteFirst();
}

//equal operator
lnklst& operator=(const T &m){
    while(sz)DeleteFirst();
    for(auto p=m.last();p;p=p->nxt)
    InsertEnd(p->val);
    return *this;

}
//plus equal concatinate two lists

lnklst& operator+=(const T &m){

    for(auto p=m.last();p;p=p->nxt)
    InsertEnd(p->val);
    return *this;

}

// Concatine bs fe wa7da gdeda
 lnklst<T> operator+(const lnklst<T>  &m) const {
        lnklst<T> ret(*this);
        for (auto p = m.first(); p; p = p->nxt)
            ret.insertEnd(p->val);
        return ret;
    }

//ADD in he first of linkdlist
void InsertFirst(const T &v)
{
    sz++;
    auto n =new Node<T>(v,h);
    h=n;
    if (!t)t=n;
}
// ADD at last of the node
void InsertEnd(const T &v)
{
    sz++;
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
    sz++;
auto n=new Node<T> (v, p-> nxt);
p->nxt=n;
if(t==p)t=n;
}
// delete firs element
void DeleteFirst(){
    sz--;
 auto temp=h;
 h=h->nxt;
 delete temp;
 if(!h)t=0;
}

void DeleteAfter(Node<T> *p)
{
    sz--;
    auto temp=p->nxt;
    p->nxt=temp->nxt;
    delete temp;

    if(!p->nxt)t=p;
}



  Node<T>* first()const
  {
      return h;
  }
  Node<T>* last()const
  {
      return t;
  }
  int size(){
      return sz;
  }
  bool empty(){
      return h=0;
  }

 /*int print(const lnklst<int> &m)
 {
     cout<<"-----------------"<<endl;
     for(auto p=m.last();p;p=p->nxt)
    cout<<p->val<<endl;
    cout<<"-----------------"<<endl;

 }*/
};

int main()
{
    lnklst <int> m;
    m.InsertEnd(5);
    m.InsertFirst(2);
    m.InsertEnd(6);
    auto m1=m;
    m.InsertAfer(m.first(), 3);
    m.InsertAfer(m.last(),7);
    m.InsertAfer(m.last(),8);
    //print(m);
    for(auto p=m.last();p;p=p->nxt)
    cout<<p->val<<endl;
    cout<<"-----------------"<<endl;
    m.DeleteAfter(m.first());
    //print(m);
    for(auto p=m.last();p;p=p->nxt)
    cout<<p->val<<endl;
    cout<<"-----------------"<<endl;
    m.DeleteFirst();
    //print(m);
    for(auto p=m.last();p;p=p->nxt)
    cout<<p->val<<endl;
    cout<<"-----------------"<<endl;
    //print(m1)
    for(auto p=m.last();p;p=p->nxt)
    cout<<p->val<<endl;
    cout<<"-----------------"<<endl;

    return 0;
}
