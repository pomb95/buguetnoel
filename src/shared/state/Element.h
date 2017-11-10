// Generated by dia2code
#ifndef STATE__ELEMENT__H
#define STATE__ELEMENT__H

#include <string>

#include "TypeId.h"

namespace state {

  /// class Element - 
  class Element {
    // Associations
    // Attributes
  public:
    int Alive;
  protected:
    TypeId typeId;
    std::string Name;
    int PosX;
    int PosY;
    int Range;
    int Team;
    int Life;
    // Operations
  public:
    Element ();
    ~Element ();
    // Setters and Getters
    TypeId getTypeId() const;
    void setTypeId(TypeId typeId);
    const std::string& getName() const;
    void setName(const std::string& Name);
    int getPosX() const;
    void setPosX(int PosX);
    int getPosY() const;
    void setPosY(int PosY);
    int getRange() const;
    void setRange(int Range);
    int getTeam() const;
    void setTeam(int Team);
    int getLife() const;
    void setLife(int Life);
  };

};

#endif
