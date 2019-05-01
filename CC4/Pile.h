#ifndef Pile_hpp
#define Pile_hpp

#include <ostream>

// Forward declarations
template <typename T> class Pile;
template <typename T> std::ostream& operator<<( std::ostream& os,
                                               const Pile<T>& p);

// Type Pile
template <typename T>
class Pile {
  friend std::ostream& operator<< <>( std::ostream& os,
                                     const Pile<T>& p);
  
public:
  using value_type = T;
  using pointer = value_type*;
  using reference = value_type&;
  using const_reference = const value_type&;
  
private:
  pointer donnees;
  size_t taille;
  const size_t CAPACITE;
  
public:
  Pile(size_t _capacite)
  // a completer
  : donnees(new[] value_type[_capacite]), taille(0), CAPACITE(_capacite)
  {
    // a completer
  }
  
  ~Pile()
  {
    // a completer
    delete[] donnees;
  }
  
  Pile(const Pile& other)
  // a completer
  {
    // a completer
    this->donnees = new[] value_type[other->CAPACITE];
    (size_t*)this->CAPACITE = other->CAPACITE;
    this->taille = 0;
    for(size_t i = 0; i < other->taille; ++i) {
      *(this->donnees + i) = *(other->donnees + i);
      ++taille;
    }
    
  }
  
  void empiler(const value_type& v)
  {
    // a completer
    if(taille < CAPACITE) {
      donnees[taille++] = v;
    }
  }
  
  void depiler()
  {
    // a completer
    if(taille)
      --taille;
  }
  
  const_reference sommet() const
  {
    // a completer
    return donnees[taille - 1];
  }
  
};

// ne pas modifier
template <typename T>
std::ostream& operator<<( std::ostream& os,
                         const Pile<T>& p)
{
  os << "Pile(" << p.taille << "/" << p.CAPACITE << "): ";
  size_t i = p.taille;
  while(i > 0)
    os << p.donnees[--i] << " ";
  return os;
}

#endif /* Pile_hpp */