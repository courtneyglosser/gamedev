#!/usr/bin/env python

import pygame
from pygame.locals import *
from sys import exit

# Overall game dimensions
SCREEN_WIDTH = 960
SCREEN_HEIGHT = 720

# Welcome screen asset dimentions
START_BUTTON_WIDTH = 120
START_BUTTON_HEIGHT = 120
EXIT_BUTTON_WIDTH = 300
EXIT_BUTTON_HEIGHT = 200

#Game board asset dimensions
WIN_BUTTON_WIDTH = 100
WIN_BUTTON_HEIGHT = 100
LOSE_BUTTON_WIDTH = 100
LOSE_BUTTON_HEIGHT = 100

DEBUG_OUTPUT = False

# Background Assets
background_image_filename = 'images/splash2.png'

# Mouse Assets
mouse_image_filename = 'images/mouse.png'

# Welcome Screen Assets
start_button_filename = 'images/start-button.png'
exit_button_filename = 'images/exit-button.png'

# Game Board Assets
win_button_filename = 'images/win.png'
lose_button_filename = 'images/lose.png'

# Game Board Assets
win_title_filename = 'images/win.png'
lose_title_filename = 'images/lose.png'

level_display = 'welcome'

pygame.init()

def clickExit(x, y):
    """ Did the user click the exit button?
    Determine if the mouse x and y cooridinates are within the confines
    of the "exit" button.
    """
    rtn = x > SCREEN_WIDTH - EXIT_BUTTON_WIDTH
    rtn = rtn and x < SCREEN_WIDTH
    rtn = rtn and y > 0
    rtn = rtn and y < EXIT_BUTTON_HEIGHT
    return rtn

def clickStart(x, y):
    """ Did the user click the start button?
    Determine if the mouse x and y cooridinates are within the confines
    of the "start" button.
    """
    rtn = x > SCREEN_WIDTH - START_BUTTON_WIDTH
    rtn = rtn and x < SCREEN_WIDTH
    rtn = rtn and y > SCREEN_HEIGHT - START_BUTTON_HEIGHT
    rtn = rtn and y < SCREEN_HEIGHT
    return rtn

def clickWin(x, y):
    """ Did the user click on the 'Win' text?
    Determin if the mouse x and y  coordinates match with the 'Win' text
    """
    rtn = x > (SCREEN_WIDTH / 2) - (WIN_BUTTON_WIDTH / 2)
    rtn = rtn and x < (SCREEN_WIDTH / 2) + (WIN_BUTTON_WIDTH / 2)
    rtn = rtn and y > 250 and y < 300
    return rtn

def clickLose(x, y):
    """ Did the user click on the 'Lose' text?
    Determin if the mouse x and y  coordinates match with the 'Lose' text
    """
    rtn = x > (SCREEN_WIDTH / 2) - (LOSE_BUTTON_WIDTH / 2)
    rtn = rtn and x < (SCREEN_WIDTH / 2) + (LOSE_BUTTON_WIDTH / 2)
    rtn = rtn and y > 350 and y < 400
    return rtn


screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT), 0, 32)
pygame.display.set_caption("Fill Color Game")

# Preload all image assets
background = pygame.image.load(background_image_filename).convert()
mouse_cursor = pygame.image.load(mouse_image_filename).convert_alpha()
start_button = pygame.image.load(start_button_filename).convert_alpha()
exit_button = pygame.image.load(exit_button_filename).convert_alpha()
win_button = pygame.image.load(win_button_filename).convert_alpha()
lose_button = pygame.image.load(lose_button_filename).convert_alpha()
win_title = pygame.image.load(win_title_filename).convert_alpha()
lose_title = pygame.image.load(lose_title_filename).convert_alpha()

while True:

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()

        if event.type == MOUSEBUTTONUP:
            if DEBUG_OUTPUT:
                print("Mouse up");
            clickx, clicky = pygame.mouse.get_pos()

            if level_display == 'welcome':
                if clickExit(clickx, clicky):
                    pygame.quit()
                    exit()
                if clickStart(clickx, clicky):
                    if DEBUG_OUTPUT:
                        print ("Starting Game!!")
                    level_display = 'game board'
                    background = pygame.Surface(screen.get_size())
                    background = background.convert()
                    background.fill((0,0,0))
            if level_display == 'game board':
                if clickWin(clickx, clicky):
                    level_display = 'win'
                    print("Clicked Win")
                if clickLose(clickx, clicky):
                    level_display = 'lose'
                    print("Clicked Lose")


        screen.blit(background, (0,0))

        if level_display == 'welcome':
            sx = SCREEN_WIDTH - START_BUTTON_WIDTH
            sy = SCREEN_HEIGHT - START_BUTTON_HEIGHT
            screen.blit(start_button, (sx, sy))

            ex = SCREEN_WIDTH - EXIT_BUTTON_WIDTH
            ey = 0
            screen.blit(exit_button, (ex, ey))

        if level_display == 'game board':
            sx = (SCREEN_WIDTH / 2)  - (WIN_BUTTON_WIDTH / 2)
            sy = 250
            screen.blit(win_button, (sx, sy))

            ex = (SCREEN_WIDTH / 2)  - (LOSE_BUTTON_WIDTH / 2)
            ey = 350
            screen.blit(lose_button, (ex, ey))

        if level_display == 'win':
            sx = (SCREEN_WIDTH / 2)  - (WIN_BUTTON_WIDTH / 2)
            sy = 50
            screen.blit(win_title, (sx, sy))

        if level_display == 'lose':
            sx = (SCREEN_WIDTH / 2)  - (WIN_BUTTON_WIDTH / 2)
            sy = 50
            screen.blit(lose_title, (sx, sy))


        x, y = pygame.mouse.get_pos()
        x-= mouse_cursor.get_width() / 2 - 1
        y-= 5
        screen.blit(mouse_cursor, (x, y))

        if DEBUG_OUTPUT:
            print(event)

        pygame.display.update()

