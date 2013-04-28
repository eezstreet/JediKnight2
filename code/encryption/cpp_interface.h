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

#ifndef __CPP_INTERFACE_H
#define __CPP_INTERFACE_H

#ifdef __cplusplus
extern "C"
{
#endif

void	*ENCRYPT_fopen(const char *Name, const char *Mode);
void	ENCRYPT_fclose(void *File);
int		ENCRYPT_fseek(void *File, long offset, int origin);
size_t	ENCRYPT_fread(void *buffer, size_t size, size_t count, void *File);
long	ENCRYPT_ftell(void *File);

#ifdef __cplusplus
}
#endif


#endif // __CPP_INTERFACE_H