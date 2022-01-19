#pragma once

#include <stdint.h>
#include "stdbool.h"
#include "globals.h"
#include "fields.h"
#include "map.h"
#include "changes.h"

inline void shootLeft(bool when, uint8_t* ptr)																		
{														
	if ((when))											
	{													
		uint8_t* newMapInner = MAP_LEFT(ptr);			
		if (*newMapInner == FIELD_EMPTY)				
		{												
			*newMapInner = FIELD_PROJECTILE_LEFT;		
			change(newMapInner);						
		}												
		else if (*newMapInner == FIELD_BOMB)			
		{												
			*newMapInner = FIELD_BOMB_EXPLODING;		
			change(newMapInner);						
		}												
		else if (*newMapInner == FIELD_SURPRISE)		
		{												
			*newMapInner = FIELD_SURPRISE_SHOOT_ANIM1;	
			change(newMapInner);						
		}												
		else											
		{												
			uint8_t type = types[*newMapInner];			
			if (type & 1)								
			{											
				*newMapInner = FIELD_EXPLOSION_ANIM1;	
				change(newMapInner);					
			}											
		}												
	}													
}

inline void shootRight(bool when, uint8_t* ptr)
{														
	if ((when))											
	{													
		uint8_t* newMapInner = MAP_RIGHT(ptr);			
		uint8_t next = *(currentYTilesPtr + 1) == FIELD_NONE ? *newMapInner : *(currentYTilesPtr + 1);
		if (next == FIELD_EMPTY)						
		{												
			*(currentYTilesPtr + 1) = FIELD_PROJECTILE_RIGHT;
		}												
		else if (next == FIELD_BOMB)					
		{												
			*(currentYTilesPtr + 1) = FIELD_BOMB_EXPLODING;
		}												
		else if (next == FIELD_SURPRISE)				
		{												
			*(currentYTilesPtr + 1) = FIELD_SURPRISE_SHOOT_ANIM1;
		}												
		else											
		{												
			uint8_t type = types[next];					
			if (type & 1)								
			{											
				*(currentYTilesPtr + 1) = FIELD_EXPLOSION_ANIM1;
			}											
		}												
	}													
}

inline void shootUp(bool when, uint8_t* ptr)
{														
	if ((when))											
	{													
		uint8_t* newMapInner = MAP_UP(ptr);				
		if (*newMapInner == FIELD_EMPTY)				
		{												
			*newMapInner = FIELD_PROJECTILE_UP;			
			change(newMapInner);						
		}												
		else if (*newMapInner == FIELD_BOMB)			
		{												
			*newMapInner = FIELD_BOMB_EXPLODING;		
			change(newMapInner);						
		}												
		else if (*newMapInner == FIELD_SURPRISE)		
		{												
			*newMapInner = FIELD_SURPRISE_SHOOT_ANIM1;	
			change(newMapInner);						
		}												
		else											
		{												
			uint8_t type = types[*newMapInner];			
			if (type & 1)								
			{											
				*newMapInner = FIELD_EXPLOSION_ANIM1;	
				change(newMapInner);					
			}											
		}												
	}													
}

inline void shootDown(bool when, uint8_t* ptr)
{														
	if ((when))											
	{													
		uint8_t* newMapInner = MAP_DOWN(ptr);			
		uint8_t next = *nextYTilesPtr == FIELD_NONE ? *newMapInner : *nextYTilesPtr; 
		if (next == FIELD_EMPTY)						
		{												
			*nextYTilesPtr = FIELD_PROJECTILE_DOWN;		
		}												
		else if (next == FIELD_BOMB)					
		{												
			*nextYTilesPtr = FIELD_BOMB_EXPLODING;		
		}												
		else if (next == FIELD_SURPRISE)				
		{												
			*nextYTilesPtr = FIELD_SURPRISE_SHOOT_ANIM1;
		}												
		else											
		{												
			uint8_t type = types[next];					
			if (type & 1)								
			{											
				*nextYTilesPtr = FIELD_EXPLOSION_ANIM1;	
			}											
		}												
	}													
}