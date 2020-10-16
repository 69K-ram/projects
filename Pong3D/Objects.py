'''
this file just stores all the object geometry

this helped with creating the paddle:
https://technology.cpm.org/general/3dgraph/
'''

'''
COLOURS
'''
colours = ( # OpenGL uses RGB, from 0-1
    (1,0,0),
    (0,1,0),
    (0,0,1),
    (0,1,0),
    (1,1,1),
    (0,1,1),
    (1,0,0),
    (0,1,0),
    (0,0,1),
    (1,0,0),
    (1,1,1),
    (0,1,1),
    )

'''
CUBE
'''
cube_verticies = ( # for a cube
    (1, -1, -1),
    (1, 1, -1),
    (-1, 1, -1),
    (-1, -1, -1),
    (1, -1, 1),
    (1, 1, 1),
    (-1, -1, 1),
    (-1, 1, 1)
    )

cube_edges = ( # a list of the vertices that form edges
    (0,1),
    (0,3),
    (0,4),
    (2,1),
    (2,3),
    (2,7),
    (6,3),
    (6,4),
    (6,7),
    (5,1),
    (5,4),
    (5,7)
    )

cube_surfaces = ( # list of edges that make up surfaces
    (0,1,2,3),
    (3,2,7,6),
    (6,7,5,4),
    (4,5,1,0),
    (1,5,7,2),
    (4,0,3,6)
    )

'''
PADDLES
'''
paddle_verticies = ( # for a cube
    (1, -4, -1),
    (1, 3, -1),
    (-1, 3, -1),
    (-1, -4, -1),
    (1, -4, 1),
    (1, 3, 1),
    (-1, -4, 1),
    (-1, 3, 1)
    )

paddle_edges = ( # a list of the vertices that form edges
    (0,1),
    (0,3),
    (0,4),
    (2,1),
    (2,3),
    (2,7),
    (6,3),
    (6,4),
    (6,7),
    (5,1),
    (5,4),
    (5,7)
    )

paddle_surfaces = ( # list of edges that make up surfaces
    (0,1,2,3),
    (3,2,7,6),
    (6,7,5,4),
    (4,5,1,0),
    (1,5,7,2),
    (4,0,3,6)
    )
