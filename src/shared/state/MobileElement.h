// Generated by dia2code
#ifndef STATE__MOBILEELEMENT__H
#define STATE__MOBILEELEMENT__H


namespace state {
  class Element;
}

#include "Element.h"

namespace state {

  /// class MobileElement - 
  class MobileElement : public state::Element {
    // Attributes
  protected:
    /// 	
    int m_position;
    int m_MP;
    int m_LP;
    int m_ATK;
    int m_DEF;
    int m_RANGE;
    // Operations
  public:
    MobileElement ();
    ~MobileElement ();
    virtual bool const isHero ();
    virtual int Atk (const Element& other);
    virtual move (Direction direction);
    int setLife (int );
    int getLife ();
    // Setters and Getters
    int getM_position() const;
    void setM_position(int m_position);
    int getM_MP() const;
    void setM_MP(int m_MP);
    int getM_LP() const;
    void setM_LP(int m_LP);
    int getM_ATK() const;
    void setM_ATK(int m_ATK);
    int getM_DEF() const;
    void setM_DEF(int m_DEF);
    int getM_RANGE() const;
    void setM_RANGE(int m_RANGE);
  };

};

#endif
