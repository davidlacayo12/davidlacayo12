import numpy as np

#colors = np.array(['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'])
#palette = np.array(0)
#counter = 0
palette = np.array(['000000','000055','0000aa','0000ff','550000', '550055','5500aa','5500ff','aa0000','aa0055','aa00aa','aa00ff','ff0055','ff00aa','ff00ff','005500','005555','0055aa','0055ff',
'555500','555555','5555aa','5555ff','aa5500','aa5555','aa55aa','aa55ff','ff5500','ff5555','ff55aa','ff55ff','00aa00','00aa55','00aaaa','00aaff','55aa00','55aa55','55aaaa','55aaff','aaaa00','aaaa55',
'aaaaaa','aaaaff','ffaa00','ffaa55','ffaaaa','ffaaff','00ff00','00ff55','00ffaa','00ffff','55ff00','55ff55','55ffaa','55ffff','aaff00','aaff55','aaffaa','aaffff','ffff00','ffff55','ffffaa','ffffff'])
name =  'palette.txt'
f = open(name, "w")
print("start")

for x in range(len(palette)):
    f.write("'0x"+ palette[x] + "', ")
#for i in range(len(colors)):
#    temp = colors[i]
#    for j in range(len(colors)):
#        temp2 = colors[j]
#        for k in range(len(colors)):
#            temp3 = colors[i] + colors[i] + colors[j] + colors[j] + colors[k] + colors[k]
            #print(temp3)
#            f.write("'0x"+ temp3 + "', ")#np.append(palette, temp3)
            #counter = counter + 1

#for x in range(len(palette)):
#    f.write("'0x"+ palette[x] + "', ")

f.close()
print("finished")