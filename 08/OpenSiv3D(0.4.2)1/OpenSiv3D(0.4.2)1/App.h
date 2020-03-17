#pragma once
#pragma once

#include "Marker.h"


class App
{
public:
	App();

	void Update();
	void Draw();
private:
	void AssetRegiseter();

private:

	struct RingEffect : IEffect
	{
		Vec2 m_pos;

		ColorF m_color;

		RingEffect(const Vec2& pos)
			: m_pos(pos)
			, m_color(RandomColor())
		{}
		bool update(double t) override
		{

			const double e = EaseOutExpo(t);

			Circle(m_pos, e * 100).drawFrame(20.0 * (1.0 - e), m_color);

			return t < 1.0;
		}
	};
	Effect effect;


	Vec2 startPos = Vec2::Zero();
	Vec2 endPos = Vec2::Zero();
	Vec2 hw = Vec2::Zero();

	Marker* m[3];
	Marker* pm = nullptr;
	int x, y;
	Vec2 pos;

	int MouseButton[2] = { 0,0 };
};


