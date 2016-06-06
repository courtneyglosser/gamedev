#!/usr/bin/env python

import pygame
from pygame.locals import *
from constants import *

class MouseInput:
    """ Capturing and handling mouse inputs """

    def __init__(self):
        """ Leaving constructor empty for now """


    def clickExit(self, x, y):
        """ Did the user click the exit button?
        Determine if the mouse x and y cooridinates are within the confines
        of the "exit" button.
        """
        rtn = x > SCREEN_WIDTH - EXIT_BUTTON_WIDTH
        rtn = rtn and x < SCREEN_WIDTH
        rtn = rtn and y > 0
        rtn = rtn and y < EXIT_BUTTON_HEIGHT
        return rtn

    def clickStart(self, x, y):
        """ Did the user click the start button?
        Determine if the mouse x and y cooridinates are within the confines
        of the "start" button.
        """
        rtn = x > SCREEN_WIDTH - START_BUTTON_WIDTH
        rtn = rtn and x < SCREEN_WIDTH
        rtn = rtn and y > SCREEN_HEIGHT - START_BUTTON_HEIGHT
        rtn = rtn and y < SCREEN_HEIGHT
        return rtn

    def clickWin(self, x, y):
        """ Did the user click on the 'Win' text?
        Determin if the mouse x and y  coordinates match with the 'Win' text
        """
        rtn = x > (SCREEN_WIDTH / 2) - (WIN_BUTTON_WIDTH / 2)
        rtn = rtn and x < (SCREEN_WIDTH / 2) + (WIN_BUTTON_WIDTH / 2)
        rtn = rtn and y > 250 and y < 300
        return rtn

    def clickLose(self, x, y):
        """ Did the user click on the 'Lose' text?
        Determin if the mouse x and y  coordinates match with the 'Lose' text
        """
        rtn = x > (SCREEN_WIDTH / 2) - (LOSE_BUTTON_WIDTH / 2)
        rtn = rtn and x < (SCREEN_WIDTH / 2) + (LOSE_BUTTON_WIDTH / 2)
        rtn = rtn and y > 350 and y < 400
        return rtn
