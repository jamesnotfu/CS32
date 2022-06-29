#ifndef Sequence_h
#define Sequence_h

#include <string>

using ItemType = std::string;

class Sequence
{
public:
    Sequence(); // Default constructor
    Sequence(const Sequence& other); // Copy constructor
    Sequence& operator = (const Sequence& value); // Assignment operator
    ~Sequence(); // Destructor
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
    void dump() const; // Test/print information about sequence
private:
    struct Node {
        ItemType data;
        Node* m_next;
        Node* m_previous;
    };
    Node* head;
    int m_size;
};

//int subsequence(const Sequence& seq1, const Sequence& seq2);
//void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);

#endif
