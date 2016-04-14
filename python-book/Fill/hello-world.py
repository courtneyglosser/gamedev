#!/usr/bin/env python

SCREEN_WIDTH = 960
SCREEN_HEIGHT = 720
START_BUTTON_WIDTH = 120
START_BUTTON_HEIGHT = 120
EXIT_BUTTON_WIDTH = 300
EXIT_BUTTON_HEIGHT = 200

background_image_filename = 'splash2.png'
mouse_image_filename = 'mouse.png'
start_button_filename = 'start-button.png'
exit_button_filename = 'exit-button.png'

import pygame
from pygame.locals import *
from sys import exit

pygame.init()

def clickExit(x, y):
    rtn = x > SCREEN_WIDTH - EXIT_BUTTON_WIDTH
    rtn = rtn and x < SCREEN_WIDTH
    rtn = rtn and y > 0
    rtn = rtn and y < EXIT_BUTTON_HEIGHT
    return rtn

screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT), 0, 32)
pygame.display.set_caption("Hello, World!")

background = pygame.image.load(background_image_filename).convert()
mouse_cursor = pygame.image.load(mouse_image_filename).convert_alpha()
start_button = pygame.image.load(start_button_filename).convert_alpha()
exit_button = pygame.image.load(exit_button_filename).convert_alpha()

while True:

    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            exit()

        if event.type == MOUSEBUTTONUP:
            print("Mouse down");
            clickx, clicky = pygame.mouse.get_pos()
            if clickExit(clickx, clicky):
                pygame.quit()
                exit()

        screen.blit(background, (0,0))

        sx = SCREEN_WIDTH - START_BUTTON_WIDTH
        sy = SCREEN_HEIGHT - START_BUTTON_HEIGHT
        screen.blit(start_button, (sx, sy))

        ex = SCREEN_WIDTH - EXIT_BUTTON_WIDTH
        ey = 0
        screen.blit(exit_button, (ex, ey))

        x, y = pygame.mouse.get_pos()
        x-= mouse_cursor.get_width() / 2 - 1
        y-= 5
        screen.blit(mouse_cursor, (x, y))

        print(event)

        pygame.display.update()

