palette_hex = ['0x000000', '0x000055', '0x0000aa', '0x0000ff', '0x550000', '0x550055', '0x5500aa', '0x5500ff', '0xaa0000', '0xaa0055', '0xaa00aa', '0xaa00ff', 
               '0xff0055', '0xff00aa', '0xff00ff', '0x005500', '0x005555', '0x0055aa', '0x0055ff', '0x555500', '0x555555', '0x5555aa', '0x5555ff', '0xaa5500', 
               '0xaa5555', '0xaa55aa', '0xaa55ff', '0xff5500', '0xff5555', '0xff55aa', '0xff55ff', '0x00aa00', '0x00aa55', '0x00aaaa', '0x00aaff', '0x55aa00', 
               '0x55aa55', '0x55aaaa', '0x55aaff', '0xaaaa00', '0xaaaa55', '0xaaaaaa', '0xaaaaff', '0xffaa00', '0xffaa55', '0xffaaaa', '0xffaaff', '0x00ff00', 
               '0x00ff55', '0x00ffaa', '0x00ffff', '0x55ff00', '0x55ff55', '0x55ffaa', '0x55ffff', '0xaaff00', '0xaaff55', '0xaaffaa', '0xaaffff', '0xffff00', 
               '0xffff55', '0xffffaa', '0xffffff']
length = len(palette_hex)
reddit=palette_hex[1]
reddit=reddit[2:]
reddit=reddit.lower()
digits=bin(1)
digits=digits[2:]
while len(digits) < 6:
    digits= "0"+ digits
print("if ((value==6\'b"+digits+ "))")
print("begin")
print("Red=8\'h"+reddit[0:2]+";")
print("Green=8\'h"+reddit[2:4]+";")
print("Blue=8\'h"+reddit[4:]+";")
print("end")
for color in range(2,length):
    reddit=palette_hex[color]
    reddit=reddit[2:]
    reddit=reddit.lower()
    digits=bin(color)
    digits=digits[2:]
    while len(digits) < 6:
        digits= "0"+ digits
    print("else if ((value==6\'b"+digits+ "))")
    print("begin")
    print("Red=8\'h"+reddit[0:2]+";")
    print("Green=8\'h"+reddit[2:4]+";")
    print("Blue=8\'h"+reddit[4:]+";")
    print("end")
print("else")
print("begin")
print("Red=8\'hff ;")
print("Green=8\'hff;")
print("Blue=8\'hff;")
print("end")
print("end")
print("endmodule")