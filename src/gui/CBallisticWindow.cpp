// ETH32 - an Enemy Territory cheat for linux
// Copyright (c) 2007 eth32 team
// www.nixcoders.org

#include "../eth32.h"

CBallisticWindow::CBallisticWindow(const char *label, int wx, int wy, int ww, int wh)
: CWindow(label, wx, wy, ww, wh)
{
	showTitle = false;
	Resize(w, (GUI_FONTHEIGHT * 4) + (GUI_TEXTSPACING * 3) + 10);
}

void CBallisticWindow::Display(void)
{
	if (!(eth32.cg.currentWeapon->attribs & WA_BALLISTIC))
		return;

	static char buffer[64];
	int yPos = y + 5;

	CWindow::Display();

	sprintf(buffer, "%.2f", 0.001*(float)eth32.cg.snap->ps.grenadeTimeLeft);
	Draw.Text(x + 5, yPos, GUI_FONTSCALE, "Time Remaining:", GUI_FONTCOLOR1, qtrue, qfalse, GUI_FONT, true);
	Draw.Text(x2 - 5 - TEXTWIDTH(buffer), yPos, GUI_FONTSCALE, buffer, GUI_FONTCOLOR2, qtrue, qfalse, GUI_FONT, true);	
	yPos += GUI_FONTHEIGHT + GUI_TEXTSPACING;

	if (Aimbot.grenadeTarget) 
		strncpy(buffer, Aimbot.grenadeTarget->name, Draw.BreakStringByWidth(Aimbot.grenadeTarget->name, w - 15 - TEXTWIDTH("Target:"), NULL, GUI_FONT, false));
	else
		strcpy(buffer, "<none>");

	Draw.Text(x + 5, yPos, GUI_FONTSCALE, "Target:", GUI_FONTCOLOR1, qtrue, qfalse, GUI_FONT, true);
	Draw.Text(x2 - 5 - TEXTWIDTH(buffer), yPos, GUI_FONTSCALE, buffer, GUI_FONTCOLOR2, qfalse, qfalse, GUI_FONT, true);
	yPos += GUI_FONTHEIGHT + GUI_TEXTSPACING;

	sprintf(buffer, "%i", Aimbot.grenadeTarget ? (int)Aimbot.grenadeTarget->distance : -1);
	Draw.Text(x + 5, yPos, GUI_FONTSCALE, "Distance:", GUI_FONTCOLOR1, qtrue, qfalse, GUI_FONT, true);
	Draw.Text(x2 - 5 - TEXTWIDTH(buffer), yPos, GUI_FONTSCALE, buffer, GUI_FONTCOLOR2, qtrue, qfalse, GUI_FONT, true);
	yPos += GUI_FONTHEIGHT + GUI_TEXTSPACING;

	sprintf(buffer, "%.1f s", Aimbot.grenadeTarget ? Aimbot.rifleGrenadeTime : 0.0);
	Draw.Text(x + 5, yPos, GUI_FONTSCALE, "Flytime:", GUI_FONTCOLOR1, qtrue, qfalse, GUI_FONT, true);
	Draw.Text(x2 - 5 - TEXTWIDTH(buffer), yPos, GUI_FONTSCALE, buffer, GUI_FONTCOLOR2, qtrue, qfalse, GUI_FONT, true);	
}

