// Generated by dia2code
#ifndef SERVER__COMMAND__H
#define SERVER__COMMAND__H


namespace server {

  /// class Command - 
  class Command {
    // Attributes
  public:
    int Id;
    int character;
    int direction;
    int attaquant;
    int victime;
    // Operations
  public:
    Command (int Id, int character, int direction, int attaquant, int victime);
    // Setters and Getters
  };

};

#endif
