#ifndef _LOGIC_H
#define _LOGIC_H

// This struct will act as a delegate for handling the logic and draw cunstions in the game's main loop.
typedef struct{
	void (*logic)(void);
	void (*draw)(void);
} Delegate;



#endif