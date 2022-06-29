//
//  landmark.cpp
//  homework 3
//
//  Created by James Fu on 5/3/22.
//

// Your declarations and implementations would go here
class Landmark
{
private:
    string m_name;
public:
    Landmark(string name);
    virtual ~Landmark();
    string name() const;
    virtual string icon() const = 0;
    virtual string color() const;
};

Landmark::Landmark(string name) : m_name(name) {
}

string Landmark::name() const {
    return m_name;
}

string Landmark::icon() const {
    return 0;
}

string Landmark::color() const {
    return "yellow";
}

Landmark::~Landmark() {
}

class Hotel : public Landmark
{
private:
public:
    Hotel(string name);
    virtual ~Hotel();
    virtual string icon() const;
};

Hotel::Hotel(string name): Landmark(name){
}

Hotel::~Hotel() {
    cout << "Destroying the hotel " << name() << "." << endl;
}

string Hotel::icon() const {
    return "bed";
}

class Restaurant : public Landmark {
private:
    int m_capacity;
public:
    Restaurant(string name, int capacity);
    virtual ~Restaurant();
    virtual string icon() const;
};

Restaurant:: Restaurant(string name, int capacity): Landmark(name), m_capacity(capacity)
{
}

Restaurant::~Restaurant()
{
   cout << "Destroying the restaurant " << name() << "." << endl;
}

string Restaurant::icon() const
{
   if(m_capacity < 40) {
       return "small knife/fork";
   }
   else {
       return "large knife/fork";
   }
}

class Hospital : public Landmark {
private:
public:
    Hospital(string name);
    virtual ~Hospital();
    virtual string icon() const;
    virtual string color() const;
};

Hospital::Hospital(string name) : Landmark(name) {
}

Hospital::~Hospital() {
    cout << "Destroying the hospital " << name() << "." << endl;
}

string Hospital::icon() const {
    return "H";
}

string Hospital::color() const {
    return "blue";
}
