// USAGE:
// g++ -o practiceShapes shapesPractice.cpp -lX11 -lGL -lpthread -lpng -lstdc++fs
// KZ 3-3-21

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Example";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
        float fLocX = { 0.0f };
        float fLocY = { 100.0f };

		// called once per frame
		for (int y = 0; y < ScreenHeight(); y++){
			for (int x = 0; x < ScreenWidth(); x++){
				DrawCircle(fLocX, fLocY, 10, olc::WHITE);
                DrawLine(0, ScreenHeight()/2, ScreenWidth(), ScreenHeight()/2, olc::WHITE);
            }
        
        // fLocX += 1;
        // fLocY += 1;
        }
		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(256, 240, 4, 4))
		demo.Start();

	return 0;
}
