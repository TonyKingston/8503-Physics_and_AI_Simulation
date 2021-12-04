#pragma once
#include "../../Common/Vector4.h"
#include "../../Common/MeshGeometry.h"
#include "Debug.h"


namespace NCL {

	namespace CSC8503 {
		class GameObject;
	}

	enum class VolumeType {
		AABB = 1,
		OBB = 2,
		Sphere = 4,
		Mesh = 8,
		Capsule = 16,
		Compound = 32,
		Invalid = 256
	};
	class CollisionVolume
	{
	public:
		CollisionVolume() {
			type = VolumeType::Invalid;
			mesh = NULL;
		}
		~CollisionVolume() {}

		VolumeType type;

		virtual void DrawVolume(const Vector3& position, const Vector4& colour = Debug::BLUE) {
			if (mesh) {
				mesh->SetPrimitiveType(Lines);
				
			}
		};
		void SetVolumeMesh(MeshGeometry* m) { mesh = m; }
		void SetObject(CSC8503::GameObject* object) { collisionObj = object; }
		MeshGeometry* GetVolumeMesh() { return mesh; }
	private:
		MeshGeometry* mesh;
		CSC8503::GameObject* collisionObj;
	};
}