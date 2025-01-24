#include "RectangleActor.h"

RectangleActor::RectangleActor(const Vector2f& _size, const string& _path, const MyTexture::ExtensionType& _textureType, const IntRect& _rect)
							 : MeshActor(_size, _path, _textureType, _rect, "RectangleActor")
{

}