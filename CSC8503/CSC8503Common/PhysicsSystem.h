#pragma once
#include "../CSC8503Common/GameWorld.h"
#include "CollisionDetection.h"
#include "QuadTree.h"
#include <set>

namespace NCL {
	namespace CSC8503 {
		class PhysicsSystem	{
		public:
			PhysicsSystem(GameWorld& g);
			~PhysicsSystem();

			void Clear();

			void Update(float dt);

			void UseGravity(bool state) {
				applyGravity = state;
			}

			void SetGlobalDamping(float d) {
				globalDamping = d;
			}

			float GetLinearDamping() { return linearDamping; }
			void SetLinearDamping(float d) { linearDamping = d; }

			void SetGravity(const Vector3& g);
			QuadTree<GameObject*>* GetQuadTree() {
				return tree;
			}
		
		protected:
			void BasicCollisionDetection();
			void BroadPhase();
			void NarrowPhase();

			void ClearForces();

			void IntegrateAccel(float dt, bool penalty = false);
			void IntegrateVelocity(float dt);

			void UpdateConstraints(float dt);

			void UpdateCollisionList();
			void UpdateObjectAABBs();
			void UpdateSleepingObjects();
			void BuildStaticList();

			void ImpulseResolveCollision(GameObject& a , GameObject&b, CollisionDetection::ContactPoint& p) const;
			void PenaltyResolveCollision(GameObject& a, GameObject& b, CollisionDetection::ContactPoint& p) const;

			GameWorld& gameWorld;

			bool	applyGravity;
			bool    useSleep;
			Vector3 gravity;
			float sleepEpsilon;
			float	dTOffset;
			float	globalDamping;
			float linearDamping;
			bool usingPenalty;

			std::set<CollisionDetection::CollisionInfo> allCollisions;
			std::set<CollisionDetection::CollisionInfo> broadphaseCollisions;
			std::vector<GameObject*> staticObjects;
			QuadTree <GameObject*>* tree;


			bool useBroadPhase		= true;
			int numCollisionFrames	= 5;
		};
	}
}

