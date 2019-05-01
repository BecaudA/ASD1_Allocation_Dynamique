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
  Pile(size_t _capacite) : CAPACITE(_capacite)
  {
    donnees = (pointer) ::operator new(CAPACITE * sizeof(value_type));
    // donnees = new value_type[_capacite];
    taille = 0;
  }
  
  ~Pile()
  {
  for(;this->taille > 0;--taille)
     delete (donnees + taille - 1);
  }
  
  Pile(const Pile& other) : CAPACITE(other.CAPACITE)
  // a completer
  {
      donnees = (pointer) ::operator new(CAPACITE * sizeof(value_type));
      // donnees = new value_type[CAPACITE];
      this->taille = 0;
      for (size_t i = 0; i < other.taille; i++)
      {
         pointer tmp = new (donnees + taille++) value_type(other.donnees[i]);
         // this->donnees[i] = other.donnees[i];
      }
      //this->taille = other.taille;
  }
  
  void empiler(const value_type& v)
  {
    pointer tmp = new (donnees + taille++) value_type(v);
    //this->donnees[taille++] = v;
  }
  
  void depiler()
  {
    delete (donnees + --taille);
    //this->donnees[taille--];
  }
  
  const_reference sommet() const
  {
    return this->donnees[taille-1];
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
