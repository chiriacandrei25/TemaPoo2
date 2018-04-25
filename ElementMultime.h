#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Multime;
template <typename T>
class Multime_pereche;
template <typename T>
class Stiva_pereche;
template <typename T>
class Coada_pereche;

template <typename T>
class ElementMultime
{
protected:
    T val;
    ElementMultime<T> *next;
public:
    ElementMultime<T>(T x) : val(x){
        next = nullptr;
    }
    ElementMultime<T>(){
        next = nullptr;
    }
    ElementMultime<T>(const ElementMultime<T>& el){
        (*this) = el;
    }
    T Value(){
        return val;
    }
    ElementMultime<T>* nextNode(){
        return next;
    }
    ElementMultime<T>& operator = (const ElementMultime<T> &v)
    {
        val = v.val;
        next = v.next;
        return (*this);
    }
    bool operator == (const ElementMultime<T> &el){
        return val == el.val;
    }
    bool operator != (const ElementMultime<T> &el){
        return val != el.val;
    }
    bool operator < (const ElementMultime<T> &el){
        return val < el.val;
    }
    bool operator > (const ElementMultime<T> &el){
        return val > el.val;
    }
    template <typename U>
    friend istream& operator >> (istream& in, ElementMultime<U> &el);
    template <typename U>
    friend ostream& operator << (ostream& out, const ElementMultime<U> &el);
    template <typename U>
    friend istream& operator >> (istream& in, ElementMultime<U> *el);
    template <typename U>
    friend ostream& operator << (ostream& out, const ElementMultime<U> *el);
    template <typename U>
    friend istream& operator >> (istream &in, Multime<U> &v);
    template <typename U>
    friend ostream& operator << (ostream &out, const Multime<U> &v);
    template <typename U>
    friend istream& operator >> (istream &in, Multime_pereche<U> &v);
    template <typename U>
    friend ostream& operator << (ostream &out, const Multime_pereche<U> &v);
    template <typename U>
    friend Multime_pereche<U> produsCartezian(const Multime<U> &a, const Multime<U> &b);
    template <typename U>
    friend void doQueue();



    friend class Multime<T>;
    friend class Multime_pereche<T>;
    friend class Stiva_pereche<T>;
    friend class Coada_pereche<T>;
};

template <typename T>
istream& operator >> (istream& in, ElementMultime<T> *el)
{
    in >> el->val;
    return in;
}

template <typename T>
ostream& operator << (ostream& out, const ElementMultime<T> *el)
{
    out << el->val << " ";
    return out;
}

template <typename T>
istream& operator >> (istream& in, ElementMultime<T> &el)
{
    in >> el.val;
    return in;
}

template <typename T>
ostream& operator << (ostream& out, const ElementMultime<T> &el)
{
    out << el.val << " ";
    return out;
}

template <typename T>
class Pereche : public ElementMultime<T>
{
private:
    T second_val;
public:
    Pereche<T>(T first, T second) : ElementMultime<T>(first), second_val(second){
    }
    Pereche<T>(){
        this->next = nullptr;
    }
    Pereche<T>(const Pereche<T>& el){
        (*this) = el;
    }
    Pereche<T>& operator = (const Pereche<T> &v)
    {
        this->val = v.val;
        second_val = v.second_val;
        this->next = v.next;
        return (*this);
    }
    bool operator == (const Pereche<T> &el){
        return (this->val == el.val && this->second_val == el.second_val);
    }
    bool operator != (const Pereche<T> &el){
        return (this->val != el.val || this->second_val != el.second_val);
    }
    bool operator < (const Pereche<T> &el){
        return (this->val < el.val || (this->val == el.val && this->second_val < el.second_val));
    }
    bool operator > (const Pereche<T> &el){
        return (this->val > el.val || (this->val == el.val && this->second_val > el.second_val));
    }

    template <typename U>
    friend istream& operator >> (istream& in, Pereche<U> &el);
    template <typename U>
    friend ostream& operator << (ostream& out, const Pereche<U> &el);
    template <typename U>
    friend istream& operator >> (istream& in, Pereche<U> *el);
    template <typename U>
    friend ostream& operator << (ostream& out, const Pereche<U> *el);

};

template <typename T>
istream& operator >> (istream& in, Pereche<T> &el)
{
    in >> el.val >> el.second_val;
    return in;
}

template <typename T>
ostream& operator << (ostream& out, const Pereche<T> &el)
{
    out << "(" << el.val << ", " << el.second_val << ") ";
    return out;
}

template <typename T>
istream& operator >> (istream& in, Pereche<T> *el)
{
    in >> el->val >> el->second_val;
    return in;
}

template <typename T>
ostream& operator << (ostream& out, const Pereche<T> *el)
{
    out << "(" << el->val << ", " << el->second_val << ") ";
    return out;
}

