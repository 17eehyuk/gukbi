import turtle
import math
s = turtle.getscreen()

# 객체생성
t = turtle.Turtle()
s.bgcolor('pink')
t.color('blue')

t.circle(60)
t.left(60)
t.forward(60*math.sqrt(3))
t.right(60)
t.forward(-60*math.sqrt(3))
t.right(60)
t.forward(60*math.sqrt(3))
t.right(60)
t.forward(-20*math.sqrt(3))
t.left(120)
t.forward(20*math.sqrt(3))
t.left(120)
t.forward(60*math.sqrt(3))
t.left(120)
t.forward(60*math.sqrt(3))
t.left(120)
t.forward(60*math.sqrt(3))

