#ifndef __APP_GAME_SYSTEMS_AI_H__
#define __APP_GAME_SYSTEMS_AI_H__


namespace app::game::systems {

	class SysAi {
	public:
		static void updateAiDamageTakeCooldown(entt::registry& ecs, float dt);
		static void updateAiMovement(entt::registry& ecs, float dt);
		static void updateAiDeath(entt::registry& ecs, float dt);
	};
}


#endif