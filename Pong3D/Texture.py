import pygame # pygame handles the window and keyboard input
from OpenGL.GL import *  # OpenGL does all the 3D rendering

def LoadTexture(image_name):
    textureImg = pygame.image.load(image_name)
    textureData = pygame.image.tostring(textureImg, "RGBA", 1)
    width = textureImg.get_width()
    height = textureImg.get_height()

    glEnable(GL_TEXTURE_2D)
    texid = glGenTextures(1)

    glBindTexture(GL_TEXTURE_2D, texid)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData)

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST)
    return texid

def DrawTexture(pos_x = 0, pos_y = 0, pos_z = 0):
        glEnable(GL_TEXTURE_2D) # enable textures
        
        glBegin(GL_QUADS) # quadrilateral mode, becuase the textures are squares
        
        glTexCoord2f(0.0, 1.0) # top left corner
        glVertex3f(-1.0 + pos_x, 1.0 + pos_y, 0.0 + pos_z)

        glTexCoord2f(1.0, 1.0) # top right corner 
        glVertex3f(1.0 + pos_x, 1.0 + pos_y, 0.0 + pos_z)

        glTexCoord2f(1.0, 0.0) # bottom right corner
        glVertex3f(1.0 + pos_x,  -1.0 + pos_y,  0.0 + pos_z)
        
        glTexCoord2f(0.0, 0.0) # bottom left corner 
        glVertex3f(-1.0 + pos_x,  -1.0 + pos_y,  0.0 + pos_z)
        
        glEnd()
        
        glDisable(GL_TEXTURE_2D) # disable textures. if i don't, drawing non-textured things doesn't work
