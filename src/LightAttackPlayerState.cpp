#include "LightAttackPlayerState.h"
#include "Events.h"

#include <AttackPlayerState.h>
#include <IdlePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* LightAttackPlayerState::handleInput(gpp::Events& input)
{
    if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
    {
        DEBUG_MSG("LightAttackPlayerState -> AttackPlayerState");
        return new AttackPlayerState();
    }

    else if (input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
    {
        DEBUG_MSG("LightAttackPlayerState -> idlePlayerState");
        return new IdlePlayerState();
    }

    else if(input.getCurrent() == gpp::Events::Event::DIED_EVENT)
    {
        DEBUG_MSG("LightAttackPlayerState -> DiedplayerState");
        return new DiedPlayerState();
    }
    
    return nullptr;
}

void LightAttackPlayerState::update(Player& player)
{
    DEBUG_MSG("LightAttackPlayerState::update");
    DEBUG_MSG(typeid(player).name());
}

void LightAttackPlayerState::enter(Player& player)
{
    DEBUG_MSG("Entering LightAttackPlayerState");
    player.getAnimatedSprite().clearFrames(); 

    player.getAnimatedSprite().addFrame(sf::IntRect(0, 0, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(536, 0, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(1072, 0, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 495, 536, 495));
	player.getAnimatedSprite().addFrame(sf::IntRect(536, 495, 536, 495));
	// player.getAnimatedSprite().addFrame(sf::IntRect(1072, 495, 536, 495));
	// player.getAnimatedSprite().addFrame(sf::IntRect(0, 990, 536, 495));
	// player.getAnimatedSprite().addFrame(sf::IntRect(536, 990, 536, 495));
	// player.getAnimatedSprite().addFrame(sf::IntRect(1072, 990, 536, 495));
	// player.getAnimatedSprite().addFrame(sf::IntRect(0, 1485, 536, 495));

    player.getAnimatedSprite().setTime(seconds(0.03f));
}

void LightAttackPlayerState::exit(Player& player)
{
    DEBUG_MSG("Exiting LightAttackPlayerState"); 
    DEBUG_MSG(typeid(player).name());
}




