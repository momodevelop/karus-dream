#ifndef __APP_GAME_SYSTEMS_RENDERER_H__
#define __APP_GAME_SYSTEMS_RENDERER_H__

#include <SDL.h>
#include <entt.h>
#include <yuu/utils.h>
#include "../shared/shared_textures.h"

namespace app::game::systems {
	class SysRenderer {
	public:
		static void renderForeground(SDL_Renderer& renderer, shared::SharedTextures& textures, shared::SharedSpritesheets& spritesheets);
		static void renderBackground(SDL_Renderer& renderer, shared::SharedTextures& textures, shared::SharedSpritesheets& spritesheets);
		static void render(entt::registry& registry, SDL_Renderer& renderer, shared::SharedTextures& textures);
		static void renderStart(entt::registry& registry, SDL_Renderer& renderer, shared::SharedTextures& textures);
		static void renderGameOver(entt::registry& registry, SDL_Renderer& renderer, shared::SharedTextures& textures);
	};
}

#endif

