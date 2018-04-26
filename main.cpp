#include <bits/stdc++.h>
#include "ElementMultime.h"
#include "Multime.h"
#include "Multime_pereche.h"

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

template <typename T>
Multime_pereche<T> produsCartezian(const Multime<T> &a, const Multime<T> &b)
{
    Multime_pereche<T> ans;
    ElementMultime<T> *node1 = a.start;
    for(int i = 0; i < a.n; i++)
    {
        ElementMultime<T> *node2 = b.start;
        for(int j = 0; j < b.n; j++)
        {
            Pereche<T> *p = new Pereche<T>(node1->val, node2->val);
            if(ans.n == 0)
                ans.start = p;
            else
            {
                p->next = ans.start;
                ans.start = p;
            }
            ans.n++;
            node2 = node2->next;
        }
        node1 = node1->next;
    }
    return ans;
}

template <typename T>
void doQueue()
{
    Stiva_pereche<T> st1, st2;
    int nrOperations, x, y;
    string type;
    fin >> nrOperations;
    while(nrOperations--)
    {
        fin >> type;
        if(type == "push")
        {
            fin >> x >> y;
            st2.push(new Pereche<T>(x, y));
        }
        else
        {
            if(st1.size() == 0)
            {
                int half = (st2.size() + 1) / 2;
                Stiva_pereche<T> aux;
                while(st2.size() > half)
                {
                    Pereche<T> *p = new Pereche<T>(st2.top());
                    st2.pop();
                    aux.push(p);
                }
                while(st2.size() > 0)
                {
                    Pereche<T> *p = new Pereche<T>(st2.top());
                    st2.pop();
                    st1.push(p);
                }
                while(aux.size() > 0)
                {
                    Pereche<T> *p = new Pereche<T>(aux.top());
                    aux.pop();
                    st2.push(p);
                }
            }
            if(type == "front")
                fout << st1.top() << "\n";
            else
                if(type == "pop")
                    st1.pop();
        }
    }
}

int main()
{
    Multime_pereche<int> v1, v2;
    fin >> v1 >> v2;
    fout << v1 << v2;
    fout << v1 + v2;
    fout << v1 - v2;
    fout << v1 * v2;
    return 0;
}
