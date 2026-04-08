#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

struct NODE
{
    int data;
    NODE *prev;
    NODE *next;
    NODE(int val = 0) : data(val), prev(nullptr), next(nullptr) {}
};

NODE *head = nullptr, *tail = nullptr;
int len = 0;

void Pre()
{
    head = nullptr;
    tail = nullptr;
    len = 0;
}

NODE* move(int i)
{
    NODE *cur = head;
    for (int j = 0; j < i; ++j)
    {
        cur = cur->next;
    }
    return cur;
}

void insert(int i, int x)
{
    NODE *newNode = new NODE(x);
    if (len == 0)
    {
        head = tail = newNode;
    }
    else if (i == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if (i == len)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else
    {
        NODE *cur = move(i);
        newNode->prev = cur->prev;
        newNode->next = cur;
        cur->prev->next = newNode;
        cur->prev = newNode;
    }
    len++;
}

void remove(int i)
{
    if (len == 1)
    {
        delete head;
        head = tail = nullptr;
    }
    else if (i == 0)
    {
        NODE *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    else if (i == len - 1)
    {
        NODE *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }
    else
    {
        NODE *cur = move(i);
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
    }
    len--;
}

int Get_length()
{
    return len;
}

int Query(int i)
{
    if (i >= len || i < 0) return -1;
    NODE *cur = move(i);
    return cur->data;
}

void Print()
{
    if (len == 0)
    {
        cout << -1 << endl;
        return;
    }
    NODE *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data;
        if (cur->next != nullptr) cout << " ";
        cur = cur->next;
    }
    cout << endl;
}

void Clear()
{
    NODE *cur = head;
    while (cur != nullptr)
    {
        NODE *next = cur->next;
        delete cur;
        cur = next;
    }
    head = tail = nullptr;
    len = 0;
}

}
int n;
int main()
{
    cin >> n;
    int op, x, p, ans;
    LIST::Pre();
    for (int _=0;_<n;++_)
    {
        cin >> op;
        switch(op)
        {
            case 0:
                ans = LIST::Get_length();
                cout << ans << endl;
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                ans = LIST::Query(p);
                cout << ans << endl;
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                LIST::Print();
                break;
        }
    }
    LIST::Clear();
    return 0;
}
