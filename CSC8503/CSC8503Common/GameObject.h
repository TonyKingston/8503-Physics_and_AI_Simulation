#pragma once
#include "Transform.h"
#include "CollisionVolume.h"

#include "PhysicsObject.h"
#include "RenderObject.h"

#include <vector>

using std::vector;

namespace NCL {
	namespace CSC8503 {
		class GameObject	{
		public:

			enum Layer {
				Default = 1,
				IgnoreRaycast = 2,
				Player = 4
			};

			GameObject(string name = "");
			~GameObject();

			//static void InitObjects(TutorialGame* game);
			virtual bool UpdateObject(float dt) { return true; }

			void SetBoundingVolume(CollisionVolume* vol) {
				boundingVolume = vol;
			}

			const CollisionVolume* GetBoundingVolume() const {
				return boundingVolume;
			}

			bool IsActive() const {
				return isActive;
			}

			bool IsAsleep() const {
				return isAsleep;
			}

			void PutToSleep() {
				isAsleep = true;
			}

			void Wake() {
				isAsleep = false;
			}

			Transform& GetTransform() {
				return transform;
			}

			RenderObject* GetRenderObject() const {
				return renderObject;
			}

			PhysicsObject* GetPhysicsObject() const {
				return physicsObject;
			}

			Vector3 GetForwordDirection() {
				return transform.GetOrientation() * worldForward;
			}

			void SetRenderObject(RenderObject* newObject) {
				renderObject = newObject;
			}

			void SetPhysicsObject(PhysicsObject* newObject) {
				physicsObject = newObject;
			}

			const string& GetName() const {
				return name;
			}

			virtual void OnCollisionBegin(GameObject* otherObject) {
				//std::cout << "OnCollisionBegin event occured!\n";
			}

			virtual void OnCollisionEnd(GameObject* otherObject) {
				//std::cout << "OnCollisionEnd event occured!\n";
			}

			bool GetBroadphaseAABB(Vector3&outsize) const;

			void UpdateBroadphaseAABB();

			void DrawBoundingVolume() {
				boundingVolume->DrawVolume(transform.GetPosition());
			}

			void SetWorldID(int newID) {
				worldID = newID;
			}

			int		GetWorldID() const {
				return worldID;
			}

			void SetLayerMask(int layerMask) {
				layer = layerMask;
			}

			int GetLayerMask() {
				return layer;
			}
			void PrintDebugInfo();

		protected:
			Transform			transform;

			CollisionVolume*	boundingVolume;
			PhysicsObject*		physicsObject;
			RenderObject* renderObject;

			bool	isActive;
			bool    isAsleep;
			bool    isTrigger;
			int		worldID;
			int layer;
			string	name;

			Vector3 broadphaseAABB;
		};
	}
}

