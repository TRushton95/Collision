#ifndef  BOX_CPP
#define BOX_CPP

#include "Vector2.cpp"

struct Box
{
	Vector2 mPosition{};
	Vector2 mSize{};

	Vector2 End()
	{
		return Vector2{ mPosition.x + mSize.x, mPosition.y + mSize.y };
	}

	bool Intersects(Box& b)
	{
		Vector2 end = this->End();
		Vector2 bEnd = b.End();

		return mPosition.x < bEnd.x
			&& end.x > b.mPosition.x
			&& mPosition.y < bEnd.y
			&& end.y > b.mPosition.y;
	}
};

#endif