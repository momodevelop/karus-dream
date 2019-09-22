#ifndef _APP_GAME_SHARED_SPAWNER_H__
#define _APP_GAME_SHARED_SPAWNER_H__

#include <random>
#include <entt.h>
#include <ryoji/vector.h>
#include "../shared/shared_animation_indices.h"

namespace app::game::shared {
	class SharedSpawner {
		enum EnemyType {
			GHOST,
			SKELETON,
			FROG,
			BAT,
		};
		float coinTimer;
		float coinDuration;
		float enemyTimer;
		float enemyDuration;

		entt::registry& ecs;
		shared::SharedAnimationIndices& animationIndices;

		// for randoming
		std::random_device randomCoinDevice; 
		std::mt19937 randomCoinGenerator;
		std::uniform_int_distribution<> randomCoinX;
		std::uniform_int_distribution<> randomCoinY;
		std::uniform_int_distribution<> randomEnemyType;
		std::uniform_int_distribution<> randomCoinFlip;

		void spawnCoin(ryoji::math::Vec2f pos);
		void spawnEnemy(ryoji::math::Vec2f pos, bool facingRight, EnemyType type);
	public:
		SharedSpawner(entt::registry& ecs, shared::SharedAnimationIndices& animationIndices);
		~SharedSpawner();

		void update(float dt);

	};
}

#endif 