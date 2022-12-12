#ifndef Special_Ability_PLAYER_STATE_H
#define Special_Ability_PLAYER_STATE_H

#include <Player.h>
#include <PlayerState.h>

class SpecialAbilityPlayerState : public PlayerState {
public:
	virtual PlayerState* handleInput(gpp::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
};

#endif