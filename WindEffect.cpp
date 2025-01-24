#include "WindEffect.h"
#include "ActorManager.h"
#include "Duck.h"
#include "GameManager.h"

WindEffect::WindEffect(const Vector2f& _size, const string& _path, const IntRect& _rect) : MeshActor(_size, _path, PNG, _rect, "Duck")
{
	animation = CreateComponent<AnimationComponent>();
}

WindEffect::WindEffect(const WindEffect& _other) : MeshActor(_other)
{
	animation = CreateComponent<AnimationComponent>();
}

void WindEffect::Construct()
{
	Super::Construct();

	const float _timeBetween = 0.02f;
	const Vector2i& _spriteSize = Vector2i(138, 100);
	const vector<SpriteData>& _spritesData =
	{
		{ _timeBetween, Vector2i(138, 0), _spriteSize,  },
		{ _timeBetween, Vector2i(138, 100), _spriteSize },
		{ _timeBetween, Vector2i(138, 200), _spriteSize },
		{ _timeBetween, Vector2i(138, 300), _spriteSize },
		{ _timeBetween, Vector2i(138, 400), _spriteSize },
		{ _timeBetween, Vector2i(138, 500), _spriteSize },
		{ _timeBetween, Vector2i(138, 600), _spriteSize },
		{ _timeBetween, Vector2i(138, 700), _spriteSize },
		{ _timeBetween, Vector2i(138, 800), _spriteSize },
		{ _timeBetween, Vector2i(0, 0), _spriteSize,  },
		{ _timeBetween, Vector2i(0, 100), _spriteSize },
		{ _timeBetween, Vector2i(0, 200), _spriteSize },
		{ _timeBetween, Vector2i(0, 300), _spriteSize },
		{ _timeBetween, Vector2i(0, 400), _spriteSize },
		{ _timeBetween, Vector2i(0, 500), _spriteSize },
		{ _timeBetween, Vector2i(-100, -100), _spriteSize },
		//{ _timeBetween, Vector2i(0, 700), _spriteSize },
		//{ _timeBetween, Vector2i(0, 800), _spriteSize },
	};
	AnimationData _animationData = AnimationData(2.0f, _spritesData, true, false, RD_COLUMN);
	/*_animationData.notifies[5] = []()
	{
		if (MovementComponent* _movement = M_GAME.GetCurrent()->GetDuck()->GetComponent< MovementComponent>())
		{
			M_GAME.GetCurrent()->GetDuck()->GetComponent<MovementComponent>()->SetRotateSpeed(500.0f);
		}
		else if (MovementComponent* _movement = M_GAME.GetCurrent()->GetDuck()->GetMovement())
		{
			M_GAME.GetCurrent()->GetDuck()->GetComponent<MovementComponent>()->SetRotateSpeed(500.0f);
		}
	};
	
	_animationData.notifies[15] = []()
		{
			if (MovementComponent* _movement = M_GAME.GetCurrent()->GetDuck()->GetComponent< MovementComponent>())
			{
				M_GAME.GetCurrent()->GetDuck()->GetComponent<MovementComponent>()->SetRotateSpeed(100.0f);
			}
			else if (MovementComponent* _movement = M_GAME.GetCurrent()->GetDuck()->GetMovement())
			{
				M_GAME.GetCurrent()->GetDuck()->GetComponent<MovementComponent>()->SetRotateSpeed(100.0f);
			}
		};*/
	animation->AddAnimation(new Animation("WindGust", GetMesh()->GetShape(), _animationData));
	animation->SetCurrentAnimation("WindGust");
	animation->StartAnimation();
}

void WindEffect::Deconstruct()
{
	Super::Deconstruct();
	animation->StopAnimation();
}

void WindEffect::BeginPlay()
{
	Super::BeginPlay();

	/*new Timer([&]() 
	{ 
		Destroy(); 
		if (MovementComponent* _movement = M_GAME.GetCurrent()->GetDuck()->GetComponent< MovementComponent>())
		{
			M_GAME.GetCurrent()->GetDuck()->GetComponent<MovementComponent>()->SetRotateSpeed(100.0f);
		}
		else if (MovementComponent* _movement = M_GAME.GetCurrent()->GetDuck()->GetMovement())
		{
			M_GAME.GetCurrent()->GetDuck()->GetComponent<MovementComponent>()->SetRotateSpeed(100.0f);
		}
	}, seconds(GetLifeSpan()), true);*/
}