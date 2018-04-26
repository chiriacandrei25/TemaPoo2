#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Multime
{
protected:
    int n = 0;
    ElementMultime<T> *start;
public:
    Multime<T>(int nr, ElementMultime<T> *p) : n(nr), start(p){
    }
    Multime<T>(){
        n = 0;
        start = nullptr;
    }
    Multime<T>(const Multime<T> &v)
    {
        (*this) = v;
    }
    virtual void addNode(ElementMultime<T> *node)
    {
        node->next = start;
        start = node;
        n++;
    }
    virtual ~Multime<T>(){
        clear();
    }
    virtual bool hasElement(const int &x) const
    {
        ElementMultime<T> *node = start;
        for(int i = 0; i < n; i++)
        {
            if(node->Value() == x)
                return true;
            node = node->nextNode();
        }
        return false;
    }
    virtual bool hasElement(ElementMultime<T> &x) const {
        return hasElement(x.val);
    }
    virtual void clear()
    {
        if(n == 0)
            return;
        ElementMultime<T> *node = start, *node1;
        for(int i = 0; i < n; i++)
        {
            node1 = node->nextNode();
            delete node;
            node = node1;
        }
        n = 0;
    }

    Multime<T> transformArray(int *v, int n)
    {
        Multime<T> ans;
        for(int i = 0; i < n; i++)
            if(!ans.hasElement(v[i]))
            {
                ElementMultime<T> *node1 = new ElementMultime<T>(v[i]);
                ans.addNode(node1);
            }
        return ans;
    }

    virtual Multime<T>& operator = (const Multime<T> &v)
    {
        if(v.n == 0)
        {
            n = 0;
            start = 0;
            return (*this);
        }
        this->clear();
        n = v.n;
        start = new ElementMultime<T>(*v.start);
        ElementMultime<T>* cur_node = start;
        int i = 1;
        for(ElementMultime<T>* node = v.start; i < v.n; node = node->next, i++)
        {
            ElementMultime<T>* new_node = new ElementMultime<T>(*(node->next));
            cur_node->next = new_node;
            cur_node = new_node;
        }
        return (*this);
    }

    virtual Multime<T> operator + (const Multime<T> &v)
    {
        Multime<T> ans = (*this);
        ElementMultime<T> *node = v.start;
        for(int i = 0; i < v.n; i++)
        {
            if(!this->hasElement(node->val))
            {
                ElementMultime<T> *node1 = new ElementMultime<T>(*node);
                ans.addNode(node1);
            }
            node = node->next;
        }
        return ans;
    }

    virtual Multime<T> operator * (const Multime<T> &v)
    {
        Multime<T> ans;
        ElementMultime<T> *node = v.start;
        for(int i = 0; i < v.n; i++)
        {
            if(this->hasElement(node->val))
            {
                ElementMultime<T> *node1 = new ElementMultime<T>(*node);
                ans.addNode(node1);
            }
            node = node->next;
        }
        return ans;
    }

    virtual Multime<T> operator - (const Multime<T> &v)
    {
        Multime<T> ans;
        ElementMultime<T> *node = start;
        for(int i = 0; i < n; i++)
        {
            if(!v.hasElement(node->val))
            {
                ElementMultime<T> *node1 = new ElementMultime<T>(*node);
                ans.addNode(node1);
            }
            node = node->next;
        }
        return ans;
    }
    template <typename U>
    friend istream& operator >> (istream &in, Multime<U> &v);
    template <typename U>
    friend ostream& operator << (ostream &out, const Multime<U> &v);
    template <typename U>
    friend Multime_pereche<U> produsCartezian(const Multime<U> &a, const Multime<U> &b);
    template <typename U>
    friend void doQueue();
};

template <typename T>
istream& operator >> (istream &in, Multime<T> &v)
{
    int x;
    v.clear();
    in >> v.n >> x;
    v.start = new ElementMultime<T>(x);
    ElementMultime<T> *node = v.start;
    for(int i = 1; i < v.n; i++)
    {
        in >> x;
        node->next = new ElementMultime<T>(x);
        node = node->next;
    }
    return in;
}

template <typename T>
ostream& operator << (ostream &out, const Multime<T> &v)
{
    if(v.n == 0)
        return (out << "\n");
    ElementMultime<T> *node = v.start;
    for(int i = 0; i < v.n; i++)
    {
        out << node;
        node = node->next;
    }
    return (out << "\n");
}

