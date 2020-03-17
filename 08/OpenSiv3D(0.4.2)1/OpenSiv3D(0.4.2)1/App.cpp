#include "App.h"



App::App()
{
	AssetRegiseter();

	// ウィンドウを手動リサイズ可能にする
	Window::SetStyle(WindowStyle::Sizable);

	Window::Resize({ 1280,720 });


	// 背景を水色にする
	Scene::SetBackground(Palette::Black);

	pos.x = 350;
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
	MouseButton[0] = MouseButton[1];
	MouseButton[1] = MouseL.pressed();

	//FontAsset(U"font2")(U"MouseButton[0]: ",MouseButton[0]).draw(100, 100);
	//FontAsset(U"font2")(U"MouseButton[1]: ",MouseButton[1]).draw(100, 130);



	if (SimpleGUI::Button(U"Set Triangle as Parent", Vec2(0,0)))
	{
		//Vec2 curPos = m[0]->GetCurrentPosition();

		m[0]->SetParent(nullptr);
		m[1]->SetParent(m[0]);
		m[2]->SetParent(m[1]);

		//m[0]->SetPosition(curPos);
		//m[1]->SetPosition(curPos);
		//m[2]->SetPosition(curPos);
	}
	if (SimpleGUI::Button(U"Set Circle as Parent", Vec2(0, 40)))
	{
		//Vec2 curPos = m[1]->GetCurrentPosition();

		m[1]->SetParent(nullptr);
		m[2]->SetParent(m[1]);
		m[0]->SetParent(m[2]);

		//m[1]->SetPosition(curPos);
		//m[2]->SetPosition(curPos);
		//m[0]->SetPosition(curPos);
	}
	if (SimpleGUI::Button(U"Set Square as Parent", Vec2(0, 80)))
	{
		//Vec2 curPos = m[2]->GetCurrentPosition();
		m[2]->SetParent(nullptr);
		m[0]->SetParent(m[2]);
		m[1]->SetParent(m[0]);

		//m[2]->SetPosition(curPos);
		//m[0]->SetPosition(curPos);
		//m[1]->SetPosition(curPos);
	}

	if (!MouseButton[0] && MouseButton[1])
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

	if (MouseButton[0] && MouseButton[1])
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
	if (MouseButton[0] && !MouseButton[1])
	{
		pm = nullptr;
	}

	if (MouseButton[0] && !MouseButton[1])
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
