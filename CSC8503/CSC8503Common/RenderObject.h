#pragma once
#include "../../Common/Matrix4.h"
#include "../../Common/TextureBase.h"
#include "../../Common/ShaderBase.h"
#include "../../Common/Vector4.h"
#include "../../Common/Vector3.h"

namespace NCL {
	using namespace NCL::Rendering;

	class MeshGeometry;

	namespace CSC8503 {
		class Transform;
		using namespace Maths;
		const Vector3 worldForward = Vector3(0, 0, -1);
		const Vector3 worldUp = Vector3(0, 1, 0);

		class RenderObject
		{
		public:


			RenderObject(Transform* parentTransform, MeshGeometry* mesh, TextureBase* tex, ShaderBase* shader, Vector4 colour = Vector4(1,1,1,1));
			~RenderObject();

			void SetDefaultTexture(TextureBase* t) {
				texture = t;
			}

			TextureBase* GetDefaultTexture() const {
				return texture;
			}

			MeshGeometry*	GetMesh() const {
				return mesh;
			}

			Transform*		GetTransform() const {
				return transform;
			}

			ShaderBase*		GetShader() const {
				return shader;
			}

			void SetColour(const Vector4& c) {
				colour = c;
			}

			Vector4 GetColour() const {
				return colour;
			}

		protected:
			MeshGeometry*	mesh;
			TextureBase*	texture;
			ShaderBase*		shader;
			Transform*		transform;
			Vector4			colour;
		};
	}
}
