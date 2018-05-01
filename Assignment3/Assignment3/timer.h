/*
 * timer.h
 *
 * Created: 4/11/2018 2:38:13 PM
 *  Author: chfs
 */


#ifndef TIMER_H_
#define TIMER_H_

#define F_CPU 10000000L
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

typedef struct timer * timer_t;

// constructor
timer_t timer_create(uint8_t time);
// finalizer
void timer_destroy(timer_t self);

// methods
void timer_start(timer_t self);
void timer_stop(timer_t self);
void timer_reset(timer_t self);
void timer_setTime(timer_t self, uint8_t time);
uint8_t timer_getTime(timer_t self);
bool timer_isStarted(timer_t self);
void timer_inc(timer_t self);
void timer_dec(timer_t self);

#endif /* TIMER_H_ */
