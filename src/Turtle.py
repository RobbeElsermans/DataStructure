# /bin/python
import sys
import turtle
import fileinput


def draw(text, forward, left, right):
    stack = []
    for command in text:
        turtle.pd()
        if command in ["F", "G", "R", "L","A", "B"]:
            turtle.forward(forward)
        elif command == "f":
            turtle.pu()  # pen up - not drawing
            turtle.forward(forward)
        elif command == "+":
            turtle.right(right)
        elif command == "-":
            turtle.left(left)
        elif command == "[":
            stack.append((turtle.position(), turtle.heading()))
        elif command == "]":
            turtle.pu()  # pen up - not drawing
            position, heading = stack.pop()
            turtle.goto(position)
            turtle.setheading(heading)

    #turtle.done()


def drawInteger(text, forward, left, right):
    stack = []
    for command in text:
        turtle.pd()
        if command in ["1"]:
            turtle.forward(forward)
        elif command == "0":
            turtle.pu()  # pen up - not drawing
            turtle.forward(forward)
        elif command == "2":
            turtle.right(right)
        elif command == "3":
            turtle.left(left)
        elif command == "[":
            stack.append((turtle.position(), turtle.heading()))
        elif command == "]":
            turtle.pu()  # pen up - not drawing
            position, heading = stack.pop()
            turtle.goto(position)
            turtle.setheading(heading)
        #print(command)
    #turtle.done()


def main():
    turtle.speed(0)  # het snelste
    turtle_screen = turtle.Screen()
    turtle_screen.screensize(2000, 2000)
    turtle.colormode(255)

    # disable when drawing needed
    turtle_screen.tracer(0)

    turtle.left(90)

    #turtle.penup()
    #turtle.goto(-500, -500)
    #turtle.pendown()

    # print(text)

    # 0 -> triangle
    # 1 -> plant
    # 2 -> hilbert
    # 3 -> dragon
    # 4 -> snow
    # 5 -> tree
    # 6 -> numberLines
    # 7 -> weirdness
    # 8 -> forrest
    typen = 5

    if typen == 0:
        text = fileinput.input("../output/Triangle1671222347.txt").readline()
        draw(text, 2, 60, 60)
    elif typen == 1:
        text = fileinput.input("../output/Plant1674475501.txt").readline()
        draw(text, 3, 25, 25)
    elif typen == 2:
        text = fileinput.input("../output/Hilbert1671222355.txt").readline()
        draw(text, 3, 90, 90)
    elif typen == 3:
        text = fileinput.input("../output/Dragon1671222353.txt").readline()
        draw(text, 5, 90, 90)
    elif typen == 4:
        text = fileinput.input("../output/SnowWindow1671222358.txt").readline()
        draw(text, 3, 90, 90)
    elif typen == 5:
        text = fileinput.input("../output/Tree1674474982.txt").readline()
        draw(text, 5, 22.5, 22.5)
    elif typen == 6:
        turtle.penup()
        turtle.goto(500, -500)
        turtle.pendown()
        text = fileinput.input("../output/Numberlines1674390054.txt").readline()
        drawInteger(text, 2, 90, 90)
    elif typen == 7:
        text = fileinput.input("../output/Weirdness1674475556.txt").readline()
        draw(text, 2, 90, 90)
    elif typen == 8:
        text = fileinput.input("../output/Tree1671222360.txt").readline()
        turtle.color((1, 255, 1))
        draw(text, 5, 22.5, 22.5)

        turtle.penup()
        turtle.goto(-40, -20)
        turtle.pendown()
        turtle.color((1, 200, 1))
        draw(text, 4, 22.5, 22.5)

        turtle.penup()
        turtle.goto(100, -10)
        turtle.pendown()
        turtle.color((1, 150, 1))
        draw(text, 6, 22.5, 22.8)


    turtle.done()
    # disable when drawing needed
    turtle_screen.update()


if __name__ == "__main__":
    try:
        main()
    except BaseException:
        sys.exit(0)
