# /bin/python
import sys
import turtle
import fileinput


def draw(text, forward, left, right):
    stack = []
    for command in text:
        turtle.pd()
        if command in ["F", "G", "R", "L"]:
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

    turtle.done()


def main():
    turtle.speed(0)  # het snelste
    turtle_screen = turtle.Screen()
    turtle_screen.screensize(2000, 2000)
    text = fileinput.input("../output/Dragon1671179701.txt").readline()

    turtle.left(90)

    print(text)
    # 0 -> triangle
    # 1 -> plant
    # 2 -> hilbert
    # 3 -> dragon
    # 4 -> snow
    # 5 -> tree
    typen = 3

    if typen == 0:
        draw(text, 15, 80, 80)
    elif typen == 1:
        draw(text, 5, 25, 25)
    elif typen == 2:
        draw(text, 15, 90, 90)
    elif typen == 3:
        draw(text, 5, 90, 90)
    elif typen == 4:
        draw(text, 5, 90, 90)
    elif typen == 5:
        draw(text, 5, 22.5, 22.5)


if __name__ == "__main__":
    try:
        main()
    except BaseException:
        sys.exit(0)
