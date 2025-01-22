#include "Animation.h"
#include "TextureManager.h"

bool LinkedAnimation::TryToChange()
{
	if (!IsValid()) return false;
	animation->Start();
	return true;
}

Animation::Animation(const string& _name, ShapeObject* _shape, const AnimationData& _data)
{
	currentIndex = 0;
	name = _name;
	data = _data;
	shape = _shape;
	timer = new Timer([&]() 
	{
		Update(); 
	},
	seconds(data.sprites[currentIndex].timeBetween), true, true);
}

Animation::Animation(const Animation& _other)
{
	currentIndex = _other.currentIndex;
	name = _other.name;
	data = _other.data;
	shape = _other.shape;
	timer = new Timer([&]()
	{
		Update();
	},
	seconds(data.sprites[currentIndex].timeBetween), true, true);
}

Animation::~Animation()
{
	LOG(Warning, "Delete Animation");
	//M_TIMER.RemoveTimer(timer);
}

void Animation::Reset()
{
	currentIndex = 0;
	timer->Reset();
}

void Animation::Update()
{
	if (!IsValidIndex())
	{
		if (!data.canLoop)
		{
			// transition

			Stop();
			return;
		}

		Reset();
	}
	if (data.isReversed)
	{
		shape->SetScale(Vector2f(-1.0f, 1.0f));
	}
	const SpriteData& _spriteData = data.sprites[++currentIndex - 1];
	M_TEXTURE.SetTextureRect(shape->GetDrawable(), _spriteData.start, _spriteData.size);
}


void Animation::Start()
{
	Update();
	timer->Start();
}

void Animation::Resume()
{
	timer->Resume();
}

void Animation::Pause()
{
	timer->Pause();
}

void Animation::Stop()
{
	Pause();
	Reset();
}

