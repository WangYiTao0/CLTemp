#pragma once
#include <Siv3D.hpp>


	class Marker
	{
	private:
		static const float MARKER_RADIUS;
		Vec2 position_;
	protected:
		int numChild;
		Marker** pChild;
		Marker* pParent;
	public:

		void SetPosition(const Vec2& position) { position_ = position; }
		const Vec2& GetPosition(void) const { return position_; }

		void AddChild(Marker* pChild);
		Marker** GetChild(int& numChild);

		void SetParent(Marker* pParent);
		Vec2 GetCurrentPosition()const;

		bool IsInRange(const Vec2& position) const;
		virtual void Draw(void);

		Marker() { pParent = nullptr; pChild = nullptr; numChild = 0; }
		Marker(Marker* pp)
		{
			this->SetParent(pp);
			pp->AddChild(this);
			pChild = nullptr;
			numChild = 0;
		}
		virtual ~Marker() { delete[]pChild; }
	};

	class CSquare : public Marker
	{
	public:
		CSquare() :Marker() {}
		CSquare(Marker* pp) :Marker(pp) {}
		void Draw(void);
	};

	class CTriangle : public Marker
	{
	public:
		CTriangle() :Marker() {}
		CTriangle(Marker* pp) :Marker(pp) {}
		void Draw(void);
	};

