#include <Events.h>
#include <SpecialAbilityPlayerState.h>

#include <IdlePlayerState.h>
#include <DiedPlayerState.h>

PlayerState* SpecialAbilityPlayerState::handleInput(gpp::Events& input)
{
    if(input.getCurrent() == gpp::Events::Event::SPECIAL_ABILITY_STOP_PLAYER_STATE_)
    {
        DEBUG_MSG("SpecialAbilityPlayerState -> IdlePlayerState");
        return new IdlePlayerState(); 
    }
    else if(input.getCurrent() == gpp::Events::Event::DIED_EVENT)
    {
        DEBUG_MSG("SpecialAbilityPlayerState -> IdlePlayerState");
        return new DiedPlayerState(); 
    }

    return nullptr;
}

void SpecialAbilityPlayerState::update(Player& player)
{
    DEBUG_MSG("SpecialAbilityPlayerState::update");
    DEBUG_MSG(typeid(player).name());
}

void SpecialAbilityPlayerState::enter(Player& player)
{
    DEBUG_MSG("Entering  SpecialAbilityPlayerState");
    player.getAnimatedSprite().clearFrames();

    player.getAnimatedSprite().addFrame(sf::IntRect(5700, 14, 109, 115));
	player.getAnimatedSprite().addFrame(sf::IntRect(5820, 14, 109, 115));
	player.getAnimatedSprite().addFrame(sf::IntRect(5946, 14, 109, 115));
	player.getAnimatedSprite().addFrame(sf::IntRect(5700, 145, 109, 115));
	
    player.getAnimatedSpriteFrame().setTime(seconds(0.10f));
}

void SpecialAbilityPlayerState::exit(Player& player)
{
    DEBUG_MSG("Exiting SpecialAbilityPlayerState");
    DEBUG_MSG(typeid(player).name());
}