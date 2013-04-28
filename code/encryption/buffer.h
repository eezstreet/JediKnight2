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

#ifndef __BUFFER_H
#define __BUFFER_H

extern const int	BufferIncrease;

class cBuffer
{
private:
	char			*Buffer;
	int				Size, ActualSize, Pos;
	bool			FreeNextAdd;
	int				Increase;

public:
			cBuffer(int InitIncrease = BufferIncrease);
			~cBuffer(void) { Free(); }

	const char			*Get(void) { return Buffer; } 
	const char			*GetWithPos(void) { return Buffer + Pos; } 
	const int			GetSize(void) { return Size; }
	const int			GetRemaining(void) { return Size - Pos; }

	void				FreeBeforeNextAdd(void) { FreeNextAdd = true; }
	void				ResetPos(void) { Pos = 0; }
	void				ResetSize(void) { Size = 0; }

	char				*Add(char *Data, int Amount);
	void				Read(void);
	char				*Read(int Amount);
	bool				ValidPos(void) { return (Pos < Size); }

	size_t				strcspn(const char *notin);

	void				Free(void);
};

#endif // __BUFFER_H