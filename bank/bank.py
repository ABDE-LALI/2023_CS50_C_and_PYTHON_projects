greeting = input("Greeting : ")
words = greeting.lower().split()
if (words[0] in ["hello", "hello,"]):
    print("$0")
elif (words[0][0] == "h"):
    print("$20" )
else :
    print("$100")
print(words[0])
