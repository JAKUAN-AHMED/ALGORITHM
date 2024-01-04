import turtle

# Set up the turtle
screen = turtle.Screen()
screen.bgcolor("white")
pen = turtle.Turtle()
pen.speed(1)
pen.penup()
pen.goto(-100, 0)

# Draw the message "Samia I ❤️ You"
pen.write("Samia I", font=("Arial", 16, "normal"))
pen.forward(120)
pen.color("red")
pen.write("❤️ You", font=("Arial", 16, "normal"))

# Draw a heart emoji
pen.penup()
pen.goto(-50, -50)
pen.pendown()
pen.color("red")
pen.begin_fill()
pen.left(50)
pen.forward(133)
pen.circle(50, 200)
pen.right(140)
pen.circle(50, 200)
pen.forward(133)
pen.end_fill()

# Hide the turtle
pen.hideturtle()

# Keep the window open until it's closed by the user
turtle.done()
