'''
3D pong game
Written by Salix
2020-10-15

The code is structured as follows:
importing libraries
declare variables
define functions
window setup
main menu
main loop
'''

'''
IMPORTS
'''
import pygame               # pygame handles the window and keyboard input
from pygame.locals import *
from OpenGL.GL import *     # OpenGL does all the 3D rendering
from OpenGL.GLU import *    # extra  OpenGL functions

from Objects import *       # other file with object geometry
from Texture import *       # texture loading and drawing functions
import math                 # has math functions like tan
import random               # this is only used to put the ball in a random position

'''
VARIABLES
'''
screenX = 1200       # screen size
screenY = 800
fov = 90             # field of view for camera
cameraDistance = -25 # how far camera is back from the playfield

# calculates the size of playfield based on far back the camera is and its FOV. 
playfieldHeight = vFOV = fov * math.pi / 180
playfieldHeight = 2 * math.tan( vFOV / 2 ) * abs(cameraDistance)
playfieldWidth = playfieldHeight * ( screenX / screenY )
playfieldWidth -= 7

playerOneY = 0       # the Y position of the paddles
playerTwoY = 0
paddleHeight = 9     # width and height of paddles. needed for collision detection.
paddleWidth = 2
paddleSpeed = 0.4    # how fast the paddles move up/down

singleplayer = False # the gamemode. defaults to 2 player
cameraView = 'static'# camera can either be static, centred in the middle of screen, or ballcam where it follows the ball
cameraLastPressed = 0# records when the button to change cameras is pressed, so the camera toggle wont rapidly cycle between the two

ballX = random.randrange(-5, 5) # initialize ball to a random location near the centre of screen
ballY = random.randrange(-5, 5)

ballXdir = 1          # position and speed of ball
ballYdir = 1
ballSpeed = 0.3       # speed of ball

p1score = 0           # score for both players
p2score = 0

'''
FUNCTIONS
'''
def Cube():
    # draws the colours for the cube
    glBegin(GL_QUADS) # gets OpenGL ready to draw quadtilaterals
    for surface in cube_surfaces:
        x = 0
        for vertex in surface:
            offset_vertex = list(cube_verticies[vertex]) # tuples can't be modified, so convert to list
            offset_vertex[0] += ballX                    # change the vertex's X coordinate
            offset_vertex[1] += ballY                    # change the vertex's Y coordinate
            x += 1
            glColor3fv(colours[x])                       # specifies colour
            glVertex3fv(tuple(offset_vertex)) # convert back to tuple, and draw the vertex. in GL_LINES mode, it will automatically connect the vertices
    glEnd()                                              # ends this draw
    
    # draws the cube
    glBegin(GL_LINES) # function uses OpenGL code. initializes 'line' mode
    for edge in cube_edges:
        for vertex in edge:
            offset_vertex = list(cube_verticies[vertex]) # tuples can't be modified, so convert to list
            offset_vertex[0] += ballX                    # change the vertex's X coordinate
            offset_vertex[1] += ballY                    # change the vertex's Y coordinate
            glVertex3fv(tuple(offset_vertex)) # convert back to tuple, and draw the vertex. in GL_LINES mode, it will automatically connect the vertices
    glEnd()                                              # ends this draw
    
def Paddles():
    # draws paddle one
    glBegin(GL_LINES) # function uses OpenGL code. initializes 'line' mode
    for edge in paddle_edges:
        for vertex in edge:
            offset_vertex = list(paddle_verticies[vertex]) # tuples can't be modified, so convert to list
            offset_vertex[0] -= playfieldWidth / 2         # change the vertex's X coordinate
            offset_vertex[1] += playerOneY                 # change the vertex's Y coordinate
            glVertex3fv(tuple(offset_vertex))              # draws lines between the vertices
    glEnd()                                                # ends this draw

    # draws paddle two
    glBegin(GL_LINES)
    for edge in paddle_edges:
        for vertex in edge:
            offset_vertex = list(paddle_verticies[vertex])
            offset_vertex[0] += playfieldWidth / 2
            offset_vertex[1] += playerTwoY
            glVertex3fv(tuple(offset_vertex))
    glEnd()

def DrawBorder(width, height):
    glLineWidth(2) # sets the line thickness to 2
    glBegin(GL_LINES)
    
    # top
    borderVertex = [-(width/2), (height/2) - 0.1, 0] # creates a list with x,y,z 
    glVertex3fv(tuple(borderVertex))
    borderVertex = [width/2, (height/2) - 0.1, 0]
    glVertex3fv(tuple(borderVertex))
    
    # bottom
    borderVertex = [width/2, - (height/2), 0]
    glVertex3fv(tuple(borderVertex))
    borderVertex = [-(width/2), -(height/2), 0]
    glVertex3fv(tuple(borderVertex))

    # left
    borderVertex = [-(width/2), (height/2) - 0.1, 0] 
    glVertex3fv(tuple(borderVertex))
    borderVertex = [-(width/2), -(height/2), 0]
    glVertex3fv(tuple(borderVertex))

    # right
    borderVertex = [width/2, height/2 - 0.1, 0]
    glVertex3fv(tuple(borderVertex))
    borderVertex = [width/2, -(height/2), 0]
    glVertex3fv(tuple(borderVertex))
    
    glEnd()
    glLineWidth(1) # sets line width back to 1

def DrawScore(score1, score2):
    global p1score
    global p2score
        
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)   # clears buffer. all draw functions go after this

    glMatrixMode(GL_MODELVIEW)                         # centres the camera
    glLoadIdentity()
    gluLookAt(0, 0, 25,  0, 0, 0,  0, 1, 0)

    glBindTexture(GL_TEXTURE_2D, numbers[score1 % 6]); # binds the texture for the score
    DrawTexture(-1, 0, 20)                             # draws the number with a x,y,z offset

    glBindTexture(GL_TEXTURE_2D, numbers[score2 % 6]); # binds the texture
    DrawTexture(1, 0, 20)                              # draws the texture

    pygame.display.flip() # switches buffer, updates display. draw functions need to go before this
    
    startWait = pygame.time.get_ticks()
    while pygame.time.get_ticks() - startWait < 2000:
        CheckForCloseWindow()
    
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)   # clears buffer. all draw functions go after this
    
    if p1score >= 5: # player 1 win
        glBindTexture(GL_TEXTURE_2D, player1win);      # binds the texture
        DrawTexture(0, 0, 23)                          # draws the texture
        pygame.display.flip()
        startWait = pygame.time.get_ticks()
        while pygame.time.get_ticks() - startWait < 3000:
            CheckForCloseWindow()
        MainMenu()
        
    if p2score >= 5: # player 2 win
        if singleplayer == False: # if player 2 won
            glBindTexture(GL_TEXTURE_2D, player2win);      # binds the texture
            DrawTexture(0, 0, 23)                          # draws the texture

        if singleplayer == True: # if AI won
            glBindTexture(GL_TEXTURE_2D, aiwin);      # binds the texture
            DrawTexture(0, 0, 23)
            
        pygame.display.flip()
        startWait = pygame.time.get_ticks()
        while pygame.time.get_ticks() - startWait < 3000:
            CheckForCloseWindow()
        MainMenu()

def MoveCube():
    global ballX # the variables this function modifives must be declared global in this function or it gives an error
    global ballY
    global ballXdir
    global ballYdir
    global p1score
    global p2score
    global ballSpeed
    # moves ball
    ballX += ballXdir * ballSpeed
    ballY += ballYdir * ballSpeed

    # checks for bounces off walls
    # vertical walls. this means someone scored
    if ballX >= playfieldWidth / 2: # right wall, so player two
        ballXdir = -1
        ballX = random.randrange(-5, 5)
        ballY = random.randrange(-5, 5)
        ballSpeed = 0.3
        
        p1score += 1
        DrawScore(p1score, p2score)
        print("SCOOOOORE!")
        
    elif ballX <= (-1 * playfieldWidth / 2): # left wall, so player one
        ballXdir = 1
        ballX = random.randrange(-5, 5)
        ballY = random.randrange(-5, 5)
        ballSpeed = 0.3
        
        p2score += 1
        DrawScore(p1score, p2score)
        print("SCOOOOORE!")
        
    # horizontal walls
    if ballY + 2 >= playfieldHeight / 2:
        ballYdir = -1
    elif ballY - 2 <= (-1 * playfieldHeight) / 2:
        ballYdir = 1

    # paddle bounces
    if ballY < playerOneY + (paddleHeight / 2) and ballY > playerOneY - (paddleHeight / 2) and ballX - 2 <=  -1 * playfieldWidth / 2: # left player
        ballXdir = 1
        ballSpeed += 0.01
    if ballY < playerTwoY + (paddleHeight / 2) and ballY > playerTwoY - (paddleHeight / 2) and ballX + 2 >=       playfieldWidth / 2: # right player
        ballXdir = -1
        ballSpeed += 0.01

def KeyboardPlayerOne():
    # checks keys and moves the paddle for player one
    global playerOneY # these two variables this function modifies must be declared global in this function or it gives an error
    
    keys = pygame.key.get_pressed()
    if keys[K_w] == True and playerOneY <= (playfieldHeight / 2) - 7:
        playerOneY += paddleSpeed # Player 1 up 
    if keys[K_s] == True and playerOneY >= -1 * (playfieldHeight / 2) + 7:
        playerOneY -= paddleSpeed # Player 1 down

def KeyboardPlayerTwo():
    # checks keys and moves the paddle for player two
    global playerOneY # these two variables this function modifies must be declared global in this function or it gives an error
    global playerTwoY
    
    keys = pygame.key.get_pressed()
    if keys[K_UP] == True and playerTwoY <= (playfieldHeight / 2) - 7:
        playerTwoY += paddleSpeed # Player 2 up
    if keys[K_DOWN] == True and playerTwoY >= -1 * (playfieldHeight / 2) + 7:
        playerTwoY -= paddleSpeed # Player 2 down

def CheckForCloseWindow(): # this function is essential to pygame, if it isn't run every so often the program will freeze up
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()

def AI(zeroplayer = False): # controls player two if in singleplayer mode
    global playerTwoY
    global playerOneY
    if   ballY > playerTwoY   and playerTwoY <=     (playfieldHeight / 2) - 7:
        playerTwoY += paddleSpeed # Player 2 up

    if   ballY < playerTwoY   and playerTwoY >= -1 *(playfieldHeight / 2) + 7:
        playerTwoY -= paddleSpeed # Player 2 down
        
    if zeroplayer == True:
        if   ballY > playerOneY   and playerOneY <=     (playfieldHeight / 2) - 7:
            playerOneY += paddleSpeed # Player 2 up

        if   ballY < playerOneY   and playerOneY >= -1 *(playfieldHeight / 2) + 7:
            playerOneY -= paddleSpeed # Player 2 down

def MainMenu():
    global singleplayer
    global p1score
    global p2score
    global playerOneY
    global playerTwoY
    p1score = 0 # reset everything
    p2score = 0
    playerOneY = 0
    playerTwoY = 0
    glTranslatef(0.0,0.0, -1 * cameraDistance - 1) # moves camera forwards to where  the title screen image is drawn
    menu = True
    while menu == True:
        
        CheckForCloseWindow()
        
        keys = pygame.key.get_pressed()
        if keys[K_SPACE] == True: 
            menu = False
        if keys[K_1] == True:
            singleplayer = True
        if keys[K_2] == True:
            
            singleplayer == False
        if keys[K_0] == True:
            singleplayer = ''
        
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) # clears buffer. all draw functions go after this
        glBindTexture(GL_TEXTURE_2D, startscreen);
        DrawTexture()
        pygame.display.flip() # switches buffer, updates display. draw functions need to go before this
        pygame.time.wait(10)
    
    glTranslatef(0.0,0.0, cameraDistance + 1) # moves camera back again
    Main()
'''
MAIN LOOP
'''
def Main():
    global cameraView
    global cameraLastPressed
    while True:
        CheckForCloseWindow()
        
        keys = pygame.key.get_pressed()
        if keys[K_c] == True and pygame.time.get_ticks() - cameraLastPressed > 750:
            cameraLastPressed = pygame.time.get_ticks()
            if cameraView == 'static':
                cameraView = 'ballcam'
            elif cameraView == 'ballcam':
                cameraView = 'static'
                

        if singleplayer == True:
            KeyboardPlayerOne()
            AI()
        elif singleplayer == False:
            KeyboardPlayerOne()
            KeyboardPlayerTwo()
        else:
            AI(zeroplayer = True)
            
        MoveCube() # move the cube, checks for scores
        
        if cameraView == 'ballcam':
            glMatrixMode(GL_MODELVIEW)
            glLoadIdentity()
            gluLookAt(0, 0, 25,  ballX / 5, ballY / 5, 0,  0, 1, 0)
        else:
            glMatrixMode(GL_MODELVIEW)
            glLoadIdentity()
            gluLookAt(0, 0, 25,  0, 0, 0,  0, 1, 0)
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT) # clears buffer. all draw functions go after this

        glEnable(GL_CULL_FACE)
        
        Cube()    # renders cube
        Paddles() # renders paddles
        DrawBorder(playfieldWidth + (paddleWidth * 3), playfieldHeight)
        
        glCullFace(GL_FRONT )
        
        pygame.display.flip() # switches buffer, updates display. draw functions need to go before this
        pygame.time.wait(10)
        
'''
WINDOW / OPENGL SETUP
'''
# window and camera setup
pygame.init()
display = (screenX, screenY)
pygame.display.set_mode(display, DOUBLEBUF|OPENGL) # starts Pygame to recieve OpenGL code. Double buffers display
pygame.display.set_caption('3D pong') # sets window title
glMatrixMode(GL_PROJECTION)
glLoadIdentity()
gluPerspective(fov, (display[0]/display[1]), 0.1, 100.0) # FOV, aspect ratio, znear clipping plance, zfar

glMatrixMode(GL_MODELVIEW)
glTranslatef(0.0,0.0, cameraDistance) # translates camera. x, y, z
glMatrixMode(GL_PROJECTION)

# load images to OpenGL textures
startscreen = LoadTexture('assets/titlescreen.png')
numbers = [0,0,0,0,0,0]
numbers[0] = LoadTexture('assets/0.png')
numbers[1] = LoadTexture('assets/1.png')
numbers[2] = LoadTexture('assets/2.png')
numbers[3] = LoadTexture('assets/3.png')
numbers[4] = LoadTexture('assets/4.png')
numbers[5] = LoadTexture('assets/5.png')
player1win = LoadTexture('assets/playeronewin.png')
player2win = LoadTexture('assets/playertwowin.png')
aiwin      = LoadTexture('assets/playeraiwin.png')

# the whole program
MainMenu()
