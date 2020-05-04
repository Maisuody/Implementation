#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Node {
    T val;
    Node<T> *nxt;

    Node(const T &val, Node<T> *nxt) : val(val), nxt(nxt) {}
};

template<typename T>
class lnkLst {
    Node<T> *h, *t;
    int sz;
public:
    lnkLst() : h(0), t(0), sz(0) {}

    lnkLst(const lnkLst<T> &l) : lnkLst() {
        for (auto p = l.first(); p; p = p->nxt)
            insertEnd(p->val);
    }

    ~lnkLst() {
        while (sz)deleteFirst();
    }

    lnkLst<T>  &operator=(const lnkLst<T>  &l) {
        while (sz)deleteFirst();
        for (auto p = l.first(); p; p = p->nxt)
            insertEnd(p->val);
        return *this;
    }

    lnkLst<T>  &operator+=(const lnkLst<T>  &l) {
        for (auto p = l.first(); p; p = p->nxt)
            insertEnd(p->val);
        return *this;
    }

    lnkLst<T> operator+(const lnkLst<T>  &l) const {
        lnkLst<T> ret(*this);
        for (auto p = l.first(); p; p = p->nxt)
            ret.insertEnd(p->val);
        return ret;
    }
    lnkLst<T> operator()(int s,int len) const {
        lnkLst<T> ret;

        auto x=h;
        while (s--)x=x->nxt;
        while (len--){
            ret.insertEnd(x->val);
            x=x->nxt;
        }
        return ret;
    }
    void insertBegin(const T &v) {
        sz++;
        auto n = new Node<T>(v, h);
        h = n;
        if (!t)t = n;
    }

    void insertEnd(const T &v) {
        sz++;
        auto n = new Node<T>(v, 0);
        if (t)
            t->nxt = n;
        else
            h = n;
        t = n;
    }

    void insertAftet(Node<T> *p, const T &v) {
        sz++;
        auto n = new Node<T>(v, p->nxt);
        p->nxt = n;
        if (t == p)t = n;
    }

    void deleteFirst() {
        sz--;
        auto temp = h;
        h = h->nxt;
        delete temp;
        if (!h)t = 0;
    }

    void deleteAftet(Node<T> *p) {
        sz--;
        auto temp = p->nxt;
        p->nxt = temp->nxt;
        delete temp;
        if (!p->nxt)t = p;
    }

    Node<T> *first() const {
        return h;
    }

    Node<T> *last() const {
        return t;
    }
    T& operator[](int i){
        auto x=h;
        while (i--)x=x->nxt;
        return x->val;
    }
    const T& operator[](int i)const{
        auto x=h;
        while (i--)x=x->nxt;
        return x->val;
    }
    int size() {
        return sz;
    }

    bool empty() {
        return h == 0;
    }
};

template<class T>
class Stack{
    lnkLst<T> l;
public:
    int size() {
        return l.size();
    }

    bool empty() {
        return l.empty();
    }
    void push(const T &v){
        l.insertBegin(v);
    }
    T& top()const {
       return l.first()->val;
    }
    void pop() {
        l.deleteFirst();
    }
};


template<class T>
class Queue{
    lnkLst<T> l;
public:
    int size() {
        return l.size();
    }

    bool empty() {
        return l.empty();
    }
    void enqueue(const T &v){
        l.insertEnd(v);
    }
    T& front()const {
        return l.first()->val;
    }
    void deque() {
        l.deleteFirst();
    }
};

void print(const lnkLst<int> &l) {
    cout << "----------------\n";
    for (auto p = l.first(); p; p = p->nxt)
        cout << p->val << endl;
    cout << "----------------\n";
}

int main() {
    lnkLst<int> l;
    l.insertBegin(5);
    l.insertBegin(2);
    l.insertEnd(6);
    auto l2=l;
    l.insertAftet(l.first(), 3);
    l.insertAftet(l.last(), 7);
    l.insertAftet(l.last(), 8);
    auto l4=l(3,2);
    print(l);
    l.deleteAftet(l.first());
    print(l);
    l.deleteFirst();
    print(l);
    print(l2);
    auto l3=l2+l;
    print(l3);
    l3+=l2;
    print(l3);
    l3=l2;
    print(l3);
    l3[2]=9;
    l3[1]=7;
    print(l3);
    print(l4);
    Stack<int> s;
    for(auto a:{3,4,5,6}){
        s.push(a);
    }
    for(;s.size();s.pop())
        cout<<s.top()<<endl;

    cout << "----------------\n";
    Queue<int> q;
    for(auto a:{3,4,5,6}){
       q.enqueue(a);
    }
    for(;q.size();q.deque())
        cout<<q.front()<<endl;
    return 0;
}
