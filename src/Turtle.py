#/bin/python

import turtle
import fileinput

turtle.speed("fastest")
text = fileinput.input("../output/test1670759286.txt").readline();

print(text)

for item in text:
    print(item)

    #if item == 'X' or item == 'Y':
        #print("do nothing")

    if item == 'F':
        #print("go forward")
        turtle.forward(5)

    if item == '+':
        #print("go 90° right")
        turtle.right(90)

    if item == '-':
        #print("go 90° left")
        turtle.left(90)

turtle.done()