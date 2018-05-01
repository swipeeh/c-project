/*
 * timer.c
 *
 * Created: 4/11/2018 2:43:52 PM
 *  Author: chfs
 */


#include "timer.h"

static void display_done()
{
    uint8_t counter = 10;
    PORTA = 0xff;
    while (counter--)
    {
        PORTA = ~PORTA;
        _delay_ms(100);
    }
}

static void display_time(uint8_t time)
{
    PORTA = ~time;
}

struct timer
{
    uint8_t time;
    uint8_t started;
    uint8_t remainingTime;
};


timer_t timer_create(uint8_t time)
{
    timer_t new_timer = (timer_t)malloc(sizeof(struct timer));
    new_timer->started = false;

    timer_setTime(new_timer, time);

    return new_timer;
}

void timer_destroy(timer_t self)
{
    free(self);
}

// methods
void timer_start(timer_t self)
{
    self->started = true;
    while (self->started && self->remainingTime > 0)
    {
        self->remainingTime--;
        //display_time(self->remainingTime);
        _delay_ms(1000);
    }
    if (self->remainingTime < 1)
    {
        //display_done();
    }
}

void timer_stop(timer_t self)
{
    self->started = false;
}

void timer_reset(timer_t self)
{
    self->started = false;
    self->remainingTime = self->time;
    display_time(self->remainingTime);
}

void timer_setTime(timer_t self, uint8_t time)
{
    self->time = time;
    self->remainingTime = self->time;
    display_time(self->remainingTime);
}

uint8_t timer_getTime(timer_t self)
{
    return self->remainingTime;
}

bool timer_isStarted(timer_t self)
{
    return self->started;
}

void timer_inc(timer_t self)
{
    int time = timer_getTime(self);
    if (time < UINT8_MAX)
    {
        time++;
    }
    timer_setTime(self, time);
}

void timer_dec(timer_t self)
{
    int time = timer_getTime(self);
    if (time > 1)
    {
        time--;
    }
    timer_setTime(self, time);
}
