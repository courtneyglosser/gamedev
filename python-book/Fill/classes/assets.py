#!/usr/bin/env python

import pygame
from pygame.locals import *

class Assets:
    """ Manage the game assets.  Images, sound files, etc """

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

    def __init__(self):
        """ Blank init to start """

    def preload(self, pygame):
        """ Preload all image assets """
        self.background = pygame.image.load(self.background_image_filename).convert()
        self.mouse_cursor = pygame.image.load(self.mouse_image_filename).convert_alpha()
        self.start_button = pygame.image.load(self.start_button_filename).convert_alpha()
        self.exit_button = pygame.image.load(self.exit_button_filename).convert_alpha()
        self.win_button = pygame.image.load(self.win_button_filename).convert_alpha()
        self.lose_button = pygame.image.load(self.lose_button_filename).convert_alpha()
        self.win_title = pygame.image.load(self.win_title_filename).convert_alpha()
        self.lose_title = pygame.image.load(self.lose_title_filename).convert_alpha()
