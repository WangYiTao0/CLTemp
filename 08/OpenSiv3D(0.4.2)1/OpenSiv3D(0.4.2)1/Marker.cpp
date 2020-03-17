#include "Marker.h"



const float Marker::MARKER_RADIUS = 16.0f;

void Marker::AddChild(Marker* pChild)
{
	int num = this->numChild;
	if (num != 0)
	{
		Marker** oldppm = this->pChild;
		Marker** newppm = new Marker * [num + 1];
		for (int i = 0; i < num; i++)
		{
			newppm[i] = oldppm[i];
		}
		newppm[num] = pChild;
		this->numChild += 1;
		delete[]oldppm;
	}
	else if (num == 0)
	{
		this->pChild = new Marker * [1];
		this->pChild[0] = pChild;
		this->numChild += 1;
	}
}

Marker** Marker::GetChild(int& numChild)
{
	numChild = this->numChild;
	return this->pChild;
}

void Marker::SetParent(Marker* pParent)
{
	this->pParent = pParent;
}

s3d::Vec2 Marker::GetCurrentPosition() const
{
	Vec2 curPos;
	curPos.x = 0;
	curPos.y = 0;
	if (pParent)
		curPos = pParent->GetCurrentPosition();
	curPos.x = this->GetPosition().x + curPos.x;
	curPos.y = this->GetPosition().y + curPos.y;
	return curPos;
}

bool Marker::IsInRange(const Vec2& position) const
{
	Vec2 curPos = this->GetCurrentPosition();
	float xlen = position.x - curPos.x;
	float ylen = position.y - curPos.y;
	float sqlen = xlen * xlen + ylen + ylen;

	return sqlen <= MARKER_RADIUS * MARKER_RADIUS;
}

void Marker::Draw(void)
{
	Vec2 curPos = this->GetCurrentPosition();

	Circle(curPos.x, curPos.y, MARKER_RADIUS).draw(Palette::Gray);

	for (int i = 0; i < this->numChild; i++)
	{
		this->pChild[i]->Draw();
	}
}

void CSquare::Draw(void)
{
	Vec2 curPos = this->GetCurrentPosition();

	Rect(curPos.x - 15, curPos.y - 15, 30).draw(Palette::Blueviolet);

	for (int i = 0; i < this->numChild; i++)
	{
		this->pChild[i]->Draw();
	}
}

void CTriangle::Draw(void)
{
	Vec2 curPos = this->GetCurrentPosition();
	Vec2 tri[3];
	tri[0].x = curPos.x;
	tri[0].y = curPos.y - 15;
	tri[1].x = curPos.x - 15;
	tri[1].y = curPos.y + 15;
	tri[2].x = curPos.x + 15;
	tri[2].y = curPos.y + 15;
	Triangle(tri[0], tri[1], tri[2]).draw(Palette::Red);

	for (int i = 0; i < this->numChild; i++)
	{
		this->pChild[i]->Draw();
	}
}

