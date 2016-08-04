#!/usr/bin/env python

import pygame
from pygame.locals import *
from sys import exit
from classes.assets import Assets
from classes.constants import *
from classes.mouse_input import MouseInput

level_display = 'welcome'

pygame.init()

screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT), 0, 32)
pygame.display.set_caption("Fill Color Game")

images = Assets()
mouse = MouseInput()

images.preload(pygame)

background = images.background

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
                if mouse.clickExit(clickx, clicky):
                    pygame.quit()
                    exit()
                if mouse.clickStart(clickx, clicky):
                    if DEBUG_OUTPUT:
                        print ("Starting Game!!")
                    level_display = 'game board'
                    background = pygame.Surface(screen.get_size())
                    background = background.convert()
                    background.fill((0,0,0))
            if level_display == 'game board':
                if mouse.clickWin(clickx, clicky):
                    level_display = 'win'
                    print("Clicked Win")
                if mouse.clickLose(clickx, clicky):
                    level_display = 'lose'
                    print("Clicked Lose")


        screen.blit(background, (0,0))

        if level_display == 'welcome':
            sx = SCREEN_WIDTH - START_BUTTON_WIDTH
            sy = SCREEN_HEIGHT - START_BUTTON_HEIGHT
            screen.blit(images.start_button, (sx, sy))

            ex = SCREEN_WIDTH - EXIT_BUTTON_WIDTH
            ey = 0
            screen.blit(images.exit_button, (ex, ey))

        if level_display == 'game board':
            sx = (SCREEN_WIDTH / 2)  - (WIN_BUTTON_WIDTH / 2)
            sy = 250
            screen.blit(images.win_button, (sx, sy))

            ex = (SCREEN_WIDTH / 2)  - (LOSE_BUTTON_WIDTH / 2)
            ey = 350
            screen.blit(images.lose_button, (ex, ey))

        if level_display == 'win':
            sx = (SCREEN_WIDTH / 2)  - (WIN_BUTTON_WIDTH / 2)
            sy = 50
            screen.blit(images.win_title, (sx, sy))

        if level_display == 'lose':
            sx = (SCREEN_WIDTH / 2)  - (WIN_BUTTON_WIDTH / 2)
            sy = 50
            screen.blit(images.lose_title, (sx, sy))


        x, y = pygame.mouse.get_pos()
        x-= images.mouse_cursor.get_width() / 2 - 1
        y-= 5
        screen.blit(images.mouse_cursor, (x, y))

        if DEBUG_OUTPUT:
            print(event)

        pygame.display.update()

