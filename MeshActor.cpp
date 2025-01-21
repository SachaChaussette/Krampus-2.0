#include "MeshActor.h"
#include "Game.h"

MeshActor::MeshActor(const MeshActor& _other)
{
	mesh = CreateComponent<MeshComponent>(*_other.mesh);
	renderMeshToken = _other.renderMeshToken;
}

MeshActor::MeshActor(const float _radius, const size_t& _pointCount, const string& _path,
					const IntRect& _rect)
{
	mesh = CreateComponent<MeshComponent>(_radius, _pointCount, _path, _rect);

	renderMeshToken = M_GAME.BindOnRenderWindow(bind(&MeshActor::RenderMesh,this, placeholders::_1));

}

MeshActor::MeshActor(const Vector2f _size, const string& _path, const IntRect& _rect)
{
	mesh = CreateComponent<MeshComponent>(_size, _path, _rect);
}

void MeshActor::Construct()
{
	Super::Construct();
	renderMeshToken = M_GAME.BindOnRenderWindow(bind(&MeshActor::RenderMesh, this, placeholders::_1));
}

void MeshActor::Deconstruct()
{
	Super::Deconstruct();
	M_GAME.UnbindOnRenderWindow(renderMeshToken);
}


void MeshActor::RenderMesh(RenderWindow& _window)
{
	_window.draw(*mesh->GetShape()->GetDrawable());
}

