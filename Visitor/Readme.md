

I'm surprised I hadn't already created this file.

This is basically a quick capture of todo items I would like to pursue when
I get free time so I don't have to waste time considering what I want to
implement if I have a free minute.

TODO
====

Main game loop implementation
- Currently, blows through one path of game execution, and terminates
- Want to allow additional player input
-- Fight again?
-- Inn?
- Manual player "quit" state

Battle loop
- Now just trade blows until the monster is dead.
- Need to give player attack / run options
- Need to check if player is alive as well


More Monsters
- Currently have a manually defined "Kobold"
- At least some more monsters, even if manual
- Eventually a monster "file" that allows for random loading

Randomize damage
- Currently, just using max.  shouldn't be terribly difficult

More robust save file
- Currently just an archaic list of numbers
- Limited to 3 characters based on display
-- So, could get more robust in save structure.
-- Would be nice to suppose JSON or some other data format

