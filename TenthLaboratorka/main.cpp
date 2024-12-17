#include <iostream>
using namespace std;


struct Node
{   
    Node* next;
    int data;
};


// Ввести последовательность натуральных чисел. Если в последовательности нет ни одного числа, содержащего две одинаковых цифры, 
// упорядочить последовательность по невозрастанию последней цифры числа. В противном случае удалить из последовательности числа, 
// начинающиеся четной цифрой и продублировать остальные числа. Последовательность хранить в односвязном списке.

void createList(Node* head, unsigned int n) // Создаёт forward_list
{
    Node* p = head;
    for (unsigned int i = 0; i < n; i++)
    {
        Node* q = new Node;
        p->next = q;

        cout << "Enter a value: ";
        cin >> q->data;
        q->next = nullptr;

        p = p->next;
    }
}


void printList(Node* head) // Выводит лист
{
    Node* p = head;
    while (p->next != nullptr)
    {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}


void clearList(Node* head) // Удаляет весь лист
{
    Node* p = head;
    while (p->next != nullptr)
    {
        Node* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
    }
    delete p;
}


bool containsIdenticalDigits(int n) // Проверяет, содержиться ли одинаковые цифры в числе
{
    n = abs(n);

    for (int i = 0; i < 10; i++)
    {
        int counter = 0;
        int number = n;
        while (number != 0)
        {
            if (number % 10 == i)
            {
                counter++;
            }
            number /= 10;
        }
        if (counter > 1) return true;
    }

    return false;
}


bool doesListContainsNumberWithIdenticalDigits(Node* head) // Проверяет, есть ли в листе числа, состоящих из повторяющихся цифр
{
    Node* p = head;
    while (p->next != nullptr)
    {
        if (containsIdenticalDigits(p->next->data))
        {
            return true;
        }
        p = p->next;
    }
    return false;
}


int getLastDigit(int n) // Выдаёт последнюю цифру числа
{
    return abs(n) % 10;
}


void sortListByLastDigit(Node* head) // Сортирует лист по невозрастанию последней цифры числа
{
    Node* p = head->next;
    for (Node * a = p; a->next != nullptr; a = a->next)
        for (Node * b = a->next; ; b = b->next)
        {
            if (getLastDigit(a->data) < getLastDigit(b->data)) swap(a->data, b->data);
            if (b->next == nullptr) break;
        }
}


int getFirstDigit(int n) // Выдаёт последнюю цифру числа
{
    while (n > 9)
    {
        n /= 10;
    }
    return n;
}


void removeElemFromList(Node* head, Node* elem) // Удаляет определенный элемент из листа
{
    Node* p = head;
    while (p->next != nullptr)
    {
        if (p->next == elem)
        {
            Node* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
            return;
        }
        p = p->next;
    }
    cout << "Not found\n";
}


void copyElemFromList(Node* head, Node* elem) // Дублирует определенный элемент листа
{
    Node* p = head;
    while (p->next != nullptr)
    {
        if (p->next == elem)
        {
            Node* q = new Node;
            q->data = p->next->data;
            q->next = p->next->next;
            p->next->next = q;  
            return;
        }
        p = p->next;
    }
    cout << "Not found\n";
}


void deleteNumbersStartsWithEvenDigit(Node* head) // Удаляет все элементы с числами, начинающимися с чётной цифры
{
    Node* p = head;
    while (p->next != nullptr)
    {
        if ((getFirstDigit(p->next->data)) % 2 == 0)
        {
            removeElemFromList(head, p->next);
        }
        else
        {
            p = p->next;
        } 
    }
}


void makeCopyOfEachElem(Node* head) // Делает дубликаты всех элементов листа
{
    Node* p = head;
    while (p->next != nullptr)
    {
        copyElemFromList(head, p->next);
        p = p->next->next;
    }
}


int main() 
{
    
    unsigned int n;
    cout << "Enter list length: ";
    cin >> n;

    Node* head = new Node{nullptr, 0}; // Создаём "головной" элемент листа
    head->next = nullptr;             // head->next == (*head).next
    head->data = 0;                  // head->data == (*head).data

    createList(head,  n);
    
    if (!doesListContainsNumberWithIdenticalDigits(head))
    {
        sortListByLastDigit(head);
    }
    else
    {
        deleteNumbersStartsWithEvenDigit(head);
        printList(head);
        makeCopyOfEachElem(head);
    }
    
    printList(head);

    clearList(head);
    system("pause");
    return 0;
}