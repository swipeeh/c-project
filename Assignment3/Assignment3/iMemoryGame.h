/*
 * iMemoryGame.h
 *
 * Created: 30-Apr-18 10:18:00 AM
 *  Author: patih
 */ 


#ifndef IMEMORYGAME_H_
#define IMEMORYGAME_H_

interface iMemorygame{
	void startGame();
	void endGame();
	void roundWon();
	void roundLost();
	void delay();
	void randomSequence();
	void readUserInput();
	void randomLevels();
}



#endif /* IMEMORYGAME_H_ */