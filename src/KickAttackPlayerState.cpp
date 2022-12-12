#include <Events.h>

#include <KickAttackPlayerState.h>

#include <IdlePlayerState.h>
#include <LightAttackPlayerState.h>
#include <DiedPlayerState.h>

PlayerState* KickAttackPlayerState::handleInput(gpp::Events& input)
{
    
    if(input.getCurrent() == gpp::Events::Event::LIGHT_ATTACK_EVENT)
    {
        DEBUG_MSG("StompAttackPlayerState -> LightAttackPlayerState");
        return new LightAttackPlayerState();
    }
    else if(input.getCurrent() == gpp::Events::Event::ATTACK_STOP_EVENT)
    {
        DEBUG_MSG("StompAttackPlayerState -> IdlePlayerState");
        return new IdlePlayerState();
    }
    else if(input.getCurrent() == gpp::Events::Event::DIED_EVENT)
    {
        DEBUG_MSG("StompAttackPlayerState -> DiedPlayerState");
        return new DiedPlayerState;
    }

    return nullptr;
}

void KickAttackPlayerState::update(Player &player)
{
    DEBUG_MSG("StompAttackPlayerState::update"); 
    DEBUG_MSG(typeid(player).name());
}

void KickAttackPlayerState::enter(Player &player)
{
    DEBUG_MSG("Entering StompAttackPlayerState");
    // stomp attack animation
    player.getAnimatedSprite().clearFrames();
    
    // jump frames
    player.getAnimatedSprite().addFrame(sf::IntRect(3900, 1756, 362, 483));
	player.getAnimatedSprite().addFrame(sf::IntRect(4262, 1756, 362, 483));
	player.getAnimatedSprite().addFrame(sf::IntRect(4624, 1756, 362, 483));
    player.getAnimatedSprite().addFrame(sf::IntRect(3900, 2239, 362, 483));
	player.getAnimatedSprite().addFrame(sf::IntRect(4262, 2239, 362, 483));
	player.getAnimatedSprite().addFrame(sf::IntRect(4624, 2239, 362, 483));
   
    // jump throw frames
    player.getAnimatedSprite().addFrame(sf::IntRect(4596, 862, 360, 431));
	player.getAnimatedSprite().addFrame(sf::IntRect(4956, 862, 360, 431));
	player.getAnimatedSprite().addFrame(sf::IntRect(5316, 862, 360, 431));
	player.getAnimatedSprite().addFrame(sf::IntRect(4596, 1293, 360, 431));

    player.getAnimatedSprite().setTime(seconds(0.03f));
}

void KickAttackPlayerState::exit(Player &player)
{
    DEBUG_MSG("Exiting StompAttackPlayerState");
    DEBUG_MSG(typeid(player).name());
}