import sys
from pyfiglet import Figlet
figs = Figlet()
if (len(sys.argv) not in [1, 3]):
    print("Error: the number of the command line arguments is incorrect!?")
    sys.exit(1)
elif len(sys.argv) == 3 and not(sys.argv[1] in ["-f", "--font"]):
    print("Error: the second line argument should be '-f' or '--font' !?")
    sys.exit(1)
elif len(sys.argv) == 3 and not (sys.argv[2] in figs.getFonts()):
    print("Error: the enterd font isn`t avaiable!?")
    sys.exit(1)
if len(sys.argv) == 3:
    figs.setFont(font=sys.argv[2])
word = input("enter a word to do art : ")
print(figs.renderText(word))
