// Generated by dia2code
#ifndef ENGINE__ENGINE__H
#define ENGINE__ENGINE__H

#include <state/State.h>
#include <vector>

namespace state {
  class State;
};
namespace engine {
  class Command;
}

#include "state/State.h"
#include "Command.h"

namespace engine {

  /// class Engine - 
  class Engine {
    // Attributes
  private:
    state::State currentState;
    std::vector<Command> commands;
    // Operations
  public:
    Engine ();
    ~Engine ();
    void addCommand (Command cmd);
    void Update (state::State& state_game);
    void testInit ();
    void clearCommands ();
    // Setters and Getters
  };

};

#endif
