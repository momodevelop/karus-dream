#include <ryoji/vector.h>
#include <ryoji/easing.h>
#include <ryoji/common.h>
#include <yuu/utils.h>
#include <constants.h>
#include <SDL.h>
#include <SDL_image.h>

#include "state.h"


using namespace ryoji;
using namespace math;
using namespace yuu;

namespace app::splash {

	State::State(
		SDL_Renderer& renderer, 
		std::function<void()> completedCallback
	) noexcept :
		completedCallback(completedCallback),
		timer(0.f),
		stateUpdate(&State::stateIntroUpdate),
		splashRects{
			RectData {
				Vec2f { -kRectSize, gDisplayHalfHeight - kRectHalfSize },
				Vec2f { gDisplayHalfWidth - kRectSize, gDisplayHalfHeight - kRectHalfSize },
				Vec2f { kRectSize, kRectSize },
				TEXTURE_KARU,
			},

			RectData {
				Vec2f { gDisplayWidth, gDisplayHalfHeight - kRectHalfSize },
				Vec2f { gDisplayHalfWidth, gDisplayHalfHeight - kRectHalfSize },
				Vec2f { kRectSize, kRectSize },
				TEXTURE_SUI,
			},
		},
		textures{
			SDL_TextureUniquePtr(yuu::SDL_CreateTextureFromPathX(&renderer, "img/karu.png")),
			SDL_TextureUniquePtr(yuu::SDL_CreateTextureFromPathX(&renderer, "img/sui.png")), 
		}
	{
	}

	State::~State() noexcept
	{		
	}

	void State::onEnter() noexcept
	{
	}

	void State::onUpdate(float dt) noexcept
	{
		(this->*stateUpdate)(dt);
	}

	void State::onExit() noexcept
	{
	}

	void State::onRender(SDL_Renderer& renderer) noexcept
	{
		for (const auto& splashRect : splashRects)  {
			SDL_Rect destRect = SDL_Rect { 
				(int)splashRect.current.x, 
				(int)splashRect.current.y, 
				(int)splashRect.size.x, 
				(int)splashRect.size.y 
			};
			SDL_SetTextureAlphaMod(textures[splashRect.textureHandler].get(), splashRect.alpha);
			SDL_RenderCopy(&renderer, textures[splashRect.textureHandler].get(), NULL, &destRect);
		}
		
	}

	void State::onHandleEvent(SDL_Event& e) noexcept
	{
		switch (e.type) {
		case SDL_EventType::SDL_MOUSEBUTTONDOWN:
		case SDL_EventType::SDL_KEYDOWN:
			completedCallback();
			break;
		}
	}

	void State::onClean() noexcept
	{
	}

	void State::stateIntroUpdate(float dt) noexcept
	{
		float ease = easing::easeOutBounce(clamp(0.f, 1.0f, timer / kDuration));
		for (auto& splashRect : splashRects) {
			Vec2f delta = splashRect.end - splashRect.start;
			splashRect.current = splashRect.start + delta * ease;
		}
		
		
		if (timer > kDuration) {
			timer = 0.f;
			stateUpdate = &State::stateOutroUpdate;
		}

		timer += dt;
	}
	void State::stateOutroUpdate(float dt) noexcept
	{
		float a = clamp(0.f, kDuration, timer / kDuration);
		if (timer > kDuration) {
			completedCallback();
			return;
		}
		
		for (auto& splashRect : splashRects) {
			splashRect.alpha = 255 + (Uint8)(a * -255);
		}
		
		timer += dt;
	}

}