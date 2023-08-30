#Simple Pong in Python
import turtle

wn = turtle.Screen()
wn.title("Pong by @David Lacayo")
wn.bgcolor("black")
wn.setup(width=800, height= 600)
wn.tracer(0)

#Paddle A
paddle_a = turtle.Turtle()
paddle_a.speed(0)
paddle_a.shape("square")   #default is 20x20 size
paddle_a.color("white")
paddle_a.shapesize(stretch_wid=5, stretch_len=1)
paddle_a.penup()
paddle_a.goto(-350, 0)

#Paddle B
paddle_b = turtle.Turtle()
paddle_b.speed(0)
paddle_b.shape("square")   #default is 20x20 size
paddle_b.color("white")
paddle_b.shapesize(stretch_wid=5, stretch_len=1)
paddle_b.penup()
paddle_b.goto(350, 0)
#Ball
ball = turtle.Turtle()
ball.speed(0)
ball.shape("square")   #default is 20x20 size
ball.color("white")
ball.penup()
ball.goto(0, 0)
ball.dx = 3
ball.dy = 3

#Function
def paddle_a_up():
    y = paddle_a.ycor()
    y += 20
    paddle_a.sety(y)

def paddle_a_down():
    y = paddle_a.ycor()
    y -= 20
    paddle_a.sety(y)
def paddle_b_up():
    y = paddle_b.ycor()
    y += 20
    paddle_b.sety(y)

def paddle_b_down():
    y = paddle_b.ycor()
    y -= 20
    paddle_b.sety(y)

#Keyboard Binding
wn.listen()
wn.onkeypress(paddle_a_up, "w")
wn.onkeypress(paddle_a_down, "s")
wn.onkeypress(paddle_b_up, "Up")
wn.onkeypress(paddle_b_down, "Down")


# Main game loop

while True:
    wn.update()


    # Move the ball
    ball.setx(ball.xcor() + ball.dx)
    ball.sety(ball.ycor() + ball.dy)

    # Border Checking
    if ball.ycor() > 290:           #top border
        ball.sety(290)
        ball.dy *= -1

    if ball.ycor() < -290:          #bottom border
        ball.sety(-290)
        ball.dy *= -1

    if ball.xcor() > 390:           #right side border
        ball.goto(0,0)
        ball.dx *=-1

    if ball.xcor() < -390:          #left side border
        ball.goto(0,0)
        ball.dx *=-1

    # Paddle and ball collisions
    if (340 < ball.xcor() < 350) and (ball.ycor() < (paddle_b.ycor() + 40)) and ball.ycor() > (paddle_b.ycor() - 40):
        ball.setx(340)
        ball.dx *= -1
    if (-340 > ball.xcor() > -350) and (ball.ycor() < (paddle_a.ycor() + 40)) and ball.ycor() > (paddle_a.ycor() - 40):
        ball.setx(-340)
        ball.dx *= -1
