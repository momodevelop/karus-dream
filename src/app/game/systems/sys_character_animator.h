#ifndef __APP_GAME_SYSTEMS_CHARACTER_ANIMATOR_H__
#define __APP_GAME_SYSTEMS_CHARACTER_ANIMATOR_H__

#include <SDL.h>
#include <entt.h>
#include <ryoji/rect.h>

#include "../shared/shared_character_animations.h"

namespace app::game::systems {

	class SysCharacterAnimator {
	public:
		void update(entt::registry& registry, shared::SharedCharacterAnimations& characterAnimations);
	};
}


#endif