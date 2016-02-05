import sys, pygame

print ("Verifying various pygame extensions")

def success (module):
    print ("Successfully loaded pygame " + module + " module")

def failure (module):
    print ("Failure to load pygame " + module + " module")




if pygame.cursors is None:
    failure("cursors")
else:
    success("cursors")

if pygame.display is None:
    failure("display")
else:
    success("display")

if pygame.draw is None:
    failure("draw")
else:
    success("draw")

if pygame.event is None:
    failure("event")
else:
    success("event")

if pygame.font is None:
    failure("font")
else:
    success("font")

if pygame.image is None:
    failure("image")
else:
    success("image")

if pygame.key is None:
    failure("key")
else:
    success("key")

if pygame.mouse is None:
    failure("mouse")
else:
    success("mouse")
