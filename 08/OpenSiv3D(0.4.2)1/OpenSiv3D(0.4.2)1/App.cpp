#include "App.h"



App::App()
{
	AssetRegiseter();

	// �E�B���h�E���蓮���T�C�Y�\�ɂ���
	Window::SetStyle(WindowStyle::Sizable);

	Window::Resize({ 1280,720 });
	// �w�i�𐅐F�ɂ���
	Scene::SetBackground(Palette::Black);

	pos.x = 150;
	pos.y = 100;
	m[0] = new CTriangle();
	m[1] = new Marker(m[0]);
	m[2] = new CSquare(m[1]);
	m[0]->SetPosition(pos);
	m[1]->SetPosition(pos);
	m[2]->SetPosition(pos);

}

void App::Update()
{
	Vec2 vec = Cursor::PosF();

	if (MouseL.pressed())
	{
		for (int i = 0; i < 3; i++)
		{
			if (m[i]->IsInRange(vec))
			{
				pm = m[i];
				break;
			}
		}
	}
	if (MouseL.pressed())
	{
		if (pm)
		{
			Vec2 vecC = pm->GetCurrentPosition();
			Vec2 vecP = pm->GetPosition();
			vecP.x += vec.x - vecC.x;
			vecP.y += vec.y - vecC.y;
			pm->SetPosition(vecP);
		}
	}
	if (MouseL.pressed() && !MouseR.pressed())
	{
		pm = nullptr;
	}

	if (MouseL.down())
	{
		effect.add<RingEffect>(Cursor::Pos());
	}

	effect.update();
}

void App::Draw()
{
	m[0]->Draw();
}

void App::AssetRegiseter()
{
	FontAsset::Register(U"font0", 20, Typeface::Heavy);
	FontAsset::Register(U"font1", 20, Typeface::Black);
	FontAsset::Register(U"font2", 20, Typeface::Regular);
	FontAsset::Register(U"font4", 15, Typeface::Medium);
}
