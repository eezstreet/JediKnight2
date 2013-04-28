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

#pragma once
#if !defined __TR_WORLDEFFECTS_H
#define __TR_WORLDEFFECTS_H

class CWorldEffectsSystem;
#include "../game/q_shared.h"


#define PARTICLE_FLAG_RENDER			0x00000001

struct	SParticle
{
	vec3_t		pos;
	vec3_t		velocity;
	unsigned	flags;
};



class CWorldEffect
{
protected:
	CWorldEffect	*mNext, *mSlave, *mOwner;
	bool			mEnabled, mIsSlave;

public:
	enum
	{
		WORLDEFFECT_ENABLED = 0,
		WORLDEFFECT_PARTICLES,
		WORLDEFFECT_PARTICLE_COUNT,

		WORLDEFFECT_END
	};

public:
			CWorldEffect(CWorldEffect *owner = 0);
	virtual ~CWorldEffect(void);
	
	void			SetNext(CWorldEffect *next) { mNext = next; }
	CWorldEffect	*GetNext(void) { return mNext; }
	void			SetSlave(CWorldEffect *slave) { mSlave = slave; }
	CWorldEffect	*GetSlave(void) { return mSlave; }
	void			AddSlave(CWorldEffect *slave);

	void			SetIsSlave(bool isSlave) { mIsSlave = isSlave; }
	void			SetOwner(CWorldEffect *owner) { mOwner = owner; }

	virtual	bool	Command(const char  *command);

	virtual	void	ParmUpdate(CWorldEffectsSystem *system, int which);
	virtual	void	ParmUpdate(CWorldEffect *effect, int which);
	virtual	void	SetVariable(int which, bool newValue, bool doSlave = false);
	virtual	void	SetVariable(int which, float newValue, bool doSlave = false);
	virtual	void	SetVariable(int which, int newValue, bool doSlave = false);
	virtual	void	SetVariable(int which, vec3_t newValue, bool doSlave = false);

	virtual	int			GetIntVariable(int which) { return 0; }
	virtual	SParticle	*GetParticleVariable(int which) { return 0; }

	virtual	void	Update(CWorldEffectsSystem *system, float elapseTime);
	virtual	void	Render(CWorldEffectsSystem *system);
};



class CWorldEffectsSystem
{
protected:
	CWorldEffect	*mList, *mLast;

public:
			CWorldEffectsSystem(void);
	virtual	~CWorldEffectsSystem(void);

			void	AddWorldEffect(CWorldEffect *effect);

	virtual	int			GetIntVariable(int which) { return 0; }
	virtual	SParticle	*GetParticleVariable(int which) { return 0; }
	virtual float		GetFloatVariable(int which) { return 0.0; }
	virtual	float		*GetVecVariable(int which) { return 0; }

	virtual	bool	Command(const char *command);

	virtual	void	Update(float elapseTime);
	virtual	void	ParmUpdate(int which);
	virtual	void	Render(void);
};


void R_InitWorldEffects(void);
void R_ShutdownWorldEffects(void);
void RB_RenderWorldEffects(void);

void R_WorldEffectCommand(const char *command);
void R_WorldEffect_f(void);

bool R_GetWindVector(vec3_t windVector);
bool R_GetWindSpeed(float &windSpeed);

bool R_IsRaining();
bool R_IsSnowing();

#endif // __TR_WORLDEFFECTS_H
