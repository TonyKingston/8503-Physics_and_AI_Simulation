#include "RenderObject.h"
#include "../../Common/MeshGeometry.h"

using namespace NCL::CSC8503;
using namespace NCL;

RenderObject::RenderObject(Transform* parentTransform, MeshGeometry* mesh, TextureBase* tex, ShaderBase* shader, Vector4 colour) {
	this->transform	= parentTransform;
	this->mesh		= mesh;
	this->texture	= tex;
	this->shader	= shader;
	this->colour = colour;
}

RenderObject::~RenderObject() {

}