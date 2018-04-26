#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Multime_pereche : public Multime<T>
{
public:
    Multime_pereche<T>(int nr, Pereche<T>* p) : Multime<T>(nr, p){
    }
    virtual ~Multime_pereche<T>(){
    }
    Multime_pereche<T>(){
        this->n = 0;
        this->start = nullptr;
    }
    Multime_pereche<T>(const Multime_pereche<T> &v)
    {
        (*this) = v;
    }
    virtual bool hasElement(const int &x, const int &y) const
    {
        Pereche<T> *node = static_cast<Pereche<T>*>(this->start);
        for(int i = 0; i < this->n; i++)
        {
            if(node->Value() == x && node->secondValue() == y)
                return true;
            node = static_cast<Pereche<T>*>(node->nextNode());
        }
        return false;
    }
    virtual bool hasElement(Pereche<T> &x) const {
        return hasElement(x.Value(), x.secondValue());
    }
    virtual Multime_pereche<T>& operator = (const Multime_pereche<T> &v)
    {
        if(v.n == 0)
        {
            this->n = 0;
            this->start = 0;
            return (*this);
        }
        this->clear();
        this->n = v.n;
        this->start = new Pereche<T>(*static_cast<Pereche<T>*>(v.start));
        ElementMultime<T>* cur_node = this->start;
        int i = 1;
        for(ElementMultime<T>* node = v.start; i < v.n; node = node->next, i++)
        {
            Pereche<T>* new_node = new Pereche<T>(*static_cast<Pereche<T>*>(node->next));
            cur_node->next = new_node;
            cur_node = new_node;
        }
        return (*this);
    }
    virtual Multime_pereche<T> operator + (const Multime_pereche<T> &v)
    {
        Multime_pereche<T> ans = (*this);
        Pereche<T> *node = static_cast<Pereche<T>*>(v.start);
        for(int i = 0; i < v.n; i++)
        {
            if(!this->hasElement(*node))
            {
                Pereche<T> *node1 = new Pereche<T>(*node);
                ans.addNode(node1);
            }
            node = static_cast<Pereche<T>*>(node->next);
        }
        return ans;
    }

    virtual Multime_pereche<T> operator * (const Multime_pereche<T> &v)
    {
        Multime_pereche<T> ans;
        Pereche<T> *node = static_cast<Pereche<T>*>(v.start);
        for(int i = 0; i < v.n; i++)
        {
            if(this->hasElement(*node))
            {
                Pereche<T> *node1 = new Pereche<T>(*node);
                ans.addNode(node1);
            }
            node = static_cast<Pereche<T>*>(node->next);
        }
        return ans;
    }

    virtual Multime_pereche<T> operator - (const Multime_pereche<T> &v)
    {
        Multime_pereche<T> ans;
        Pereche<T> *node = static_cast<Pereche<T>*>(this->start);
        for(int i = 0; i < this->n; i++)
        {
            if(!v.hasElement(*node))
            {
                Pereche<T> *node1 = new Pereche<T>(*node);
                ans.addNode(node1);
            }
            node = static_cast<Pereche<T>*>(node->next);
        }
        return ans;
    }
    friend class Pereche<T>;
    template <typename U>
    friend istream& operator >> (istream &in, Multime_pereche<U> &v);
    template <typename U>
    friend ostream& operator << (ostream &out, const Multime_pereche<U> &v);
};

template <typename T>
istream& operator >> (istream &in, Multime_pereche<T> &v)
{
    in >> v.n;
    v.start = new Pereche<T>();
    in >> static_cast<Pereche<T>*>(v.start);
    ElementMultime<T> *node = v.start;
    for(int i = 1; i < v.n; i++)
    {
        node->next = new Pereche<T>();
        in >> static_cast<Pereche<T>*>(node->next);
        node = node->next;
    }
    return in;
}

template <typename T>
ostream& operator << (ostream &out, const Multime_pereche<T> &v)
{
    ElementMultime<T> *node = v.start;
    for(int i = 0; i < v.n; i++)
    {
        out << static_cast<Pereche<T>*>(node);
        node = node->next;
    }
    out << "\n";
    return out;
}

template <typename T>
class Stiva_pereche : public Multime_pereche<T>
{
public:
    Stiva_pereche(int nr, Pereche<T>* p) : Multime_pereche<T>(nr, p){
    }
    ~Stiva_pereche(){
    }
    Stiva_pereche(){
    }
    void push(Pereche<T> *p){
        p->next = this->start;
        this->start = p;
        this->n++;
    }
    void pop(){
        ElementMultime<T> *node = this->start->next;
        delete this->start;
        this->start = node;
        this->n--;
    }
    int size(){
        return this->n;
    }
    Pereche<T> top(){
        return *static_cast<Pereche<T>*>(this->start);
    }
};

template <typename T>
class Coada_pereche : public Multime_pereche<T>
{
private:
    Pereche<T> *finish;
public:
    Coada_pereche(int nr, Pereche<T>* p) : Multime_pereche<T>(nr, p){
    }
    ~Coada_pereche(){
    }
    void push(Pereche<T> *p){
        this->finish->next = p;
        this->finish = p;
        this->n++;
    }
    void pop(){
        ElementMultime<T> *node = this->start->next;
        delete this->start;
        this->start = node;
        this->n--;
    }
};
