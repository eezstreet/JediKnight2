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

#if !defined(MINIHEAP_H_INC)
#define MINIHEAP_H_INC


class CMiniHeap
{
	char	*mHeap;
	char	*mCurrentHeap;
	int		mSize;
	int		mMaxAlloc;
public:

// reset the heap back to the start
void ResetHeap()
{
	if ((int)mCurrentHeap - (int)mHeap>mMaxAlloc)
	{
		mMaxAlloc=(int)mCurrentHeap - (int)mHeap;
	}
	mCurrentHeap = mHeap;
}

// initialise the heap
CMiniHeap(int size)
{
	mHeap = (char *)Z_Malloc(size, TAG_GHOUL2, qtrue);
	mSize = size;
	mMaxAlloc=0;
	if (mHeap)
	{
		ResetHeap();
	}
}

// free up the heap
~CMiniHeap()
{
	if (mHeap)
	{
		Z_Free(mHeap);
	}
#if _DEBUG
	char mess[1000];
	sprintf(mess,"Max miniheap allocated %d\n",mMaxAlloc);
	OutputDebugString(mess);
#endif
}

// give me some space from the heap please
char *MiniHeapAlloc(int size)
{
	if (size < (mSize - ((int)mCurrentHeap - (int)mHeap)))
	{
		char *tempAddress =  mCurrentHeap;
		mCurrentHeap += size;
		return tempAddress;
	}
	return NULL;
}

};

extern CMiniHeap *G2VertSpaceServer;


#endif	//MINIHEAP_H_INC
