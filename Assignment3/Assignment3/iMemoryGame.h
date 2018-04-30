/*
 * iMemoryGame.h
 *
 * Created: 30-Apr-18 10:18:00 AM
 *  Author: patih
 */ 


#ifndef IMEMORYGAME_H_
#define IMEMORYGAME_H_

	typedef struct memorygame_t
	{
		int level;
		int *sequence;
		}memorygame_t;
	
	void startGame();
	void endGame();
	void roundWon();
	void roundLost();
	void randomSequence(memorygame_t *self);
	bool compareNumbers(int a,int b);
	void readUserInput();
	void randomLevels();




#endif /* IMEMORYGAME_H_ */