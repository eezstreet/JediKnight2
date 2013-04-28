/*
This file is part of Jedi Knight 2.

    Jedi Knight 2 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    Jedi Knight 2 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Jedi Knight 2.  If not, see <http://www.gnu.org/licenses/>.
*/
// Copyright 2001-2013 Raven Software

// Filename:-	win_video.cpp
//
// leave this as first line for PCH reasons...
//
#include "../server/exe_headers.h"

			   

#include "../client/client.h"
#include "win_local.h"

qboolean VIDEO_GetDims(int *piWidth, int *piHeight)
{
	return qfalse;
}

qboolean VIDEO_NextFrameReady(void)
{
	return qtrue;
}

void VIDEO_Pause(qboolean bPaused)
{
}

void VIDEO_Mute(qboolean bMute)
{
}

qboolean VIDEO_NextFrame( byte *pbDestBuffer, int iBytesPerLine, qboolean &bFrameSkipped)
{
	return qfalse;
}

void VIDEO_Close(void)
{
}

qboolean VIDEO_Open(char *psPathlessBaseName, qboolean qbInGame, qboolean qbTestOpenOnly, int iLanguageNumber)
{
	return qfalse;
}

