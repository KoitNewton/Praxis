numbers =[2,4,6,8]
for num in numbers:
    num = num *2;
    print (num)

import math as m

def circleArea():
    radius = float(input('Radius:'))
    radiusSqr = m.pow(radius, 2)
    area = m.pi * (radiusSqr)
    return area

area = circleArea()
print (area)
