from PIL import Image
from collections import Counter
from scipy.spatial import KDTree
import os
import sys
import numpy as np
def hex_to_rgb(num):
    h = str(num)
    return int(h[0:4], 16), int(('0x' + h[4:6]), 16), int(('0x' + h[6:8]), 16)
def rgb_to_hex(num):
    h = str(num)
    return int(h[0:4], 16), int(('0x' + h[4:6]), 16), int(('0x' + h[6:8]), 16)
filename = input("What's the image name? ")
new_w, new_h = map(int, input("What's the new width x height? Like 40 80. ").split(' '))
palette_hex = ['0x000000', '0x000055', '0x0000aa', '0x0000ff', '0x550000', '0x550055', '0x5500aa', '0x5500ff', '0xaa0000', '0xaa0055', '0xaa00aa', '0xaa00ff', 
               '0xff0055', '0xff00aa', '0xff00ff', '0x005500', '0x005555', '0x0055aa', '0x0055ff', '0x555500', '0x555555', '0x5555aa', '0x5555ff', '0xaa5500', 
               '0xaa5555', '0xaa55aa', '0xaa55ff', '0xff5500', '0xff5555', '0xff55aa', '0xff55ff', '0x00aa00', '0x00aa55', '0x00aaaa', '0x00aaff', '0x55aa00', 
               '0x55aa55', '0x55aaaa', '0x55aaff', '0xaaaa00', '0xaaaa55', '0xaaaaaa', '0xaaaaff', '0xffaa00', '0xffaa55', '0xffaaaa', '0xffaaff', '0x00ff00', 
               '0x00ff55', '0x00ffaa', '0x00ffff', '0x55ff00', '0x55ff55', '0x55ffaa', '0x55ffff', '0xaaff00', '0xaaff55', '0xaaffaa', '0xaaffff', '0xffff00', 
               '0xffff55', '0xffffaa', '0xffffff']
palette_rgb = [hex_to_rgb(color) for color in palette_hex]

pixel_tree = KDTree(palette_rgb)
im = Image.open("./sprite_originals/" + filename+ ".png") #Can be many different formats.
im = im.convert("RGBA")
im = im.resize((new_w, new_h),Image.ANTIALIAS) # regular resize
pix = im.load()
pix_freqs = Counter([pix[x, y] for x in range(im.size[0]) for y in range(im.size[1])])
pix_freqs_sorted = sorted(pix_freqs.items(), key=lambda x: x[1])
pix_freqs_sorted.reverse()
outImg = Image.new('RGB', im.size, color='white')
outFile = open("./sprite_bytes/" + filename + '.txt', 'w')
i = 0
for y in range(im.size[1]):
    for x in range(im.size[0]):
        pixel = im.getpixel((x,y))
        if(pixel[3] < 200):
            outImg.putpixel((x,y), palette_rgb[0])
            #ministrike3 changed the %x to a %d because I hate hex
            outFile.write("%d\n" % (0))
        else:
            index = pixel_tree.query(pixel[:3])[1]
            outImg.putpixel((x,y), palette_rgb[index])
            #ministrike3 changed the %x to a %d because I hate hex
            outFile.write("%d\n" % (index))
        i += 1
outFile.close()
#--------------
# everything above is a very slightly modified version of github user atrifex's 
#repo named ECE385-helper tools 
#I wanted the ability to have my sprites available to me as arrays 
#So i changed his hex output into decimal
#and then wrote a bit down here that reformats it into the right array 
os.system('cls' if os.name == 'nt' else 'clear')
name = "./sprite_bytes/" + filename + '.txt'
rawtxt =  open(name, "r")
text= rawtxt.read()
text=text.splitlines()
xval=new_w
yval=new_h
os.system('cls' if os.name == 'nt' else 'clear')
f = open("./sprite_bytes/" + filename + 'array.txt', 'w')
sys.stdout = f
swagger = "\'{"
print(filename + " <=")
print("\'{")
for y in range(0,yval):
    for x in range(0,xval):
        values=str(text[y*xval+x])
        if values == "a":
            values = "17"
        if values == "b":
            values = "18"
        if values == "c":
            values = "19"
        if values == "d":
            values = "20"
        if values == "e":
            values = "21"
        if values == "f":
            values = "22"
        if values == "1a":
            values = "23"
        if values == "1b":
            values = "24"
        if values == "1c":
            values = "25"
        if values == "1d":
            values = "26"
        if values == "1e":
            values = "27"
        if values == "1f":
            values = "28"
        if values == "2a":
            values = "29"
        if values == "2b":
            values = "30"
        if values == "2c":
            values = "31"
        if values == "2d":
            values = "32"
        if values == "2e":
            values = "33"
        if values == "2f":
            values = "34"
        if values == "3a":
            values = "35"
        if values == "3b":
            values = "36"
        if values == "3c":
            values = "37"
        if values == "3d":
            values = "38"
        if values == "3e":
            values = "39"
        if values == "3f":
            values = "40"
        if values == "4a":
            values = "41"
        if values == "4b":
            values = "42"
        if values == "7":
            values = "0"
        swagger = swagger+values
        if(x<xval-1):
            swagger=swagger+(",")
    swagger=swagger+"}"
    if(y<yval-1):
        swagger=swagger+(",")
    print(swagger)
    swagger = "\'{"
print("};")
outImg.save("./sprite_converted/" + filename + ".png")
os.remove("./sprite_bytes/" + filename + '.txt')