// ETH32 - an Enemy Territory cheat for linux
// Copyright (c) 2007 eth32 team
// www.nixcoders.org

#pragma once

#include "CWindow.h"

class CRadarWindow : public CWindow
{
public:
	CRadarWindow(char *wlabel, int wx, int wy, int ww, int wh);
	void Display(void);
	int MouseWheel(int mx, int my, int wheel);

	void SetOrigin(int ox, int oy);
	void Reposition(int ox, int oy);

	void AddPlayer(player_t *player);
private:
	player_t *points[MAX_CLIENTS];
	int numPoints;

	int cx, cy;		// center of window
};

